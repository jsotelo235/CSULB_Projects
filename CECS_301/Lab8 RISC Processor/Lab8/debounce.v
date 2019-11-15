`timescale 1ns / 100ps
/************************************************************************
* File Name: debounce.v
* Project: Lab Project 5 - Register Files
* Designer: Jarod Bamber
* Email:	jarod.bamber@gmail.com
* Rev. Date: Oct. 18, 2016
*
* Purpose: Creates a one clock tick pulse after sampling 10 previous
* inputs. This is mandatory when working with buttons because the
* signal "bounces" when initially pressed. This module waits for
* the 9 previous ticks to stabalize then outputs a 1 for one clock
* tick. The way this works is by saving the current input to q[0]
* and the previous 9 to q[9:1], then waiting for everything to be
* a 1 except q[9] the oldest sample, meaning that the signal was
* stable for the last 9 ticks. However the signal goes back to a 0
* once q[9] is also a 1, which is what makes it a oneshot pulse.
* 
* Notes:
* 
************************************************************************/
module debounce(clk, reset, step, oneshot);
	input clk, reset, step;
	output oneshot;
	wire oneshot;
	
	reg q9, q8, q7, q6, q5, q4, q3, q2, q1, q0;
	always @ (posedge clk or posedge reset)
		if (reset == 1'b1)
         //assign all 0's
			{q9, q8, q7, q6, q5, q4, q3, q2, q1, q0} <= 10'b0;
		else begin
			//shift in each clock tick while it is bouncing
			q9 <= q8; q8 <= q7; q7 <= q6; q6 <= q5; q5 <= q4;
			q4 <= q3; q3 <= q2; q2 <= q1; q1 <= q0; q0 <= step;
		end
		//create a one shot pulse only when the sequence is 0111111111
      //then stops at when another 1 is shifted in
		assign oneshot = !q9 & q8 & q7 & q6 & q5 & q4 & q3 & q2 & q1 & q8 & q0;
endmodule
