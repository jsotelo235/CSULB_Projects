`timescale 1ns / 100ps
/************************************************************************
* File Name: hex_to_7_seg.v
* Project: Lab Project 5 - Register Files
* Designer: Jarod Bamber
* Email:	jarod.bamber@gmail.com
* Rev. Date: Oct. 18, 2016
*
* Purpose: Takes a 4 bit set of binary data and outputs the corresponding
* hex symbol. Each letter (a-g) represents to notch of the 7 seg display
* and must be turned on and off depending on what hex symbol is supposed
* to be represented on the given anode.
* 
* Notes:
* 
************************************************************************/
module hex_to_7_seg(hex, a, b, c, d, e, f, g);

input [3:0] hex;
output reg a, b, c, d, e, f, g;

			always @(hex)
			case (hex)
				4'b0000: {a, b, c, d, e, f, g} = 7'b000_0001; // 0
				4'b0001: {a, b, c, d, e, f, g} = 7'b100_1111; // 1
				4'b0010: {a, b, c, d, e, f, g} = 7'b001_0010; // 2
				4'b0011: {a, b, c, d, e, f, g} = 7'b000_0110; // 3
				4'b0100: {a, b, c, d, e, f, g} = 7'b100_1100; // 4
				4'b0101: {a, b, c, d, e, f, g} = 7'b010_0100; // 5
				4'b0110: {a, b, c, d, e, f, g} = 7'b010_0000; // 6
				4'b0111: {a, b, c, d, e, f, g} = 7'b000_1111; // 7
				4'b1000: {a, b, c, d, e, f, g} = 7'b000_0000; // 8
				4'b1001: {a, b, c, d, e, f, g} = 7'b000_0100; // 9
				4'b1010: {a, b, c, d, e, f, g} = 7'b000_1000; // A
				4'b1011: {a, b, c, d, e, f, g} = 7'b110_0000; // B
				4'b1100: {a, b, c, d, e, f, g} = 7'b011_0001; // C
				4'b1101: {a, b, c, d, e, f, g} = 7'b100_0010; // D
				4'b1110: {a, b, c, d, e, f, g} = 7'b011_0000; // E
				4'b1111: {a, b, c, d, e, f, g} = 7'b011_1000; // F
				default: {a, b, c, d, e, f, g} = 7'b111_1111; // Display is off
			endcase
			
endmodule
