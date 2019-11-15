`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:59:29 04/27/2017 
// Design Name: 
// Module Name:    dec_3to8 
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
module dec_3to8(In , en, Y);

      // Input declarations
     input     [2:0]     In;
     input               en;
     
     // Output declarations
     output    [7:0]     Y;
     
     // assigning decoder output
     assign Y = ({en,In} ==    4'b1000) ? 8'b0000_0001:
                ({en,In} ==    4'b1001) ? 8'b0000_0010:
			 ({en,In} ==    4'b1010) ? 8'b0000_0100:
			 ({en,In} ==    4'b1011) ? 8'b0000_1000:
			 ({en,In} ==    4'b1100) ? 8'b0001_0000:
			 ({en,In} ==    4'b1101) ? 8'b0010_0000:
			 ({en,In} ==    4'b1110) ? 8'b0100_0000:
			 ({en,In} ==    4'b1111) ? 8'b1000_0000:
                                          8'b0000_0000;
endmodule
