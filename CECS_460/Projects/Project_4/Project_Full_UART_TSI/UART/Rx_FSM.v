`timescale 1ns / 1ps
//*******************************************************//
// This document contains information proprietary        //
// to the CSULB student that created the                 //
// file - any reuse without adequate approval and        //
// documentation is prohibited                           //
//                                                       //
// Class:      <CECS 460 SOC>                            //
// Project:    <Project 3>                               //
// File name:  Rx_FSM.v                                  //
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
module Rx_FSM(clk, rst, rx, btu, done, start, do_it);

     input          clk, rst;
     input          rx, btu, done;
     
     output         start, do_it;
     
     reg            start, do_it;
     
     reg  [1:0]     CurrentState, NxtState;
     reg            NxtStart, NxtDo_It;
     
     parameter      s0 = 2'b00,
                    s1 = 2'b01,
                    s2 = 2'b10;
         
     always @(posedge clk, posedge rst)
     begin
          if(rst)
               {CurrentState, start, do_it} <= {s0, 2'b00};
          else
               {CurrentState, start, do_it} <= {NxtState, NxtStart, NxtDo_It};
     end
     
     always @(*)
     begin
          NxtStart = 0;
          NxtDo_It = 0;
          NxtState = CurrentState;
          case(CurrentState)
               s0: 
               begin
                    {NxtState, NxtStart, NxtDo_It} = (rx) ? {s0, 2'b00} : 
                                                            {s1, 2'b11};
               end
               s1: 
               begin
                    {NxtState, NxtStart, NxtDo_It} = 
                                             (rx)           ? {s0, 2'b00} :
                                             (~rx && ~btu)  ? {s1, 2'b11} : 
                                                              {s2, 2'b01};
               end         
               s2: 
               begin     
                    {NxtState, NxtStart, NxtDo_It} = (~done) ? {s2, 2'b01} : 
                                                               {s0, 2'b00};
               end
               default   : {NxtState, NxtStart, NxtDo_It} = {s0, 2'b00};           
          endcase
     end
endmodule
