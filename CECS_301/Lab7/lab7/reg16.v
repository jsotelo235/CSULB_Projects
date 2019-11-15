`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:12:44 04/18/2017 
// Design Name: 
// Module Name:    reg16 
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
module reg16(clk, reset, ld, Din, DA, DB, oeA, oeB);

     input               clk, reset, ld, oeA, oeB;
     input     [15:0]    Din;
     
     output    [15:0]    DA, DB;
     
     reg       [15:0]    Dout;
     
     //behavioral section for writing to the register
     always @(posedge clk or posedge reset)
          if(reset)
               Dout <= 16'b0;
          else
               if(ld)
                    Dout <= Din;
               else
                    Dout <= Dout;
                    
          //conditional continuous assignment for reading the register
          assign DA = oeA ? Dout   :    16'hz;
          assign DB = oeB ? Dout   :    16'hz;
endmodule
