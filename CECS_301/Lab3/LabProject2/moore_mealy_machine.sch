<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="artix7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="clk_100MHz" />
        <signal name="XLXN_4" />
        <signal name="x" />
        <signal name="M" />
        <signal name="XLXN_10" />
        <signal name="reset" />
        <signal name="step" />
        <signal name="Z" />
        <signal name="Q(2:0)" />
        <signal name="XLXN_18" />
        <port polarity="Input" name="clk_100MHz" />
        <port polarity="Input" name="x" />
        <port polarity="Input" name="M" />
        <port polarity="Input" name="reset" />
        <port polarity="Input" name="step" />
        <port polarity="Output" name="Z" />
        <port polarity="Output" name="Q(2:0)" />
        <blockdef name="clk_div">
            <timestamp>2017-2-23T8:47:47</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="one_shot">
            <timestamp>2017-2-23T8:47:57</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <blockdef name="sequence_detector_101101">
            <timestamp>2017-2-23T8:48:12</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="clk_div" name="XLXI_1">
            <blockpin signalname="clk_100MHz" name="clk_in" />
            <blockpin signalname="reset" name="reset" />
            <blockpin signalname="XLXN_1" name="clk_out" />
        </block>
        <block symbolname="one_shot" name="XLXI_2">
            <blockpin signalname="XLXN_1" name="clk_in" />
            <blockpin signalname="reset" name="reset" />
            <blockpin signalname="step" name="D_in" />
            <blockpin signalname="XLXN_2" name="D_out" />
        </block>
        <block symbolname="sequence_detector_101101" name="XLXI_3">
            <blockpin signalname="XLXN_2" name="clk" />
            <blockpin signalname="reset" name="reset" />
            <blockpin signalname="x" name="X" />
            <blockpin signalname="M" name="M" />
            <blockpin signalname="Z" name="Z" />
            <blockpin signalname="Q(2:0)" name="Q(2:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="528" y="1296" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1264" y="1360" name="XLXI_2" orien="R0">
        </instance>
        <instance x="2224" y="1424" name="XLXI_3" orien="R0">
        </instance>
        <branch name="XLXN_1">
            <wire x2="1264" y1="1200" y2="1200" x1="912" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="2224" y1="1200" y2="1200" x1="1648" />
        </branch>
        <branch name="clk_100MHz">
            <wire x2="528" y1="1200" y2="1200" x1="384" />
        </branch>
        <iomarker fontsize="28" x="384" y="1200" name="clk_100MHz" orien="R180" />
        <branch name="x">
            <wire x2="1968" y1="1664" y2="1664" x1="144" />
            <wire x2="2224" y1="1328" y2="1328" x1="1968" />
            <wire x2="1968" y1="1328" y2="1664" x1="1968" />
        </branch>
        <branch name="M">
            <wire x2="2208" y1="1728" y2="1728" x1="160" />
            <wire x2="2224" y1="1392" y2="1392" x1="2208" />
            <wire x2="2208" y1="1392" y2="1728" x1="2208" />
        </branch>
        <branch name="reset">
            <wire x2="464" y1="1488" y2="1488" x1="192" />
            <wire x2="1040" y1="1488" y2="1488" x1="464" />
            <wire x2="1728" y1="1488" y2="1488" x1="1040" />
            <wire x2="528" y1="1264" y2="1264" x1="464" />
            <wire x2="464" y1="1264" y2="1488" x1="464" />
            <wire x2="1264" y1="1264" y2="1264" x1="1040" />
            <wire x2="1040" y1="1264" y2="1488" x1="1040" />
            <wire x2="1728" y1="1264" y2="1488" x1="1728" />
            <wire x2="2224" y1="1264" y2="1264" x1="1728" />
        </branch>
        <branch name="step">
            <wire x2="1248" y1="1584" y2="1584" x1="176" />
            <wire x2="1264" y1="1328" y2="1328" x1="1248" />
            <wire x2="1248" y1="1328" y2="1584" x1="1248" />
        </branch>
        <branch name="Z">
            <wire x2="2976" y1="1200" y2="1200" x1="2608" />
        </branch>
        <iomarker fontsize="28" x="2976" y="1200" name="Z" orien="R0" />
        <branch name="Q(2:0)">
            <wire x2="2976" y1="1392" y2="1392" x1="2608" />
        </branch>
        <iomarker fontsize="28" x="2976" y="1392" name="Q(2:0)" orien="R0" />
        <iomarker fontsize="28" x="192" y="1488" name="reset" orien="R180" />
        <iomarker fontsize="28" x="176" y="1584" name="step" orien="R180" />
        <iomarker fontsize="28" x="160" y="1728" name="M" orien="R180" />
        <iomarker fontsize="28" x="144" y="1664" name="x" orien="R180" />
        <rect width="0" x="2640" y="2000" height="4" />
        <text style="fontsize:48;fontname:Arial;textcolor:rgb(255,0,0)" x="2276" y="2276">Name: Jose Sotelo</text>
        <text style="fontsize:48;fontname:Arial;textcolor:rgb(255,0,0)" x="2284" y="2360">Date: February 23, 2017</text>
        <text style="fontsize:48;fontname:Arial;textcolor:rgb(255,0,0)" x="2280" y="2196">Assignment: Lab 2 (Structural Model)</text>
        <text style="fontsize:60;fontname:Arial;textcolor:rgb(0,0,255)" x="2644" y="2096">CECS 301</text>
        <rect width="1156" x="2224" y="2008" height="560" />
        <text style="fontsize:48;fontname:Arial;textcolor:rgb(255,0,0)" x="2280" y="2440">Email: jsotelo235@gmail.com</text>
    </sheet>
</drawing>