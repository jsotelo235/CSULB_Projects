`timescale 1ns/1ps

// Reference Design for TramelBlaze Processor
// John Tramel CECS CSULB 12/5/2017


module ReferenceDesign (clk, rst, swin, leds);

input         clk;    // 50 MHz clock
input         rst;    // asynchronous HA reset
input         swin;   // switch in
output [15:0] leds;   // sixteen leds (nexys4)

// data types for various blocks

wire          rsts;
reg    [ 1:0] rQ;
wire          db;
reg    [ 1:0] pedQ;
reg    [ 2:0] next, present;
reg    [18:0] counter;
wire          tick;
reg           interrupt;
wire   [15:0] in_port;
wire   [15:0] out_port;
wire   [15:0] port_id;
reg    [15:0] leds;

//////////////////////////////////////////////////////////
// asynchronous in synchronous out - reset conditioning
//////////////////////////////////////////////////////////

assign rsts = ~rQ[1];

always @(posedge clk, posedge rst)
   if (rst) {rQ[1],rQ[0]} <= {1'b0, 1'b0};
   else     {rQ[1],rQ[0]} <= {rQ[0],1'b1};
  
//////////////////////////////////////////////////////////
// generate the 10ms pulse for the debounce
//////////////////////////////////////////////////////////

assign tick = (counter == 499_999);

always @(posedge clk, posedge rsts)
   if (rsts)  counter <= 19'b0; else
   if (tick)  counter <= 19'b0; else
              counter <= counter + 19'b1;

//////////////////////////////////////////////////////////
// debounce the switch input
//////////////////////////////////////////////////////////

parameter    S00 = 3'b000,        // output 0
             S01 = 3'b001,
             S02 = 3'b010,
             S03 = 3'b011,
             S10 = 3'b100,        // output 1
             S11 = 3'b101,
             S12 = 3'b110,
             S13 = 3'b111;

always @(posedge clk, posedge rsts)
   if (rsts) present <= S00; else
             present <= next;

assign db = present[2];
                                  
always @(*)
   case(present)
           S00: next = (swin)         ? S01 : S00;
           S01: next = (swin & tick)  ? S02 :
                       (swin)         ? S01 :
                                        S00;
           S02: next = (swin & tick)  ? S03 :
                       (swin)         ? S02 :
                                        S00;
           S03: next = (swin & tick)  ? S10 :
                       (swin)         ? S03 :
                                        S00;
           S10: next = (!swin)        ? S11 : S10;
           S11: next = (!swin & tick) ? S12 :
                       (!swin)        ? S11 :
                                        S10;
           S12: next = (!swin & tick) ? S13 :
                       (!swin)        ? S12 :
                                        S10;
           S13: next = (!swin & tick) ? S01 :
                       (!swin)        ? S13 :
                                        S10;
       default: next =                  S00;
  endcase
  
//////////////////////////////////////////////////////////
// positive edge detect of db
//////////////////////////////////////////////////////////

assign ped = pedQ[0] & ~pedQ[1];

always @(posedge clk, posedge rsts)
   if (rsts) {pedQ[1],pedQ[0]} <= {1'b0,1'b0}; 
   else      {pedQ[1],pedQ[0]} <= {pedQ[0],db};
	
//////////////////////////////////////////////////////////
// rs flop for holding interrupt to TramelBlaze
//////////////////////////////////////////////////////////

always @(posedge clk, posedge rsts)
   if (rsts)          interrupt <= 1'b0; else
   if (ped)           interrupt <= 1'b1; else
   if (interrupt_ack) interrupt <= 1'b0;

//////////////////////////////////////////////////////////
// instantiate the TramelBlaze Processor
//////////////////////////////////////////////////////////

tramelblaze_top tbt
                   (
                   .CLK          (clk), 
		   .RESET        (rsts), 
		   .IN_PORT      (in_port), 
		   .INTERRUPT    (interrupt), 
                        
		   .OUT_PORT     (out_port), 
		   .PORT_ID      (port_id), 
		   .READ_STROBE  (read_strobe), 
		   .WRITE_STROBE (write_strobe), 
		   .INTERRUPT_ACK(interrupt_ack)
	           );

//////////////////////////////////////////////////////////
// define a register to drive the leds
//////////////////////////////////////////////////////////

always @(posedge clk, posedge rsts)
   if (rsts)         leds <= 16'b0; else
   if (write_strobe) leds <= out_port;

endmodule
