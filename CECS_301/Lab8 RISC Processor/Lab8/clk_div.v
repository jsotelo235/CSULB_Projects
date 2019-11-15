`timescale 1ns / 100ps
/************************************************************************
* File Name: clk_div.v
* Project: Lab Project 5 - Register Files
* Designer: Jarod Bamber
* Email:	jarod.bamber@gmail.com
* Rev. Date: Oct. 18, 2016
*
* Purpose: A clock divider that takes a 500MHz clock abd divides it so  
* that the output is only 500Hz. This brings the clock to the target
* speed.
* 
* Notes:
* 
************************************************************************/
module clk_div(clk, reset, clk_500);
	input clk, reset;
	output clk_500;
	reg clk_500;
	integer i;
   
   //Divides the clk to output only when specified below in the if statment
	always @(posedge clk or posedge reset) begin
		if (reset == 1'b1) begin
			i = 0;
			clk_500 = 0;
		end
      //got a clk, so increment the counter and
      //test to see if it is at the target period
		else begin
			i = i+1;
			//using 200000 since clk speed is 100MHz.
         //100MHz/200000 = 500Hz which is the target speed.
			if (i >= 200000) begin
				clk_500 = ~clk_500;
				i = 0;
			end
		end
	end
endmodule
