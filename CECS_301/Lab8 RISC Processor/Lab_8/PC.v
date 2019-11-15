`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:40:50 05/05/2017 
// Design Name: 
// Module Name:    PC 
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
module PC(clk, reset, ld, in, D, Q);

     input                    clk, reset, ld, in;
     input          [15:0]    D;
     
     output reg     [15:0]    Q;
     
     always @(posedge clk or posedge reset)
          if(reset == 1'b1)
               Q <= 16'b0;
          else
               case({ld,in})
                    2'b01     :    Q <= Q + 16'b1;     // in is enabled
                    2'b10     :    Q <= D;             // ld is enabled
                    default   :    Q <= Q;             // Default: pass Q
               endcase
endmodule
