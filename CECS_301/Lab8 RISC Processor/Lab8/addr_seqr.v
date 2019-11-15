`timescale 1ns / 1ps
/**********************************************************************************
* File Name: addr_seqr.v
* Project: Lab Project 8 - 16-bit RISC Processor
* Designer: Jose Pacheco
* Email: pacheco216@gmail.com
* Rev. Date: Nov. 27, 2016
*
* Purpose: A memory counter that cycles through 16 bit sequences from the ram.
*
* Notes:
***********************************************************************************/
module addr_seqr(clk, reset, addr);
	input clk;
	input reset;
	output reg [15:0] addr;
	
	always @ (posedge clk, posedge reset) begin
      if (reset == 1'b1)
         addr = 16'b0;
      else
         addr = addr + 1;
	end 

endmodule 