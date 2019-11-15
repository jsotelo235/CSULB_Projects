`timescale 1ns / 1ps
/******************************************************************************************
*    File Name:     One shot debounce Module
*    Project:       Lab Project 4: Memory & Display Controllers
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:         jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Rev. Date:     March 12, 2017
*
*    Purpose:
*    The one-shot debounce module is used to filter out the signal produce
*    by a switch. When a switch is pressed or "pushed" the output produce
*    by this event causes the switch to debounce for a period of time.
*
*    This module is used twice to debounce the down push buttons for the address
*    sequencer (add_seqr) and the input for the write enable of the RAM module.
*    More detail ar provide within those modules.
*   
*    The reason why this unwated bounce in the switch takes place, is due to
*    the electro-mechanical construction of the switch. To help out filter the
*    unwated bounce in the switch, we need to "wait" for a period of time until
*    the switch become stable. The wait time for this "stabilization" is approximately
*    about 10 to 20ms. 
*
*    In our case, since we are bringing in a 500Hz clock frequency that has been "divide" by
*    the clock divider circuit, we need to determine exactly how long this wait time needs to
*    occur until the switch stabilizes. 
*
*    To determine the wait period we need to divide 1 over the incoming frequency. Since, the switch
*    takes about 10 samples to stabilize we multiply 10 samples by the result of (1/incoming frequency).
*    The result is 20ms, thus our switch stabilizes after each 20ms.
*
*   Once the signal is stable, a "one-shot" output is sent to the D_out output of the "one-shot"
*   circuit. Each signal depends on the posedge clock of the clock divider. If a reset is detected,
*   the one-shot circuit sends a "0" and disables the circuit for that movement. 
*
*   Notes:
 ******************************************************************************************/
module debounce( clk_in, reset, D_in, D_out);

     //Input declarations
     input clk_in, reset, D_in;
     
     //Output declarations
     output wire D_out;
     
     reg [9:0] Q;

     always @(posedge clk_in or posedge reset)
          if(reset)
               Q[9:0]<=10'b0;
          else begin
               // shift in the new sample that is on the D_in input one bit at a time
               Q[9]<=Q[8];Q[8]<=Q[7];Q[7]<=Q[6];Q[6]<=Q[5];Q[5]<=Q[4];Q[4]<=Q[3];
               Q[3]<=Q[2];Q[2]<=Q[1];Q[1]<=Q[0];Q[0]<=D_in;
          end
          
     assign D_out= !Q[9]&Q[8]&Q[7]&Q[6]&Q[5]&Q[4]&Q[3]&Q[2]&Q[1]&Q[0];
     
endmodule
