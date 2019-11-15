`timescale 1ns / 100ps
/************************************************************************
* File Name: cpu_eu.v
* Project: Lab Project 8: 16-bit RISC Processor
* Designer: Jarod Bamber & Jose Pacheco
* Email:	jarod.bamber@gmail.com / pacheco216@gmail.com
* Rev. Date: Nov. 15, 2016 / Nov. 27, 2016
*
* Purpose: Wrapper module for the IDP, a PC, an IR, as well as
* four conditional statements. Able to preform operations
* when data is input through the ram. Also has 3 bits (1 each)
* representing Negative, Zero, and Carry.
*  
* 
* Notes:
* 
************************************************************************/
module cpu_eu(clk, reset, we, W_Adr, R_Adr, S_Adr,
				  IR_out, IR_load, pc_sel, s_sel, ad_sel,
				  Address, pc_inc, pc_load, N, Z, C, D_in, 
				  D_out, alu_op);
	
	input clk, reset, we, s_sel, ad_sel, pc_sel;
	input pc_inc, IR_load, pc_load;
	input [2:0] W_Adr, R_Adr, S_Adr;
	input [3:0] alu_op;
	input [15:0] D_in;
	
	output N, Z, C;
	output [15:0] Address, D_out, IR_out;
	
	wire [15:0] pc_in, pc_out, reg_out, sign_ext, pc_add;
   
	
	//MUX that switches between the adder and alu data
	assign pc_in = (pc_sel == 1'b1) ? D_out : pc_add;
	
	//MUX that switches between the IDP registers and the PC
	assign Address = (ad_sel == 1'b1) ? reg_out : pc_out;
	
	//Replicates 7th bit of IR output eight times for a signed 16 bit value
	assign sign_ext = {{8{IR_out[7]}}, IR_out[7:0]};
	
	//Adds pc_out and sign extension
	assign pc_add = pc_out + sign_ext;
	
   //IDP where all of the calculating and immediate storage are handled
   //Able to preform operations based on the ALU_OP specified by the IR
	int_data_path 	IDP (clk, reset, we, W_Adr, R_Adr, S_Adr, D_in, s_sel, 
							  alu_op, N, Z, C, reg_out, D_out); //Changes alu_out to D_out
	
   //The PC used to access address
	pc			 PRGM_CNT (clk, reset, pc_load, pc_inc, pc_in, pc_out);

	//The IR which gives instructions to the IDP, based on the data input
   //Can not be incremented.
	pc 		 INST_REG (clk, reset, IR_load, ir_inc, D_in, IR_out);

endmodule
