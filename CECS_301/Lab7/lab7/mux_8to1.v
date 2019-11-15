`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:37:24 04/22/2017 
// Design Name: 
// Module Name:    mux_8to1 
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
module mux_8to1(sel, d, mux_out);

     input          [31:0]    d;     
     input          [2:0]     sel;
     
     output reg     [3:0]     mux_out; 
          
     always @(d or sel)
     begin
          case(sel)
               3'b000 : mux_out = d[3:0];
               3'b001 : mux_out = d[7:4];
               3'b010 : mux_out = d[11:8];
               3'b011 : mux_out = d[15:12];
               3'b100 : mux_out = d[19:16];
               3'b101 : mux_out = d[23:20];
               3'b110 : mux_out = d[27:24];
               3'b111 : mux_out = d[31:28];
               default: mux_out = 4'b0000;
          endcase
     end
endmodule
