`timescale 1ns / 1ps
/***********************************************************************************************
*    File Name:          PC (Program Counter)
*    Project:            Lab Project 7: CPU Execution Unit
*    Used by Designers:  Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:              jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Accesed On:         April 22, 2017
*
*    Purpose:
*    The purpose for this module is create a 16 bit register behaviorally. We will use
*    this register to create the pc (Program Counter) needed to access the memory addresses
*    of the register file.
*
*    In detail, the program counter is a register in a computer processor that contains the 
*    addresses or locations of the instruction being executed at each clock cycle. Upon
*    fetching teh instruction, the program counter is incremented by one and points to the
*    next location of the next instruction.
 ****************************************************************************************************/
module Program_Counter(clk , reset, ld ,inc, D, Q);

	input                    clk, reset, ld, inc ; 
	input          [15:0]    D;
	output reg     [15:0]    Q;
     
	always @(posedge clk or posedge reset)
          if (reset)
               Q<=16'b0;
          else begin
               case({ld,inc})
                    2'b01     : Q <= Q+16'b1;
                    2'b10     : Q <= D;
                    default   : Q <= Q;
	endcase 
	end
endmodule
