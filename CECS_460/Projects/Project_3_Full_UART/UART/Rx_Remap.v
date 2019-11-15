`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 3>                               //
// File name:  Rx_Remap.v                                //
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
module Rx_Remap(sel, data_in, remap);

     input     [1:0]     sel;           // eight and p_en
     input     [9:0]     data_in;       // shift reg data
     
     output    [9:0]     remap;         // remap combo
     
     reg       [9:0]     remap;
     
     always @(*)
          case(sel)
               2'b00     :    remap <= {2'b00, data_in[9:2]};
               2'b01     :    remap <= {1'b0,  data_in[9:1]};
               2'b10     :    remap <= {1'b0,  data_in[9:1]};
               2'b11     :    remap <= data_in;
               default   :    remap <= {2'b00, data_in[9:2]};
          endcase
          
endmodule
