`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     dec_3to_8.v
*    Project:       Lab Project 7: CPU Excecution unit
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     April. 19, 2017
*
*    Purpose:
*    The purpose for this module is to create a 3-to-8 decoder that is used
*    to select one 2^n outputs from n inputs.
*    
*    The module of the 3-to-8 decoder is constructed with an active high
*    enable input and active low outputs. This module uses a trinary con-
*    tinuous assignment statement for the combinational logic.
 ****************************************************************************/
module dec_3to_8(en, in, Y);

	//IO Declarations
	input             en;
	input     [2:0]   in;
	output    [7:0]   Y;
	
	//assign the output
	assign Y = ( {en,in} == 4'b1000) ? 8'b0000_0001 :
				  ( {en,in} == 4'b1001) ? 8'b0000_0010 :
				  ( {en,in} == 4'b1010) ? 8'b0000_0100 :
				  ( {en,in} == 4'b1011) ? 8'b0000_1000 :
				  ( {en,in} == 4'b1100) ? 8'b0001_0000 :
				  ( {en,in} == 4'b1101) ? 8'b0010_0000 :
				  ( {en,in} == 4'b1110) ? 8'b0100_0000 :
				  ( {en,in} == 4'b1111) ? 8'b1000_0000 :
									 8'b0000_0000;
endmodule
