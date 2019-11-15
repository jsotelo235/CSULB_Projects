`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:26:28 03/11/2017 
// Design Name: 
// Module Name:    lab4_top_module 
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
module lab4_top_module(clk_in, reset, D_in, addr_step, wr_pulse, anodes, a, b, c, d, e, f, g);

     input               clk_in, reset;
     input               addr_step, wr_pulse;
     input     [15:0]    D_in;                    //inputs to the RAM come from sixteen slides switches
     
     output    [7:0]     anodes;
     output              a, b, c, d, e, f, g;
     
     wire                w0;  //wire coming out from clock divider
     wire                w1;  //wire coming out from pixel clk
     wire                w2;  //wire coming out from one shot 1
     wire                w3;  //wire coming out from one shot 2
     wire      [2:0]     w4;  //wire coming out from pixel controller  
     wire      [7:0]     w5;  //wire coming out from 8 bit address sequence
     wire      [15:0]    w6;  //wire coming out from 16 bit ram
     wire      [3:0]     w7;  //wire coming out from ad_mux  
     
     //*********************************************************
     //   Clock Divider Instantiation
     //*********************************************************
     clk_div
               clk_divider(.clk_in(clk_in), .reset(reset), .clk_out(w0)); 
     
     //*********************************************************
     //   Pixel_Clk Instantiation
     //*********************************************************
     pixel_clk
               px_clk(.clk_in(clk_in), .reset(reset), .clk_out(w1));
               
     //********************************************************
     //   one_shot_debounce module Instantiation
     //********************************************************
     one_shot_debounce
                         debounce_1(.clk_in(w0), .reset(reset), .D_in(addr_step), .D_out(w2));
     one_shot_debounce   
                         debounce_2(.clk_in(w0), .reset(reset), .D_in(wr_pulse), .D_out(w3));

     //*********************************************************
     //   Pixel Controller module Instantiation
     //*********************************************************
     pixel_controller
                         px_controller(.clk(w1), .reset(reset), .sel(w4), 
                         .an7(anodes[7]), .an6(anodes[6]), .an5(anodes[5]),
                         .an4(anodes[4]), .an3(anodes[3]), .an2(anodes[2]),
                         .an1(anodes[1]), .an0(anodes[0]));
                                       
     //*********************************************************
     //   Addr_Seqr module Instantiation
     //*********************************************************
     addr_seqr
               add_sequence(.clk(w2), .reset(reset), .addr(w5));

     //*********************************************************
     //   Ram1 module Instantiation
     //*********************************************************
     ram1
              ram(.clk(clk_in), .we(w3), .addr(w5), .din(D_in), .dout(w6));

     //**********************************************************
     //   Ad_Mux module Instantiation
     //**********************************************************
     ad_mux
               mux(.d7(0), .d6(0), .d5(w5), .d4(w5),
                   .d3(w6), .d2(w6), .d1(w6), .d0(w6), 
                   .sel(w4), .y(w7));

     //**********************************************************
     //   Seven Segment Display
     //**********************************************************
     hex_to_7segment
                    display(.hex(w7), .a(a), .b(b), .c(c), .d(d), .e(e), .f(f), .g(g));
endmodule
