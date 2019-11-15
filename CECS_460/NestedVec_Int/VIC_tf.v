`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:46:03 03/18/2018
// Design Name:   TryIt3_tf
// Module Name:   C:/Users/tramel/Desktop/TryIt/TryIt/VIC_tf.v
// Project Name:  TryIt
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: VIC
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module VIC_tf;

        // Inputs
        reg clk;
        reg rst;
        reg cs;
        reg [15:0] datain;
        reg [4:0] port_id;
        reg read_strobe;
        reg write_strobe;
        reg [15:0] interrupts;
        reg IntAck;
	     reg [15:0] dback;

        // Outputs
        wire [15:0] dout;
        wire InterruptOut;

   // data types
        integer i;
        
        // Instantiate the Unit Under Test (UUT)
        VIC uut (
                .clk(clk), 
                .rst(rst), 
                .cs(cs), 
                .datain(datain), 
                .port_id(port_id), 
                .read_strobe(read_strobe), 
                .write_strobe(write_strobe), 
                .dout(dout), 
                .interrupts(interrupts), 
                .IntAck(IntAck), 
                .InterruptOut(InterruptOut)
        );

   always #5 clk = ~clk;

        initial 
           begin
           // Initialize Inputs
           clk = 0;
           rst = 1;
           cs = 0;
           datain = 0;
           port_id = 0;
           read_strobe = 0;
           write_strobe = 0;
           interrupts = 0;
           IntAck = 0;

           // Wait 100 ns for global reset to finish
           #100 rst = 0;
        
           // Write the Interrupt Address Vectors
           for(i=0; i<16; i=i+1)
              begin
              repeat (5) @(posedge clk) ;
	           DoWrite(i+100,i[4:0]+16);
				  $displayh(i+100);
              end
	      
           // Read the Interrupt Address Vectors
           for(i=0; i<16; i=i+1)
              begin
              repeat (5) @(posedge clk) ;
	           DoRead(dback,i[4:0]+16);
              end

           // write the enable register
           datain = 16'Hffff;
           repeat (5) @(posedge clk) ;
           cs = 1;
           port_id = 0;
           write_strobe = 1;
           @(posedge clk) ;
           write_strobe = 0;
           cs = 0;
           
           repeat(5) @(posedge clk) ;
           interrupts = 16'hFFFF;
			  #1085 ;
			  @(posedge clk) interrupts = 16'h0000;
			  repeat(10) @(posedge clk) ;
			  interrupts = 16'hffff;
			  #800 ; 
			  @(posedge clk) interrupts = 16'h0000;
           end
      
        always @(posedge InterruptOut)
           begin $display("got it");
           repeat (2) @(posedge clk) ;
           IntAck = 1;
           @(posedge clk)
           IntAck = 0;
			  end
			  
		  always @(posedge InterruptOut)
			  begin
			  repeat(1) @(posedge clk) ;
           cs = 1;
           port_id = 6;
           read_strobe = 1;
           @(posedge clk) ;
           read_strobe = 0;
			  cs = 0;
			  repeat(1) @(posedge clk) ;
           end

task DoRead;
	output [15:0] data;
	input  [15:0] adrs;

	begin
	@(posedge clk)
        cs = 1;
        port_id = adrs;
        @(posedge clk) 
        read_strobe = 1;
		  $displayh(dout);
        @(posedge clk) 
        read_strobe = 0;
	port_id = 0;
	cs = 0;
        end
endtask

task DoWrite;
	input [15:0] data;
	input [15:0] adrs;

	begin
	@(posedge clk) 
	cs = 1;
	port_id = adrs;
        datain = data;
	@(posedge clk)
	write_strobe = 1;
	@(posedge clk)
	cs = 0;
	write_strobe = 0;
	port_id = 0;
	datain = 0;
        end
endtask

endmodule

