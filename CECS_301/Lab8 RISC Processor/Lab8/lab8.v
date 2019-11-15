`timescale 1ns / 100ps
/************************************************************************
* File Name: lab8.v
* Project: Lab Project 8: 16-bit RISC Processor
* Designer: Jarod Bamber & Jose Pacheco
* Email:	jarod.bamber@gmail.com / pacheco216@gmail.com
* Rev. Date: Nov. 15, 2016 / Nov. 27, 2016
*
* Purpose: Top level module for the 16-bit RISC Processor, including
* a clock divider, button debouncer, the RISC Processor, a 256x16 ram
* CoreGen unit filled with specific values used to test the RISC
* Processor, a memory counter, and a display controller to display the 
* address and data on the 7-seg display.
* 
* Notes:
* 
************************************************************************/
module lab8(clk, reset, step_clk, step_mem, dump_mem,
				status,
				an0, an1, an2, an3, an4, an5, an6, an7,
				a, b, c, d, e, f, g);
	
	input clk, reset, step_clk, step_mem, dump_mem;
	
	output an0, an1, an2, an3, an4, an5, an6, an7;
	output a, b, c, d, e, f, g;
	output [7:0] status;

	wire clk_out, mw_en, debounce;
	wire [15:0] madr, mem_counter, Address, mem_din, mem_dout;
	
	assign madr = (dump_mem == 1'b1) ? mem_counter : Address;
   
   //Divides the clock to the targeted speed of 500Hz
	clk_div		CLK_500HZ  (clk, reset, clk_out);
	
   //Debounces the push buttons used in the project
	debounce		STEP_CLK   (clk_out, reset, step_clk, debounce),	
					STEP_MEM   (clk_out, reset, step_mem, mem_debounce);
	
   //Wrapper module for the RISC Processor, containing the CPU_EU and CU
	RISC			RISC	  	  (debounce, reset, mw_en, Address, status,
								   mem_dout, mem_din);
	
   //256x16 RAM CoreGen module
   //Loaded with specific values used for testing purposes
	ram1			RAM_256x16 (clk_out, mw_en, madr, mem_din, mem_dout);
	
	//16-bit counter used to view the contents of memory
	addr_seqr	MEM_COUNT  (mem_debounce, reset, mem_counter);
	
   //Display Controller
   //Shows address on the left and data on the right
	display_controller  DISP_CONT (clk, reset, a, b, c, d, e, f, g,
											 an0, an1, an2, an3, an4, an5, an6, an7,
											 madr[15:12], madr[11:8], 
										    madr[7:4],   madr[3:0], 
                                  mem_dout[15:12],   mem_dout[11:8], 
                                  mem_dout[7:4],     mem_dout[3:0]);


endmodule
