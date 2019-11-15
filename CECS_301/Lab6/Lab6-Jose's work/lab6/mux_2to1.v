`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:41:54 03/26/2017 
// Design Name: 
// Module Name:    mux_2to1 
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
module mux_2to1(a, b, sel, mux_out);

     input     [15:0]    a, b;
     input               sel;
     
     output    [15:0]    mux_out;
     
     reg       [15:0]    mux_out;
     
     always @(a or b or sel)
          if(sel == 1'b0)
               mux_out = a;
          else
               mux_out = b;
endmodule
