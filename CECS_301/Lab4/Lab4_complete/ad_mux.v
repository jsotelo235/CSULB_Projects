`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     Ad_Mux
*    Project:       Lab Project 4: Memory & Display Controllers
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     March. 12, 2017
*
*    Purpose:
*    The purpose for this module to make a 8-to-1 MUX for multiplexing
*    adress/data information to the 7-segment module.
*
*    This is the last module that completes the display controller in
*    conjuction with the pixel_clk and pixel_controller modules.
*
*    Multiplexing is the generic term used to describe the operation of
*    sending one or more digital signal over a transmission line depending
*    on the selector.
*
*    In this case, we will be multiplexing the outputs and inputs of the RAM
*    into the 8-to-1 multiplexer. We will be accessing data nibbles into the
*    7-segment display module.
*
*    The "high nibble" of the add_seqr (addr[7:4]) will be sent to the 7-segment
*    display in conjuction with anode an5.
*
*    The "low nibble" of the add_seqr (addr[3:0]) will be sent to the 7-segment
*    displays in conjunction with anode an4.
*
*    The "highest nibble" of the output of the RAM (dout[15:12]) will be sent to
*    the 7-segment display in conjuction with anode an3.
*
*    The "next nibble" of the output of the RAM (dout[11:8]) will be sent to
*    the 7-segment display in conjuction with anode an2.
*
*    The "next nibble" of the output of the RAM (dout[7:4]) will be sent to
*    the 7-segment display in conjuction with anode an1.
*
*    The "lowest nibble" of the output of the RAM (dout[3:0]) will be sent 
*    to the 7-segment display in conjuction with anode an0. 
*
*    Lastly, the multiplexer will not select the last two anodes 
*    7 and 6 since they are set to 4 bit 0's.  
*
*    The output of the multiplexer should produce a 4 bit data tha will be sent
*    to the seven segment display. 
*
*    Thus, the display controller must send one of eight hex-nibbles to the
*    hex_to_7seg module to assert/deassert the appropriate anode signals at the
*    same time.
*    
*    Notes:
*
 ****************************************************************************/
module ad_mux(sel, D_out,addr,y);

     input     [15:0]    D_out;
     input     [2:0]     sel;
	input     [7:0]     addr;
     output    [3:0]     y; 
     reg       [3:0]     y;
     
     always @(sel)
     begin
          case(sel)
               3'b000 : y = D_out[3:0];
               3'b001 : y = D_out[7:4];
               3'b010 : y = D_out[11:8];
               3'b011 : y = D_out[15:12];
               3'b100 : y = addr[3:0];
               3'b101 : y = addr[7:4];
               3'b110 : y = 4'b0000;
               3'b111 : y = 4'b0000;
               default: y = 4'bx;
          endcase
     end
endmodule
