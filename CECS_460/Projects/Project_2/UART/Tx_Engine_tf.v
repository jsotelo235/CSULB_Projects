`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Tx_Engine_tf.v                            //
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

module Tx_Engine_tf;

	// Inputs
	reg clk;
	reg rst;
	reg load;
	reg [7:0] data_in;
	reg eight;
	reg p_en;
	reg ohel;
	reg [3:0] baud;

	// Outputs
	wire txrdy;
	wire tx;

	// Instantiate the Unit Under Test (UUT)
	Tx_Engine uut (
		.clk(clk), 
		.rst(rst), 
		.load(load), 
		.data_in(data_in), 
		.eight(eight), 
		.p_en(p_en), 
		.ohel(ohel), 
		.baud(baud), 
		.txrdy(txrdy), 
		.tx(tx)
	);

     always #5 clk = ~clk;
     
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		load = 0;
		eight = 0;
		p_en = 0;
		ohel = 0;
          
          data_in = 8'h65;
		baud = 4'b0001;

		// Wait 100 ns for global reset to finish
		#100;
          
          rst = 0;
          #100;
          
          //case 0
          eight = 0;
		p_en = 0;
		ohel = 0;
          load = 1;
          #100;
          
          //case 1
          eight = 0;
		p_en = 0;
		ohel = 1;
          load = 1;
          #100;
          
          //case 2
          eight = 0;
		p_en = 1;
		ohel = 0;
          load = 1;
          #100;
          
          //case 3
          eight = 0;
		p_en = 1;
		ohel = 1;
          load = 1;
          #100;
          
          //case 4
          eight = 1;
		p_en = 0;
		ohel = 0;
          load = 1;
          #100;
  
          //case 5
          eight = 1;
		p_en = 0;
		ohel = 1;
          load = 1;
          #100;
          
          //case 6
          eight = 1;
		p_en = 1;
		ohel = 0;
          load = 1;
          #100
          
          //case 7
          eight = 1;
		p_en = 1;
		ohel = 1;
          load = 1;
          #100;
          
	end
      
endmodule

