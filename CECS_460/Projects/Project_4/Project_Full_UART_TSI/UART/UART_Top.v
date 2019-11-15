`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 3>                               //
// File name:  UART_Top.v                                //
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
module UART_Top(clk, rst, write, read, out_port, rx, baud, 
                eight, p_en, ohel, tx, UART_DS, UART_INT);

     input               clk, rst;
     input               write;
     input     [1:0]     read;
     input     [7:0]     out_port;
     input     [3:0]     baud;
     input               eight, p_en, ohel;
     input               rx;
     
     output              tx;
     output    [7:0]     UART_DS;
     output              UART_INT;
     
     wire                w_tx_rdy;
     wire                w_rx_rdy;
     wire                w_ped_tx;
     wire                w_ped_rx;
     wire                w_perr;
     wire                w_ferr;
     wire                w_ovf;
     wire      [18:0]    k;
     wire      [7:0]     w_data_to_TB;
     wire      [7:0]     w_status;
     
     //***********************************
     //   Baud
     //***********************************
     Baud_Dec
          baud_dec(
               .baud(baud), 
               .baud_count(k)
          );
          
     //***********************************
     //   Tx Engine
     //***********************************
     Tx_Engine
          transmit_engine(
               .clk(clk),    
               .rst(rst),   
               .load(write), 
               .baud_count(k), 
               .data_in(out_port), 
               .eight(eight),  
               .p_en(p_en),  
               .ohel(ohel), 
               .txrdy(w_tx_rdy),      
               .tx(tx)
          );
          
     //***********************************
     //   Rx Engine
     //***********************************
     Rx_Engine
          receive_engine(
               .clk(clk), 
               .rst(rst), 
               .rx(rx), 
               .k(k), 
               .eight(eight), 
               .p_en(p_en), 
               .ohel(ohel), 
               .read(read[0]),
               .rx_rdy(w_rx_rdy), 
               .parity_err(w_perr), 
               .frame_err(w_ferr), 
               .overflow(w_ovf), 
               .data_to_TB(w_data_to_TB)
          );
          
     assign w_status = {3'b0, w_ovf, w_ferr, w_perr, w_tx_rdy, w_rx_rdy};
          
     assign UART_DS = (read[1]) ? w_status     :
                      (read[0]) ? w_data_to_TB : 
                                  8'b0;
     
     //***********************************
     //   PED Tx
     //   PED Rx
     //***********************************
     PED
          tx_ped(
               .clk(clk), 
               .rst(rst), 
               .ped_in(w_tx_rdy), 
               .ped_out(w_ped_tx)
          ),
          
          rx_ped(
               .clk(clk), 
               .rst(rst), 
               .ped_in(w_rx_rdy), 
               .ped_out(w_ped_rx)
          );
          
     assign UART_INT = w_ped_tx | w_ped_rx;  // wire to SR Flop
endmodule
