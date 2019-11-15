`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Tx_bit_time_counter.v                     //
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
module Tx_bit_time_counter(clk, rst, baud_count, sel, btu);

     input               clk, rst;
     input     [18:0]    baud_count;
     input     [1:0]     sel;      // concat 1-bit do_it & btu wires
     
     output              btu;
     
     reg       [18:0]    mux_out;
     reg       [18:0]    bit_time_count;
     
     // MUX Selector   
     always @(*)
          case(sel)
               2'b00     :    mux_out <= 19'b0;
               2'b01     :    mux_out <= 19'b0;
               2'b10     :    mux_out <= bit_time_count + 19'b1;
               2'b11     :    mux_out <= 19'b0;
               default   :    mux_out <= 19'b0;
          endcase
          
     // 19 bit Register
     always @(posedge clk, posedge rst)
          if(rst)
               bit_time_count <= 19'b0;
          else
               bit_time_count <= mux_out;

     // Comparator
     assign btu = (bit_time_count == baud_count) ? 1'b1 : 1'b0;
     
endmodule
