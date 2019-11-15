`timescale 1ns / 1ps
/***********************************************************************************************
*    File Name:          IR (Instructions Register)
*    Project:            Lab Project 7: CPU Execution Unit
*    Used by Designers:  Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:              jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Accesed On:         April 22, 2017
*
*    Purpose:
*    The purpose for this module is create a 16 bit register behaviorally. We will use
*    this register to create the ir (Instructions Register) that holds the instructions
*    that are currently being executed or decoded. The IR will be used to stored an instruction 
*    in a register that its fetched from memory. 
 ***********************************************************************************************/
module Instruction_register(clk, reset, ld, Din, Dout);

     input                    clk,reset,ld;
     input          [15:0]    Din;
     
     output reg     [15:0]    Dout;

     always @ (posedge clk or posedge reset)
          if (reset)
               Dout <= 16'b0;
          else begin
               if (ld==1'b1)
                    Dout <= Din;
               else
                    Dout <= Dout;
               end
endmodule
