`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Rx_DataPath.v                             //
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
module Rx_DataPath(clk, rst, btu, start, rx, 
                   eight, p_en, even, done, read, 
                   rx_rdy, parity_err, frame_err, overflow, data_to_TB);

     input               clk, rst;
     input               btu, start, rx;
     input               eight, p_en;
     input               even, done;
     input               read;
     
     output              rx_rdy;
     output              parity_err;
     output              frame_err;
     output              overflow;
     output    [7:0]     data_to_TB;
     
     reg                 stop_bit_mux_out;
     
     wire      [9:0]     w_shift_reg_out;
     wire      [9:0]     w_remap;
     wire                w_p_gen_mux;
     wire                w_p_gen_even_mux;
     wire                w_p_bit_mux;
     wire                w_perr;
     wire                w_ferr;
     wire                w_ovf;
     
     //***********************************
     //   Rx Shift Register
     //***********************************
     Rx_Shift_Reg
          rx_shift_reg(
               .clk(clk), 
               .rst(rst), 
               .sh(btu & ~start), 
               .sdi(rx), 
               .data_out(w_shift_reg_out)
          );
          
     //***********************************
     //   Rx ReMap
     //***********************************
     Rx_Remap
          rx_remap(
               .sel({eight, p_en}), 
               .data_in(w_shift_reg_out), 
               .remap(w_remap)
          );
              
     assign w_p_gen_mux = (eight) ? w_remap[7] : 1'b0;
     
     assign w_p_gen_even_mux = (even) ? (^{w_p_gen_mux, w_remap[6:0]}) :
                                       ~(^{w_p_gen_mux, w_remap[6:0]});
     
     assign w_p_bit_mux = (eight) ? w_remap[8] : w_remap[7];
     
     assign w_perr = p_en & (^{w_p_gen_even_mux, w_p_bit_mux}) & done;
     
     //***********************************
     //   Stop Bit Select MUX
     //***********************************
     always @(*)
          case({eight, p_en})
               2'b00     :    stop_bit_mux_out <= w_remap[7];
               2'b01     :    stop_bit_mux_out <= w_remap[8]; 
               2'b10     :    stop_bit_mux_out <= w_remap[8];
               2'b11     :    stop_bit_mux_out <= w_remap[9];
               default   :    stop_bit_mux_out <= w_remap[7];
          endcase
          
     //***********************************
     //   SR Rx Ready Flop
     //***********************************
     Rx_SR_Flop
          rx_ready(
               .clk(clk), 
               .rst(rst),
               .S(done), 
               .R(read), 
               .Q(rx_rdy)
          );
     
     //***********************************
     //   SR Rx Parity Error
     //***********************************
     Rx_SR_Flop
          p_err(
               .clk(clk), 
               .rst(rst), 
               .S(w_perr), 
               .R(read), 
               .Q(parity_err)
          );
          
     //***********************************
     //   SR Rx Framing Error
     //***********************************
     Rx_SR_Flop
          framing_err(
               .clk(clk), 
               .rst(rst), 
               .S(done & ~stop_bit_mux_out), 
               .R(read), 
               .Q(frame_err)
          );
          
     //***********************************
     //   SR Rx Overflow Error
     //***********************************
     Rx_SR_Flop
          ovf_err(
               .clk(clk), 
               .rst(rst), 
               .S(done & rx_rdy), 
               .R(read), 
               .Q(overflow)
          );

     //***********************************
     //   Data sent to TramelBlaze
     //***********************************
     assign data_to_TB = (eight) ? w_remap[7:0] : {1'b0, w_remap[6:0]};
endmodule
