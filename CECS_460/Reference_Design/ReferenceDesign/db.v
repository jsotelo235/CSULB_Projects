`timescale 1ns/1ns

// mechanical debounce
// inputs must remain stable for at least 20ms to switch output
// CECS460 CSULB John Tramel 9/16/2013

module debounce(clk, rst, tick, swin, db);

input         clk;
input         rst;
input         tick;     // 10ms pulse
input         swin;     // switch in
output        db;

reg     [2:0] next, present;

parameter    S00 = 3'b000,        // output 0
             S01 = 3'b001,
             S02 = 3'b010,
             S03 = 3'b011,
             S10 = 3'b100,        // output 1
             S11 = 3'b101,
             S12 = 3'b110,
             S13 = 3'b111;

always @(posedge clk, posedge rst)
   if (rst) present <= S00; else
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
        
endmodule
