`timescale 1ns / 100ps
/************************************************************************
* File Name: int_data_path.v
* Project: Lab Project 6 - Integer Datapath
* Designer: Jarod Bamber & Jose Pacheco
* Email:	jarod.bamber@gmail.com / pacheco216@gmail.com
* Rev. Date: Nov. 1, 2016 / Oct. 31, 2016
*
* Purpose: Wrapper module for the 8x16 register, the alu, and a simple
* mux (in the form of a conditional statement). Handles all the 
* storing and calculating. Contains 3 bits for Negative, Zero, and Carry
* 
* 
* 
* Notes:
* 
************************************************************************/
module int_data_path(clk, reset, we, W_Adr, R_Adr, S_Adr, DS, s_sel, alu_op, 
							N, Z, C, reg_out, WR);
	input clk, reset, we, s_sel;
	input [15:0] DS;
	input [2:0] W_Adr, R_Adr, S_Adr;
	input [3:0] alu_op;
	
	wire [15:0] s_out;
	wire [15:0] s_in;
	output [15:0] reg_out;
	output [15:0] WR;
	output N, Z, C;
	
   //Mux (conditional) statement
   //Loads in DS if s_sel is 1
	assign s_out = (s_sel == 1'b0) ? s_in : DS;
	
   //8x16 reigster file
   //Contains all the registers and how they intereact between eachother
	register_file  REG_FILE (clk, reset, we, W_Adr, R_Adr, S_Adr, WR, reg_out, s_in);
   
   //ALU with multiple functions (show in detail on ALU module)
   //Stores data in the registers
	alu	ALU (reg_out, s_out, alu_op, WR, N, Z, C);

endmodule
