`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 3>                               //
// File name:  Rx_bit_counter_tf.v                       //
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

module Rx_bit_counter_tf;

	// Inputs
	reg clk;
	reg rst;
	reg [1:0] sel;
	reg eight;
	reg p_en;

	// Outputs
	wire done;

	// Instantiate the Unit Under Test (UUT)
	Rx_bit_counter uut (
		.clk(clk), 
		.rst(rst), 
		.sel(sel), 
		.eight(eight), 
		.p_en(p_en), 
		.done(done)
	);

     always #5 clk = ~clk;
     
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		sel = 0;
		eight = 0;
		p_en = 0;

		// Wait 100 ns for global reset to finish
		#5;
          
          sel = 2'b11;
          
          eight = 0;
          p_en = 1;
          #5;
          
        
	end
      
endmodule

