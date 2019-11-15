`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:42:50 04/19/2017 
// Design Name: 
// Module Name:    adr_mux 
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
module adr_mux(a, b, sel, mux_out);
     
     input     [15:0]    a,b;
     input               sel;
     
     output    [15:0]    mux_out;
     
     assign mux_out = sel ? a : b;
endmodule
