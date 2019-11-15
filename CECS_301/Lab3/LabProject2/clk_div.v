`timescale 1ns / 1ps
/****************************************************************************
*    File Name:   clock divider
*    Project:     Lab Project 3: Sequence Detectors(phase 2)
*    Designer:    Jose Sotelo
*    Email:       jsotelo235@gmail.com
*    Rev. Date:   Feb. 25, 2017
*
*    Purpose:
*    The following behavioral verilog module is for a clock divider. The
*    purpose for this module is take in a clock frequency as an input and 
*    divide the clock's frequency to a specific value according to your project's
*    specification. In our case, we will be dividing a 100MHz clock to a manageable
*    500Hz clock.
*
*    The clock tick and the reset inputs of the clock divider only
*    function on a posedge of the clock.
*
*    The clock divider module in this case checks for a wide one bit
*    binary value "1" and if found the clock is reset. Else the integer
*    value i checks if its greater than or equal to our calculated clock
*    frequency of "500000". If the condition is true, the clock and the
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
     
     input     clk_in, reset;
     output    clk_out;
     reg       clk_out;
     integer   i;
     
     always @(posedge clk_in or posedge reset) begin
          if(reset == 1'b1) begin
               i = 0;
               clk_out = 0;
          end 
          else begin
               i = i + 1;
               if(i > 104166) begin
                    clk_out = ~clk_out;
                    i = 0;
               end
          end
       end
endmodule
