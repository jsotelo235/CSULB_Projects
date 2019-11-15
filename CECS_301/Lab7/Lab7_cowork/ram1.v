`timescale 1ns / 1ps
/****************************************************************************
*    File Name:     Ram1
*    Project:       Lab Project 4: Memory & Display Controllers
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Emails:        jsotelo235@gmail.com and hloudhabachi@gmail.com 
*    Rev. Date:     March. 12, 2017
*
*    Purpose:
*    The purpose for this module is to store register location into
*    memory and retrieve that location to be displayed in the seven
*    segment display.
*
*    Create the RAM module by usingthe New Source Wizard and entering the
*    clk, we, addr, din inputs and the dout output.
*
*    To create this module, we used the Xilinx "Coregen IP" Core generator to genrate
*    a verilog Instantiation Template File that will be used in creating this module.
*    The instructions to create the RAM ar shown below.
* 
*    Using the Block Memory Generator in the Coregen dialog boxes fill in the field
*    shown:
*    Component Name:          ram_256x16
*    Interface Type:          Native
*    Memory Type:             Single Port RAM
*    Write and Read Width:    16
*    Write and Read Depth:    256
*    All other field are left unchange
*
*    Click on the Load Init File and browse the file ram_256x16_lab7.coe
*    giving by the instructor in the CD ROM.
*
*    After speciying the "Init File" click on the "Generate" button to generate
*    the RAM module with the initial values.        
*    Be patient, the CoreGen take some time to generate the RAM core.
*
*    Click on the View HDL Instantiation in the process CORE Generator in Xilinx.
*    Copy the Instantiation Template File created by the CORE Generator
*    (ram_256x16.veo). This files contain the codethat is used to instantiate
*    the RAM module into your project.
*
*    Make sure you change the instance name and your parameters according to the
*    definitions made for the ram1 module.   
*     
*    The mapping of the RAM address inputs addr[15:0] and data outputs dout[15:0]
*    to the 7-segement display is describe in the ad_mux module.
*
*    Note:
*    The clk of the RAM is to be clocked by the 100MHz of the Nexys4 board.
 ****************************************************************************/
module ram1(
    input clk,
    input we,
    input [15:0] addr,
    input [15:0] din,
    output [15:0] dout
    );
    
    ram_256x16 dut (
     .clka(clk),
     .wea(we),
     .addra(addr),  // input  [15 : 0] addra
     .dina(din),    // input  [15 : 0] dina
     .douta(dout)   // output [15 : 0] douta
);
endmodule
