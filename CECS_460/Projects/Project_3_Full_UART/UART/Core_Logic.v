`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Final Project>                           //
// File name:  Core_Logic.v                              //
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
module Core_Logic(clk, rst, baud, eight, p_en, ohel, rx, tx, leds);
     
     input               clk, rst;
     input     [3:0]     baud;
     input               eight, p_en, ohel;
     input               rx;
     
     output              tx;
     output    [15:0]    leds;
     
     reg       [15:0]    leds;
     
     wire                w_rst_s;
     wire                w_write_strobe;
     wire                w_read_strobe;
     wire                w_int_ack;
     wire      [7:0]     w_uart_ds;
     wire                w_uart_int;
     wire                w_interrupt;
     wire      [15:0]    w_port_id;
     wire      [15:0]    w_out_port;
     
     reg       [15:0]    w_write;
     reg       [15:0]    w_read;
     
     //***********************************
     //   AISO
     //***********************************
     Aiso
          aiso(
               .clk(clk), 
               .rst(rst), 
               .rst_s(w_rst_s)
          );
         
     //***********************************
     //   Address Decode
     //***********************************          
     always @(*)
     begin
          w_write = 16'b0;
          w_read  = 16'b0;
          
          w_write[w_port_id] = w_write_strobe;
          w_read[w_port_id]  = w_read_strobe;
     end
     
     //***********************************
     //   UART
     //***********************************
     UART_Top
          uart(
               .clk(clk), 
               .rst(w_rst_s), 
               .write(w_write[0]), 
               .read(w_read[1:0]), 
               .out_port(w_out_port[7:0]), 
               .rx(rx), 
               .baud(baud), 
               .eight(eight), 
               .p_en(p_en), 
               .ohel(ohel), 
               .tx(tx), 
               .UART_DS(w_uart_ds), 
               .UART_INT(w_uart_int)
          );
          
     //***********************************
     //   SR Flop Interrupt 
     //***********************************
     SR_Flop
          sr_interrupt(
               .clk(clk), 
               .rst(w_rst_s), 
               .S(w_uart_int), 
               .R(w_int_ack), 
               .Q(w_interrupt)
          );
          
     //***********************************
     //   TramelBlaze
     //***********************************
     tramelblaze_top 
          tb_top(
               .CLK(clk), 
               .RESET(w_rst_s), 
               .IN_PORT({8'b0, w_uart_ds}), 
               .INTERRUPT(w_interrupt), 
               .OUT_PORT(w_out_port), 
               .PORT_ID(w_port_id), 
               .READ_STROBE(w_read_strobe), 
               .WRITE_STROBE(w_write_strobe), 
               .INTERRUPT_ACK(w_int_ack)
          );
          
     //***********************************
     //   Walking LEDs
     //***********************************   
     always @(posedge clk, posedge w_rst_s)
     begin
          if(w_rst_s)
               leds <= 16'b0;
          else if(w_write[2])
               leds <= w_out_port;
          else
               leds <= leds;
     end

endmodule
