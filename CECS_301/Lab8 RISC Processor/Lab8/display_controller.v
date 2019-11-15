`timescale 1ns / 100ps
/************************************************************************
* File Name: display_controller.v
* Project: Lab Project 5 - Register Files
* Designer: Jarod Bamber
* Email:	jarod.bamber@gmail.com
* Rev. Date: Nov. 15, 2016
*
* Purpose: A display controller with all the modules needed to
* assign each anode a piece of info at a time. Works for a
* board with 8 anodes. Takes in 4 bit pieces of information
* in each select, chooses an anode to assign it to, then
* converts the bits to hex and displays on the LED display.
* 
* Notes:
* 
************************************************************************/
module display_controller(clk, reset, a, b, c, d, e, f, g,
								  an0, an1, an2, an3, an4, an5, an6, an7, 
								  sel7, sel6, sel5, sel4, sel3, sel2, sel1, sel0);
									
	input clk, reset;
	input [3:0] sel7, sel6, sel5, sel4, sel3, sel2, sel1, sel0;
	
	
	output an0, an1, an2, an3, an4, an5, an6, an7;
	output a, b, c, d, e, f, g;
	
	wire           clk_out;
	wire	 [3:0]   hex;
	wire   [2:0]   seg_sel;



   //Divides the clock to the desired speed of 1000Hz
	led_clk    LED_CLK      (clk, reset, clk_out);
	
   //A FSM that turns on 1 LED at a time so 
   //that the LED is ready to receive data
	led_controller  LED_CNT (clk_out, reset, seg_sel, an7, an6, an5, an4, an3, an2, an1, an0);
	
   //Assigns the correct LED to its specified data
	ad_mux      AD_MUX      (hex, seg_sel, sel7, sel6, sel5, sel4, sel3, sel2, sel1, sel0);
	
   //Changes the 4 bits of data to its hex representation
   //on the 7-segments
	hex_to_7_seg 	 SEV_SEG (hex, a, b, c, d, e, f, g);
	


endmodule
