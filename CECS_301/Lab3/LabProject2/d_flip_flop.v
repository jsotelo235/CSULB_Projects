`timescale 1ns / 1ps
/****************************************************************************
 *File Name:   One bit D-Flip Flop 
 *Project:     Lab Project 2: Sequence Detectors(phase 1)
 *Designer:    Jose Sotelo
 *Email:       jsotelo235@gmail.com
 *Rev. Date:   Feb. 20, 2017
 *
 *Purpose:
 *
 *Notes:
 ****************************************************************************/
module d_flip_flop(Clk, Reset, D, Q);
     
     input     D, Clk, Reset;
     output    Q;
     reg       Q;
     
     always @(posedge Clk or posedge Reset)
     begin
          if(Reset)
               Q <= 1'b0;
          else
               Q <= D;
     end
endmodule
