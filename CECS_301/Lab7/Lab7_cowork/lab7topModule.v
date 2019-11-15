`timescale 1ns / 1ps
/*********************************************************************************
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
 ***********************************************************************************/
module lab7topModule(clk_100Mhz,reset,SW,btnleft,btndown,Anodes,a,b,c,d,e,f,g,N,Z,C);

     input             clk_100Mhz, reset, btnleft, btndown;
     input   [5:0]     SW;
  
     output  [7:0]     Anodes;
     output            a, b, c, d, e, f, g, N, Z, C;
  
     wire              clk_500, step_clk, mem_we;
     wire    [15:0]    Address,ALU_out,D_in;
  
     //*************************************
     //   Instantiation of clock divider
     //*************************************
     clk_div 
	        divider(clk_100Mhz, reset, clk_500);
             
     //********************************
     //   Debounce Instantiation
     //********************************
     debounce 
               deb2(clk_500,  reset, btnleft, mem_we ),     // debounced btn_Left
               debo1(clk_500, reset, btndown, step_clk );  // debounced btn_Down

     //*****************************************
     // CPU_EU (CPU Execution Unit)
     //*****************************************			
     //CPU_EU(  step_clk,     reset,    adr_sel, s_sel,     pc_ld,    pc_inc,	 
     CPU_EU cpu(step_clk,     reset,    SW[5],    SW[4],    SW[3],    SW[2],
               //reg_we,      ir_ld,    DS,       ALU_Out,  Address,  N,
                SW[1],        SW[0],    D_in,     ALU_out,  Address,  N,
              //Z,            C 
                Z,            C);
                
     //*****************************************
     // RAM 256x16
     //*****************************************
     ram1 
          ram(clk_100Mhz, mem_we, Address[7:0], ALU_out, D_in);

     //*****************************************
     // Display Controller
     //*****************************************
     display_controller 
          display(clk_100Mhz, reset, {Address,ALU_out}, Anodes, a, b, c, d, e, f, g);
endmodule
