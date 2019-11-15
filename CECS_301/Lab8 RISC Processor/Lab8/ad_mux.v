`timescale 1ns / 100ps
/************************************************************************
* File Name: ad_mux.v
* Project: Lab Project 5 - Register Files
* Designer: Jarod Bamber
* Email:	jarod.bamber@gmail.com
* Rev. Date: Oct. 18, 2016
*
* Purpose: Takes the present state from the led_controller and assigns
* the correct set of information. Holds all the data that needs to be
* displayed and waits until the correct anode is ready to receive the
* data.
* 
* Notes:
* 
************************************************************************/
module ad_mux(ad_out, seg_sel, seg7, seg6,
              seg5, seg4, seg3, seg2, seg1, seg0);
              
   //Inputs          
	input [2:0] seg_sel;
	input [3:0] seg0, seg1, seg2, seg3, seg4, seg5, seg6, seg7;
   
   //Outputs
	output reg [3:0] ad_out;
   
   //Assign each anode the correct set of information
	always @(seg0 or seg1 or seg2 or seg3 or
            seg4 or seg5 or seg6 or seg7 or
            seg_sel)
	begin
		case(seg_sel)
			3'b000  : ad_out = seg0;
			3'b001  : ad_out = seg1;
			3'b010  : ad_out = seg2;
			3'b011  : ad_out = seg3;
         3'b100  : ad_out = seg4;
         3'b101  : ad_out = seg5;
         3'b110  : ad_out = seg6;
         3'b111  : ad_out = seg7;
			default : ad_out = 4'b0000;
		endcase
	end
endmodule