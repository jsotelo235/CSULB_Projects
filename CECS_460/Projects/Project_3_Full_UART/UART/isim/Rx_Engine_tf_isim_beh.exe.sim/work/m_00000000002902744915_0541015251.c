/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/CSULB_Classes/CECS_460/Projects/Project_3_Full_UART/UART/Rx_FSM.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {7U, 0U};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {9U, 0U};
static unsigned int ng6[] = {2U, 0U};



static void Always_41_0(char *t0)
{
    char t15[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 4216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 4784);
    *((int *)t2) = 1;
    t3 = (t0 + 4248);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(42, ng0);

LAB5:    xsi_set_current_line(43, ng0);
    t4 = (t0 + 1616U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 3296);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3136);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    t13 = (t0 + 2976);
    t14 = (t13 + 56U);
    t16 = *((char **)t14);
    xsi_vlogtype_concat(t15, 4, 4, 3U, t16, 2, t12, 1, t4, 1);
    t17 = (t0 + 2656);
    xsi_vlogvar_wait_assign_value(t17, t15, 0, 0, 1, 0LL);
    t18 = (t0 + 2496);
    xsi_vlogvar_wait_assign_value(t18, t15, 1, 0, 1, 0LL);
    t19 = (t0 + 2816);
    xsi_vlogvar_wait_assign_value(t19, t15, 2, 0, 2, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(44, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2656);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 0LL);
    t13 = (t0 + 2496);
    xsi_vlogvar_wait_assign_value(t13, t11, 1, 0, 1, 0LL);
    t14 = (t0 + 2816);
    xsi_vlogvar_wait_assign_value(t14, t11, 2, 0, 2, 0LL);
    goto LAB8;

}

static void Always_49_1(char *t0)
{
    char t7[8];
    char t8[8];
    char t30[8];
    char t31[8];
    char t32[8];
    char t46[8];
    char t57[8];
    char t76[8];
    char t84[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    char *t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    char *t88;
    char *t89;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    int t108;
    int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    char *t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    char *t122;
    char *t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;
    char *t133;
    char *t134;
    char *t135;

LAB0:    t1 = (t0 + 4464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 4800);
    *((int *)t2) = 1;
    t3 = (t0 + 4496);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(50, ng0);

LAB5:    xsi_set_current_line(51, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 3136);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3296);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 2816);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2976);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 2);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2816);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 2, t5, 2);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t6 == 1)
        goto LAB11;

LAB12:
LAB14:
LAB13:    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3296);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    t5 = (t0 + 3136);
    xsi_vlogvar_assign_value(t5, t2, 1, 0, 1);
    t9 = (t0 + 2976);
    xsi_vlogvar_assign_value(t9, t2, 2, 0, 2);

LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(56, ng0);

LAB16:    xsi_set_current_line(57, ng0);
    t9 = (t0 + 1776U);
    t10 = *((char **)t9);
    memset(t8, 0, 8);
    t9 = (t10 + 4);
    t11 = *((unsigned int *)t9);
    t12 = (~(t11));
    t13 = *((unsigned int *)t10);
    t14 = (t13 & t12);
    t15 = (t14 & 1U);
    if (t15 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t9) != 0)
        goto LAB19;

LAB20:    t17 = (t8 + 4);
    t18 = *((unsigned int *)t8);
    t19 = *((unsigned int *)t17);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB21;

LAB22:    t22 = *((unsigned int *)t8);
    t23 = (~(t22));
    t24 = *((unsigned int *)t17);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t17) > 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t8) > 0)
        goto LAB27;

LAB28:    memcpy(t7, t26, 8);

LAB29:    t27 = (t0 + 3296);
    xsi_vlogvar_assign_value(t27, t7, 0, 0, 1);
    t28 = (t0 + 3136);
    xsi_vlogvar_assign_value(t28, t7, 1, 0, 1);
    t29 = (t0 + 2976);
    xsi_vlogvar_assign_value(t29, t7, 2, 0, 2);
    goto LAB15;

LAB9:    xsi_set_current_line(61, ng0);

LAB30:    xsi_set_current_line(62, ng0);
    t3 = (t0 + 1776U);
    t5 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t5 + 4);
    t11 = *((unsigned int *)t3);
    t12 = (~(t11));
    t13 = *((unsigned int *)t5);
    t14 = (t13 & t12);
    t15 = (t14 & 1U);
    if (t15 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t3) != 0)
        goto LAB33;

