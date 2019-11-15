`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:33:26 03/22/2017 
// Design Name: 
// Module Name:    pixel_clk 
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
module pixel_clk(clk_in, reset, clk_out);

     input     clk_in, reset;
     output    clk_out;
     reg       clk_out;
     integer   i;
     
     always @(posedge clk_in or posedge reset) begin
          if(reset == 1'b1) begin
               i = 0;
               clk_out = 0;
          end 
          else begin
               i = i + 1;
               if(i > 104167) begin
                    clk_out = ~clk_out;
                    i = 0;
               end
          end
       end
endmodule
