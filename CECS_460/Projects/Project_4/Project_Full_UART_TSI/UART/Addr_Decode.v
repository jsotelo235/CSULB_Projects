`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 3>                               //
// File name:  Addr_Decode.v                             //
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
module Addr_Decode(port_id, write_strobe, read_strobe, writes, reads);

     input     [15:0]    port_id;
     input               write_strobe;
     input               read_strobe;
     
     output    [15:0]    writes;
     output    [15:0]    reads;
     
     reg       [15:0]    writes;
     reg       [15:0]    reads;
     
     always @(*)
     begin
          writes = 16'b0;
          reads  = 16'b0;
          
          writes[port_id] = write_strobe;
          reads[port_id]  = read_strobe;
     end
     
endmodule
