`timescale 1ns / 1ps
/******************************************************************************************
*    File Name:   Lab 2 Top module
*    Project:     Lab Project 2: Sequence Detectors(phase 1)
*    Designer:    Jose Sotelo
*    Email:       jsotelo235@gmail.com
*    Rev. Date:   Feb. 24, 2017
*
*    Purpose:
*    This is the top module for the whole project. It contains the clock divider,
*    one-shot, and the sequence detector circuit for "101101". We will be instantiating
*    each circuit by using the previous modules created.
*
*    To complete the sequence detector we need to instantiate the clock divider and pass in
*    the incoming clock frequency, the reset, and the output. Once this instance is defined,
*    we used the output of the clock divider as the input for the one-shot circuit. The one-
*    shot circuit accepts in a reset and D_in input to allow us to provide a reset or the clock 
*    input to the sequence detector.
*
*    Lastly, the sequence detector circuit accepts the one-shot frequency signal that allows
*    the circuit to move one bit a time to locate the non-overlapping sequence "101101". A reset 
*    is also set to clear the detector once the button is pressed. The X input is used to detect
*    the non-overlapping sequence. The M input is used to select which finite state machine is the
*    sequence detector currently operating at. The result outputs a "1" for Z and Q[2:0] to represent
*    the current state when the sequence was detected.
* 
*    Notes:
 ******************************************************************************************/
module lab2_top_module(Clk_In, Reset, Step, X, M, Z, Q);

     input          Clk_In, Reset;
     input          Step, X, M;
     
     output         Z;
     output[2:0]    Q;
     
     wire w0, w1;
     
     clk_div
               clkDivider (.clk_in(Clk_In), .reset(Reset), .clk_out(w0));
     one_shot 
               debounce   (.clk_in(w0), .reset(Reset), .D_in(Step), .D_out(w1));
               
     sequence_detector_101101 detector (.clk(w1), .reset(Reset), .X(X), .M(M), .Z(Z), .Q(Q));
endmodule