LAB34:    t10 = (t8 + 4);
    t18 = *((unsigned int *)t8);
    t19 = *((unsigned int *)t10);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB35;

LAB36:    t22 = *((unsigned int *)t8);
    t23 = (~(t22));
    t24 = *((unsigned int *)t10);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB37;

LAB38:    if (*((unsigned int *)t10) > 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t8) > 0)
        goto LAB41;

LAB42:    memcpy(t7, t30, 8);

LAB43:    t133 = (t0 + 3296);
    xsi_vlogvar_assign_value(t133, t7, 0, 0, 1);
    t134 = (t0 + 3136);
    xsi_vlogvar_assign_value(t134, t7, 1, 0, 1);
    t135 = (t0 + 2976);
    xsi_vlogvar_assign_value(t135, t7, 2, 0, 2);
    goto LAB15;

LAB11:    xsi_set_current_line(68, ng0);

LAB83:    xsi_set_current_line(69, ng0);
    t3 = (t0 + 2096U);
    t5 = *((char **)t3);
    memset(t30, 0, 8);
    t3 = (t5 + 4);
    t11 = *((unsigned int *)t3);
    t12 = (~(t11));
    t13 = *((unsigned int *)t5);
    t14 = (t13 & t12);
    t15 = (t14 & 1U);
    if (t15 != 0)
        goto LAB87;

LAB85:    if (*((unsigned int *)t3) == 0)
        goto LAB84;

LAB86:    t9 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t9) = 1;

LAB87:    t10 = (t30 + 4);
    t16 = (t5 + 4);
    t18 = *((unsigned int *)t5);
    t19 = (~(t18));
    *((unsigned int *)t30) = t19;
    *((unsigned int *)t10) = 0;
    if (*((unsigned int *)t16) != 0)
        goto LAB89;

LAB88:    t25 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t25 & 1U);
    t33 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t33 & 1U);
    memset(t8, 0, 8);
    t17 = (t30 + 4);
    t34 = *((unsigned int *)t17);
    t35 = (~(t34));
    t36 = *((unsigned int *)t30);
    t37 = (t36 & t35);
    t38 = (t37 & 1U);
    if (t38 != 0)
        goto LAB90;

LAB91:    if (*((unsigned int *)t17) != 0)
        goto LAB92;

LAB93:    t26 = (t8 + 4);
    t39 = *((unsigned int *)t8);
    t40 = *((unsigned int *)t26);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB94;

LAB95:    t42 = *((unsigned int *)t8);
    t43 = (~(t42));
    t44 = *((unsigned int *)t26);
    t45 = (t43 || t44);
    if (t45 > 0)
        goto LAB96;

LAB97:    if (*((unsigned int *)t26) > 0)
        goto LAB98;

LAB99:    if (*((unsigned int *)t8) > 0)
        goto LAB100;

LAB101:    memcpy(t7, t28, 8);

LAB102:    t29 = (t0 + 3296);
    xsi_vlogvar_assign_value(t29, t7, 0, 0, 1);
    t52 = (t0 + 3136);
    xsi_vlogvar_assign_value(t52, t7, 1, 0, 1);
    t53 = (t0 + 2976);
    xsi_vlogvar_assign_value(t53, t7, 2, 0, 2);
    goto LAB15;

LAB17:    *((unsigned int *)t8) = 1;
    goto LAB20;

LAB19:    t16 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB20;

LAB21:    t21 = ((char*)((ng1)));
    goto LAB22;

LAB23:    t26 = ((char*)((ng3)));
    goto LAB24;

LAB25:    xsi_vlog_unsigned_bit_combine(t7, 4, t21, 4, t26, 4);
    goto LAB29;

LAB27:    memcpy(t7, t21, 8);
    goto LAB29;

LAB31:    *((unsigned int *)t8) = 1;
    goto LAB34;

LAB33:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB34;

LAB35:    t16 = ((char*)((ng1)));
    goto LAB36;

LAB37:    t17 = (t0 + 1776U);
    t21 = *((char **)t17);
    memset(t32, 0, 8);
    t17 = (t21 + 4);
    t33 = *((unsigned int *)t17);
    t34 = (~(t33));
    t35 = *((unsigned int *)t21);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB47;

