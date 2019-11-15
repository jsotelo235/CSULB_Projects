`timescale 1ns / 1ps
/*************************************************************************************
*    File Name:          CPU_EU.v
*    Project:            Lab Project 7: CPU Execution Unit
*    Used by Designers:  Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:              jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Accesed On:         April 22, 2017       
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
module CPU_EU(step_clk,  reset,    adr_sel,  s_sel,    pc_ld,    pc_inc,   
              reg_we,    ir_ld,    DS,       ALU_Out,  Address,  N,        Z,        C );

					  
     input               step_clk, reset, adr_sel, s_sel, pc_ld, pc_inc, reg_we, ir_ld;
     input     [15:0]    DS;
     
     output              N, Z, C;
     output    [15:0]    ALU_Out, Address;
     
     wire      [15:0]    IR_Out, PC_Out, Reg_Out, ALU_Out;
     
          
     //*****************************************
     // IR (Instructions Register)
     //*****************************************
     Instruction_register 
                         IR(step_clk,reset,ir_ld,DS,IR_Out);
                         
     //*****************************************
     // IDP
     // Integer Datapath
     //*****************************************
     Interger_DataPath
     //                        clk,          reset,    WE,       W_Adr,              R_Adr,     
                      datapath(step_clk,     reset,    reg_we,   IR_Out[8:6],        IR_Out[5:3],
     //                        S_Adr,        S_Sel,    DS,       Alu_Op,             Reg_Out, 
                               IR_Out[2:0],  s_sel,    DS,       IR_Out[15:12],      Reg_Out,
     //                        Alu_Out,      N,        Z,        C
                               ALU_Out,      N,        Z,        C);
                               
     Program_Counter
     //                 clk,       reset,    ld,       inc,
                     PC(step_clk,  reset,    pc_ld,    pc_inc,
     //                 D,         Q
                        ALU_Out,   PC_Out);

     //*****************************************
     // Adr_Mux
     // Conditional assignment statement
     //*****************************************
     assign Address = adr_sel? Reg_Out: PC_Out;
endmodule
