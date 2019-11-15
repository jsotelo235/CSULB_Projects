`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 3>                               //
// File name:  Rx_Shift_Reg.v                            //
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
module Rx_Shift_Reg(clk, rst, sh, sdi, data_out);

     input               clk, rst;
     input               sh;
     input               sdi;      // Rx input
     
     output    [9:0]     data_out;
     
     reg       [9:0]     data_out;
     
     always @(posedge clk, posedge rst)
          if(rst)
               data_out <= 10'b0;
          else if(sh)
               data_out <= {sdi, data_out[9:1]};
          else
               data_out <= data_out;
               

endmodule
