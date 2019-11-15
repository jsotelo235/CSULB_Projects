`timescale 1ns / 1ps
/************************************************************************
* File Name: RISC.v
* Project: Lab Project 8: 16-bit RISC Processor
* Designer: Jose Pacheco
* Email:	pacheco216@gmail.com
* Rev. Date: Nov. 27, 2016
*
* Purpose: Wrapper module for the RISC containing the cpu_eu and the 
* control unit.
* 
* Notes: 
* 
************************************************************************/
module RISC(clk, reset, mw_en, Address, status, D_in, D_out);

	input clk, reset;
	input [15:0] D_in;
	
	output        mw_en;
	output [7:0]  status;
	output [15:0] Address, D_out;
	
	wire N, Z, C, rw_en, ad_sel, s_sel, pc_sel, pc_inc, pc_load;
	wire [2:0] W_Adr, R_Adr, S_Adr;
	wire [3:0] alu_op;
	wire [15:0] mem_din, mem_dout, IR_out;

	cpu_eu  CPU_EU  (clk, reset, rw_en, W_Adr, R_Adr, S_Adr, IR_out,
						  IR_load, pc_sel, s_sel, ad_sel, Address, pc_inc,
						  pc_load, N, Z, C, D_in, D_out, alu_op);
						 
	cu	   CTRL_UNIT (clk, reset, IR_out, N, Z, C, W_Adr, R_Adr, S_Adr,
						  ad_sel, s_sel, pc_load, pc_inc, pc_sel, IR_load,
						  mw_en, rw_en, alu_op, status);
						 

endmodule
