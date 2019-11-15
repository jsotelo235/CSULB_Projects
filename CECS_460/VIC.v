`timescale 1ns/1ps

// Vectored Interrupt Controller
// CSULB CECS 460 John Tramel
// Beta Release 21Mar18
// 05022018 jct - bug found by students - vector array changed with write to 0
//                added VectArray signal to designate references to array
//
// 16 interrupts prioritized for the tramelblaze architecture
// Each interrupt must transition from zero to one to be detected
// cs assumes port_id[15:12] is F???. assign cs = port_id[15:12] == 4'b1111
//   F000: writes of 1's enables interrupt associated with bit position [15:0]
//   F001: writes of 1's disables interrupt associated with bit position
//   F002: writes of 1's forces the associated interrupt to be active - testing
//   F003: writes of 1's forces the associated interrupt to be inactive
//   F006: reads will return the interrupt vector for highest priority active interrupt
//   F010: (r/w) Interrupt Vector Address of interrupt 0 (highest priority)
//   F011: (r/w) Interrupt Vector Address of interrupt 1 
//   F012: (r/w) Interrupt Vector Address of interrupt 2 
//   F013: (r/w) Interrupt Vector Address of interrupt 3 
//   F014: (r/w) Interrupt Vector Address of interrupt 4 
//   F015: (r/w) Interrupt Vector Address of interrupt 5 
//   F016: (r/w) Interrupt Vector Address of interrupt 6 
//   F017: (r/w) Interrupt Vector Address of interrupt 7 
//   F018: (r/w) Interrupt Vector Address of interrupt 8 
//   F019: (r/w) Interrupt Vector Address of interrupt 9 
//   F01A: (r/w) Interrupt Vector Address of interrupt 10 
//   F01B: (r/w) Interrupt Vector Address of interrupt 11 
//   F01C: (r/w) Interrupt Vector Address of interrupt 12 
//   F01D: (r/w) Interrupt Vector Address of interrupt 13 
//   F01E: (r/w) Interrupt Vector Address of interrupt 14 
//   F01F: (r/w) Interrupt Vector Address of interrupt 15 (lowest priority)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vectored Interrupt Controller (with PED at end)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

module VIC(clk, rst, cs, datain, port_id, read_strobe, write_strobe, dout, interrupts, IntAck, InterruptOut);
input         clk;             // system clock (posedge)
input         rst;             // system reset HA - asynchronous
input         cs;              // chip select
input  [15:0] datain;          // input data bus
input  [ 4:0] port_id;         // address bus decoded within module
input  [15:0] interrupts;      // 16 interrupts prioritize from 0 down to 15
input         IntAck;          // interrupt acknowledge from tramelblaze
input         read_strobe;     // HA read strobe one clock wide
input         write_strobe;    // HA write strobe one clock wide
output        InterruptOut;    // interrupt to the tramelblaze
output [15:0] dout;

reg    [15:0] Enable;          // Enable register
reg    [15:0] oute;            // Enable register D term
reg    [15:0] Status;          // Status register
reg    [15:0] outs;            // Status register D term

reg    [15:0] clrint;          // clear interrupt whose vector is read

reg    [15:0] VectAdrs [15:0]; // Vector Address Array 16 x 16

wire   [15:0] IntReq;          // Interrupt Request Pulse
integer       i;               // 'wrapping' variable
integer       j;               // 'wrapping' variable

reg    [31:0] reads;           // read signals for 32 locations (not all used)
reg    [31:0] writes;          // write signals for 32 locations (not all used)
reg           read;            // indication read occuring (could have used read_strobe)
reg           write;           // indication write occuring (could have used write_strobe)
reg    [ 3:0] Vad;             // Vector Array Address
reg    [15:0] Vout;            // Vector Array Output

wire [15:0] IntVec;            // enable & status - active and enabled interrupts
wire        IntOn;
reg         InterruptOut;
reg  [ 3:0] HiInt;             // identifying highest priority interrupt active

wire        VectArray;         // address referencing Vector Array

///////////////////////////////////////////////////////////
// Decode addresses for reads/writes
////////////////////////////////////////////////////////////

assign  VectArray = port_id[4];   // set when referencing Vector Array

always @(*)
   begin
        reads  = 32'b0;
        writes = 32'b0;
        read   =  1'b0;
        write  =  1'b0;
	Vad    =  4'b0;
        if (cs)
           begin
           reads[port_id]  = read_strobe;
           writes[port_id] = write_strobe;
           read            = |reads;
           write           = |writes;
           Vad             = (port_id == 5'h06) ? HiInt : port_id[3:0]; 
           end
   end                

///////////////////////////////////////////////////////////
// Enable register W0: sets -- W1: clears
////////////////////////////////////////////////////////////

always @(*)
   for (i=0; i<16; i=i+1)
      begin
      if (writes[0] & datain[i]) oute[i] = 1'b1; else
      if (writes[1] & datain[i]) oute[i] = 1'b0; else
                                 oute[i] = Enable[i];
      end

always @(posedge clk, posedge rst)
   if (rst) Enable <= 16'b0;
   else     Enable <= oute;

///////////////////////////////////////////////////////////
// Status register W2: sets -- W3: clears
//    Interrupt occurance sets
//    Reading Interrupt Vector clears
////////////////////////////////////////////////////////////

always @(*)
   for (j=0; j<16; j=j+1)
      begin
      if (IntReq[j])             outs[j] = 1'b1; else
      if (datain[j] & writes[2]) outs[j] = 1'b1; else
      if (datain[j] & writes[3]) outs[j] = 1'b0; else
      if (clrint[j])             outs[j] = 1'b0; else
                                 outs[j] = Status[j];
      end

always @(posedge clk, posedge rst)
   if (rst) Status <= 16'b0;
   else     Status <= outs;

///////////////////////////////////////////////////////////
// posedge detect circuit to generate IntReq[15:0]
////////////////////////////////////////////////////////////

ped ped [15:0] (
   .clk (clk),
   .rst (rst),
   .in  (interrupts[15:0]),
   .out (IntReq[15:0])
   );

///////////////////////////////////////////////////////////
// Interrupt to Processor when status == enable == 1
////////////////////////////////////////////////////////////

assign IntVec = Enable & Status;
assign IntOn  = |IntVec & ~|clrint;

ped pediv (
   .clk(clk),
   .rst(rst),
   .in (IntOn),
   .out(SetInt)
   );

always @(posedge clk, posedge rst)
   if (rst)    InterruptOut <= 1'b0; else
   if (SetInt) InterruptOut <= 1'b1; else
   if (IntAck) InterruptOut <= 1'b0;


always @(*)
   casez (IntVec)
      16'b????_????_????_???1: HiInt = 4'b0000;
      16'b????_????_????_??10: HiInt = 4'b0001;
      16'b????_????_????_?100: HiInt = 4'b0010;
      16'b????_????_????_1000: HiInt = 4'b0011;
      16'b????_????_???1_0000: HiInt = 4'b0100;
      16'b????_????_??10_0000: HiInt = 4'b0101;
      16'b????_????_?100_0000: HiInt = 4'b0110;
      16'b????_????_1000_0000: HiInt = 4'b0111;
      16'b????_???1_0000_0000: HiInt = 4'b1000;
      16'b????_??10_0000_0000: HiInt = 4'b1001;
      16'b????_?100_0000_0000: HiInt = 4'b1010;
      16'b????_1000_0000_0000: HiInt = 4'b1011;
      16'b???1_0000_0000_0000: HiInt = 4'b1100;
      16'b??10_0000_0000_0000: HiInt = 4'b1101;
      16'b?100_0000_0000_0000: HiInt = 4'b1110;
      16'b1000_0000_0000_0000: HiInt = 4'b1111;
                      default: HiInt = 4'b0000;
   endcase

///////////////////////////////////////////////////////////
// when vector read clear the interrupt in status
////////////////////////////////////////////////////////////

always @(*)
   begin
   clrint = 16'b0;
   if (reads[6]) clrint[HiInt] = 1'b1;
   end

///////////////////////////////////////////////////////////
// instantiate the 16 vector addresses
////////////////////////////////////////////////////////////

always @(posedge clk, posedge rst)
   if (rst)
      for (i = 0; i < 16; i = i + 1) VectAdrs[i] <= 16'b0; else
      if  (write&VectArray) VectAdrs[Vad] <= datain;
                
always @(*)
   Vout = (VectArray) ? VectAdrs[Vad] : 16'b0;
        
assign dout =  (reads[ 4]) ? Enable       :
               (reads[ 5]) ? Status       :
               (reads[ 6]) ? Vout         :
               (reads[16]) ? VectAdrs[ 0] :
               (reads[17]) ? VectAdrs[ 1] :
               (reads[18]) ? VectAdrs[ 2] :
               (reads[19]) ? VectAdrs[ 3] :
               (reads[20]) ? VectAdrs[ 4] :
               (reads[21]) ? VectAdrs[ 5] :
               (reads[22]) ? VectAdrs[ 6] :
               (reads[23]) ? VectAdrs[ 7] :
               (reads[24]) ? VectAdrs[ 8] :
               (reads[25]) ? VectAdrs[ 9] :
               (reads[26]) ? VectAdrs[10] :
               (reads[27]) ? VectAdrs[11] :
               (reads[28]) ? VectAdrs[12] :
               (reads[29]) ? VectAdrs[13] :
               (reads[30]) ? VectAdrs[14] :
               (reads[31]) ? VectAdrs[15] :
                             16'b0;

endmodule

`timescale 1ns/1ps

// posedge detect module for instantiating in Interrupt Controller
// March 16, 2018 John Tramel CSULB CECS 460

module ped(clk, rst, in, out);

input        clk;
input        rst;
input        in;
output       out;

reg    [1:0] Q;

assign  out = Q[0] & ~Q[1];

always @(posedge clk, posedge rst)
   if (rst) Q <=  2'b0;
   else     Q <= {Q[0],in};

endmodule


