`timescale 1ns/1ns

// Asynchronous-In Synchronous-Out Reset Conditioner
// John Tramel CECS460 CSULB 9/16/2013

module AISO(clk, rst, rsts);

input  clk;   // 50 MHz clock
input  rst;   // asynchronous HA reset
output rsts;  // synchronized HA reset

reg    f1, f2;
wire   rsts;

assign rsts = ~f2;

always @(posedge clk, posedge rst)
   if (rst) {f1,f2} <= 2'b0;
   else     {f1,f2} <= {1'b1,f1};
      
endmodule
