`timescale 1ns / 1ps
/******************************************************************************************
*    File Name:     Lab4 Top Module
*    Project:       Lab Project 4: Memory & Display Controllers
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:         jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Rev. Date:     March 12, 2017
*
*    Purpose:
*    The purpose for this module is to instantiate every single module created for this
*    project. 
*    
*    The modules that are instantiated are clock divider, one shot debounce,
*    address sequencer, pixel controller, RAM, Ad mux, and seven segment display.
*    
*    The global inputs needed are the board's 100MHz clock to be passed into the clock
*    divider and the RAM. The reset input used to clear every module on posedge reset.
*    The input wr_pulse use to write enable to the RAM and the addr_seqr to move through
*    the addresses. 
*
*    The D_in inputs to the RAM are to come from the sixteen slide switches SW15
*    (din15)-SW0(din(0)).
*
*    The anode ouputs are used to be driven logic high for off and logic low for on. Depending
*    on the anodes on, they are sent to the ad_mux which then the signal are sent to the 7-segment
*    display which turns on the "pixels" a-g from the display.
*    Notes:
 ******************************************************************************************/
module lab4_toplevel(clock_100mhz, reset, wr_pulse, addr_step, D_in, a, b, c, d,  e,f, g, Anodes);

     //Input declarations
     input               clock_100mhz, reset, wr_pulse, addr_step;
     input     [15:0]    D_in;
     
     // Output declarations
     output              a,b,c,d,e,f,g;
     output    [7:0]     Anodes;
     
     //wire declarations
     wire                clk_500;
     wire                D_out;
     wire                addr_seqr_clock;
     wire                pix_clk;
     wire      [15:0]    Ram_D_out;
     wire      [2:0]     Seg_select;
     wire      [7:0]     sequence;
     wire      [3:0]     exadecimal;

     //*********************************************************
     //   Clock Divider Instantiation
     //*********************************************************
     clock_div div(clock_100mhz,reset,clk_500);
     pixel_clk pixel (clock_100mhz,reset,pix_clk);

     //********************************************************
     //   one_shot_debounce module Instantiation
     //********************************************************
     debounce deb(clk_500, reset, wr_pulse,D_out);
     debounce deb2(pix_clk,reset,addr_step,addr_seqr_clock);

     //*********************************************************
     //   Addr_Seqr module Instantiation
     //*********************************************************
     addr_seqr seq(addr_seqr_clock,reset,sequence);
     
     //*********************************************************
     //   Pixel Controller module Instantiation
     //*********************************************************
     pixel_controller pix(clk_500,reset,Seg_select,Anodes);
     
     //*********************************************************
     //   Ram1 module Instantiation
     //*********************************************************
     ram1 ram(clock_100mhz,D_out,sequence,D_in,Ram_D_out);

     //**********************************************************
     //   Ad_Mux module Instantiation
     //**********************************************************
     ad_mux mux(Seg_select,Ram_D_out,sequence,hexadecimal);

     //**********************************************************
     //   Seven Segment Display
     //**********************************************************
     hex_to_7seg segm(hexadecimal,a,b,c,d,e,f,g);
     
endmodule
