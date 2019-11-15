`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:20:09 04/28/2017 
// Design Name: 
// Module Name:    lab7_top_module 
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
module lab7_top_module(clk100MHz, reset, SW, mem_w_en, step_clk, Anodes, a, b, c, d, e, f, g, N, C, Z);

                                           //left btn  //down btn
     input               clk100MHz, reset, mem_w_en,   step_clk;
     input     [5:0]     SW;
     
     output              a, b, c, d, e, f, g, N, C, Z;
     output    [7:0]     Anodes;
     
     wire                w_clk_div_out, w_mem_w_en_out, w_step_clk_out;
     wire      [15:0]    w_D_in, w_Alu_out, w_Address_out;

     //********************************
     //   Clock 100MHz Divider
     //********************************
     clk_div
          clkDiv(.clk_in(clk100MHz), .reset(reset), .clk_out(w_clk_div_out));
     
     //********************************
     //   Debounce one shot
     //********************************
     one_shot
          debounce_1(.clk_in(w_clk_div_out), .reset(reset), .D_in(mem_w_en), .D_out(w_mem_w_en_out)),      // mem_w_en
          debounce_2(.clk_in(w_clk_div_out), .reset(reset), .D_in(step_clk), .D_out(w_step_clk_out));      // step clock
          
     //********************************
     //   CPU Execution Unit
     //********************************
     CPU_EU
          cpu_eu(.clk(w_step_clk_out),  .reset(reset),           .adr_sel(SW[5]),              .s_sel(SW[4]),
                 .pc_ld(SW[3]),         .pc_inc(SW[2]),          .reg_we(SW[1]),               .ir_ld(SW[0]),
                 .DS(w_D_in),           .Alu_Out(w_Alu_out),     .Address(w_Address_out),      .N(N),
                 .C(C),                 .Z(Z));
                 
     //********************************
     //   Ram 256x16
     //********************************
     ram
          Ram(.clk(clk100MHz), .we(w_mem_w_en_out), .addr(w_Address_out[7:0]), .din(w_Alu_out), .dout(w_D_in));
     
     //********************************
     //   Display Controller
     //********************************
     display_controller
          dp(.clk(clk100MHz), .reset(reset), .seg({w_Address_out, w_Alu_out}),  .anodes(Anodes), 
             .a(a),           .b(b),         .c(c),                             .d(d), 
             .e(e),           .f(f),         .g(g));
     
endmodule
