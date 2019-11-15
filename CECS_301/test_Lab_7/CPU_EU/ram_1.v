`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:17:00 04/28/2017 
// Design Name: 
// Module Name:    ram_1 
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
module ram_1(
    input clk,
    input we,
    input [15:0] addr,
    input [15:0] din,
    output [15:0] dout
    );

     ram_256x16 dut(
     .clka(clk), // input clka
     .wea(we), // input [0 : 0] wea
     .addra(addr), // input [7 : 0] addra
     .dina(din), // input [15 : 0] dina
     .douta(dout) // output [15 : 0] douta
);

endmodule
