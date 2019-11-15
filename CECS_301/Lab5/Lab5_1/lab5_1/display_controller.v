`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     Display Controller
*    Project:       Lab Project 5: Register Files
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     March. 22, 2017
*
*    Purpose:
*    The purpose for this module is to instantiate the pixel clock, pixel
*    controller, ad_mux, and the seven segment display to create the display
*    controller.
*    
*    The display controller will have as inputs a clock, reset, and a 32 
*    bit seg input.
*
*    The outputs will be 7 bit anodes which select which "pixel" to turn on and
*    the "pixels" a,b,c,d,e,f,g that will light up upon the selection of the
*    anodes.
*
*    Each instantiated module will have an input and output according to the
*    specifications of the display controller. The details of how each module
*    is instatiated is presented below. 
 ****************************************************************************/
module display_controller(clk, reset, seg, anodes, a, b, c, d, e, f, g);

     input               clk, reset;
     
     input     [31:0]     seg;   
     
     output    [7:0]     anodes;
     output              a, b, c, d, e, f, g;
     
     wire                w_clk_out;
     wire      [2:0]     w_sel;
     wire      [3:0]     w_mux_out;
     
     //***********************************
     //   Pixel Clock Instantiation
     //***********************************
     pixel_clk
               pix_clk(.clk_in(clk), .reset(reset), .clk_out(w_clk_out));
               
     //***********************************
     //   Pixel Controller Instantiation
     //*********************************** 
     pixel_cont
               pix_cont(.clk(w_clk_out), .reset(reset), .sel(w_sel), .anodes(anodes));
                    
     //***********************************
     //   8-to-1 Mux Instantiation
     //***********************************
     mux_8_to_1
               mux8to1(.sel(w_sel), .d(seg), .mux_out(w_mux_out));
                       
     //**********************************************
     //   Hex to 7 Segment Display Mux Instantiation
     //**********************************************
     hex_to_7seg
                    hex7seg(.hexadecimal(w_mux_out), .a(a), .b(b), .c(c), .d(d), .e(e), .f(f), .g(g));
endmodule
