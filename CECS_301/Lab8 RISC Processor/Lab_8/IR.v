`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:56:48 05/06/2017 
// Design Name: 
// Module Name:    IR 
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
module IR(clk, reset, ld, D, Q);

     input                    clk, reset, ld;
     input          [15:0]    D;
     
     output reg     [15:0]    Q;
     
     always @(posedge clk or posedge reset)
          if(reset == 1'b1)
               Q <= 16'b0;
          else
               case(ld)
                    1'b0      :    Q <= Q;
                    1'b1      :    Q <= D;
                    default   :    Q <= Q;
               endcase
endmodule
