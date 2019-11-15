`timescale 1ns / 100ps
/************************************************************************
* File Name: led_clk.v
* Project: Lab Project 5 - Register Files
* Designer: Jarod Bamber
* Email:	jarod.bamber@gmail.com
* Rev. Date: Oct. 18, 2016
*
* Purpose: A clock divider that takes a 100MHz clock and divides it so
* that the output is only 1000Hz. This brings the clock to the target
* speed.
* 
* Notes:
* 
************************************************************************/
module led_clk(clk, reset, clk_1k);
	input clk, reset;
	output clk_1k;
	reg clk_1k;
	integer i;
   
   //Divides the clk to output only when specified below in the if statment
	always @(posedge clk or posedge reset) begin
		if (reset == 1'b1) begin
			i = 0;
			clk_1k = 0;
		end
      //got a clk, so increment the counter and
      //test to see if it is at the target period
		else begin
			i = i+1;
         //100MHz/100000 = 1000Hz which is the target speed.
			if (i >= 100000) begin
				clk_1k = ~clk_1k;
				i = 0;
			end
		end
	end
endmodule
