`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  PED.v                                     //
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
module PED(clk, rst, ped_in, ped_out);
     
     input     clk, rst;
     input     ped_in;
     
     output    ped_out;
     
     reg       q1, q2;
     
     always @(posedge clk, posedge rst)
          if(rst)
               {q1, q2} <= 2'b0;
          else 
               {q1,q2} <= {ped_in, q1};
               
     //***********************************
     //   Assign Statement
     //   Modeling combinational logic
     //***********************************      
     assign ped_out = ~q2 & q1;  
     
endmodule
