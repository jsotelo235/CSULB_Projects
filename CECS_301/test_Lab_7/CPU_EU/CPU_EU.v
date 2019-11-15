`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:29:11 04/27/2017 
// Design Name: 
// Module Name:    CPU_EU 
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
module CPU_EU(clk, reset, adr_sel, s_sel, pc_ld, pc_inc, reg_we, ir_ld, DS, Alu_Out, Address, N, Z, C);

     input               clk, reset, adr_sel, s_sel, pc_ld, pc_inc, reg_we, ir_ld;
     input     [15:0]    DS;
     
     output    [15:0]    Alu_Out, Address;
     output              N, Z, C;
     
     wire      [15:0]    w_pc_out, w_ir_out, w_reg_out, Alu_Out;
     
     
     //********************************
     //   Integer Datapath
     //********************************
     integer_datapath
          idp(.Clk(clk),                    .Reset(reset),           .W_En(reg_we),       .W_Adr(w_ir_out[8:6]),
              .S_Adr(w_ir_out[2:0]),        .R_Adr(w_ir_out[5:3]),   .DS(DS),             .S_Sel(s_sel),
              .ALU_OP(w_ir_out[15:12]),     .Reg_Out(w_reg_out),     .Alu_Out(Alu_Out),   .N(N),
              .Z(Z),                        .C(C));
     
     //********************************
     //   Program Control
     //******************************** 
     PC
          pc(.clk(clk), .reset(reset), .ld(pc_ld), .in(pc_inc), .D(Alu_Out), .Q(w_pc_out));
          
     //********************************
     //   Assign 16-bit Mux
     //********************************
     assign Address = adr_sel ? w_reg_out : w_pc_out;

     //********************************
     //   Instruction Register
     //******************************** 
     IR
          ir(.clk(clk), .reset(reset), .ld(ir_ld), .D(DS), .Q(w_ir_out));

endmodule
