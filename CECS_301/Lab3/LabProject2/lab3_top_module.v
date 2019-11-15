`timescale 1ns / 1ps
/******************************************************************************************
*    File Name:   Lab 3 Top module
*    Project:     Lab Project 3: Sequence Detectors(phase 2)
*    Designer:    Jose Sotelo
*    Email:       jsotelo235@gmail.com
*    Rev. Date:   March 2, 2017
*
*    Purpose:
*    This is the top module for the whole project. It contains the clock divider,
*    one-shot, the sequence detector circuit for detecting an overlap sequence of "101101",
*    and the seven segment decoder. We will be instantiating each circuit by using the previous 
*    modules created.
*
*    To complete the sequence detector, we need to instantiate the clock divider's inputs.
*    The inputs are the incoming clock frequency, the reset, and the output. Once this instance is defined,
*    we used the output of the clock divider as the input for the one-shot circuit. The one-
*    shot circuit accepts in a reset and D_in input to allow us to provide a reset and the clock 
*    input to the sequence detector.
*
*    Thirdly, the sequence detector circuit accepts the one-shot frequency signal that allows
*    the circuit to move one bit a time to locate the overlapping sequence "101101". A reset 
*    is also set to clear the detector once the button is pressed. The X input is used to detect
*    the overlapping sequence. The M input is used to select which finite state machine the
*    sequence detector currently operating at. The outputs Z and Q[2:0] are used to illustrate
*    the current state the overlapping sequence was detected. This signals X and Q[2:0] are
*    then concatenate and sent to the hex-to-7segment decoder who selects the anodes of the
*    display to illuminate the the current state in hex.
*
*    Notes:
 ******************************************************************************************/
module lab3_top_module(Clk_In, Reset, Step, X, M, Z, a, b, c, d, e, f, g, an);

     input          Clk_In, Reset;
     input          Step, X, M;
     
     output              Z;
     output              a, b, c, d, e, f, g;
     output[7:0]         an;
     
     wire[2:0]           Q;
     wire [3:0]     inputToHex;
     wire           w0, w1;
     
     clk_div
               clkDivider (.clk_in(Clk_In), .reset(Reset), .clk_out(w0));
     one_shot 
               debounce   (.clk_in(w0), .reset(Reset), .D_in(Step), .D_out(w1));
               
     sequence_detector_101101 detector (.clk(w1), .reset(Reset), .X(X), .M(M), .Z(Z), .Q(Q));
     
     //input to the hex-to-7segment decoder will be the concatenation of of 1'b0 and 3-bit state register
     
     assign inputToHex = {1'b0,Q};
     
     hex_to_7segment
                    display(.hex(inputToHex), .a(a), .b(b), .c(c), .d(d), .e(e), .f(f), .g(g));
     assign an = 8'b11111110;
endmodule
