`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:02:45 03/07/2017 
// Design Name: 
// Module Name:    ad_mux 
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
module ad_mux(d7, d6, d5, d4, d3, d2, d1, d0, sel, y);

     input     [15:0]     d7, d6, d5, d4, d3, d2, d1, d0;
     input     [2:0]     sel;
     output    [3:0]     y;
     
     reg       [3:0]     y;
     
     
     always @(sel)
     begin
          case(sel)
               3'b000 : y = d0[3:0];
               3'b001 : y = d1[7:4];
               3'b010 : y = d2[11:8];
               3'b011 : y = d3[15:12];
               3'b100 : y = d4[3:0];
               3'b101 : y = d5[7:4];
               3'b110 : y = 4'b0000;
               3'b111 : y = 4'b0000;
          endcase
     end
endmodule
