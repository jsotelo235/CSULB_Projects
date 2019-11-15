`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:57:31 03/27/2017 
// Design Name: 
// Module Name:    s_mux 
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
module s_mux(S_in, DS_in, Sel_in, S_mux_out);

     input     [15:0]    S_in, DS_in;
     input               Sel_in;
     
     output    [15:0]   S_mux_out;
     
     wire               w_smux_out;

     assign S_mux_out = (Sel_in) ? S_in : DS_in;
endmodule
