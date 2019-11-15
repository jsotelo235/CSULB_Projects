`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:11:30 03/09/2018
// Design Name:   bit_time_counter
// Module Name:   D:/CSULB_Classes/CECS_460/Projects/Project_2/UART/bit_time_counter_tf.v
// Project Name:  UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: bit_time_counter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module bit_time_counter_tf;

	// Inputs
	reg clk;
	reg rst;
	reg [1:0] sel;
	reg [3:0] baud;

	// Outputs
	wire btu;

	// Instantiate the Unit Under Test (UUT)
	bit_time_counter uut (
		.clk(clk), 
		.rst(rst), 
		.sel(sel), 
		.baud(baud), 
		.btu(btu)
	);

     always #5 clk = ~clk;
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		sel = 0;
		baud = 0;

		// Wait 100 ns for global reset to finish
		#100;
          
          sel = 2'b00;
          baud = 4'b000;
          
          #100;
          
          $display("%b, %d, %b", sel, baud, btu);

          sel = 2'b01;
          
          #100;
          
          $display("%b, %d, %b", sel, baud, btu);        

          sel = 2'b10;
          
          #100;
          
          $display("%b, %d, %b", sel, baud, btu);
          
          sel = 2'b11;
          
          #100;
          
          $display("%b, %d, %b", sel, baud, btu);
	end
      
endmodule

