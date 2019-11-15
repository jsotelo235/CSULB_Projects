`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:13:28 04/13/2018 
// Design Name: 
// Module Name:    Stop_Bit_Sel 
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
module Stop_Bit_Sel(d7, d8, d9, sel, mux_out);

     input               d7;
     input               d8;
     input               d9;
     
     input     [1:0]     sel;
     
     output              mux_out;
     
     reg                 mux_out;
     
     always @(*)
          case(sel)
               2'b00     :    mux_out <= d7;
               2'b01     :    mux_out <= d8;
               2'b10     :    mux_out <= d8;
               2'b11     :    mux_out <= d9;
               default   :    mux_out <= d7; 
          endcase

endmodule
