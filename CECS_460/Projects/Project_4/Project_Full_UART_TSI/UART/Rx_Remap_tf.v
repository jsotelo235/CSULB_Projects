`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:55:33 04/18/2018
// Design Name:   Rx_Remap
// Module Name:   D:/CSULB_Classes/CECS_460/Projects/Project_3_Full_UART/UART/Rx_Remap_tf.v
// Project Name:  UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Rx_Remap
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Rx_Remap_tf;

	// Inputs
	reg [1:0] sel;
	reg [9:0] data_in;

	// Outputs
	wire [9:0] remap;

	// Instantiate the Unit Under Test (UUT)
	Rx_Remap uut (
		.sel(sel), 
		.data_in(data_in), 
		.remap(remap)
	);

	initial begin
		// Initialize Inputs
		sel = 0;
		data_in = 10'b11_0000_1010;
          
          #10 sel = {1'b0, 1'b0};
          #10 sel = {1'b1, 1'b0};
          #10 sel = {1'b0, 1'b1};
          #10 sel = {1'b1, 1'b1};
          #10 sel = {1'b0, 1'b0};
          
          #10;
          $finish;
	end
      
endmodule

