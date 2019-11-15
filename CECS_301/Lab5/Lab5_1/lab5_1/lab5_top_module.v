`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:39:45 03/22/2017 
// Design Name: 
// Module Name:    lab5_top_module 
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
module lab5_top_module(clock_100mhz ,reset, we , sw, a, b, c, d, e, f, g, Anodes);

     input               clock_100mhz, reset, we;
     input     [15:0]    sw;
     
     output    [7:0]     Anodes;
     output              a, b, c, d, e, f, g;

     wire                w_clk_500, we_pulse;
     wire      [15:0]    R, S;

     //***********************************
     //   Clock Divider Instantiation
     //***********************************
     clk_div
               clock_div(.clk_in(clock_100mhz), .reset(reset), .clk_out(w_clk_500));
     
     //***********************************
     //   One Shot Debounce Instantiation
     //***********************************
     one_shot
               deb(.clk_in(w_clk_500), .reset(reset), .D_in(we), .D_out(we_pulse));
               
     //***********************************
     //   Register File Instantiation
     //***********************************
     reg_file 
               Reg(.clk(clock_100mhz),  .reset(reset),     .W_adr(sw[6:4]), .we(we_pulse),
                   .R_adr(sw[15:13]),   .S_adr(sw[12:10]), .W({12'hFFF,sw[3:0]}),
                   .R(R), .S(S));
                   
     //*************************************
     //   Display Controller Instantiation
     //*************************************
     display_controller
                         dc(.clk(clock_100mhz),   .reset(reset), .seg({R,S}),
                            .anodes(Anodes),      .a(a), .b(b),  .c(c),                
                            .d(d),                .e(e),         .f(f), 
                            .g(g));

endmodule
