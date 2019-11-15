`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     mux8to1
*    Project:       Lab Project 6: Integer Data Path
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     April. 9, 2017
*
*    Purpose:
*    The purpose for this module to make a 8-to-1 MUX for multiplexing
*    adress/data information to the 7-segment module.
*
*    This is the last module that completes the display controller in
*    conjuction with the pixel_clk and pixel_controller modules.
*
*    Multiplexing is the generic term used to describe the operation of
*    sending one or more digital signal over a transmission line depending
*    on the selector.
*
*    In this case, we will be multiplexing the outputs and inputs of the R 
*    and S registers concatenated in a single segment D ({R,S}) into the 8-to-1
*    multiplexer. We will be accessing data nibbles into the 7-segment
*	display module.
*
*    The "highest nibble" of the segment (D[31:8]) will be sent to the 7-segment
*    display in conjuction with anode an7.
*
*    The next nibble of the segment (D[27:24]) will be sent to the 7-segment
*    displays in conjunction with anode an6.
*
*    D[23:20]) will be sent to the 7-segment display in conjuction with anode 
*    an5.
*
*    The lowest nibble of R register (D[19:16]) will be sent to
*    the 7-segment display in conjuction with anode an4.
*
*    The highest nibble of the S register (D[15:12]) will be sent to
*    the 7-segment display in conjuction with anode an3.
*
*    The next nibble of S register(D[11:8]) will be sent 
*    to the 7-segment display in conjuction with anode an2. 
*     
*	The nibble(D[11:8]) will be sent to the 7-segment display in
*    conjuction with anode an1 and the last nibble (D[3:0]) will be sent to an0. 
*
*    The output of the multiplexer should produce a 4 bit data that will be sent
*    to the seven segment display. 
*
*    Thus, the display controller must send one of eight hex-nibbles to the
*    hex_to_7seg module to assert/deassert the appropriate anode signals at the
*    same time.
*    
*    Notes:
*
 ****************************************************************************/
module ad_mux(sel, D, Y);

     // IO Declarations
	input      [2:0]  sel;
	input      [31:0] D;
	output reg [3:0]  Y;
	
// case statement block decides the output according to sel
	always @(sel)
		case (sel)
			3'b000	:	Y = D[3:0];
			3'b001	:	Y = D[7:4];
			3'b010	:	Y = D[11:8];
			3'b011	:	Y = D[15:12];
			3'b100	:	Y = D[19:16];
			3'b101	:	Y = D[23:20];
			3'b110	:	Y = D[27:24];
			3'b111	:	Y = D[31:28];
			default	:	Y = 4'bx;
		endcase

endmodule
