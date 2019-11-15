`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:56:43 05/08/2017 
// Design Name: 
// Module Name:    mem_counter 
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
module mem_counter(clk, reset, addr);

	input                    clk, reset;
	output reg     [15:0]    addr;
	
	always @ (posedge clk, posedge reset) begin
      if (reset == 1'b1)
         addr = 16'b0;
      else
         addr = addr + 1;
	end 
endmodule
