`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:19:12 04/18/2018
// Design Name:   Rx_Engine_Control
// Module Name:   D:/CSULB_Classes/CECS_460/Projects/Project_3_Full_UART/UART/Rx_Engine_Control_tf.v
// Project Name:  UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Rx_Engine_Control
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Rx_Engine_Control_tf;

	// Inputs
	reg clk;
	reg rst;
	reg rx;
	reg [18:0] k;
	reg eight;
	reg p_en;

	// Outputs
	wire start;
	wire btu;
	wire done;

	// Instantiate the Unit Under Test (UUT)
	Rx_Engine_Control uut (
		.clk(clk), 
		.rst(rst), 
		.rx(rx), 
		.k(k), 
		.eight(eight), 
		.p_en(p_en), 
		.start(start), 
		.btu(btu), 
		.done(done)
	);

     always #5 clk = ~clk;
     
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		rx = 1'b1;
		k = 19'd109;
		eight = 0;
		p_en = 0;

          @(negedge clk) rst = ~rst;
          #100 rx = 1'b0;
          #10_000 $finish;

	end
      
endmodule

