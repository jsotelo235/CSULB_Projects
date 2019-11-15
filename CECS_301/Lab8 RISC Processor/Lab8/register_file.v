`timescale 1ns / 100ps
/************************************************************************
* File Name: register_file.v
* Project: Lab Project 5 - Register Files
* Designer: Jarod Bamber & Jose Pacheco
* Email:	jarod.bamber@gmail.com / pacheco216@gmail.com
* Rev. Dates: Oct. 18, 2016 / Oct. 16, 2016
*
* Purpose: Contains 8 16 bit registers and 3 decoders to determine the
* read/write addresses. The register has two outputs that can be read and
* written to seperately. Registers require enables to read and write which
* comes from the decoders.
* 
* Notes:
* 
************************************************************************/
module register_file(clk, reset, we, W_Adr, R_Adr, S_Adr, W, R, S);

	 //Inputs
	 input clk, reset, we;
	 input [2:0] W_Adr, R_Adr, S_Adr;
	 input [15:0] W;
	 
    //Outputs
	 output [15:0] R, S;
	 
    //Wires
	 wire L7, L6, L5, L4, L3, L2, L1, L0,
			A7, A6, A5, A4, A3, A2, A1, A0,
			B7, B6, B5, B4, B3, B2, B1, B0;
	 
    //Modules
	 dec_3to8     WDEC(W_Adr, we,   {L7, L6, L5, L4, L3, L2, L1, L0}),
					  RDEC(R_Adr, 1'b1, {A7, A6, A5, A4, A3, A2, A1, A0}),
					  SDEC(S_Adr, 1'b1, {B7, B6, B5, B4, B3, B2, B1, B0});
					  
    //reg16				 clk, reset, LD, Din, DA, DB, oeA, oeB; 
	 reg16		  REG0(clk, reset, L0, W,   R,  S,  A0,  B0),
			   	  REG1(clk, reset, L1, W,   R,  S,  A1,  B1),
				     REG2(clk, reset, L2, W,   R,  S,  A2,  B2),
				     REG3(clk, reset, L3, W,   R,  S,  A3,  B3),
				     REG4(clk, reset, L4, W,   R,  S,  A4,  B4),
				     REG5(clk, reset, L5, W,   R,  S,  A5,  B5),
				     REG6(clk, reset, L6, W,   R,  S,  A6,  B6),
				     REG7(clk, reset, L7, W,   R,  S,  A7,  B7);
	

endmodule
