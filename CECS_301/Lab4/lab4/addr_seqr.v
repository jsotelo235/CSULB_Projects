`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:46:15 03/11/2017 
// Design Name: 
// Module Name:    addr_seqr 
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
module addr_seqr(clk, reset, addr);

     input               clk, reset;
     
     output    [7:0]     addr;
     
     reg       [7:0]     addr;     
          
     always @(posedge clk or posedge reset)
          if(reset) begin
               addr <= 8'b00;
          end else begin
               addr <= addr + 8'b01;
          end
endmodule
