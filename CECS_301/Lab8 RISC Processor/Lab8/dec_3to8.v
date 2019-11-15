`timescale 1ns / 100ps
/************************************************************************
* File Name: dec_3to8.v
* Project: Lab Project 5 - Register Files
* Designer: Jarod Bamber & Jose Pacheco
* Email:	jarod.bamber@gmail.com / pacheco216@gmail.com
* Rev. Dates: Oct. 18, 2016 / Oct. 15, 2016
*
* Purpose: A simple 3 to 8 decoder with an enable. Takes a 3 bit binary 
* value and converts it to its decimal number output when enable is on.
* Otherwise all outputs stay 0.
* 
* Notes:
* 
************************************************************************/
module dec_3to8(Din, en, Dout);
	 
	 input [2:0] Din;
	 input en;
	 
	 output reg [7:0] Dout;
	 
	 always @(en, Din)
	 begin
		case ({en, Din})
			 4'b1000 : Dout = 8'b0000_0001;
			 4'b1001 : Dout = 8'b0000_0010;
			 4'b1010 : Dout = 8'b0000_0100;
			 4'b1011 : Dout = 8'b0000_1000;
			 4'b1100 : Dout = 8'b0001_0000;
			 4'b1101 : Dout = 8'b0010_0000;
			 4'b1110 : Dout = 8'b0100_0000;
			 4'b1111 : Dout = 8'b1000_0000;
          //When enable = 0, goes to default.
			 default : Dout = 8'b0000_0000;
		endcase
	end
endmodule
