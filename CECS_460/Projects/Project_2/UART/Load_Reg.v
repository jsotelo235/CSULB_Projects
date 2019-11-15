`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Load_Reg.v                                //
//                                                       //
// Created by <Jose Sotelo> on <>                        // 
//                                                       //
// In submitting this file for class work at CSULB       //
// I am confirming that this is my work and the work     //
// of no one else.                                       // 
//                                                       //
// In the event other code source are utilized I will    //
// document which portion of code and who is the author  //
//                                                       //
// In submitting this code I acknowledge that plagiarism //
// in student project work is subject to dismissal from  //
// the class                                             //
//*******************************************************//
module Load_Reg(clk, rst, ld, D, Q);

     input               clk, rst, ld;
     input     [7:0]     D;
     
     output    [7:0]     Q;
     
     reg       [7:0]     Q;
     
     always @(posedge clk, posedge rst)
          if(rst)
          begin
               Q <= 8'b0;
          end
          else if(ld)
          begin
               Q <= D;
          end
          else
          begin
               Q <= Q;
          end
endmodule
