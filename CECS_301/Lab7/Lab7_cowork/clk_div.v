`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     clk_div.v
*    Project:       Lab Project 7: CPU Excecution unit
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:         jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Rev. Date:     April 22, 2017
*
*    Purpose:
*    The following behavioral verilog module is for a clock divider. The
*    purpose for this module is take in a clock frequency as an input and 
*    divide the clock's frequency to a specific value according to your project's
*    specification. In our case, we will be dividing a 100MHz clock to a manageable
*    500Hz clock.
*
*    The output of the clock divider will drive the inputs of the one shot debounce
*    modules.
*
*    The clock tick and the reset inputs of the clock divider only
*    function on a posedge of the clock.
*
*    The clock divider module in this case checks for a wide one bit
*    binary value "1" and if found the clock is reset. Else the integer
*    value i checks if its greater than or equal to our calculated clock
*    frequency of "100000". If the condition is true, the clock and the
*    integer value are reset and the cycle repeats.  
*
*    Notes:
*    Clock divider is used to slow down the fpga board's clock frequency
*    to a manageable frequency were the designer can see changes to their
*    application.
*
*    The value of the counter that counts the incoming clock ticks 
*    is equal to [Incoming Freq / Outgoing Freq) / 2]
 ****************************************************************************/
module clk_div(clk_in, reset, clk_out);

     // IO Declarations
	input          clk_in, reset;
	output reg     clk_out;
	
	integer        i;
	
	//**********************************************************************
	// The following verilog code will "divide" an incoming clock
	// by the 32-bit decimal value specified in the "if condition"
	//
	// The value of the counter that counts the incoming clock ticks
	// is equal to [ (Incoming Freq / Outgoing Freq) / 2 ]
	//**********************************************************************
	always @(posedge clk_in or posedge reset)
		if (reset) begin
			i = 0;
			clk_out = 0;
		end 
          else begin
               // when clock is high, increment counter
			i = i + 1;
			// test to see if half a period has elapsed
			if (i >= 100000) begin
			// when half period reached, negate clock and reset counter i
				clk_out = ~clk_out;
				i = 0;
			end
		end // if else		
endmodule
