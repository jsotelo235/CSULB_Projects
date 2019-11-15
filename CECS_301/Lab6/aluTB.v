`timescale 1ns / 1ps

/**************************************************************************
*    File Name:     aluTB.v
*    Project:       Lab Project 6: Integer Data Path
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     April 9, 2017
*
*
*    Purpose:		  Making a test that verifies each of the 13 ALU 
*						  operations. Each of the R and S inputs have unique
*                   and non-zero values depending to the to test vectors.
*						  The display of the result includes the output
*						  value of C if Carry, Z if the value is zero,
*						  and N if the value is negative.
*
*         
*    Notes:		
*
 **************************************************************************/

module aluTB;

	// Inputs
	reg [15:0] R;
	reg [15:0] S;
	reg [3:0] ALU_Op;

	// Outputs
	wire [15:0] Y;
	wire N;
	wire Z;
	wire C;

	// Instantiate the Unit Under Test (UUT)
	ALU uut (
		.R(R), 
		.S(S), 
		.ALU_Op(ALU_Op), 
		.Y(Y), 
		.N(N), 
		.Z(Z), 
		.C(C)
	);

	initial begin
		// Initialize Inputs
		$timeformat(-12, 1, " ns", 8);
		
		 R = 0;
		 S = 0;
		 ALU_Op = 0;

		
	
       ALU_Op=4'b0000;
		 R=16'h1001;
		 S=16'h0110;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 
		 ALU_Op=4'b0001;
		 R=16'h1AA1;
		 S=16'h0AA0;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);		 
		 ALU_Op=4'b0010;
		 S=16'hFFFF;
		 R=16'h0123;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 ALU_Op=4'b0011;
		 R=16'h4567;
		 S=Y;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 ALU_Op=4'b0100;
		 S=Y;
		 R=~Y;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 ALU_Op=4'b0101;
		 R=Y;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 ALU_Op=4'b0110;
		 S=16'hABCD;
		 R=~Y;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 ALU_Op=4'b0111;
		 S=16'hEF77;
		 R=16'h6969;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 ALU_Op=4'b1000;
		 S=16'h1010;
		 R=16'h0101;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 ALU_Op=4'b1001;
		 S=16'h7777;
		 R=16'h8888;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 ALU_Op=4'b1010;
		 R=16'hA001;
		 S=~Y;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 ALU_Op=4'b1011;
		 S=16'h0707;
		 R=~Y;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
		 ALU_Op=4'b1100;
		 S=~Y;
		 R=16'hABBA;
		 #10 $display("S=%h || R=%h  || ALU_Op= %h || Y=%h || C=%h, Z= %h, N=%h",
						   S,      R,       ALU_Op,       Y,      C,    Z,     N);
      $finish;
	end
      
endmodule

