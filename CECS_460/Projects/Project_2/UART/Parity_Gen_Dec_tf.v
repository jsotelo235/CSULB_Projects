`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Parity_Gen_Dec_tf.v                       //
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
module Parity_Gen_Dec_tf;

	// Inputs
	reg [7:0] load_data;
	reg eight;
	reg p_en;
	reg ohel;

	// Outputs
	wire bit10;
	wire bit9;

	// Instantiate the Unit Under Test (UUT)
	Parity_Gen_Dec uut (
		.load_data(load_data), 
		.eight(eight), 
		.p_en(p_en), 
		.ohel(ohel), 
		.bit10(bit10), 
		.bit9(bit9)
	);

	initial begin
		// Initialize Inputs
		load_data = 8'h65;
          
		eight = 0; p_en =  0; ohel =  0;
		#10;
          
          $display("%b, %b, %b, %b, %b,", load_data, eight, p_en, ohel, bit10, bit9);
          
          eight = 0; p_en =  0; ohel =  1;
          #10;
          
          $display("%b, %b, %b, %b, %b,", load_data, eight, p_en, ohel, bit10, bit9);
          
          eight = 0; p_en =  1; ohel =  0;
          #10;
          
          $display("%b, %b, %b, %b, %b,", load_data, eight, p_en, ohel, bit10, bit9);
          
          eight = 0; p_en =  1; ohel =  1;
          #10;

          $display("%b, %b, %b, %b, %b,", load_data, eight, p_en, ohel, bit10, bit9);          

          eight = 1; p_en =  0; ohel =  0;
          #10;
          
          $display("%b, %b, %b, %b, %b,", load_data, eight, p_en, ohel, bit10, bit9);
          
          eight = 1; p_en =  0; ohel =  1;
          #10;
          
          $display("%b, %b, %b, %b, %b,", load_data, eight, p_en, ohel, bit10, bit9);

          eight = 1; p_en =  1; ohel =  0;
          #10;
          
          $display("%b, %b, %b, %b, %b,", load_data, eight, p_en, ohel, bit10, bit9);
          
          eight = 1; p_en =  1; ohel =  1;
          #10;
          
          $display("%b, %b, %b, %b, %b,", load_data, eight, p_en, ohel, bit10, bit9);
          
          #10;
          $stop;
	end
      
endmodule

