`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:45:52 04/19/2017 
// Design Name: 
// Module Name:    reg16_bit 
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
module reg16_bit(clk, reset, ld, in, Q, D);

     input                    clk, reset;
     input                    ld, in;
     
     output reg     [15:0]    Q, D;
     
     always @(posedge clk or posedge reset)
          begin
          if(reset == 1'b1)
               Q <= 16'b0;
          else
               case({ld,in})
                    2'b01     :    Q <= Q + 16'b1;
                    2'b10     :    Q <= D;
                    default   :    Q <= Q;
               endcase
          end
endmodule
