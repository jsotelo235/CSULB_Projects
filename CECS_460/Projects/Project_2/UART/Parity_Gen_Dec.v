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
module Parity_Gen_Dec(load_data, eight, p_en, ohel, bit10, bit9);

     input     [7:0]     load_data;
     input               eight, p_en, ohel;
     
     output              bit10, bit9;
     
     reg                 EP, OP;
     reg                 bit10, bit9;

	//***********************************
     //   y = f(x)
     //   Function is used to determine
     //   Odd/Even parity bits
     //***********************************
      always @ (*)
         begin 
          EP   <= (eight) ?   ^load_data[7:0]   :   ^load_data[6:0];
          OP   <= (eight) ? ~(^load_data[7:0])  : ~(^load_data[6:0]);
         end
         
     always @(*)
          case({eight, p_en, ohel})
               3'b000 : {bit10, bit9}  <=  2'b11;                // 7N1
               3'b001 : {bit10, bit9}  <=  2'b11;                // 7N1
               3'b010 : {bit10, bit9}  <= {1'b1, EP};            // 7E1
               3'b011 : {bit10, bit9}  <= {1'b1, OP};            // 7O1
               3'b100 : {bit10, bit9}  <= {1'b1, load_data[7]};  // 8N1
               3'b101 : {bit10, bit9}  <= {1'b1, load_data[7]};  // 8N1
               3'b110 : {bit10, bit9}  <= {EP,   load_data[7]};  // 8E1
               3'b111 : {bit10, bit9}  <= {OP,   load_data[7]};  // 8O1
          endcase 
endmodule
