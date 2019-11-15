`timescale 1ns / 1ps
/*************************************************************************************
*    File Name:     Lab6TopLevel.v
*    Project:       Lab Project 6: Integer Data Path
*    Designers:     Houssem Eddin Loudhabachi and Jose Sotelo
*    Email:         jsotelo235@gmail.com and hloudhabachi@gmail.com
*    Rev. Date:     April 6, 2017
*
*    Purpose:
*
*    Notes:
 ******************************************************************************************/
module lab6_top_module(clk, reset, step, sw, Anodes, a, b, c, d, e, f, g, C, N, Z);
     
     input               clk, reset, step;
     input     [15:0]    sw;
     
     output              C, N, Z;         
     output    [7:0]     Anodes;
     output              a, b, c, d, e, f, g;
     
     wire                w_oneshot_out;
     wire      [15:0]    w_reg_out, w_alu_out;
     
     //********************************
     //   Debounce Instantiation
     //********************************
     debounce
               oneshot(.clk_in(clk), .reset(reset), .D_in(step), .D_out(w_oneshot_out));

     //***********************************
     //   Integer DataPath Instantiation
     //***********************************
     integer_datapath
                    int_path(.Clk(w_oneshot_out),      .Reset(reset),           .W_En(1'b1),
                             .W_Adr(sw[6:4]),          .S_Adr(sw[12:10]),       .R_Adr(sw[15:13]),
                             .DS(16'hAA55),            .S_Sel(sw[8]),           .ALU_OP(sw[3:0]),
                             .Reg_Out(w_reg_out),      .Alu_Out(w_alu_out),     .C(C),
                             .N(N),                    .Z(Z));

     //***************************************
     //  Display Controller Instantiation
     //***************************************
     display_controller
                         disp_cont(.clk(clk),          .reset(reset),      .seg({w_reg_out, w_alu_out}),
                                   .anodes(Anodes),    .a(a),              .b(b), 
                                   .c(c),              .d(d),              .e(e), 
                                   .f(f),              .g(g));
endmodule
