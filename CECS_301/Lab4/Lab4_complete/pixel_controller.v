`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     Pixel_Controller
*    Project:       Lab Project 4: Memory & Display Controllers
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     March. 12, 2017
*
*    Purpose:
*    The purpose for this module is to generate the signals for the common anode
*    inputs to the 7-segment displays and also generates the multiplexer select
*    signals for multiplexing the address/data nibbles.
*
*    To understand this module, we need to have a basic understanding of how
*    the pixel controller functions. In this project we are using two seven
*    segment displays that each need 7 bits of pixel data.
*
*    To select a pixel, we need to assert its anode (produce a logic high input)
*    and simultaneously deassert all other anodes (produce a logic low input) and
*    send this data to the multiplexer.
*
*    First, we need to create a Moore FSM diagram which the ouputs depend on the current  
*    state the anodes are in, what output it should produce and the next state
*    the anodes should transistion too.
*
*    Thus, we need to have 8 bit anodes for the two 7-segment displays, 3 bit
*    selectors, a clock and a reset. Next, we will have a state register and
*    next state variables to keep track of what state we are in and the next
*    state we should transisiton too.
*
*    The Next State Combinational Logic checks which present state we are currently in. 
*    If the present state is at the initial state then the next state is 1, if the present 
*    state is 1, the next state is 2 and so on. The default state should always be at initial
*    state.
*
*    The next part of the Moore FSM is Sequential logic. The state register logic
*    is driven by a posedge clock or posedge reset. If a posedge reset is detected
*    then we transition from whatever state we are in to a state were the state
*    registers are all 0's. Else, if no posedge reset is detected then we transition
*    from the present state to the next state on a posedge clock.
*
*    Lastly, the Output combinational logic of the Moore FSM deasserts one anode to a logic
*    low which turns on the "pixel" segments depending on the present state we are in.
*    The other anodes are asserted to a logic high which turns off those "pixel" segments in
*    that present state. The selector is used to indicate what state we are in. Thus,
*    the selector indicates state 000, 001, 010,..etc.
 ****************************************************************************/
module pixel_controller(clk, reset, sel, anodes);

     input               clk, reset;
     output    [7:0]     anodes;
     output    [2:0]     sel;
     
     reg       [7:0]     anodes;
     reg       [2:0]     sel;
     
     //*************************************
     //   Present State and
     //   next_state variables
     //*************************************
     
     reg       [7:0]     present_state;
     reg       [7:0]     next_state;
     
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
               present_state = 3'b0;       //Got a reset so set state register to all 0's
          else
               present_state = next_state;   //Got a posedge so update state register with next state
               
     //*********************************************************************
     //   Output Combinational Logic
     //   (outputs will only change when present state changes)
     //*********************************************************************
     
     always @  (present_state )
          case ( present_state )
          3'b000    :    {anodes, sel} = 11'b11111110_000;
          3'b001    :    {anodes, sel} = 11'b11111101_001;
          3'b010    :    {anodes, sel} = 11'b11111011_010;
          3'b011    :    {anodes, sel} = 11'b11110111_011;
          3'b100    :    {anodes, sel} = 11'b11101111_100;
          3'b101    :    {anodes, sel} = 11'b11011111_101;
          3'b110    :    {anodes, sel} = 11'b10111111_110;
          3'b111    :    {anodes, sel} = 11'b01111111_111;
          default   :    {anodes, sel} = 11'b11111111_000;
          endcase
endmodule
