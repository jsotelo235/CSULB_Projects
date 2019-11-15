`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:01:37 04/18/2018
// Design Name:   Rx_Engine
// Module Name:   D:/CSULB_Classes/CECS_460/Projects/Project_3_Full_UART/UART/Rx_Engine_tf.v
// Project Name:  UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Rx_Engine
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Rx_Engine_tf;

	// Inputs
	reg clk;
	reg rst;
	reg rx;
	reg [18:0] k;
	reg eight;
	reg p_en;
	reg ohel;
	reg read;

	// Outputs
	wire rx_rdy;
	wire parity_err;
	wire frame_err;
	wire overflow;
	wire [7:0] data_to_TB;

	// Instantiate the Unit Under Test (UUT)
	Rx_Engine uut (
		.clk(clk), 
		.rst(rst), 
		.rx(rx), 
		.k(k), 
		.eight(eight), 
		.p_en(p_en), 
		.ohel(ohel), 
		.read(read), 
		.rx_rdy(rx_rdy), 
		.parity_err(parity_err), 
		.frame_err(frame_err), 
		.overflow(overflow), 
		.data_to_TB(data_to_TB)
	);

     always #5 clk = ~clk;
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		rx = 1;
		k = 19'd109 - 1;
		eight = 0;
		p_en = 0;
		ohel = 0;
		read = 0;

		// Wait 100 ns for global reset to finish
		#100;
          
          rst = 0;
          rx = 0;
          
          
          wait(uut.control_rx.btu == 1);
          wait(uut.control_rx.btu == 0);
          rx = 1'b0;
          
          
          wait(uut.control_rx.btu == 1);
          wait(uut.control_rx.btu == 0);
          rx = 1'b1;
          
          
          wait(uut.control_rx.btu == 1);
          wait(uut.control_rx.btu == 0);
          rx = 1'b1;
          
          
          wait(uut.control_rx.btu == 1);
          wait(uut.control_rx.btu == 0);
          rx = 1'b1;
          
          
          wait(uut.control_rx.btu == 1);
          wait(uut.control_rx.btu == 0);
          rx = 1'b0;
          
          
          wait(uut.control_rx.btu == 1);
          wait(uut.control_rx.btu == 0);
          rx = 1'b1;
          
          
          wait(uut.control_rx.btu == 1);
          wait(uut.control_rx.btu == 0);
          rx = 1'b0;
          

          wait(uut.control_rx.btu == 1);
          wait(uut.control_rx.btu == 0);
          rx = 1'b1;
          
          wait(uut.control_rx.done == 1);
          #200
          $stop;
	end
      
endmodule

