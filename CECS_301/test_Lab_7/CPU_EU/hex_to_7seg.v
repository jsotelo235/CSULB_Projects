`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:08:02 04/27/2017 
// Design Name: 
// Module Name:    hex_to_7seg 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module hex_to_7seg(hexadecimal,a,b,c,d,e,f,g);

     // input declarations
     input[3:0] hexadecimal;

     // output declarations: 7 segment display
     output reg a,b,c,d,e,f,g;
     
     // switch case within an always block to select the logic for the 7 segment
     always @(hexadecimal)
          case (hexadecimal)
			4'b0000: {a,b,c,d,e,f,g} = 7'b0000001;
			4'b0001: {a,b,c,d,e,f,g} = 7'b1001111;
			4'b0010: {a,b,c,d,e,f,g} = 7'b0010010;
			4'b0011: {a,b,c,d,e,f,g} = 7'b0000110;
			4'b0100: {a,b,c,d,e,f,g} = 7'b1001100;
			4'b0101: {a,b,c,d,e,f,g} = 7'b0100100;
			4'b0110: {a,b,c,d,e,f,g} = 7'b0100000;
			4'b0111: {a,b,c,d,e,f,g} = 7'b0001111;
			4'b1000: {a,b,c,d,e,f,g} = 7'b0000000;
			4'b1001: {a,b,c,d,e,f,g} = 7'b0000100;
			4'b1010: {a,b,c,d,e,f,g} = 7'b0001000;
			4'b1011: {a,b,c,d,e,f,g} = 7'b1100000;
			4'b1100: {a,b,c,d,e,f,g} = 7'b0110001;
			4'b1101: {a,b,c,d,e,f,g} = 7'b1000010;
			4'b1110: {a,b,c,d,e,f,g} = 7'b0110000;
			4'b1111: {a,b,c,d,e,f,g} = 7'b0111000;
			default: {a,b,c,d,e,f,g} = 7'b1111111;
		endcase
endmodule
