`timescale 1ns / 1ps
/************************************************************************
* File Name: ram1.v
* Project: Lab Project 8: 16-Bit RISC Processor
* Designer:	Jose Pacheco
* Email:	pacheco216@gmail.com
* Rev. Date: Nov. 27, 2016
*	
* Purpose: A simple memory module that stores 256 16-bit values
*
* Notes: Used IP Core Generator to generate the ram_256x16.xco file
************************************************************************/
module ram1(clk, we, addr, din, dout);
    input clk;
	 input we;
    input [7:0] addr;
    input [15:0] din;
    output [15:0] dout;
    
    ram_256x16 ram_256x16 (
        .clka(clk), // input clka
        .wea(we), // input [0 : 0] wea
        .addra(addr), // input [7 : 0] addra
        .dina(din), // input [15 : 0] dina
        .douta(dout) // output [15 : 0] douta
      );


endmodule
