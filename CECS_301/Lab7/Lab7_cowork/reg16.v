`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     Reg16.v
*    Project:       Lab Project 7: CPU Excecution unit
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     April. 19, 2017
*
*    Purpose:
*    The purpose for this module is to create a 16 bit register file 
*    that will be used to read and write data.
*
*    The clock for the register file comes from the FPGA board's 100MHz fre-
*    quency. The reset will come from debounce button Btn_Up.
*    
*    Both outputs ports of the 16-bit register module have tri-state outputs
*    that are controlled by the respective output enable (oeA and oeB).
*
*    Tri-state output means that the output ports will assume a high impedance
*    state in addition to the logic high or low states, effectively removing
*    the output from the circuit.
 ****************************************************************************/
module reg16(clk, reset, ld, Din, DA, DB, oeA, oeB);

     // IO Declarations
	input               clk, reset, ld, oeA, oeB;
	input     [15:0]    Din;
     
	output    [15:0]    DA, DB;
	reg       [15:0]    Dout;
	
	// behavioral section for writing to the register
	always @(posedge clk or posedge reset)
		if (reset) begin
			Dout <= 16'b0;
		end
		else begin
			if (ld) begin
				Dout <= Din;
			end
			else begin
				Dout <= Dout;
			end
		end
	
	// conditional continuous assignments for reading the register
	assign DA = oeA ? Dout : 16'hz;
	assign DB = oeB ? Dout : 16'hz;
endmodule
