`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:41:29 04/16/2018
// Design Name:   Rx_FSM
// Module Name:   D:/CSULB_Classes/CECS_460/Projects/Project_3_Full_UART/UART/Rx_FSM_tf.v
// Project Name:  UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Rx_FSM
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Rx_FSM_tf;

	// Inputs
	reg clk;
	reg rst;
	reg rx;
	reg btu;
	reg done;

	// Outputs
	wire start;
	wire do_it;

	// Instantiate the Unit Under Test (UUT)
	Rx_FSM uut (
		.clk(clk), 
		.rst(rst), 
		.rx(rx), 
		.btu(btu), 
		.done(done), 
		.start(start), 
		.do_it(do_it)
	);

     always #5 clk = ~clk;
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		rx = 0;
		btu = 0;
		done = 0;

		$display("S0");
		#10;
         
          rst = 0; 
          rx = 1;
          $display("S0");
          #10;
          
          rx = 0;
          $display("S1");
          #10;
          
          rx = 1;
          $display("S0");
          #10;
          
          rx = 0;
          btu = 0;
          $display("S1");
          #10;
          
          rx = 0;
          btu = 1;
          $display("S2");
          #10;
          
          done = 0;
          $display("S2");
          #10;
          
          done = 1;
          $display("S0");
          #10;
          $stop;

	end
      
endmodule

