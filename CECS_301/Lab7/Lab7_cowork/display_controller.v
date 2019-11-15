`timescale 1ns / 1ps
/*******************************************************************************
*    File Name:     Display_Controller.v
*    Project:       Lab Project 7: CPU Excecution unit
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     April. 19, 2017
*
*    Purpose:	     The Display Controller selects which anode should be
*                   turned due to the fact that only one can be on at a time.It
*				also controls the frequency of the display.
*         
*    Notes:		This module instantiates the pixel controller module,
*                   pixel controller module, ad_mux, and the hex_to7Segment
*				module
 ******************************************************************************/
module display_controller(clk, reset, seg, Anodes, a, b, c, d, e, f, g);

   // IO Declarations
	input               clk, reset;
	input     [31:0] 	seg;
     
	output    [7:0]     Anodes;
	output		 	a, b, c, d, e, f, g;

   // wires 
	wire			     w_clk_out;
	wire      [2:0]     w_seg_sel;
	wire	     [3:0]     hexadecimal;

     //***********************************
     //   Pixel Clock Instantiation
     //***********************************
	  
	pixel_clk pix_Clk(clk, reset, w_clk_out);

     //***********************************
     //   Pixel Controller Instantiation
     //***********************************
	
	pixel_controller pix_Cont(w_clk_out, reset, Anodes, w_seg_sel);

     //***********************************
     //   8-to-1 Mux Instantiation
     //***********************************
	ad_mux mux8to1(w_seg_sel, seg, hexadecimal);

     //**********************************************
     //   Hex to 7 Segment Display Mux Instantiation
     //**********************************************
	hex_to_7seg hex7seg(hexadecimal, a, b, c, d, e, f, g);
endmodule
