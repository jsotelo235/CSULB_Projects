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
module Tx_Engine_Top(clk, rst, baud, eight, p_en, ohel, led, tx);

     input               clk, rst;
     input     [3:0]     baud;
     input               eight, p_en, ohel;
     
     output    [15:0]    led;
     output              tx;
     
     reg       [15:0]    led;
     
     wire                w_rst_s;
     wire                w_trx_ready;
     wire                w_ped_out;
     wire                w_sr_out;
     wire                w_int_ack_out;
     wire                w_write_strobe;
     wire                w_port_id;
     wire      [15:0]    w_out_port;
     

     //***********************************
     //   AISO
     //***********************************
     Aiso
          inst_1(
               .clk(clk), 
               .rst(rst), 
               .rst_s(w_rst_s)
          );
          
          
          
     //***********************************
     // Tx Engine
     //***********************************
     Tx_Engine
          inst_2(
               .clk(clk),
               .rst(w_rst_s),
               .load((w_port_id == 0) & w_write_strobe),   
               .data_in(w_out_port[7:0]), 
               .eight(eight),  
               .p_en(p_en),  
               .ohel(ohel),   
               .baud(baud),
               .txrdy(w_trx_ready),  
               .tx(tx)
          );

     //***********************************
     //   PED
     //***********************************     
     PED
          inst_3(
               .clk(clk), 
               .rst(w_rst_s), 
               .ped_in(w_trx_ready), 
               .ped_out(w_ped_out)
          );

     //***********************************
     //   SR Flop
     //***********************************
     SR_Flop
          inst_4(
               .clk(clk), 
               .rst(w_rst_s), 
               .S(w_ped_out), 
               .R(w_int_ack_out), 
               .Q(w_sr_out)
          );
    
     //***********************************
     //   Tramel Blaze
     //***********************************    
     tramelblaze_top
          inst_5(
               .CLK(clk), 
               .RESET(w_rst_s), 
               .IN_PORT(), 
               .INTERRUPT(w_sr_out), 
               .OUT_PORT(w_out_port), 
               .PORT_ID(w_port_id), 
               .READ_STROBE(), 
               .WRITE_STROBE(w_write_strobe), 
               .INTERRUPT_ACK(w_int_ack_out)
          );
   
    
     //***********************************
     //   Walking LEDs
     //***********************************   
     always @(posedge clk, posedge rst)
          if(rst)
               led <= 16'h0000;
          else if((w_port_id == 1) & w_write_strobe)
               led <= w_out_port;
endmodule
