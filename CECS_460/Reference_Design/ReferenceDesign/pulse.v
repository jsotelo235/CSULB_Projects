`timescale 1ns/1ns

// 10ms pulse generator
// for Pong Chu debounce algorithm
// CECS460 CSULB John Tramel 9/16/2013

module pulse(clk, rst, tick);

input        clk;
input        rst;

output       tick;

reg   [18:0] counter;
wire         tick;

assign tick = (counter == 499_999);

always @(posedge clk, posedge rst)
   if (rst)  counter <= 8'b0; else
   if (tick) counter <= 8'b0; else
             counter <= counter + 1;
        
endmodule
