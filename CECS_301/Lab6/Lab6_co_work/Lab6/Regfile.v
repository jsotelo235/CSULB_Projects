`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     Regfile.v
*    Project:       Lab Project 6: Integer Data Path
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     April. 06, 2017
*
*    Purpose:
*    The purpose for this module is to instantiate the 3-to-8 decoder and
*    the reg16 modules to create the the register file.
*
*    We will need to instanitate three 3-to-8 decoders and 8 instances of
*    a 16-bit register.
*    
*    The operation of the 16 bit register file is to select a register with
*    the W_Adr, R_Adr and S_Adr adress inputs. The 16-bit R data port will
*    always have the contents of the register addressed by the S_Adr inputs.
*    
*    The register addressed by the W_Adr inputs will be written with the data
*    on 16-bit W data inputs if-and-only-if the write enable (we) is asserted
*    on the positive edge of the clock.
 ****************************************************************************/
module Regfile(clk, reset, we, W_adr, R_adr, S_adr, W, R, S);
	 
   // IO Declarations
	input			clk, reset, we;
	input	[2:0]	W_adr, R_adr, S_adr;	
	input	[15:0]	W;
	output    [15:0]	R, S;
	
   // wires
	wire      [7:0]	w_out, r_out, s_out;

     //**********************************************
     //   Instantiation of 3  3_to_8_decoders
     //**********************************************
	dec_3to_8	
               d0(we,    W_adr,    w_out), // ld
			d1(1'b1,  R_adr,    r_out), // oeA
			d2(1'b1,  S_adr,    s_out); // oeB
				
     //**********************************************
     //   Instantiation of 8  16 bit registers
     //**********************************************
	  
	reg16	R0(clk, reset, w_out[0], W, R, S, r_out[0], s_out[0]),
			R1(clk, reset, w_out[1], W, R, S, r_out[1], s_out[1]),
			R2(clk, reset, w_out[2], W, R, S, r_out[2], s_out[2]),
			R3(clk, reset, w_out[3], W, R, S, r_out[3], s_out[3]),
			R4(clk, reset, w_out[4], W, R, S, r_out[4], s_out[4]),
			R5(clk, reset, w_out[5], W, R, S, r_out[5], s_out[5]),
			R6(clk, reset, w_out[6], W, R, S, r_out[6], s_out[6]),
			R7(clk, reset, w_out[7], W, R, S, r_out[7], s_out[7]);

endmodule
