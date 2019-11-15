`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:03:46 03/11/2017 
// Design Name: 
// Module Name:    display_controller 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module display_controller(clk_in, reset, clk_out, sel, d7, d6, d5, d4, d3, d2, d1, d0,
                          an7, an6, an5, an4, an3, an2, an1, an0, y);
                          
     input               clk_in, reset;
     input               d7, d6, d5, d4, d3, d2, d1, d0;
     input     [2:0]     sel;
     
     output              an7, an6, an5, an4, an3, an2, an1, an0;
     output    [3:0]     y;
     output              clk_out;
     

     wire                w0;
     wire                w1;
     wire      [2:0]     w2;
     
     
     pixel_clk
               clk_divider(.clk_in(clk_in), .reset(reset), .clk_out(clk_out));
     
     pixel_controller
                     px_controller(.clk(w0), .reset(w1), .an7(an7), .an6(an6),
                                   .an5(an5), .an4(an4), .an3(an3), .an2(an2),
                                   .an1(an1), .an0(an0));
     ad_mux         
                    mux(.d7(d7), .d6(d6), .d5(d5), .d4(d4), .d3(d3), .d2(d2), .d1(d1), .d0(d0),
                          .sel(w2), .y(y));
endmodule
