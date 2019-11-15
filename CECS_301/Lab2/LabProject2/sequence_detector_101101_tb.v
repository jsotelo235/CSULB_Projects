`timescale 1ps / 100fs

//   DATE:     Thursday February 23 2017
//   Author:   Jose Sotelo
//   Module:   sequence_detector_101101
//   FileName: sequence_detector_101101_tb
//   Project:  301_lab2
//   Version:  Version 1.0
module sequence_detector_101101_tb;

	// Inputs
	reg clk;
	reg reset;
	reg X;
	reg M;

	// Outputs
	wire [2:0] Q;
	wire Z;
     
     //Local Declarations
     reg [44:1] sequence_pattern;
     integer    i;

	// Instantiate the Unit Under Test (UUT)
	sequence_detector_101101 uut (
		.clk(clk), 
		.reset(reset), 
		.X(X), 
		.M(M),
          .Z(Z),
		.Q(Q)
	);
     
     //Generate 10 ps Clock
     always
          #5 clk = ~clk;
     
     //Initialize Inputs
     
	initial begin
	$timeformat(-12, 1, " ps", 8);
     clk = 0; reset = 0; X = 0; M = 0;
     sequence_pattern = 44'b01100010101101011011111001011011011011101010;
     @(negedge clk)
          reset = 1;
     @(negedge clk)
          reset = 0;
          M = 0;         // Moore implementation (M=0); to simulate the
                         // Mealy implementation, set M = 1 and run the simulation again
                         
     // this loop will "feed" the sequence detector with the
     //test sequence pattern from MSB to LSB
          for(i=44; i > 0; i=i-1) begin
               //change inputs on negative edge of clock
               @(negedge clk)
                    X = sequence_pattern[i];
               //display outputs after the positive clock
               @(posedge clk)
                    #1 $display("Time=%t  X=%b  Q=%b  Z=%b", $time, X, Q, Z);
               end
          $stop;
	end
endmodule

