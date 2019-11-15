`timescale 1ns/1ns

// rising edge detect pulse maker
// when input transitions from 0-> 1 generate positive pulse
// John Tramel CECS460 9/16/2013

module pm (clk, rst, in, pulse);

input  clk;
input  rst;
input  in;
output pulse;

reg    f1, f2;

wire   pulse;

assign pulse = f1 & ~f2;

always @(posedge clk, posedge rst)
   if   (rst) {f1,f2} <= 2'b0;
   else       {f1,f2} <= {in,f1};
        
endmodule
