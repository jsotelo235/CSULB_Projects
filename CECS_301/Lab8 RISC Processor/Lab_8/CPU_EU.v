`timescale 1ns / 1ps
/****************************************************************************
* File Name:          CPU_EU.V
* Project:            Lab Project 8: RISC Processor
* Used by:            Houssem Eddin Loudhabachi and Jose Sotelo
* Email:              jsotelo235@gmail.com and hloudhabachi@gmail.com
* Rev. Date:          May 11, 2017
*
* Purpose:
* In computer engineering, an execution unit (also called a functional unit) 
* is a part of the central processing unit (CPU) that performs the operations 
* and calculations as instructed by the computer program.
*****************************************************************************/
module CPU_EU(clk, reset, w_en, W_Adr, R_Adr, S_Adr, ir_load,   
              pc_sel, s_sel, adr_sel, Address, pc_inc, pc_load, D_In,
              Alu_Out, Alu_Op, IR_Out, N, Z, C);

     input               clk, reset, w_en, s_sel, adr_sel, pc_sel;
     input               pc_inc, ir_load, pc_load;
     
     input     [2:0]     W_Adr, R_Adr, S_Adr;
     input     [3:0]     Alu_Op;
     input     [15:0]    D_In;
     
     output    [15:0]    Address, Alu_Out, IR_Out;
     output              N, Z, C;       
     
     wire      [15:0]    w_pc_mux_out,  
                         w_pc_out, 
                         w_reg_out, 
                         w_sign_ext, 
                         w_16_bit_add; 

     //*****************************************
     // Integer Datapath
     //*****************************************
     integer_datapath
          idp(
               .Clk(clk),           
               .Reset(reset),           
               .W_En(w_en),        
               .W_Adr(W_Adr),
               .S_Adr(S_Adr),       
               .R_Adr(R_Adr),           
               .DS(D_In),          
               .S_Sel(s_sel), 
               .ALU_OP(Alu_Op),     
               .Reg_Out(w_reg_out),     
               .Alu_Out(Alu_Out),  
               .N(N),    
               .Z(Z),               
               .C(C)
          );
               
     //*****************************************
     // PC Mux
     //*****************************************
     assign w_pc_mux_out = (pc_sel) ? Alu_Out : w_16_bit_add;

     //*****************************************
     // PC (Program Control)
     //*****************************************
     PC
          pc(
               .clk(clk),            
               .reset(reset),      
               .ld(pc_load),    
               .in(pc_inc), 
               .D(w_pc_mux_out),     
               .Q(w_pc_out)
          );

     //*****************************************
     // Adr_Mux
     //*****************************************
     assign Address = (adr_sel) ? w_reg_out : w_pc_out;
     
     //*****************************************
     // IR (Instruction Register)
     //*****************************************
     IR
          ir(
               .clk(clk), 
               .reset(reset), 
               .ld(ir_load), 
               .D(D_In), 
               .Q(IR_Out)
          );
     
     //*****************************************
     // Sign Extension
     // Copies the 7th biy of the IR output
     // 8 times for a signed 16 bit value
     //*****************************************
     assign w_sign_ext = {{8{IR_Out[7]}}, IR_Out[7:0]};
     
     //*****************************************
     // 16 bit Adder
     //*****************************************
     assign w_16_bit_add = w_pc_out + w_sign_ext;
          
endmodule
