`timescale 1ns / 100ps
/************************************************************************
* File Name: pc.v
* Project: Lab Project 7 - CPU Execution Unit
* Designer: Jarod Bamber & Jose Pacheco
* Email:	jarod.bamber@gmail.com / pacheco216@gmail.com
* Rev. Date: Nov. 15, 2016 / Nov. 13, 2016
*
* Purpose: Loads or increments data based off of the load and inc
* inputs. If load and inc are both on, the module defaults to simply
* passing the data. Otherwise the register follows whatever input was
* enabled.
*  
* 
* Notes:
* 
************************************************************************/
module pc(clk, reset, load, inc, D, Q);
	
	input clk, reset, load, inc;
	input [15:0] D;
	
	output reg [15:0] Q;
	
	always@(posedge clk or posedge reset)
		if (reset == 1'b1)
			Q <= 16'b0;
		else
			case({load, inc})
				2'b01: Q <= Q + 16'b1;  //When inc is enabled
				2'b10: Q <= D;          //When load is enabled
				default: Q <= Q;        //Passes Q as default
			endcase
endmodule
