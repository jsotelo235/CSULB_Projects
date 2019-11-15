`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:39:43 03/22/2017 
// Design Name: 
// Module Name:    reg_file 
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
module reg_file(clk, reset, W_adr, we, R_adr, S_adr, W, R, S);

     input               clk, we, reset;
     input     [2:0]     W_adr;
     input     [2:0]     R_adr;
     input     [2:0]     S_adr;
     input     [15:0]    W;
     
     output    [15:0]    R, S;

     wire      [7:0]     w_out;
     wire      [7:0]     r_out;
     wire      [7:0]     s_out;

     //***********************************
     //   3-to-8 Decoder Instantiation
     //***********************************
     dec_3_to_8
               dec_1(.In(W_adr), .en(we),  .Y(w_out)), // Register's ld
               dec_2(.In(R_adr), .en(1'b1),.Y(r_out)), // Register's oea
               dec_3(.In(S_adr), .en(1'b1),.Y(s_out)); // Resgister's oeb
			  
     //***********************************
     //   16-bit Register Instantiation
     //***********************************
     
     //reg16 ( clk,          reset,           ld,        Din,      DA,       DB,         oeA,            oeB)
     reg16
          R0( .clk(clk), .reset(reset), .ld(w_out[0]), .Din(W) , .DA(R) , .DB(S) , .oeA(r_out[0]), .oeB(s_out[0])),
          R1( .clk(clk), .reset(reset), .ld(w_out[1]), .Din(W) , .DA(R) , .DB(S) , .oeA(r_out[1]), .oeB(s_out[1])),
          R2( .clk(clk), .reset(reset), .ld(w_out[2]), .Din(W) , .DA(R) , .DB(S) , .oeA(r_out[2]), .oeB(s_out[2])),
          R3( .clk(clk), .reset(reset), .ld(w_out[3]), .Din(W) , .DA(R) , .DB(S) , .oeA(r_out[3]), .oeB(s_out[3])),
          R4( .clk(clk), .reset(reset), .ld(w_out[4]), .Din(W) , .DA(R) , .DB(S) , .oeA(r_out[4]), .oeB(s_out[4])),
          R5( .clk(clk), .reset(reset), .ld(w_out[5]), .Din(W) , .DA(R) , .DB(S) , .oeA(r_out[5]), .oeB(s_out[5])),
          R6( .clk(clk), .reset(reset), .ld(w_out[6]), .Din(W) , .DA(R) , .DB(S) , .oeA(r_out[6]), .oeB(s_out[6])),
          R7( .clk(clk), .reset(reset), .ld(w_out[7]), .Din(W) , .DA(R) , .DB(S) , .oeA(r_out[7]), .oeB(s_out[7]));	

endmodule
