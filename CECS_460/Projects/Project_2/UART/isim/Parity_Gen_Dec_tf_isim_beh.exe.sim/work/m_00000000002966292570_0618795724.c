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
static const char *ng0 = "D:/CSULB_Classes/CECS_460/Projects/Project_2/UART/Parity_Gen_Dec.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {3U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {5U, 0U};
static unsigned int ng7[] = {6U, 0U};
static unsigned int ng8[] = {7U, 0U};



static void Always_40_0(char *t0)
{
    char t4[8];
    char t5[8];
    char t18[8];
    char t19[8];
    char t40[8];
    char t41[8];
    char t61[8];
    char t62[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    char *t81;
    char *t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;

LAB0:    t1 = (t0 + 3328U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 3896);
    *((int *)t2) = 1;
    t3 = (t0 + 3360);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(41, ng0);

LAB5:    xsi_set_current_line(42, ng0);
    t6 = (t0 + 1208U);
    t7 = *((char **)t6);
    memset(t5, 0, 8);
    t6 = (t7 + 4);
    t8 = *((unsigned int *)t6);
    t9 = (~(t8));
    t10 = *((unsigned int *)t7);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t6) != 0)
        goto LAB8;

LAB9:    t14 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    t36 = *((unsigned int *)t5);
    t37 = (~(t36));
    t38 = *((unsigned int *)t14);
    t39 = (t37 || t38);
    if (t39 > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t14) > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t5) > 0)
        goto LAB16;

LAB17:    memcpy(t4, t40, 8);

LAB18:    t58 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t58, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(43, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t2) != 0)
        goto LAB35;

LAB36:    t7 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = *((unsigned int *)t7);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB37;

LAB38:    t56 = *((unsigned int *)t5);
    t57 = (~(t56));
    t59 = *((unsigned int *)t7);
    t60 = (t57 || t59);
    if (t60 > 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t7) > 0)
        goto LAB41;

LAB42:    if (*((unsigned int *)t5) > 0)
        goto LAB43;

LAB44:    memcpy(t4, t41, 8);

LAB45:    t92 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t92, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB6:    *((unsigned int *)t5) = 1;
    goto LAB9;

LAB8:    t13 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB9;

LAB10:    t20 = (t0 + 1048U);
    t21 = *((char **)t20);
    memset(t19, 0, 8);
    t20 = (t19 + 4);
    t22 = (t21 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (t23 >> 0);
    *((unsigned int *)t19) = t24;
    t25 = *((unsigned int *)t22);
    t26 = (t25 >> 0);
    *((unsigned int *)t20) = t26;
    t27 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t27 & 255U);
    t28 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t28 & 255U);
    memset(t18, 0, 8);
    t29 = (t19 + 4);
    t30 = *((unsigned int *)t19);
    t31 = *((unsigned int *)t19);
    t31 = (t31 & 1);
    if (*((unsigned int *)t29) != 0)
        goto LAB19;

LAB20:    t33 = 1;

LAB22:    t34 = (t33 <= 7);
    if (t34 == 1)
        goto LAB23;

LAB24:    *((unsigned int *)t18) = t31;

LAB21:    goto LAB11;

LAB12:    t42 = (t0 + 1048U);
    t43 = *((char **)t42);
    memset(t41, 0, 8);
    t42 = (t41 + 4);
    t44 = (t43 + 4);
    t45 = *((unsigned int *)t43);
    t46 = (t45 >> 0);
    *((unsigned int *)t41) = t46;
    t47 = *((unsigned int *)t44);
    t48 = (t47 >> 0);
    *((unsigned int *)t42) = t48;
    t49 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t49 & 127U);
    t50 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t50 & 127U);
    memset(t40, 0, 8);
    t51 = (t41 + 4);
    t52 = *((unsigned int *)t41);
    t53 = *((unsigned int *)t41);
    t53 = (t53 & 1);
    if (*((unsigned int *)t51) != 0)
        goto LAB26;

