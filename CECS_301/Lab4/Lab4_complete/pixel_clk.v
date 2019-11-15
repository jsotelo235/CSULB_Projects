`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     Pixel_Clk
*    Project:       Lab Project 4: Memory & Display Controllers
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     March. 12, 2017
*
*    Purpose:
*    The purpose of this module is to divide the board's 100MHz clock frequency
*    to a manageable 480Hz clock.
*    
*    The reason we need a 480Hz frequency is because this module plays an
*    important role in the designing a display controller. To concept lies
*    in the display resolution and the frequency of the entire display. To
*    be abel to produce a fresh rate, we need to calculate the minimum 
*    "pixel clock" frequency and period. To do this we need to analyze
*    what kind of display resolution we are working with. In this case,
*    we will be using the Nexys4 board's two seven segment displays.
*    
*    To calculate the resolution for the two seven segment displays, we
*    need to find the # columns X # rows, coupled by the frequency of
*    the entire display.
*
*    In our case, the two seven segment displays contain the following:
*    8 columns X 1 row, having 8 pixels on the display. For this project,
*    the required refresh rate for the display is to be at 60Hz.
*    
*    The calculations are:
*    60Hz * 8 pixels = 480 pixels/sec
*    1/(480)         = 2.083 ms
*    Thus, the required frequency need for the display is 480Hz and
*    the period is 2.083 ms.
*    Entire display is refreshed once every = 2.083 X 8 = 16.66 ms
*
*    To produce this frequency or refresh rate, we will use the same
*    concept used in the clock divider.
*
*    Notes:
*    Clock divider is used to slow down the fpga board's clock frequency
*    to a manageable frequency were the designer can see changes to their
*    application.
*
*    The value of the counter that counts the incoming clock ticks 
*    is equal to [Incoming Freq / Outgoing Freq) / 2]
 ****************************************************************************/
module pixel_clk(clk_in, reset, clk_out);
     
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
               if(i > 104167) begin
                    clk_out = ~clk_out;
                    i = 0;
               end
          end
       end
endmodule
