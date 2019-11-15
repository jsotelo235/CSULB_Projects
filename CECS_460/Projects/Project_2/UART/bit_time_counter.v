`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 2>                               //
// File name:  Shift_Register .v                         //
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
module bit_time_counter(clk, rst, sel, baud, btu);

     input               clk, rst;
     input     [1:0]     sel;      // concat 1-bit do_it & btu wires
     input     [3:0]     baud;
     
     output              btu;
     
     reg       [18:0]    baud_count;
     reg       [18:0]    mux_out;
     reg       [18:0]    bit_time_count;
     
     // MUX Selector   
     always @(*)
          case(sel)
               2'b00 : mux_out <= 19'b0;
               2'b01 : mux_out <= 19'b0;
               2'b10 : mux_out <= bit_time_count + 19'b1;
               2'b11 : mux_out <= 19'b0;
          endcase
          
     // 19 bit Register
     always @(posedge clk, posedge rst)
          if(rst)
               bit_time_count <= 19'b0;
          else
               bit_time_count <= mux_out;






     // Baud Rate
     // Calculation (1/baud rate) / (1/100MHz) - 1
     always @(*)
          case(baud)
               4'b0000 : baud_count <= 333333 - 1;    // Baud rate 300
               4'b0001 : baud_count <= 83333  - 1;    // Baud rate 1200
               4'b0010 : baud_count <= 41667  - 1;    // Baud rate 2400
               4'b0011 : baud_count <= 20833  - 1;    // Baud rate 4800
               4'b0100 : baud_count <= 10417  - 1;    // Baud rate 9600
               4'b0101 : baud_count <= 5208   - 1;    // Baud rate 19200
               4'b0110 : baud_count <= 2604   - 1;    // Baud rate 38400
               4'b0111 : baud_count <= 1736   - 1;    // Baud rate 57600
               4'b1000 : baud_count <= 868    - 1;    // Baud rate 115200
               4'b1001 : baud_count <= 434    - 1;    // Baud rate 230400
               4'b1010 : baud_count <= 217    - 1;    // Baud rate 460800
               4'b1011 : baud_count <= 109    - 1;    // Baud rate 921600
               default : baud_count <= 333333 - 1;    // Default rate 300
          endcase

     // Comparator
     assign btu = (bit_time_count == baud_count) ? 1'b1 : 1'b0;

endmodule
