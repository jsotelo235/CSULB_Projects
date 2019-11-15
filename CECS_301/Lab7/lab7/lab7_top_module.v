`timescale 1ns / 1ps
/***********************************************************************************************
*    File Name:          Lab7 Top Module
*    Project:            Lab Project 7: CPU Execution Unit
*    Used by Designers:  Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:              jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Accesed On:         April 22, 2017
*
*    Purpose:
*    The purpose for this module is to instatiate the clock divider, debounce
*    one shot, cpu_eu, ram, and display controller modules.
*
*    We will use the instantiations above to verify the correctness of our
*    CPU_EU and Memory interface by stepping through the exact micro-operations
*    sequence specified by the instructor. The general process for each micro-
*    operation step is to first set up the appropriate control word using the
*    FPGA board switches, and then asserting the appropriate "step_clock" or
*    memory "write_enable" button.
* 
*    Our top module displays the 16-bit Address coming out of the CPU_EU on the
*    leftmost 4 digits of the display and the 16-bit D_out coming also out of
*    the CPU_EU on the rightmost 4 digits of the display.
*
*    The "Control Word" inputs for this project are presented below:
*
*    reset = btn up, mem w_en = btn left, step_clk = btn down
*
*    adr_sel = sw 5, s_sel = sw 4, pc_ld = sw 3, pc_inc = sw 2, reg_w_en = sw1, ir_ld = sw 0
*
*    Alu_Op = IR[15:12], W_Adr = IR[8:6], R_Adr = IR[5:3], S_Adr = IR[2:0]
 ****************************************************************************************************/
module lab7_top_module(clk_100mhz, reset, SW, step_clk, mem_w_en, N , C, Z, Anodes, a,b,c,d,e,f,g);
     
     input               clk_100mhz, reset, step_clk, mem_w_en;
     input     [5:0]     SW; 
     
     output              N, C, Z;
     output              a, b, c, d, e, f, g;
     output    [7:0]     Anodes;
     
     wire                w_clk_div_out, w_step_clk_out, w_mem_w_en_out ;
     wire      [15:0]    w_address, w_d_out, w_d_in;
     
     //*****************************************
     // Clock Divider
     //*****************************************
     clk_div
               clkDiv(.clk_in(clk_100mhz), .reset(reset), .clk_out(w_clk_div_out));
     
     //*****************************************
     // One Shot Debounce 
     //*****************************************
     one_shot
               debounce_1(.clk_in(w_clk_div_out), .reset(reset), .D_in(step_clk),    .D_out(w_step_clk_out)),
               debounce_2(.clk_in(w_clk_div_out), .reset(reset), .D_in(mem_w_en),    .D_out(w_mem_w_en_out));
     
     //*****************************************
     // CPU_EU (CPU Execution Unit)
     //*****************************************
      cpu_eu
               cpu(.clk(w_step_clk_out),     .reset(reset),      .adr_sel(SW[5]),         .s_sel(SW[4]),
                   .pc_ld(SW[3]),            .pc_inc(SW[2]),     .reg_w_en(SW[1]),        .ir_ld(SW[0]),
                   .DS(w_d_in),              .N(N),              .C(C),                   .Z(Z),          
                   .Adress(w_address),       .D_out(w_d_out));

     //*****************************************
     // RAM 256x16
     //*****************************************
     Ram1
          r1(.clk(clk_100mhz), .we(w_mem_w_en_out), .addr(w_address[7:0]), .din(w_d_out), .dout(w_d_in));
     
     
     //*****************************************
     // Display Controller
     //*****************************************
     display_controller
                         dp(.clk(clk_100mhz),     .reset(reset),      .seg({w_address, w_d_out}),   
                            .anodes(Anodes),      .a(a),              .b(b),      
                            .c(c),                .d(d),              .e(e),    
                            .f(f),                .g(g));
endmodule
