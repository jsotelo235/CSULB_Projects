`timescale 1ns / 100ps
/************************************************************************
* File Name: led_controller.v
* Project: Lab Project 5 - Register Files
* Designer: Jarod Bamber
* Email:	jarod.bamber@gmail.com
* Rev. Date: Oct. 18, 2016
*
* Purpose: A simple autonomous FSM that cycles through all 8 anodes.
* This leaves 1 anode ready to recieve information at any given
* time. At each present state, the corresponding anode is turned
* on (driven low) and the state (seg_sel) is output to a mux as
* the select input.
* 
* Notes:
* 
************************************************************************/
module led_controller(clk, reset, sel, an7, an6, an5, an4, an3, an2, an1, an0);
	input clk; 
	input reset;
	output reg an7, an6, an5, an4, an3, an2, an1, an0;
	output reg [2:0] sel;
	
	reg [2:0] present;
	reg [2:0] next;
	
   //Cycle through each anode
	always @(present)
	   case(present)
			3'b000: next = 3'b001;
		   3'b001: next = 3'b010;
		   3'b010: next = 3'b011;
		   3'b011: next = 3'b100;
         3'b100: next = 3'b101;
         3'b101: next = 3'b110;
         3'b110: next = 3'b111;
         3'b111: next = 3'b000;
		   default : next = 3'b000;
		endcase
	
   //reset or go to next state
   always @(posedge clk , posedge reset) 
	if(reset == 1'b1) 
		present <= 3'b000; 
	else 
		if(reset == 1'b0) begin
			present <= next; 
		end
		
	// turn all anodes off except the one selected and
   // prepares the seg_sel to be passed to ad_mux
	always @(present)
	   case(present)
		   3'b000: {an0, an1, an2, an3, an4, an5, an6, an7, //Anode 0
                                 sel[2], sel[1], sel[0]} <= 11'b01111111_000;
		   3'b001: {an0, an1, an2, an3, an4, an5, an6, an7, //Anode 1
                                 sel[2], sel[1], sel[0]} <= 11'b10111111_001;
		   3'b010: {an0, an1, an2, an3, an4, an5, an6, an7, //Anode 2
                                 sel[2], sel[1], sel[0]} <= 11'b11011111_010;
		   3'b011: {an0, an1, an2, an3, an4, an5, an6, an7, //Anode 3
                                 sel[2], sel[1], sel[0]} <= 11'b11101111_011;
         3'b100: {an0, an1, an2, an3, an4, an5, an6, an7, //Anode 4
                                 sel[2], sel[1], sel[0]} <= 11'b11110111_100;
         3'b101: {an0, an1, an2, an3, an4, an5, an6, an7, //Anode 5
                                 sel[2], sel[1], sel[0]} <= 11'b11111011_101;
         3'b110: {an0, an1, an2, an3, an4, an5, an6, an7, //Anode 6
                                 sel[2], sel[1], sel[0]} <= 11'b11111101_110;
         3'b111: {an0, an1, an2, an3, an4, an5, an6, an7, //Anode 7
                                 sel[2], sel[1], sel[0]} <= 11'b11111110_111;
		   default {an0, an1, an2, an3, an4, an5, an6, an7, //default
                                 sel[2], sel[1], sel[0]} <= 11'b11111111_000;
	   endcase

endmodule