LAB27:    t55 = 1;

LAB29:    t56 = (t55 <= 6);
    if (t56 == 1)
        goto LAB30;

LAB31:    *((unsigned int *)t40) = t53;

LAB28:    goto LAB13;

LAB14:    xsi_vlog_unsigned_bit_combine(t4, 1, t18, 1, t40, 1);
    goto LAB18;

LAB16:    memcpy(t4, t18, 8);
    goto LAB18;

LAB19:    t32 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB21;

LAB23:    t30 = (t30 >> 1);
    t35 = (t30 & 1);
    t31 = (t31 ^ t35);

LAB25:    t33 = (t33 + 1);
    goto LAB22;

LAB26:    t54 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB28;

LAB30:    t52 = (t52 >> 1);
    t57 = (t52 & 1);
    t53 = (t53 ^ t57);

LAB32:    t55 = (t55 + 1);
    goto LAB29;

LAB33:    *((unsigned int *)t5) = 1;
    goto LAB36;

LAB35:    t6 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB36;

LAB37:    t13 = (t0 + 1048U);
    t14 = *((char **)t13);
    memset(t40, 0, 8);
    t13 = (t40 + 4);
    t20 = (t14 + 4);
    t23 = *((unsigned int *)t14);
    t24 = (t23 >> 0);
    *((unsigned int *)t40) = t24;
    t25 = *((unsigned int *)t20);
    t26 = (t25 >> 0);
    *((unsigned int *)t13) = t26;
    t27 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t27 & 255U);
    t28 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t28 & 255U);
    memset(t19, 0, 8);
    t21 = (t40 + 4);
    t30 = *((unsigned int *)t40);
    t31 = *((unsigned int *)t40);
    t31 = (t31 & 1);
    if (*((unsigned int *)t21) != 0)
        goto LAB46;

LAB47:    t33 = 1;

LAB49:    t34 = (t33 <= 7);
    if (t34 == 1)
        goto LAB50;

LAB51:    *((unsigned int *)t19) = t31;

LAB48:    memset(t18, 0, 8);
    t29 = (t19 + 4);
    t36 = *((unsigned int *)t29);
    t37 = (~(t36));
    t38 = *((unsigned int *)t19);
    t39 = (t38 & t37);
    t45 = (t39 & 1U);
    if (t45 != 0)
        goto LAB56;

LAB54:    if (*((unsigned int *)t29) == 0)
        goto LAB53;

LAB55:    t32 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t32) = 1;

LAB56:    t42 = (t18 + 4);
    t43 = (t19 + 4);
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    *((unsigned int *)t18) = t47;
    *((unsigned int *)t42) = 0;
    if (*((unsigned int *)t43) != 0)
        goto LAB58;

LAB57:    t53 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t53 & 1U);
    t55 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t55 & 1U);
    goto LAB38;

LAB39:    t44 = (t0 + 1048U);
    t51 = *((char **)t44);
    memset(t62, 0, 8);
    t44 = (t62 + 4);
    t54 = (t51 + 4);
    t63 = *((unsigned int *)t51);
    t64 = (t63 >> 0);
    *((unsigned int *)t62) = t64;
    t65 = *((unsigned int *)t54);
    t66 = (t65 >> 0);
    *((unsigned int *)t44) = t66;
    t67 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t67 & 127U);
    t68 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t68 & 127U);
    memset(t61, 0, 8);
    t58 = (t62 + 4);
    t69 = *((unsigned int *)t62);
    t70 = *((unsigned int *)t62);
    t70 = (t70 & 1);
    if (*((unsigned int *)t58) != 0)
        goto LAB59;

LAB60:    t72 = 1;

LAB62:    t73 = (t72 <= 6);
    if (t73 == 1)
        goto LAB63;

LAB64:    *((unsigned int *)t61) = t70;

