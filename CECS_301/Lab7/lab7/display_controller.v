`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:08:18 04/21/2017 
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
     pixel_controller
               pix_cont(.clk(w_clk_out), .reset(reset), .sel(w_sel), .anodes(anodes));
                    
     //***********************************
     //   8-to-1 Mux Instantiation
     //***********************************
     mux_8to1
               mux8to1(.sel(w_sel), .d(seg), .mux_out(w_mux_out));
                       
     //**********************************************
     //   Hex to 7 Segment Display Mux Instantiation
     //**********************************************
     hex_to_7seg
               hex7seg(.hexadecimal(w_mux_out), .a(a), .b(b), .c(c), .d(d), .e(e), .f(f), .g(g));


endmodule
