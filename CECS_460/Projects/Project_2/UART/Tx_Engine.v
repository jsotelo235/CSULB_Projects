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
module Tx_Engine(clk,    rst,   load,   data_in, 
                 eight,  p_en,  ohel,   baud,
                 txrdy,  tx
               );
     input               clk, rst;
     input               load;
     input     [7:0]     data_in;
     input               eight, p_en, ohel;
     input     [3:0]     baud;
     
     output              txrdy;
     output              tx;
     
     wire                rst;
     wire                w_done;
     wire                w_do_it;
     wire                w_btu;
     wire      [7:0]     w_load_data;
     wire                w_bit10, w_bit9;
     
     reg                 w_load_d1;
     
     //***********************************
     //   SR Flip Flop TxRdy
     //***********************************
     SR_Flop_Txrdy
          inst_1(
               .clk(clk), 
               .rst(rst), 
               .S(w_done), 
               .R(load), 
               .Q(txrdy)
          );
          
     //***********************************
     //   SR Flip Flop DoIt
     //***********************************
     SR_Flop
          inst_2(
               .clk(clk), 
               .rst(rst), 
               .S(w_load_d1), 
               .R(w_done), 
               .Q(w_do_it)
          );
                
     //***********************************
     // 8-bit Loadable Register
     //***********************************
     Load_Reg
          inst_3(
               .clk(clk), 
               .rst(rst), 
               .ld(load), 
               .D(data_in), 
               .Q(w_load_data)
          );
          
     //***********************************
     // Parity Decoder
     //***********************************
     Parity_Gen_Dec
          inst_4(
               .load_data(w_load_data), 
               .eight(eight), 
               .p_en(p_en), 
               .ohel(ohel), 
               .bit10(w_bit10),
               .bit9(w_bit9)
          );
     
     //***********************************
     //   Register
     //***********************************
     always @(posedge clk, posedge rst)
          if(rst)
               w_load_d1 <= 1'b0;
          else
               w_load_d1 <= load;
               
               
               
               
               
               
               
               
               
               
               
     //***********************************
     //   Shift Register
     //***********************************
     Shift_Register
          inst_5(
               .clk(clk), 
               .rst(rst), 
               .data_in({w_bit10, w_bit9, w_load_data[6:0], 1'b0, 1'b1}), 
               .load(w_load_d1), 
               .shift(w_btu), 
               .sdo(tx)
          );
               
     //***********************************
     //   Bit Time Counter
     //***********************************
     bit_time_counter
          inst_6(
               .clk(clk), 
               .rst(rst), 
               .sel({w_do_it, w_btu}), 
               .baud(baud), 
               .btu(w_btu)
          );
          
     //***********************************
     //   Bit Counter
     //***********************************
     bit_counter
          inst_7(
               .clk(clk), 
               .rst(rst), 
               .sel({w_do_it, w_btu}), 
               .done(w_done)
          );
endmodule
