`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Shift_Reg_tf.v                            //
//                                                       //
// Created by <Jose Sotelo> on <>                        // 
//                                                       //
// In submitting this file for class work at CSULB       //
// I am confirming that this is my work and the work     //
// of no one else.                                       // 
//                                                       //
// In the event other code source are utilized I will    //
// document which portion of code and who is the author  //
//                                                       //
// In submitting this code I acknowledge that plagiarism //
// in student project work is subject to dismissal from  //
// the class                                             //
//*******************************************************//

module Shift_Reg_tf;

	// Inputs
	reg clk;
	reg rst;
	reg [10:0] data_in;
	reg load;
	reg shift;

	// Outputs
	wire sdo;

	// Instantiate the Unit Under Test (UUT)
	Shift_Register uut (
		.clk(clk), 
		.rst(rst), 
		.data_in(data_in), 
		.load(load), 
		.shift(shift), 
		.sdo(sdo)
	);

     always #5 clk = ~clk;
     
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		data_in = 0;
		load = 0;
		shift = 0;

		// Wait 100 ns for global reset to finish
		#10;
          
          rst = 0;
          #10;
          
          data_in = 11'b11111_000001;
          load = 1;
          #10;
          
          load = 0;
          #10;
          
          shift = 1;
          #10;
          
     
	end
      
endmodule

