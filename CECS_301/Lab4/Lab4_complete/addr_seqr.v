`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     Addr_Seqr Module
*    Project:       Lab Project 4: Memory & Display Controllers
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     March. 12, 2017
*
*    Purpose:
*    The purpose for this module is to create a 8 bit up counter.
*    Counters are sequential circuits that are used for counting
*    pulses. Counters are made by a group of flip flops with a clocked
*    signal. 
*
*    In this case, the 8 bit up counter counts the bits each posedge clk in the address
*    register adding a 1 each time if no reset is present. If there's a reset during a
*    posedge clk or reset, the counter is reset to the binary value of 0.
*    
*    Notes:
*
 ****************************************************************************/
module addr_seqr(clk, reset, addr);

     // Input/Output Declarations
	input 			     clk, reset;
	output reg     [7:0]     addr;
	
     // Counter logic
	always @(posedge clk or posedge reset)
          if (reset) begin
			addr <= 8'b00;           // reset To value of 0
		end else begin
			addr <= addr + 8'b01;    // addition by 1 to count-up
		end
endmodule
