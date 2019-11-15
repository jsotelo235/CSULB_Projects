`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:23:24 04/27/2017 
// Design Name: 
// Module Name:    integer_datapath 
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
module integer_datapath(Clk, Reset, W_En, W_Adr, S_Adr, R_Adr, DS, S_Sel, ALU_OP, Reg_Out, Alu_Out, N, Z, C);

     input                    Clk, Reset, W_En, S_Sel;
     input          [2:0]     W_Adr, S_Adr, R_Adr;
     input          [15:0]    DS;
     input          [3:0]     ALU_OP;
     

     output wire    [15:0]    Alu_Out, Reg_Out;
     output                   N, Z, C;
     
     wire           [15:0]    w_smux_in, w_smux_out;    

     //********************************
     //   Register File Instantiation
     //********************************
     reg_file
               Reg_File(.clk(Clk),           .reset(Reset),      .W_adr(W_Adr),      .we(W_En),
                        .R_adr(R_Adr),       .S_adr(S_Adr),      .W(Alu_Out),        .R(Reg_Out),
                        .S(w_smux_in));
                         
     //*****************************************
     // S_Mux
     // Conditional assignment statement
     // Loads in DS if S_Sel is 1
     //*****************************************
     assign w_smux_out = (S_Sel == 1'b0) ? w_smux_in : DS;

     //***************************************
     //   Arithmetic-Logic-Unit Instantiation
     //***************************************
     ALU                                                                    //WR
               alu(.R(Reg_Out),    .S(w_smux_out),    .Alu_Op(ALU_OP),    .Y(Alu_Out),
                   .N(N),          .Z(Z),             .C(C));
              
endmodule
