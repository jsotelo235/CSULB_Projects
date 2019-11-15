`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:25:50 05/09/2017 
// Design Name: 
// Module Name:    ramA 
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
module ramA(
    input clk,
    input we,
    input [7:0] addr,
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
