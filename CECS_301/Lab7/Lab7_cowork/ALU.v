`timescale 1ns / 1ps
/*******************************************************************************
*    Written by:         R. W. Allison
*    Date:               March 21, 2017
*    File:               ALU.v
*
*    File Name:          ALU.v
*    Project:            Lab Project 7: CPU Excecution unit
*    Used by Designers:  Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:              jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Accesed On:         April 19, 2017       
*
*    This 16-bit ALU will will be used in the 301 "Integer Datapath" project
*    to perform various manipulations on 16-bit integers.
*    There are 4 "Op" inputs to perform up to 16 basic operations.
*    Currently, there are only 13 of the 16 operations used.
*
*    The alu status flags represent the Y output being negative (N), 
*    zero (Z), and a carry out (C).
 *******************************************************************************/
module ALU( R, S, ALU_Op, Y, N, Z, C );

	input          [15:0]    R, S;
	input          [3:0]     ALU_Op;
     
	output reg     [15:0]    Y;
	output reg               N, Z, C;
	
	always @( R, S, ALU_Op ) begin
	
		case ( ALU_Op )
			4'b0000: {C,Y} = {1'b0,S};		// pass S
			4'b0001: {C,Y} = {1'b0,R};		// pass R
			4'b0010: {C,Y} = S + 1; 			// increment S
			4'b0011: {C,Y} = S - 16'b1;       	// decrement S
			4'b0100: {C,Y} = R + S; 			// add
			4'b0101: {C,Y} = R - S; 			// subtract
			4'b0110: begin					// right shift S (logic)
							C = S[0];
							Y = S >> 1;
						end
			4'b0111: begin					// left shift S (logic)
							C = S[15];
							Y = S << 1;
						end
			4'b1000: {C,Y} = {1'b0,R & S};	// logic and
			4'b1001: {C,Y} = {1'b0,R | S};	// logic or
			4'b1010: {C,Y} = {1'b0,R ^ S};	// logic xor
			4'b1011: {C,Y} = {1'b0,~S};	     // logic not S (1's comp)
			4'b1100: {C,Y} =  16'b0 - S;	     // negate S    (2's comp)
			default: {C,Y} = {1'b0,S};	     // pass S for default
		endcase
		
		// handle last two status flags
		N = Y[15];
		if ( Y == 16'b0 )
			Z = 1'b1;
		else
			Z = 1'b0;
			
	end // end always
endmodule
