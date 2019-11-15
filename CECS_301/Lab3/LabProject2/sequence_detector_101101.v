`timescale 1ns / 1ps
/*******************************************************************************************************
*    File Name:   Sequence detector for sequence 101101
*    Project:     Lab Project 2: Sequence Detectors(phase 1)
*    Designer:    Jose Sotelo
*    Email:       jsotelo235@gmail.com
*    Rev. Date:   March 2, 2017
*
*    Purpose:
*         Purpose for this module is to create Moore and Mealy FSM that detects the overlapping 
*         sequence of "101101". 
*
*         A Moore machine is a finite state machine whose outputs depend on only the present state. 
*         A Mealy machine is also a finite state machine whose outputs depend on both the inputs and 
*         the present states.
*         
*         To design this two FSM's, we need to create state diagram for both Moore and Mealy. After creating
*         the diagram, we will use the states to create a state table. From the state table, we will derive 
*         the state equations by using karnaugh maps. We will be using structural assignment to map out the 
*         Moore and Mealy machine.
*
*         For the Moore machine we will need six states that will transitions between each other detecting
*         the sequence "101101". If no sequence is detected, the output will be a "0". Otherwise if the 
*         sequence is detected the output will be a "1". In the case for the Mealy machine, we will need
*         five states to detect the same sequence "101101".
*
*         The result should be circuit who can detect a non-overlapping sequence of "101101"
*         using a Moore or Mealy machine. To be able to transition from each machine a input "M"
*         selector will be use to determine which current finite state machine we are in. If M = 0,
*         indicates we are in a Moore implementation. If M = 1, then the circuit implements a "Mealy"
*         machine.
*   
*         The input X will be used to detect the non-overlapping sequence of "101101". The output Z will
*         now be send to a seven segment decoder who will produce an illuminate display of the state we
*         are currently in.
*
*    Notes:
*         The state diagram, state table and k-maps of a Moore or Mealy machine can be locate 
*         in the deliverables. The circuit functions at each posedge rising clock frequency.
*
*         The state equations change depending on your application.
*   
*         A Moore machine normally requires more states to generate identical output sequence to
*         a Mealy machine. The reason is that the transitions are associated with the outputs in
*         a Mealy machine. 
 *********************************************************************************************************/
module sequence_detector_101101(clk, reset, X, M, Z, Q);

     input          clk, reset;
     input          X;
     input          M;
     
     output[2:0]    Q;
     output         Z;
     
     wire           moore_d0, moore_d1, moore_d2;
     wire           mealy_d0, mealy_d1, mealy_d2;
     wire[2:0]      mooreQ, mealyQ;
     
    // **********************************************************
    // Moore Sequence Detector for a serial input sequence 101101
    // **********************************************************
     
    // *********** Next State Combinational Logic ************** wrong
                            
          assign moore_d0 = ( mooreQ[2] & (~mooreQ[1]) & (~mooreQ[0])) |
                            ((~mooreQ[2]) & (~mooreQ[1]) & X)|
                            ((~mooreQ[2]) & (~mooreQ[0]) & X);                            
                            
          assign moore_d1 = ( mooreQ[2] & mooreQ[0] & X) |
                            ( mooreQ[2] & mooreQ[1] & (~X)) | 
                            ((~mooreQ[2]) & mooreQ[0] & (~X))|
                            ((~mooreQ[2]) & mooreQ[1] & (~mooreQ[0]) & X);
                            
          assign moore_d2 = ( mooreQ[2] & mooreQ[1] & X) |
                            ( mooreQ[1] & mooreQ[0] & X) |
                            ( mooreQ[2] & mooreQ[0] & X)|
                            ( mooreQ[2] & (~mooreQ[1]) & (~mooreQ[0]) & (~X));                          
                            
    // *********** State Register Using D-FF instances **********
     
      d_flip_flop 
                                               //N.S.          //P.S.
          moore_q0(.Clk(clk), .Reset(reset), .D(moore_d0), .Q(mooreQ[0])),
          moore_q1(.Clk(clk), .Reset(reset), .D(moore_d1), .Q(mooreQ[1])),
          moore_q2(.Clk(clk), .Reset(reset), .D(moore_d2), .Q(mooreQ[2]));
     
    // ********** Output Combinational Logic *******************
          assign moore_Z = (mooreQ[2] & mooreQ[1]);
          
    // **********************************************************
    // Mealy Sequence Detector for a serial input sequence 101101
    // ***********************************************************
     
     // *********** Next State Combinational Logic **************
          assign mealy_d0 = ((~mealyQ[0]) & X) |
                            ( mealyQ[2] & (~mealyQ[0])) |
                            ((~mealyQ[1]) & X);
                            
          assign mealy_d1 = ( mealyQ[1] & (~mealyQ[0]) & X) |
                            ( mealyQ[2] & mealyQ[0] & X) |
                            ((~mealyQ[2]) & mealyQ[0] & (~X));
                            
          assign mealy_d2 = ( mealyQ[2] & (~mealyQ[0]) & (~X))|
                            ( mealyQ[1] & mealyQ[0] & X);
     
     // *********** State Register Using D-FF instances *********
        d_flip_flop 
                                               //N.S.          //P.S.
          mealy_q0(.Clk(clk), .Reset(reset), .D(mealy_d0), .Q(mealyQ[0])),
          mealy_q1(.Clk(clk), .Reset(reset), .D(mealy_d1), .Q(mealyQ[1])),
          mealy_q2(.Clk(clk), .Reset(reset), .D(mealy_d2), .Q(mealyQ[2]));
    
     // ********** Output Combinational Logic *********************
          assign mealy_Z = (mealyQ[2] & mealyQ[0] & X);
          
     // *******************************************************************************
    //    2-to-1 mux to choose Moore/Mealy Q's and Moore/Mealy z for global outputs
    //    if M==0 then {Q,Z} = {mooreQ, moore_Z} else {Q, Z} = {mealyQ, mealy_Z}
    // ********************************************************************************
          assign {Q, Z} = (~M) ? {mooreQ, moore_Z} : {mealyQ, mealy_Z};
endmodule
