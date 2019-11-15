`timescale 1ns / 1ps
/*************************************************************************************
*    File Name:          CPU_EU.v
*    Project:            Lab Project 7: CPU Execution Unit
*    Used by Designers:  Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:              jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Accesed On:         April 21, 2017       
*
*    Purpose:
*    The purpose for this lab is to construct the CPU execution unit by
*    instantiating the integer datapath (IDP), 2 16-bit registers PC and 
*    IR and lastly, 16-bit 2-to-1 mux.
*
*    The integer datapath (IDP) contains the register file and 16-bit ALU.
*    The IDP is used to perform certain operations on data items.
*    Data moves between register to register and the ALU.
*    
*    The two main register are involved in fetching an instruction for
*    execution: the program counter (PC) and the instruction register
*    (IR). The PC is the register that contains the address of the next
*    instruction to be fetched. Then, the fetched instruction is placed
*    into memory which then its loaded in the IR for execution.
*
*    After the instruction is executed, the PC is updated to point to the
*    next instruction to be executed.
*    
*    The outputs of the CPU are to be stored in 256x16 Memory.
 **************************************************************************************/
module cpu_eu(clk, reset, adr_sel, s_sel, pc_ld, pc_inc, reg_w_en, ir_ld, DS, N, C, Z, Adress, D_out);
     
     
     input                    clk, reset;
     input                    adr_sel, s_sel, pc_ld, pc_inc, reg_w_en, ir_ld;
     input          [15:0]    DS;
          
     output                   N, Z, C;
     output        [15:0]    Adress, D_out;
     
     wire           [15:0]    w_reg_out, w_pc_out, w_ir_out, w_D_out;   
     
     
     
     //*****************************************
     // IDP
     // Integer Datapath
     //*****************************************
     integer_datapath
          idp(.Clk(clk),                .Reset(reset),           .W_En(reg_w_en),         .W_Adr(w_ir_out[8:6]),
              .S_Adr(w_ir_out[2:0]),    .R_Adr(w_ir_out[5:3]),   .DS(DS),                 .S_Sel(s_sel),
              .ALU_OP(w_ir_out[15:12]), .Reg_Out(w_reg_out),     .Alu_Out(w_D_out),        .N(N),
              .Z(Z),                    .C(C));
           
     //*****************************************
     // PC (Program Counter)
     //*****************************************
     pc
          PC(.clk(clk), .reset(reset), .ld(pc_ld), .in(pc_inc), .D(w_D_out), .Q(w_pc_out));

     //*****************************************
     // Adr_Mux
     // Conditional assignment statement
     //*****************************************
      assign Adress = (s_sel == 1'b0) ? w_reg_out : w_pc_out;
      
     //*****************************************
     // IR (Instructions Register)
     //*****************************************
     ir
          IR(.clk(clk), .reset(reset), .ld(ir_ld), .D(DS), .Q(w_ir_out));
endmodule
