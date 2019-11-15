`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  SR_Flop.v                                 //
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
module SR_Flop(clk, rst, S, R, Q);

     input     clk, rst;
     input     S, R;
     
     output    Q;
     
     reg       Q;
     
     always @(posedge clk, posedge rst)
          if(rst)
               Q <= 1'b0;
          else if(S)
               Q <= 1'b1;
          else if(R)
               Q <= 1'b0;
          else
               Q <= Q;
endmodule
