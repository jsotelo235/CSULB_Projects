`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:20:03 03/07/2018
// Design Name:   Shift_Register
// Module Name:   D:/CSULB_Classes/CECS_460/Projects/Project_2/UART/Shift_Reg_tb.v
// Project Name:  UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Shift_Register
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Shift_Reg_tb;

	// Inputs
	reg clk;
	reg rst;
	reg [10:0] data_in;
	reg load;
	reg shift;

	// Outputs
	wire sdo;

	// Instantiate the Unit Under Test (UUT)
	Shift_Register uut (
		.clk(clk), 
		.rst(rst), 
		.data_in(data_in), 
		.load(load), 
		.shift(shift), 
		.sdo(sdo)
	);

     always #5 clk = ~clk;
     
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		data_in = 11'b0;
		load = 0;
		shift = 0;

		#500;
          
          data_in = 11'b00001_000001;
          rst = 1;
          load = 0;
          shift = 0;
          
          #100;
          
          load = 1'b1;
          #100;
          
          load = 1'b0;
          shift = 1'b1;
          #100;
          
          shift = 1'b1;
          #100;
          
          shift = 1'b1;
          #100;
          
          shift = 1'b1;
          #100;
          
          shift = 1'b1;
          #100;          

          shift = 1'b1;
          #100;

          shift = 1'b1;
          #100;

          shift = 1'b1;
          #100;

	end
      
endmodule

