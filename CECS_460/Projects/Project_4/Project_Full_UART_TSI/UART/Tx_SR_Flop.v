`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:36:06 04/16/2018 
// Design Name: 
// Module Name:    Tx_SR_Flop 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Tx_SR_Flop(clk, rst, S, R, Q);

     input     clk, rst;
     input     S, R;
     
     output    Q;
     
     reg       Q;
     
     always @(posedge clk, posedge rst)
          if(rst)
               Q <= 1'b0;
          else if(S)
               Q <= 1'b1;
          else if(R)
               Q <= 1'b0;
          else
               Q <= Q;


endmodule
