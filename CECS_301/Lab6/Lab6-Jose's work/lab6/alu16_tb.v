`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:05:14 04/10/2017
// Design Name:   alu16
// Module Name:   D:/301/Lab6/Lab6-Jose's work/lab6/alu16_tb.v
// Project Name:  lab6
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: alu16
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module alu16_tb;

	// Inputs
	reg [15:0] R;
	reg [15:0] S;
	reg [3:0] Alu_Op;

	// Outputs
	wire [15:0] Y;
	wire N;
	wire Z;
	wire C;

	// Instantiate the Unit Under Test (UUT)
	alu16 uut (
		.R(R), 
		.S(S), 
		.Alu_Op(Alu_Op), 
		.Y(Y), 
		.N(N), 
		.Z(Z), 
		.C(C)
	);

	initial begin
     $timeformat (-9, 1, "ns", 6);
     
     // Initialize Inputs
     R = 0; S = 0; Alu_Op = 0;
     
     // Pass S OP
     #10 {R, S, Alu_Op} = ;
     
     // Pass R OP
     #10 {R, S, Alu_Op} = ;
     
     // Increment S OP
     #10 {R, S, Alu_Op} = ;
     
     // Decrement S OP
     #10 {R, S, Alu_OP} = 
     
     // Add R + S
     #10 {R, S, Alu_Op} = ;
     
     // Subtract R - S
     #10 {R, S, Alu_Op} = ;
     
     // Right shift S (logic)
     #10 {R, S, Alu_Op} = ;
     
     // Left shift S (logic)
     #10 {R, S, Alu_Op} = ;
     
     // Logic And Op
     #10 {R, S, Alu_Op} = ;
     
     // Logic Or Op
     #10 {R, S, Alu_Op} = ;
     
     // Logic XOR Op
     #10 {R, S, Alu_Op} = ;
     
     // Logic Not S (1's complement)
     #10 {R, S, Alu_Op} = ;
     
     // Negate S (2's complement)
     #10 {R, S, Alu_Op} = ;
     
     

	end
      
endmodule