LAB45:    if (*((unsigned int *)t17) == 0)
        goto LAB44;

LAB46:    t26 = (t32 + 4);
    *((unsigned int *)t32) = 1;
    *((unsigned int *)t26) = 1;

LAB47:    t27 = (t32 + 4);
    t28 = (t21 + 4);
    t38 = *((unsigned int *)t21);
    t39 = (~(t38));
    *((unsigned int *)t32) = t39;
    *((unsigned int *)t27) = 0;
    if (*((unsigned int *)t28) != 0)
        goto LAB49;

LAB48:    t44 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t44 & 1U);
    t45 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t45 & 1U);
    memset(t46, 0, 8);
    t29 = (t32 + 4);
    t47 = *((unsigned int *)t29);
    t48 = (~(t47));
    t49 = *((unsigned int *)t32);
    t50 = (t49 & t48);
    t51 = (t50 & 1U);
    if (t51 != 0)
        goto LAB50;

LAB51:    if (*((unsigned int *)t29) != 0)
        goto LAB52;

LAB53:    t53 = (t46 + 4);
    t54 = *((unsigned int *)t46);
    t55 = *((unsigned int *)t53);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB54;

LAB55:    memcpy(t84, t46, 8);

LAB56:    memset(t31, 0, 8);
    t116 = (t84 + 4);
    t117 = *((unsigned int *)t116);
    t118 = (~(t117));
    t119 = *((unsigned int *)t84);
    t120 = (t119 & t118);
    t121 = (t120 & 1U);
    if (t121 != 0)
        goto LAB70;

LAB71:    if (*((unsigned int *)t116) != 0)
        goto LAB72;

LAB73:    t123 = (t31 + 4);
    t124 = *((unsigned int *)t31);
    t125 = *((unsigned int *)t123);
    t126 = (t124 || t125);
    if (t126 > 0)
        goto LAB74;

LAB75:    t128 = *((unsigned int *)t31);
    t129 = (~(t128));
    t130 = *((unsigned int *)t123);
    t131 = (t129 || t130);
    if (t131 > 0)
        goto LAB76;

LAB77:    if (*((unsigned int *)t123) > 0)
        goto LAB78;

LAB79:    if (*((unsigned int *)t31) > 0)
        goto LAB80;

LAB81:    memcpy(t30, t132, 8);

LAB82:    goto LAB38;

LAB39:    xsi_vlog_unsigned_bit_combine(t7, 4, t16, 4, t30, 4);
    goto LAB43;

LAB41:    memcpy(t7, t16, 8);
    goto LAB43;

LAB44:    *((unsigned int *)t32) = 1;
    goto LAB47;

LAB49:    t40 = *((unsigned int *)t32);
    t41 = *((unsigned int *)t28);
    *((unsigned int *)t32) = (t40 | t41);
    t42 = *((unsigned int *)t27);
    t43 = *((unsigned int *)t28);
    *((unsigned int *)t27) = (t42 | t43);
    goto LAB48;

LAB50:    *((unsigned int *)t46) = 1;
    goto LAB53;

LAB52:    t52 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB53;

LAB54:    t58 = (t0 + 1936U);
    t59 = *((char **)t58);
    memset(t57, 0, 8);
    t58 = (t59 + 4);
    t60 = *((unsigned int *)t58);
    t61 = (~(t60));
    t62 = *((unsigned int *)t59);
    t63 = (t62 & t61);
    t64 = (t63 & 1U);
    if (t64 != 0)
        goto LAB60;

LAB58:    if (*((unsigned int *)t58) == 0)
        goto LAB57;

LAB59:    t65 = (t57 + 4);
    *((unsigned int *)t57) = 1;
    *((unsigned int *)t65) = 1;

LAB60:    t66 = (t57 + 4);
    t67 = (t59 + 4);
    t68 = *((unsigned int *)t59);
    t69 = (~(t68));
    *((unsigned int *)t57) = t69;
    *((unsigned int *)t66) = 0;
    if (*((unsigned int *)t67) != 0)
        goto LAB62;

LAB61:    t74 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t74 & 1U);
    t75 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t75 & 1U);
    memset(t76, 0, 8);
    t77 = (t57 + 4);
    t78 = *((unsigned int *)t77);
    t79 = (~(t78));
    t80 = *((unsigned int *)t57);
    t81 = (t80 & t79);
    t82 = (t81 & 1U);
    if (t82 != 0)
        goto LAB63;

