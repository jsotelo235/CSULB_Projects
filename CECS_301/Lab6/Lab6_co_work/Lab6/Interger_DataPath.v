`timescale 1ns / 1ps
/*************************************************************************************
*    File Name:     Integer_DataPath.v
*    Project:       Lab Project 6: Integer Data Path
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:         jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Rev. Date:     April 6, 2017
*
*    Purpose:
*    The purpose of this module is to create Integer DataPath by instantiating
*    the register file, S-Mux, and the ALU16 modules.
*
*    The register file instance used in this module is used to write & read contents
*    into the register file. When writing to the register file, the 16-bit data input WR
*    will come from the output of the ALU. to write to an address in the register fiele
*    we used the 3-bit W_Adr inputs. 
*
*    To read the contents inside of the register file, we used the 4-bit R_Adr to read 
*    and output the contents of the most significant bits. The 4-bit S_Adr is used to read 
*    and output the contents of the least significant bits. 
*
*    The purpose for the S-Mux is to multiplexed two input data lines S and DS depending
*    on the data selector S_Sel. The first input to the S-Mux comes from the 16-bit S output
*    of the register file. The 16-bit DS input is hardwired to hex value "AA55". Depending
*    which data selector S_Sel is inputed, the output of the S-Mux will be either S or DS.
*
*    The inputs of the ALU16 module come from the R output of the register file and the 
*    output of the S-Mux. The purpose for the ALU16 is to perform arithmetic and logic
*    operations. It represents one of the fundamental building blocks of a CPU. In our
*    ALU16, it performs 13 arithmetic operations on 16-bit integers. To perform these
*    13 operations, the user must input which operation to use into the 4-bit Alu_Op
*    inputs. The operations are:
*
*    1)  Pass S
*    2)  Pass R
*    3)  Increment S
*    4)  Decrement S
*    5)  Add
*    6)  Subtract
*    7)  Right shift S
*    8)  Left shift S
*    9)  Logic And
*    10) Logic Or
*    11) Logic XOR
*    12) Logic not S (1's complement)
*    13) Negate S    (2's complement)
*    Default: Pass S
*    
*    The ALU status flags represent the result operation that took place by representing the 
*    Y output signifying if there was a carry (C), if it's zero (Z) or if its negative (N). 
*
*    Notes:
 ******************************************************************************************/
module Interger_DataPath(clk,      reset,    WE,  W_Adr,    R_Adr, S_Adr, S_Sel, DS, Alu_Op,
					Reg_Out,  Alu_Out,  N,   Z,        C);
                         
     input                    clk, reset, WE, S_Sel;
     input          [2:0]     W_Adr, R_Adr, S_Adr;
     input          [3:0]     Alu_Op;
     input          [15:0]    DS;
     
     output                   N, Z, C;
     output wire    [15:0]    Reg_Out, Alu_Out;

     wire           [15:0]    S_Wire, SM_Out;

     //********************************
     //   Register File Instantiation
     //********************************
     //			(clk, reset,   we,  W_adr,    R_adr,    S_adr,    W,        R,        S);
     Regfile regfile(clk,rest,     WE,  W_Adr,    R_Adr,    S_Adr,    Alu_Out,  Reg_Out,  S_Wire);
     
     //********************************
     //   S_Mux Instantiation
     //********************************
     //      ( S_Sel,    S_in,     DS,  S_out );
     S_MUX mux(S_Sel,    S_Wire,   DS,  SM_Out);

     //***************************************
     //   Arithmetic-Logic-Unit Instantiation
     //***************************************
     //           ( R,        S,        ALU_Op,   Y,        N,   Z,   C );
     ALU ArithLogUn(Reg_Out,  SM_Out,   Alu_Op,   Alu_Out,  N,   Z,   C);
endmodule
