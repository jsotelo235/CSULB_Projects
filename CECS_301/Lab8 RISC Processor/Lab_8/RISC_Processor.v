`timescale 1ns / 1ps
/****************************************************************************
* File Name:          RISC_Processor.V
* Project:            Lab Project 8: RISC Processor
* Used by:            Houssem Eddin Loudhabachi and Jose Sotelo
* Email:              jsotelo235@gmail.com and hloudhabachi@gmail.com
* Rev. Date:          May 11, 2017
*
* Purpose:
* This module's function is to instantiate the system's CPU Execution Unit
* (CPU-EU) via the interconnection of five components; the IDP, the Program 
* Counter, the Instruction Register, an Address Multiplexer, and the 256x16 Ram 
* module. The instruction register holds sixteen bit control words and passes 
* them into the IDP. The program counter's input is the data output from the 
* IDP, and the address mux switches between this sixteen bit output, and the 
* register output from the IDP. The output from the address multiplexer becomes 
* the address input to the ram module, the data output from the ALU becomes 
* the data input to the ram, and the ram's output gets stored in the 
* instruction register.
*****************************************************************************/
module RISC_Processor(clk, reset, D_in, mw_en, status, Address, D_out);

     input               clk, reset;
     input     [15:0]    D_in;
     
     output              mw_en;
     output    [7:0]     status;
     output    [15:0]    Address,   D_out;
     
     wire                N, Z, C;
     wire                w_rw_en, 
                         w_s_sel, 
                         w_adr_sel, 
                         w_ir_ld, 
                         w_pc_ld, 
                         w_pc_inc, 
                         w_pc_sel;
     
     wire      [2:0]     w_W_Adr, w_R_Adr, w_S_Adr;
     wire      [3:0]     w_Alu_Op;
     wire      [15:0]    w_IR_out, w_D_in;
          
     //*****************************************
     // CPU_EU
     //*****************************************
     CPU_EU
          cpu_eu(
               .clk(clk),             
               .reset(reset),           
               .w_en(w_rw_en),       
               .W_Adr(w_W_Adr),     
               .R_Adr(w_R_Adr),       
               .S_Adr(w_S_Adr),         
               .ir_load(w_ir_ld),  
               .pc_sel(w_pc_sel),     
               .s_sel(w_s_sel),       
               .adr_sel(w_adr_sel),     
               .Address(Address),  
               .pc_inc(w_pc_inc),     
               .pc_load(w_pc_ld),     
               .D_In(w_D_in),           
               .Alu_Out(D_out),    
               .Alu_Op(w_Alu_Op),   
               .IR_Out(w_IR_out),     
               .N(N),                   
               .Z(Z),              
               .C(C)
          );  
                      
     //*****************************************
     // CU (Control Unit)
     //*****************************************
      CU
          control_unit(
               .clk(clk),            
               .reset(reset),      
               .IR(w_IR_out),      
               .N(N),     
               .Z(Z),   
               .C(C),          
               .W_Adr(w_W_Adr),      
               .R_Adr(w_R_Adr),    
               .S_Adr(S_Adr),
               .adr_sel(w_adr_sel),  
               .s_sel(w_s_sel),
               .pc_ld(w_pc_ld),      
               .pc_inc(w_pc_inc),  
               .pc_sel(w_pc_sel),  
               .ir_ld(w_ir_ld),
               .mw_en(mw_en),        
               .rw_en(w_rw_en),    
               .alu_op(w_Alu_Op),  
               .status(status)
          );
endmodule
