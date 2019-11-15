`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:38:16 04/15/2018
// Design Name:   Tx_Engine
// Module Name:   D:/CSULB_Classes/CECS_460/Projects/Project_3_Full_UART/UART/Tx_Engine_tf.v
// Project Name:  UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Tx_Engine
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Tx_Engine_tf;

	// Inputs
	reg clk;
	reg rst;
	reg load;
	reg [18:0] baud_count;
	reg [7:0] data_in;
	reg eight;
	reg p_en;
	reg ohel;

	// Outputs
	wire txrdy;
	wire tx;

	// Instantiate the Unit Under Test (UUT)
	Tx_Engine uut (
		.clk(clk), 
		.rst(rst), 
		.load(load), 
		.baud_count(baud_count), 
		.data_in(data_in), 
		.eight(eight), 
		.p_en(p_en), 
		.ohel(ohel), 
		.txrdy(txrdy), 
		.tx(tx)
	);

     always #5 clk = ~clk;
     
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		load = 0;
		baud_count = 0;
		data_in = 0;
		eight = 0;
		p_en = 0;
		ohel = 0;
          
		#100;
          rst = 1'b1;
          
          #100;
          rst = 1'b0;
          load = 1'b1;
          baud_count = 19'b1;
          data_in = 7'b111_001;
          eight = 0;
          p_en = 1;
          ohel = 0;
          
          #100;
        

	end
      
endmodule

