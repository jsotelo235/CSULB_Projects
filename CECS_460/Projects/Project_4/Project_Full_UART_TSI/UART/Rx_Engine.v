`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 3>                               //
// File name:  Rx_Engine.v                               //
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
module Rx_Engine(clk, rst, rx, k, eight, p_en, ohel, read,
                 rx_rdy, parity_err, frame_err, overflow, data_to_TB);

     input               clk, rst;
     input               rx;
     input     [18:0]    k;
     input               eight, p_en, ohel;
     input               read;
     
     output              rx_rdy;
     output              parity_err;
     output              frame_err;
     output              overflow;
     output    [7:0]     data_to_TB;
     
     wire                w_start;
     wire                w_btu;
     wire                w_done;
     
     //***********************************
     //   Rx Engine Control
     //***********************************
     Rx_Engine_Control
          control_rx(
               .clk(clk), 
               .rst(rst), 
               .rx(rx), 
               .k(k), 
               .eight(eight), 
               .p_en(p_en), 
               .start(w_start), 
               .btu(w_btu), 
               .done(w_done)
          );
          
     //***********************************
     //   Rx Engine Datapath
     //***********************************
     Rx_DataPath
          datapath_rx(
               .clk(clk), 
               .rst(rst), 
               .btu(w_btu), 
               .start(w_start), 
               .rx(rx), 
               .eight(eight), 
               .p_en(p_en), 
               .even(~ohel), 
               .read(read), 
               .done(w_done),
               .rx_rdy(rx_rdy),                
               .parity_err(parity_err), 
               .frame_err(frame_err), 
               .overflow(overflow), 
               .data_to_TB(data_to_TB)
          );
endmodule