LAB61:    memset(t41, 0, 8);
    t75 = (t61 + 4);
    t76 = *((unsigned int *)t75);
    t77 = (~(t76));
    t78 = *((unsigned int *)t61);
    t79 = (t78 & t77);
    t80 = (t79 & 1U);
    if (t80 != 0)
        goto LAB69;

LAB67:    if (*((unsigned int *)t75) == 0)
        goto LAB66;

LAB68:    t81 = (t41 + 4);
    *((unsigned int *)t41) = 1;
    *((unsigned int *)t81) = 1;

LAB69:    t82 = (t41 + 4);
    t83 = (t61 + 4);
    t84 = *((unsigned int *)t61);
    t85 = (~(t84));
    *((unsigned int *)t41) = t85;
    *((unsigned int *)t82) = 0;
    if (*((unsigned int *)t83) != 0)
        goto LAB71;

LAB70:    t90 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t90 & 1U);
    t91 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t91 & 1U);
    goto LAB40;

LAB41:    xsi_vlog_unsigned_bit_combine(t4, 1, t18, 1, t41, 1);
    goto LAB45;

LAB43:    memcpy(t4, t18, 8);
    goto LAB45;

LAB46:    t22 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB48;

LAB50:    t30 = (t30 >> 1);
    t35 = (t30 & 1);
    t31 = (t31 ^ t35);

LAB52:    t33 = (t33 + 1);
    goto LAB49;

LAB53:    *((unsigned int *)t18) = 1;
    goto LAB56;

LAB58:    t48 = *((unsigned int *)t18);
    t49 = *((unsigned int *)t43);
    *((unsigned int *)t18) = (t48 | t49);
    t50 = *((unsigned int *)t42);
    t52 = *((unsigned int *)t43);
    *((unsigned int *)t42) = (t50 | t52);
    goto LAB57;

LAB59:    t71 = (t61 + 4);
    *((unsigned int *)t61) = 1;
    *((unsigned int *)t71) = 1;
    goto LAB61;

LAB63:    t69 = (t69 >> 1);
    t74 = (t69 & 1);
    t70 = (t70 ^ t74);

LAB65:    t72 = (t72 + 1);
    goto LAB62;

LAB66:    *((unsigned int *)t41) = 1;
    goto LAB69;

LAB71:    t86 = *((unsigned int *)t41);
    t87 = *((unsigned int *)t83);
    *((unsigned int *)t41) = (t86 | t87);
    t88 = *((unsigned int *)t82);
    t89 = *((unsigned int *)t83);
    *((unsigned int *)t82) = (t88 | t89);
    goto LAB70;

}

