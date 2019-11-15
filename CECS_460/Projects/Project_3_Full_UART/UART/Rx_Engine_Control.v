`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 3>                               //
// File name:  Rx_Engine_Control.v                       //
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
module Rx_Engine_Control(clk, rst, rx, k, eight, p_en,
                         start, btu, done);

     input               clk, rst;
     input               rx;
     input     [18:0]    k;
     input               eight;
     input               p_en;
     
     output              start;
     output              btu;
     output              done;
          
      wire               w_do_it;
      
     //***********************************
     //   Rx FSM
     //***********************************     
     Rx_FSM
          rx_fsm(
               .clk(clk), 
               .rst(rst), 
               .rx(rx), 
               .btu(btu), 
               .done(done), 
               .start(start), 
               .do_it(w_do_it)
          );
          
     //***********************************
     //   Rx Bit Time Counter
     //***********************************
      Rx_bit_time_counter
          rx_btc(
               .clk(clk), 
               .rst(rst), 
               .start(start),
               .k(k), 
               .sel({w_do_it, btu}), 
               .btu(btu)
          );
       
     //***********************************
     //   Rx Bit Counter
     //***********************************
     Rx_bit_counter
          rx_bc(
               .clk(clk), 
               .rst(rst), 
               .sel({w_do_it, btu}), 
               .eight(eight),
               .p_en(p_en),
               .done(done)
          );
endmodule
