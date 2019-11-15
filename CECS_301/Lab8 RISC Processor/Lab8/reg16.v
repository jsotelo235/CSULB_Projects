`timescale 1ns / 100ps
/************************************************************************
* File Name: reg16.v
* Project: Lab Project 5 - Register Files
* Designer: Jarod Bamber
* Email:	jarod.bamber@gmail.com
* Rev. Date: Oct. 18, 2016
*
* Purpose: A 16 bit register with two different outputs. Can store data in 
* DA and/or DB. Only loads if the ld signal is enabled on posedge of clk
* tick, and only outputs DA and/or DB if their respective output enable
* is on or not. Otherwise, if the output enable for DA or DB is off, the
* register will output all Z's for the respective output.
* 
* Notes:
* 
************************************************************************/
module reg16(clk, reset, ld, Din, DA, DB, oeA, oeB);
   input clk, reset, ld, oeA, oeB;
   input[15:0] Din;
   output[15:0] DA, DB;
   reg[15:0] Dout;
   
   //behavioral selection for writing to the register
   always @(posedge clk or posedge reset) 
      if (reset)
         Dout <=16'b0;
      else
         if (ld)
            Dout <= Din;
         else Dout <= Dout;
    
    //Conditional continuous assignment for reading the register
    assign DA = oeA ? Dout : 16'hz;
    assign DB = oeB ? Dout : 16'hz;
endmodule
