`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Tx_bit_counter.v                          //
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
module Tx_bit_counter(clk, rst, sel, done);

     input               clk, rst;
     input     [1:0]     sel;
     
     output              done;
     
     reg       [3:0]     mux_out;
     reg       [3:0]     bit_count;
     
     
     // MUX Select
     always @(*)
          case(sel)
               2'b00 : mux_out <= 4'b0;
               2'b01 : mux_out <= 4'b0;
               2'b10 : mux_out <= bit_count;
               2'b11 : mux_out <= bit_count + 4'b1;
          endcase

     // 4-bit Register
     always @(posedge clk, posedge rst)
          if(rst)
               bit_count <= 4'b0;
          else
               bit_count <= mux_out;
          
     assign done = (bit_count == 11) ? 1'b1 : 1'b0;
     
endmodule
