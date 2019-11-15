`timescale 1ns / 1ps
/******************************************************************************************
*   File Name:   One shot debounce 
*   Project:     Lab Project 3: Sequence Detectors(phase 2)
*   Designer:    Jose Sotelo
*   Email:       jsotelo235@gmail.com
*   Rev. Date:   Feb. 25, 2017
*
*   Purpose:
*   The one-shot debounce module is used to filter out the signal produce
*   by a switch. When a switch is pressed or "pushed" the output produce
*   by this event causes the switch to debounce for a period of time.
*   
*   The reason why this unwated bounce in the switch takes place, is due to
*   the electro-mechanical construction of the switch. To help out filter the
*   unwated bounce in the switch, we need to "wait" for a period of time until
*   the switch become stable. The wait time for this "stabilization" is approximately
*   about 10 to 20ms. 
*
*   In our case, since we are bringing in a 500Hz clock frequency that has been "divide" by
*   the clock divider circuit, we need to determine exactly how long this wait time needs to
*   occur until the switch stabilizes. 
*
*   To determine the wait period we need to divide 1 over the incoming frequency. Since, the switch
*   takes about 10 samples to stabilize we multiply 10 samples by the result of (1/incoming frequency).
*   The result is 20ms, thus our switch stabilizes after each 20ms.
*
*   Once the signal is stable, a "one-shot" output is sent to the D_out output of the "one-shot"
*   circuit. Each signal depends on the posedge clock of the clock divider. If a reset is detected,
*   the one-shot circuit sends a "0" and disables the circuit for that movement. 
*
*   Notes:
 *****************************************************************************************/
module one_shot(clk_in, reset, D_in, D_out);
     
     input     D_in, clk_in, reset;
     output    D_out;
     wire      D_out;
     
     reg       q9, q8, q7, q6, q5, q4, q3, q2, q1, q0;
     
     always @ (posedge clk_in or posedge reset)
          if(reset == 1'b1)
               { q9, q8, q7, q6, q5, q4, q3, q2, q1, q0} <= 10'b0;
          else begin
               q9 <= q8; q8 <= q7; q7 <= q6; q6 <= q5; q5 <= q4;
               q4 <= q3; q3 <= q2; q2 <= q1; q1 <= q0; q0 <= D_in;
          end
          
     assign D_out = !q9 & q8 & q7 & q6 & q5 &
                     q4 & q3 & q2 & q1 & q0;
endmodule
