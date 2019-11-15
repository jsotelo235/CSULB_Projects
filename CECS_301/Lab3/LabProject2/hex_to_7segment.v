`timescale 1ns / 1ps
/******************************************************************************************
*    File Name:   Lab 3 Top module
*    Project:     Lab Project 3: Sequence Detectors(phase 2)
*    Designer:    Jose Sotelo
*    Email:       jsotelo235@gmail.com
*    Rev. Date:   March 2, 2017
*
*    Purpose:
*
*    In this module, we are designing a 7-segment LED display that provides a very convenient
*    way of illustrating information in the form of numbers, letters, and characters.
*    7-segment displays are made of seven individual coloured LED's within one display
*    package. 
*
*    In in our case, we will be using the 7-segment decoder to display Hex values from
*    0-9 and A to F respectively. The right combination of LED's are needed to be illu-
*    minated and to do so we need to create boolean expresions for those combinations.
*
*    To create the boolean expressions, we must first understand what type of display the 
*    7-segment uses to illuminated the LED's. The first way to activate the LED's by using
*    the Common Cathode Display. In this type of connection, the LED's are joined together to
*    logic "0" or ground. Each individual segment is illuminated by applying a high or logic
*    "1" signal to the individual Anode terminals.
*
*    The second way to illuminate the LED's is by using the Common Anode Display. In this type
*    of connection, the LED's are joined together to logic "1" and the individual segments are
*    illuminated by connecting the individual Cathode terminals to a low or logic "0" signal.
*
*    In our case, we will be using the Common Anode Display to illuminate the LED's to create
*    the Hex values for our application.         
* 
*    Each individual segment is represented by a letter such as a,b,c,d,e,f,and g.
*    So in order to illuminate the hex value 1 we will need each individual segment
*    a, d, e, f, g to be logic "1" and the segments b and c be logic "0". This process,
*    is repeated to create the boolean expressions for the hex values 0-9 and A-F.
*
*    Notes:
*    A truth table to create the boolean expressions for each hex value is needed.
 ******************************************************************************************/
module hex_to_7segment(hex, a, b, c, d, e, f, g);

     input[3:0]     hex;
     output reg     a, b, c, d, e, f, g;         
     
     
     always @(hex)
          case(hex)
               4'b0000:  {a,b,c,d,e,f,g} = 7'b000_0001;  //hex 0
               4'b0001:  {a,b,c,d,e,f,g} = 7'b100_1111; //hex 1
               4'b0010:  {a,b,c,d,e,f,g} = 7'b001_0010; //hex 2
               4'b0011:  {a,b,c,d,e,f,g} = 7'b000_0110; //hex 3
               4'b0100:  {a,b,c,d,e,f,g} = 7'b100_1100; //hex 4
               4'b0101:  {a,b,c,d,e,f,g} = 7'b010_0100; //hex 5
               4'b0110:  {a,b,c,d,e,f,g} = 7'b010_0000; //hex 6
               4'b0111:  {a,b,c,d,e,f,g} = 7'b000_1111; //hex 7
               4'b1000:  {a,b,c,d,e,f,g} = 7'b000_0000; //hex 8
               4'b1001:  {a,b,c,d,e,f,g} = 7'b000_0100; //hex 9
               4'b1010:  {a,b,c,d,e,f,g} = 7'b000_1000; //hex a
               4'b1011:  {a,b,c,d,e,f,g} = 7'b110_0000; //hex b
               4'b1100:  {a,b,c,d,e,f,g} = 7'b011_0001; //hex c
               4'b1101:  {a,b,c,d,e,f,g} = 7'b100_0010; //hex d
               4'b1110:  {a,b,c,d,e,f,g} = 7'b011_0000; //hex e
               4'b1111:  {a,b,c,d,e,f,g} = 7'b111_0001; //hex f
               default:  {a,b,c,d,e,f,g} = 7'b111_1110; //display is off  
          endcase
endmodule
