`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:51:14 03/25/2018
// Design Name:   Rx_Shift_Reg
// Module Name:   D:/CSULB_Classes/CECS_460/Projects/Project_3_Full_UART/UART/Rx_Shift_Reg_tf.v
// Project Name:  UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Rx_Shift_Reg
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Rx_Shift_Reg_tf;

	// Inputs
	reg clk;
	reg rst;
	reg sh;
	reg sdi;

	// Outputs
	wire [9:0] data_out;

	// Instantiate the Unit Under Test (UUT)
	Rx_Shift_Reg uut (
		.clk(clk), 
		.rst(rst), 
		.sh(sh), 
		.sdi(sdi), 
		.data_out(data_out)
	);

     always #5 clk = ~clk;
     
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1'b1;
		sh = 0;
		sdi = 0;
          
          @(negedge clk) rst = ~rst;
          @(negedge clk) sh = 1'b1;
          
          repeat(3)begin
              @(negedge clk) sdi = 1'b1;
          end

          repeat(3)begin
              @(negedge clk) sdi = 1'b0;
          end

          repeat(3)begin
              @(negedge clk) sdi = 1'b1;
          end
          
          @(negedge clk) sdi = 1'b1;
          @(negedge clk) sh = 1'b0;
          
          #10 $finish;
	end
      
endmodule

