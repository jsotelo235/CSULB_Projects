`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Tx_shift_register .v                      //
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
module Tx_shift_register(clk, rst, data_in, load, shift, sdo);

     input               clk, rst;
     input     [10:0]    data_in;
     input               load;
     input               shift;
     
     output              sdo;
     
     reg       [10:0]    shift_reg;
     
     always @(posedge clk, posedge rst)
          if(rst)
               shift_reg <= 11'b11111_111111;
          else if(load)
               shift_reg <= data_in;
          else if(shift)
               shift_reg <= {1'b1, shift_reg[10:1]};
          else
               shift_reg <= shift_reg;
               
     assign sdo = shift_reg[0];

endmodule
