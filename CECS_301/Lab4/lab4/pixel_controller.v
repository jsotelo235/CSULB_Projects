`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:26:33 03/07/2017 
// Design Name: 
// Module Name:    pixel_controller 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module pixel_controller(clk, reset, sel, an7, an6, an5, an4, an3, an2, an1, an0);

     input               clk, reset;
     output              an7, an6, an5, an4, an3, an2, an1, an0;
     output    [2:0]     sel;
     
     reg                 an7, an6, an5, an4, an3, an2, an1, an0;
     reg       [2:0]     sel;
     
     //*************************************
     //   State register and
     //   next_state variables
     //*************************************
     
     reg       [2:0]     present_state;
     reg       [2:0]     next_state;
     
     //********************************************************************
     //   Next State Combinational Logic
     //   (next values can change anytime but will only be "clocked" below)
     //********************************************************************
      
      always @( present_state )
          case( present_state )
               3'b000    :    next_state = 3'b001;
               3'b001    :    next_state = 3'b010;
               3'b010    :    next_state = 3'b011;
               3'b011    :    next_state = 3'b100;
               3'b100    :    next_state = 3'b101;
               3'b101    :    next_state = 3'b110;
               3'b110    :    next_state = 3'b111;
               3'b111    :    next_state = 3'b000;
               default   :    next_state = 3'b000;
          endcase;
          
     //********************************************************************
     //   State Register Logic (Sequential Logic)
     //   using the non-blocking assignment for sequential logic
     //********************************************************************
     
     always @(posedge clk or posedge reset)
          if (reset == 1'b1)
               present_state = 3'b0;        //Got a reset so set state register to all 0's
          else
               present_state = next_state;  //Got a posedge so update state register with next state
               
     //*********************************************************************
     //   Output Combinational Logic
     //   (outputs will only change when present state changes)
     //*********************************************************************
     
     always @  (present_state )
          case ( present_state )
          3'b000    :    {an7, an6, an5, an4, an3, an2, an1, an0, sel} = 11'b11111110_000;
          3'b001    :    {an7, an6, an5, an4, an3, an2, an1, an0, sel} = 11'b11111101_001;
          3'b010    :    {an7, an6, an5, an4, an3, an2, an1, an0, sel} = 11'b11111011_010;
          3'b011    :    {an7, an6, an5, an4, an3, an2, an1, an0, sel} = 11'b11110111_011;
          3'b100    :    {an7, an6, an5, an4, an3, an2, an1, an0, sel} = 11'b11101111_100;
          3'b101    :    {an7, an6, an5, an4, an3, an2, an1, an0, sel} = 11'b11011111_101;
          3'b110    :    {an7, an6, an5, an4, an3, an2, an1, an0, sel} = 11'b10111111_110;
          3'b111    :    {an7, an6, an5, an4, an3, an2, an1, an0, sel} = 11'b01111111_111;
          default   :    {an7, an6, an5, an4, an3, an2, an1, an0, sel} = 11'b11111111_000;
          endcase
endmodule
