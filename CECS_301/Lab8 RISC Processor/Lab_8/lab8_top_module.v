`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:44:38 05/07/2017 
// Design Name: 
// Module Name:    lab8_top_module 
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
module lab8_top_module(clk100MHz,  reset,    step_clk, step_mem, dump_mem, status, 
                       anodes,     a,        b,        c,        d,        e,       
                       f,          g);

     input               clk100MHz, reset, step_clk, step_mem, dump_mem;
     
     output    [7:0]     anodes, status;
     output              a, b, c, d, e, f, g;
     
     wire                w_clk_div, w_step_clk, w_step_mem, w_mw_en;
     wire      [15:0]    madr, w_mem_counter, w_Address_out, w_d_in, w_d_out; 
     
     //*****************************************
     // Clock Divider
     //*****************************************
     clk_div
               clk_div(.clk_in(clk100MHz), .reset(reset), .clk_out(w_clk_div));
         
     //*****************************************
     // Debounce One Shot
     //*****************************************
     one_shot
               step_clk_db(.clk_in(w_clk_div), .reset(reset), .D_in(step_clk), .D_out(w_step_clk)),
               step_mem_db(.clk_in(w_clk_div), .reset(reset), .D_in(step_mem), .D_out(w_step_mem));
               
     //*****************************************
     // RISC Processor
     //*****************************************
     RISC_Processor
               RISC(.clk(w_step_clk),    .reset(reset),               .D_in(w_d_out),      .mw_en(w_mw_en), 
                    .status(status),     .Address(w_Address_out),     .D_out(w_d_in));
                              
     //*****************************************
     // RAM
     //*****************************************
     ramA
          rama(.clk(clk100MHz), .we(w_mw_en), .addr(madr[7:0]), .din(w_d_out), .dout(w_d_in));

     //*****************************************
     // 16 bit Memory Counter Register
     //*****************************************  
     mem_counter
               memory_counter(.clk(w_step_mem), .reset(reset), .addr(w_mem_counter));

     //*****************************************
     // Mem Dump Mux Counter
     //*****************************************
      assign madr = dump_mem  ? w_mem_counter : w_Address_out;
     
     //*****************************************
     // Display Controller
     //*****************************************
     display_controller
               display(.clk(clk),  .reset(reset), .seg({madr, w_d_out}),   .anodes(anodes), 
                       .a(a),      .b(b),         .c(c),                   .d(d), 
                       .e(e),      .f(f),         .g(g));
endmodule