static void Always_46_1(char *t0)
{
    char t4[8];
    char t13[8];
    char t14[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;

LAB0:    t1 = (t0 + 3576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 3912);
    *((int *)t2) = 1;
    t3 = (t0 + 3608);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(47, ng0);
    t5 = (t0 + 1528U);
    t6 = *((char **)t5);
    t5 = (t0 + 1368U);
    t7 = *((char **)t5);
    t5 = (t0 + 1208U);
    t8 = *((char **)t5);
    xsi_vlogtype_concat(t4, 3, 3, 3U, t8, 1, t7, 1, t6, 1);

LAB5:    t5 = ((char*)((ng1)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t9 == 1)
        goto LAB6;

LAB7:    t2 = ((char*)((ng3)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB8;

LAB9:    t2 = ((char*)((ng4)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB10;

LAB11:    t2 = ((char*)((ng2)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB12;

LAB13:    t2 = ((char*)((ng5)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB14;

LAB15:    t2 = ((char*)((ng6)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng7)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB18;

LAB19:    t2 = ((char*)((ng8)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB20;

LAB21:
LAB22:    goto LAB2;

LAB6:    xsi_set_current_line(48, ng0);
    t10 = ((char*)((ng2)));
    t11 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t11, t10, 0, 0, 1, 0LL);
    t12 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t12, t10, 1, 0, 1, 0LL);
    goto LAB22;

LAB8:    xsi_set_current_line(49, ng0);
    t3 = ((char*)((ng2)));
    t5 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 1, 0LL);
    t6 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t6, t3, 1, 0, 1, 0LL);
    goto LAB22;

LAB10:    xsi_set_current_line(50, ng0);
    t3 = (t0 + 2248);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    xsi_vlogtype_concat(t13, 2, 2, 2U, t7, 1, t6, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t8, t13, 0, 0, 1, 0LL);
    t10 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t10, t13, 1, 0, 1, 0LL);
    goto LAB22;

LAB12:    xsi_set_current_line(51, ng0);
    t3 = (t0 + 2408);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    xsi_vlogtype_concat(t13, 2, 2, 2U, t7, 1, t6, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t8, t13, 0, 0, 1, 0LL);
    t10 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t10, t13, 1, 0, 1, 0LL);
    goto LAB22;

LAB14:    xsi_set_current_line(52, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    memset(t14, 0, 8);
    t3 = (t14 + 4);
    t6 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 7);
    t17 = (t16 & 1);
    *((unsigned int *)t14) = t17;
    t18 = *((unsigned int *)t6);
    t19 = (t18 >> 7);
    t20 = (t19 & 1);
    *((unsigned int *)t3) = t20;
    t7 = ((char*)((ng3)));
    xsi_vlogtype_concat(t13, 2, 2, 2U, t7, 1, t14, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t8, t13, 0, 0, 1, 0LL);
    t10 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t10, t13, 1, 0, 1, 0LL);
    goto LAB22;

LAB16:    xsi_set_current_line(53, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    memset(t14, 0, 8);
    t3 = (t14 + 4);
    t6 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 7);
    t17 = (t16 & 1);
    *((unsigned int *)t14) = t17;
    t18 = *((unsigned int *)t6);
    t19 = (t18 >> 7);
    t20 = (t19 & 1);
    *((unsigned int *)t3) = t20;
    t7 = ((char*)((ng3)));
    xsi_vlogtype_concat(t13, 2, 2, 2U, t7, 1, t14, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t8, t13, 0, 0, 1, 0LL);
    t10 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t10, t13, 1, 0, 1, 0LL);
    goto LAB22;

LAB18:    xsi_set_current_line(54, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    memset(t14, 0, 8);
    t3 = (t14 + 4);
    t6 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 7);
    t17 = (t16 & 1);
    *((unsigned int *)t14) = t17;
    t18 = *((unsigned int *)t6);
    t19 = (t18 >> 7);
    t20 = (t19 & 1);
    *((unsigned int *)t3) = t20;
    t7 = (t0 + 2248);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    xsi_vlogtype_concat(t13, 2, 2, 2U, t10, 1, t14, 1);
    t11 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 1, 0LL);
    t12 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t12, t13, 1, 0, 1, 0LL);
    goto LAB22;

LAB20:    xsi_set_current_line(55, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    memset(t14, 0, 8);
    t3 = (t14 + 4);
    t6 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 7);
    t17 = (t16 & 1);
    *((unsigned int *)t14) = t17;
    t18 = *((unsigned int *)t6);
    t19 = (t18 >> 7);
    t20 = (t19 & 1);
    *((unsigned int *)t3) = t20;
    t7 = (t0 + 2408);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    xsi_vlogtype_concat(t13, 2, 2, 2U, t10, 1, t14, 1);
    t11 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 1, 0LL);
    t12 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t12, t13, 1, 0, 1, 0LL);
    goto LAB22;

}


extern void work_m_00000000002966292570_0618795724_init()
{
	static char *pe[] = {(void *)Always_40_0,(void *)Always_46_1};
	xsi_register_didat("work_m_00000000002966292570_0618795724", "isim/Parity_Gen_Dec_tf_isim_beh.exe.sim/work/m_00000000002966292570_0618795724.didat");
	xsi_register_executes(pe);
}