LAB64:    if (*((unsigned int *)t77) != 0)
        goto LAB65;

LAB66:    t85 = *((unsigned int *)t46);
    t86 = *((unsigned int *)t76);
    t87 = (t85 & t86);
    *((unsigned int *)t84) = t87;
    t88 = (t46 + 4);
    t89 = (t76 + 4);
    t90 = (t84 + 4);
    t91 = *((unsigned int *)t88);
    t92 = *((unsigned int *)t89);
    t93 = (t91 | t92);
    *((unsigned int *)t90) = t93;
    t94 = *((unsigned int *)t90);
    t95 = (t94 != 0);
    if (t95 == 1)
        goto LAB67;

LAB68:
LAB69:    goto LAB56;

LAB57:    *((unsigned int *)t57) = 1;
    goto LAB60;

LAB62:    t70 = *((unsigned int *)t57);
    t71 = *((unsigned int *)t67);
    *((unsigned int *)t57) = (t70 | t71);
    t72 = *((unsigned int *)t66);
    t73 = *((unsigned int *)t67);
    *((unsigned int *)t66) = (t72 | t73);
    goto LAB61;

LAB63:    *((unsigned int *)t76) = 1;
    goto LAB66;

LAB65:    t83 = (t76 + 4);
    *((unsigned int *)t76) = 1;
    *((unsigned int *)t83) = 1;
    goto LAB66;

LAB67:    t96 = *((unsigned int *)t84);
    t97 = *((unsigned int *)t90);
    *((unsigned int *)t84) = (t96 | t97);
    t98 = (t46 + 4);
    t99 = (t76 + 4);
    t100 = *((unsigned int *)t46);
    t101 = (~(t100));
    t102 = *((unsigned int *)t98);
    t103 = (~(t102));
    t104 = *((unsigned int *)t76);
    t105 = (~(t104));
    t106 = *((unsigned int *)t99);
    t107 = (~(t106));
    t108 = (t101 & t103);
    t109 = (t105 & t107);
    t110 = (~(t108));
    t111 = (~(t109));
    t112 = *((unsigned int *)t90);
    *((unsigned int *)t90) = (t112 & t110);
    t113 = *((unsigned int *)t90);
    *((unsigned int *)t90) = (t113 & t111);
    t114 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t114 & t110);
    t115 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t115 & t111);
    goto LAB69;

LAB70:    *((unsigned int *)t31) = 1;
    goto LAB73;

LAB72:    t122 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t122) = 1;
    goto LAB73;

LAB74:    t127 = ((char*)((ng3)));
    goto LAB75;

LAB76:    t132 = ((char*)((ng5)));
    goto LAB77;

LAB78:    xsi_vlog_unsigned_bit_combine(t30, 4, t127, 4, t132, 4);
    goto LAB82;

LAB80:    memcpy(t30, t127, 8);
    goto LAB82;

LAB84:    *((unsigned int *)t30) = 1;
    goto LAB87;

LAB89:    t20 = *((unsigned int *)t30);
    t22 = *((unsigned int *)t16);
    *((unsigned int *)t30) = (t20 | t22);
    t23 = *((unsigned int *)t10);
    t24 = *((unsigned int *)t16);
    *((unsigned int *)t10) = (t23 | t24);
    goto LAB88;

LAB90:    *((unsigned int *)t8) = 1;
    goto LAB93;

LAB92:    t21 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB93;

LAB94:    t27 = ((char*)((ng5)));
    goto LAB95;

LAB96:    t28 = ((char*)((ng1)));
    goto LAB97;

LAB98:    xsi_vlog_unsigned_bit_combine(t7, 4, t27, 4, t28, 4);
    goto LAB102;

LAB100:    memcpy(t7, t27, 8);
    goto LAB102;

}


extern void work_m_00000000002902744915_0541015251_init()
{
	static char *pe[] = {(void *)Always_41_0,(void *)Always_49_1};
	xsi_register_didat("work_m_00000000002902744915_0541015251", "isim/Rx_Engine_tf_isim_beh.exe.sim/work/m_00000000002902744915_0541015251.didat");
	xsi_register_executes(pe);
}
