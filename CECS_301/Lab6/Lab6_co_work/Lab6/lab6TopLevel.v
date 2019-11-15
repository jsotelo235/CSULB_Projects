`timescale 1ns / 1ps
/*************************************************************************************
*    File Name:     Lab6TopLevel.v
*    Project:       Lab Project 6: Integer Data Path
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:         jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Rev. Date:     April 9, 2017
*
*    Purpose:
*    The purpose for this top module is to instantiate the debounce one-shot, the integer
*    datapath, and the display controller modules.
*
*    For this lab, the reset button comes from the FPGA board's button up and the clock
*    to the register file comes from debounced button down. 
*
*    The clock input to the integer datapath module comes from the debounced clock output.
*    The write enable to the register file is to be asserted by connecting it to logic level
*    "1". The inputs to W_Adr come froms the FPGA board's slide switches 6-4. The inputs to
*    the R_Adr come from the board's 15-13 switches.
*
*    The S_Adr inputs also come from the board's slide switches 12-10. The inputs the Alu_Op
*    will come from the silde switches 3-0. Lastly, the input the data selector S_Sel come
*    from the slide switch 8.
*
*    The contents of the Reg_Out data port depends solely on the R_Adr inputs. The output of
*    the Alu_Out data port depends on the S_Adr, S_Sel and Alu_Op inputs.
*
*    The hexadecimal values on outputs Reg_Out and Alu_Out are to be displayed on the
*    multiplexed 7-segmenent LED display. Reg_Out displays the four most significant
*    digits, while the Alu_Out side displays the four least signigicant digits.
*
*    Notes:
*    Slide switches 9 and 7 are not used.
 ******************************************************************************************/
module lab6TopLevel(clk, reset, Btn_Down, SW, N, Z, C, Anodes, a,b,c,d,e,f,g);

     input          clk,reset,Btn_Down;
	input   [15:0] SW;
     
	output         N, Z, C, a, b, c, d, e, f, g;
	output  [7:0]  Anodes;
	
	wire           debounced_btn;
	wire [15:0]    Reg_out,Alu_Out;
     
	
     //********************************
     //   Debounce Instantiation
     //********************************	
	debounce
               deb( clk, reset, Btn_Down, debounced_btn );

     //***********************************
     //   Integer DataPath Instantiation
     //***********************************	
                              //(clk,        reset,      WE,          W_Adr,           R_Adr
	Interger_DataPath IDP(debounced_btn,    reset,    1'b1,          SW[6:4],       SW[15:13],
     
	//                       S_Adr,         S_Sel,      DS,          Alu_Op,
                           SW[12:10],        SW[8],    16'hAA55,      SW[3:0],
                           
	//                    Reg_Out,          Alu_Out,       N,             Z,        C
                           Reg_out,          Alu_Out,       N,             Z,        C);
	
     //***************************************
     //  Display Controller Instantiation
     //***************************************			
	display_controller 
                         display(clk, reset, {Reg_out,Alu_Out}, Anodes, a, b, c, d, e, f, g);
endmodule
