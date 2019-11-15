`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:56:32 12/05/2017
// Design Name:   ReferenceDesign
// Module Name:   C:/Users/tramel/Documents/XilinxProjects/ReferenceDesign/ReferenceDesign/ReferenceDesign/ReferenceDesign_tf.v
// Project Name:  ReferenceDesign
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ReferenceDesign
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ReferenceDesign_tf;

	// Inputs
	reg clk;
	reg rst;
	reg swin;

	// Outputs
	wire [15:0] leds;

	// Instantiate the Unit Under Test (UUT)
	ReferenceDesign uut (
		.clk(clk), 
		.rst(rst), 
		.swin(swin), 
		.leds(leds)
	);

   always #5 clk = ~clk;
	
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		swin = 0;

		// Wait 100 ns for global reset to finish
		#100 rst = 0;
        
		// Add stimulus here

      #1000 swin = 1;
		repeat (20)
		   begin
			#30_000_000 swin = 0;
			#30_000_000 swin = 1;
			end
		
	end
      
endmodule

