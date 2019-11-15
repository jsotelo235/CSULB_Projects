`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Final Project>                           //
// File name:  Top_Level.v                               //
//                                                       //
// Created by <Jose Sotelo> on <April 16, 2018>          // 
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
module Top_Level(clk, rst, baud, eight, p_en, ohel, rx, tx, leds);

     input               clk, rst;
     input     [3:0]     baud;
     input               eight;
     input               p_en;
     input               ohel;
     input               rx;
     
     output              tx;
     output    [15:0]    leds;
   
     wire                w_clk, w_rst;
     wire      [3:0]     w_baud;
     wire                w_eight;
     wire                w_p_en;
     wire                w_ohel;
     wire                w_rx;
     wire      [15:0]    w_leds;
     
     
     //***********************************
     //   Core Logic
     //***********************************
     Core_Logic
          uart_core(
               .clk(w_clk), 
               .rst(w_rst), 
               .baud(w_baud), 
               .eight(w_eight), 
               .p_en(w_p_en), 
               .ohel(w_ohel), 
               .rx(w_rx), 
               .tx(w_tx), 
               .leds(w_leds)
          );
          
     //***********************************
     //   TSI
     //***********************************
     TSI
          tsi_buf(
               .i_clk(clk), 
               .i_rst(rst), 
               .i_baud(baud), 
               .i_eight(eight), 
               .i_p_en(p_en), 
               .i_ohel(ohel), 
               .i_rx(rx), 
               .i_tx(w_tx), 
               .i_leds(w_leds),
               .o_clk(w_clk), 
               .o_rst(w_rst), 
               .o_baud(w_baud), 
               .o_eight(w_eight), 
               .o_p_en(w_p_en), 
               .o_ohel(w_ohel), 
               .o_rx(w_rx), 
               .o_tx(tx), 
               .o_leds(leds)
          );
         
endmodule
