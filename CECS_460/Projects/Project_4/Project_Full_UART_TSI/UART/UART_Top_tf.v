`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:19:29 04/20/2018
// Design Name:   UART_Top
// Module Name:   D:/CSULB_Classes/CECS_460/Projects/Project_3_Full_UART/UART/UART_Top_tf.v
// Project Name:  UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: UART_Top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module UART_Top_tf;

	// Inputs
	reg clk;
	reg rst;
	reg write;
	reg [1:0] read;
	reg [7:0] out_port;
	reg rx;
	reg [3:0] baud;
	reg eight;
	reg p_en;
	reg ohel;

	// Outputs
	wire tx;
	wire [7:0] UART_DS;
	wire UART_INT;

	// Instantiate the Unit Under Test (UUT)
	UART_Top uut (
		.clk(clk), 
		.rst(rst), 
		.write(write), 
		.read(read), 
		.out_port(out_port), 
		.rx(rx), 
		.baud(baud), 
		.eight(eight), 
		.p_en(p_en), 
		.ohel(ohel), 
		.tx(tx), 
		.UART_DS(UART_DS), 
		.UART_INT(UART_INT)
	);

     always #5 clk = ~clk;
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		write = 0;
		read = 2'b00;
		out_port = 8'b01101010;
		rx = 0;
		baud = 4'b1011;
		eight = 0;
		p_en = 0;
		ohel = 0;
          
          @(negedge clk) rst = ~rst;
          @(negedge clk) write = 1;
          @(negedge clk) write = 0;
          @(negedge clk) write = 2;
          
          #50_000 read = 1;
          @(negedge clk) read = 0;
          $finish;
        


	end
      
endmodule

