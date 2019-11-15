`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Tx_Engine .v                              //
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
module Tx_Engine_Top(clk, rst, baud, eight, p_en, ohel, tx);

     input               clk, rst;
     input     [3:0]     baud;
     input               eight, p_en, ohel;
     
     output              tx;
     
     wire                w_trx_ready;
     wire                w_ped_out;
     wire                w_sr_out;
     wire                w_int_ack_out;
     wire                w_write_strobe;
     wire                w_port_id;
     wire      [15:0]    w_out_port;
     

endmodule
