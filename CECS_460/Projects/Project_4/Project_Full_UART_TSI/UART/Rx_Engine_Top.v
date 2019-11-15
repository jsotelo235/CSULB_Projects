`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Rx_Engine_Top.v                           //
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
module Rx_Engine_Top(clk, rst, rx, k);

     input               clk, rst;
     input               rx;
     input     [18:0]    k;
          
     //***********************************
     //   Rx Engine Control
     //***********************************
     Rx_Engine_Control
          rx_control(
               .clk(clk), 
               .rst(rst), 
               .rx(rx), 
               .k(k), 
               .eight(), 
               .p_en(),
               .do_it(), 
               .start(), 
               .btu(), 
               .done()
          );
          
     //***********************************
     //   Rx Engine Datapath
     //***********************************
     Rx_DataPath
          rx_datapath(
               .clk(clk), 
               .rst(rst), 
               .btu(), 
               .start(), 
               .rx(), 
               .eight(), 
               .p_en(), 
               .even(), 
               .reads(), 
               .done(), 
               .rx_rdy(), 
               .parity_err(), 
               .frame_err(), 
               .overflow(), 
               .data_to_TB()
          );
endmodule
