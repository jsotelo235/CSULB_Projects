`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:04:20 03/10/2017 
// Design Name: 
// Module Name:    ram1 
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
module ram1(
    input           clk,
    input           we,
    input  [7:0]    addr,
    input  [15:0]   din,
    output [15:0]   dout
    );
//----------- Begin Cut here for INSTANTIATION Template ---// INST_TAG
     ram_256x16 ram (
     .clka(clk), // input clka
     .wea(we), // input [0 : 0] wea
     .addra(addr), // input [7 : 0] addra
     .dina(din), // input [15 : 0] dina
     .douta(dout) // output [15 : 0] douta
);
// INST_TAG_END ------ End INSTANTIATION Template ---------

endmodule
