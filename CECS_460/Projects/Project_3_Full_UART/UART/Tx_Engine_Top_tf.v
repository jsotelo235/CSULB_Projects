`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:22:27 03/13/2018
// Design Name:   Tx_Engine_Top
// Module Name:   D:/CSULB_Classes/CECS_460/Projects/Project_2/UART/Tx_Engine_Top_tf.v
// Project Name:  UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Tx_Engine_Top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Tx_Engine_Top_tf;

	// Inputs
	reg clk;
	reg rst;
	reg [3:0] baud;
	reg eight;
	reg p_en;
	reg ohel;

	// Outputs
	wire [15:0] led;
	wire tx;

	// Instantiate the Unit Under Test (UUT)
	Tx_Engine_Top uut (
		.clk(clk), 
		.rst(rst), 
		.baud(baud), 
		.eight(eight), 
		.p_en(p_en), 
		.ohel(ohel), 
		.led(led), 
		.tx(tx)
	);

     always #5 clk = ~clk;
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		baud = 0;
		eight = 0;
		p_en = 0;
		ohel = 0;

		// Wait 100 ns for global reset to finish
		#100;
          
          rst = 0;
          #100;
          
          baud = 4'b0001;
        
		// Add stimulus here

	end
      
endmodule

