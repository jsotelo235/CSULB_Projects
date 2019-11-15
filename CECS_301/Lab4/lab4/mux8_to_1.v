`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:16:41 03/07/2017 
// Design Name: 
// Module Name:    mux8_to_1 
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
module mux8_to_1(select, d, q);
     
     input     [1:0]     select;
     input     [7:0]     d;
     
     output              q;
     
     reg                 q;
     
     wire      [1:0]     w_select;      //wires for the selectors
     wire      [7:0]     w_d;           //wires for the d inputs
     
     always @(select or d)
     begin
          case(select)
               3'b000 : q = d[0];
               3'b001 : q = d[1];
               3'b010 : q = d[2];
               3'b011 : q = d[3];
               3'b100 : q = d[4];
               3'b101 : q = d[5];
               3'b110 : q = d[6];
               3'b111 : q = d[7];
          endcase
     end
endmodule
