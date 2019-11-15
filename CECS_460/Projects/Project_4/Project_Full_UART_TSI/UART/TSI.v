`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Final Project>                           //
// File name:  TSI.v                                     //
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
module TSI(i_clk, i_rst, i_baud, i_eight, i_p_en, i_ohel, i_rx, i_tx, i_leds,
           o_clk, o_rst, o_baud, o_eight, o_p_en, o_ohel, o_rx, o_tx, o_leds);
          
          
     input               i_clk;
     input               i_rst;
     input     [3:0]     i_baud;
     input               i_eight;
     input               i_p_en;
     input               i_ohel;
     input               i_rx;
     
     input               i_tx;
     input     [15:0]    i_leds;
     
     output              o_clk;
     output              o_rst;
     output    [3:0]     o_baud;
     output              o_eight;
     output              o_p_en;
     output              o_ohel;
     output              o_rx;
     
     output              o_tx;
     output    [15:0]    o_leds;

     // BUFG: Global Clock Simple Buffer
     // 7 Series
     // Xilinx HDL Libraries Guide, version 2012.2
     BUFG 
          BUFG_inst (
                    .O(o_clk), // 1-bit output: Clock output
                    .I(i_clk)  // 1-bit input: Clock input
          );
          
     // IOBUF: Single-ended Bi-directional Buffer
     // All devices
     // Xilinx HDL Libraries Guide, version 2012.2
     IBUF #(
          .IBUF_LOW_PWR("TRUE"), // Low Power - "TRUE", High Perfor = "FALSE"
          .IOSTANDARD("DEFAULT") // Specify the I/O standard
         ) rst(
               .O(o_rst), // Buffer output
               .I(i_rst)  // Buffer input
          );
          
     IBUF #(
          .IBUF_LOW_PWR("TRUE"), // Low Power - "TRUE", High Perfor = "FALSE"
          .IOSTANDARD("DEFAULT") // Specify the I/O standard
         ) baud[3:0](
               .O(o_baud), // Buffer output
               .I(i_baud)  // Buffer input
          );
          
     IBUF #(
          .IBUF_LOW_PWR("TRUE"), // Low Power - "TRUE", High Perfor = "FALSE"
          .IOSTANDARD("DEFAULT") // Specify the I/O standard
         ) eight(
               .O(o_eight), // Buffer output
               .I(i_eight)  // Buffer input
          );
          
     IBUF #(
          .IBUF_LOW_PWR("TRUE"), // Low Power - "TRUE", High Perfor = "FALSE"
          .IOSTANDARD("DEFAULT") // Specify the I/O standard
         ) p_en(
               .O(o_p_en), // Buffer output
               .I(i_p_en)  // Buffer input
          );
         
     IBUF #(
          .IBUF_LOW_PWR("TRUE"), // Low Power - "TRUE", High Perfor = "FALSE"
          .IOSTANDARD("DEFAULT") // Specify the I/O standard
         ) ohel(
               .O(o_ohel), // Buffer output
               .I(i_ohel)  // Buffer input
          );
          
     IBUF #(
          .IBUF_LOW_PWR("TRUE"), // Low Power - "TRUE", High Perfor = "FALSE"
          .IOSTANDARD("DEFAULT") // Specify the I/O standard
         ) rx(
               .O(o_rx),  // Buffer output
               .I(i_rx)   // Buffer input
          );
          
     // OBUF: Single-ended Output Buffer
     // 7 Series
     // Xilinx HDL Libraries Guide, version 2012.2
     
     OBUF #(
          .DRIVE(12),             // Specify the output drive strength
          .IOSTANDARD("DEFAULT"), // Specify the output I/O standard
          .SLEW("SLOW")           // Specify the output slew rate
     )tx (
               .O(o_tx),  // Buffer output (connect directly to top-level port)
               .I(i_tx)   // Buffer input
          );
          
     OBUF #(
          .DRIVE(12),             // Specify the output drive strength
          .IOSTANDARD("DEFAULT"), // Specify the output I/O standard
          .SLEW("SLOW")           // Specify the output slew rate
     )leds[15:0] (
               .O(o_leds),  // Buffer output (connect directly to top-level port)
               .I(i_leds)   // Buffer input
          );
endmodule
