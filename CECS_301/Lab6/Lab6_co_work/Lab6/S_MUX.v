`timescale 1ns / 1ps
/*************************************************************************************
*    File Name:     S_MUX.v
*    Project:       Lab Project 6: Integer Data Path
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:         jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Rev. Date:     April 6, 2017
*
*    Purpose:
*    The purpose for this module to create a 2-to-1 MUX that will be used as an
*    instantiation in the integer datapath module.
*
*    The 2-to-1 MUX is written using a case statement. Its functionality is to select
*    one signal and transmit it to a single output channel. It allows binary information
*    from the inputs (S_in and DS) to be output onto a single data line (S_out) depending
*    ont the data selector (S_Sel). 
*    
*    If the data selector (S_Sel) is logic low "0" the output selected will be 16 bits S_in.
*    If the data selector (S_Sel) is logic high "1" the output selected will be 16 bits DS.
*    By default, if data selector (S_Sel) is not choosen the output will be a constant 16'bx.
*    Notes:
 ******************************************************************************************/
module S_MUX( S_Sel, S_in, DS, S_out );

	input             S_Sel;
	input      [15:0] S_in, DS;
	output reg [15:0] S_out;
	
	always @( S_Sel )
		case ( S_Sel )
			1'b0    : S_out = S_in;
			1'b1    : S_out = DS;
			default : S_out = 16'bx;
		endcase
endmodule
