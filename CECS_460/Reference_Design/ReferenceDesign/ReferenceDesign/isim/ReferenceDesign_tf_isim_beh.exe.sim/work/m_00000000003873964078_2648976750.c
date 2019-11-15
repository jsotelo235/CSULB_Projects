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
static const char *ng0 = "C:/Users/tramel/Documents/XilinxProjects/ReferenceDesign/ReferenceDesign/ReferenceDesign.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {0, 0};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {1U, 0U};
static int ng5[] = {499999, 0};
static unsigned int ng6[] = {2U, 0U};
static unsigned int ng7[] = {3U, 0U};
static unsigned int ng8[] = {4U, 0U};
static unsigned int ng9[] = {5U, 0U};
static unsigned int ng10[] = {6U, 0U};
static unsigned int ng11[] = {7U, 0U};



static void Cont_33_0(char *t0)
{
    char t3[8];
    char t6[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;

LAB0:    t1 = (t0 + 6336U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 4616);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t7 = (t6 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 1);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 1);
    t14 = (t13 & 1);
    *((unsigned int *)t7) = t14;
    memset(t3, 0, 8);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t6);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t15) == 0)
        goto LAB4;

LAB6:    t21 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t21) = 1;

LAB7:    t22 = (t3 + 4);
    t23 = (t6 + 4);
    t24 = *((unsigned int *)t6);
    t25 = (~(t24));
    *((unsigned int *)t3) = t25;
    *((unsigned int *)t22) = 0;
    if (*((unsigned int *)t23) != 0)
        goto LAB9;

LAB8:    t30 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t30 & 1U);
    t31 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t31 & 1U);
    t32 = (t0 + 9376);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    memset(t36, 0, 8);
    t37 = 1U;
    t38 = t37;
    t39 = (t3 + 4);
    t40 = *((unsigned int *)t3);
    t37 = (t37 & t40);
    t41 = *((unsigned int *)t39);
    t38 = (t38 & t41);
    t42 = (t36 + 4);
    t43 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t43 | t37);
    t44 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t44 | t38);
    xsi_driver_vfirst_trans(t32, 0, 0);
    t45 = (t0 + 9136);
    *((int *)t45) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t26 = *((unsigned int *)t3);
    t27 = *((unsigned int *)t23);
    *((unsigned int *)t3) = (t26 | t27);
    t28 = *((unsigned int *)t22);
    t29 = *((unsigned int *)t23);
    *((unsigned int *)t22) = (t28 | t29);
    goto LAB8;

}

static void Always_35_1(char *t0)
{
    char t13[8];
    char t22[8];
    char t30[8];
    char t31[8];
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
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    int t20;
    char *t21;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    int t29;
    char *t32;
    unsigned int t33;

LAB0:    t1 = (t0 + 6584U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 9152);
    *((int *)t2) = 1;
    t3 = (t0 + 6616);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 2296U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB5;

LAB6:    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 4616);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t22, 0, 8);
    t11 = (t22 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t22) = t8;
    t9 = *((unsigned int *)t12);
    t10 = (t9 >> 0);
    t19 = (t10 & 1);
    *((unsigned int *)t11) = t19;
    xsi_vlogtype_concat(t13, 2, 2, 2U, t22, 1, t2, 1);
    t14 = (t0 + 4616);
    t15 = (t0 + 4616);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t18 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t30, t17, 2, t18, 32, 1);
    t21 = (t30 + 4);
    t28 = *((unsigned int *)t21);
    t20 = (!(t28));
    if (t20 == 1)
        goto LAB12;

LAB13:    t23 = (t0 + 4616);
    t24 = (t0 + 4616);
    t25 = (t24 + 72U);
    t26 = *((char **)t25);
    t27 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t31, t26, 2, t27, 32, 1);
    t32 = (t31 + 4);
    t33 = *((unsigned int *)t32);
    t29 = (!(t33));
    if (t29 == 1)
        goto LAB14;

LAB15:
LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(36, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4616);
    t14 = (t0 + 4616);
    t15 = (t14 + 72U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t13, t16, 2, t17, 32, 1);
    t18 = (t13 + 4);
    t19 = *((unsigned int *)t18);
    t20 = (!(t19));
    if (t20 == 1)
        goto LAB8;

LAB9:    t21 = (t0 + 4616);
    t23 = (t0 + 4616);
    t24 = (t23 + 72U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t22, t25, 2, t26, 32, 1);
    t27 = (t22 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (!(t28));
    if (t29 == 1)
        goto LAB10;

LAB11:    goto LAB7;

LAB8:    xsi_vlogvar_wait_assign_value(t12, t11, 0, *((unsigned int *)t13), 1, 0LL);
    goto LAB9;

LAB10:    xsi_vlogvar_wait_assign_value(t21, t11, 1, *((unsigned int *)t22), 1, 0LL);
    goto LAB11;

LAB12:    xsi_vlogvar_wait_assign_value(t14, t13, 0, *((unsigned int *)t30), 1, 0LL);
    goto LAB13;

LAB14:    xsi_vlogvar_wait_assign_value(t23, t13, 1, *((unsigned int *)t31), 1, 0LL);
    goto LAB15;

}

static void Cont_43_2(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;

LAB0:    t1 = (t0 + 6832U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 5256);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB7;

LAB4:    if (t18 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB7:    t22 = (t0 + 9440);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memset(t26, 0, 8);
    t27 = 1U;
    t28 = t27;
    t29 = (t6 + 4);
    t30 = *((unsigned int *)t6);
    t27 = (t27 & t30);
    t31 = *((unsigned int *)t29);
    t28 = (t28 & t31);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t33 | t27);
    t34 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t34 | t28);
    xsi_driver_vfirst_trans(t22, 0, 0);
    t35 = (t0 + 9168);
    *((int *)t35) = 1;

LAB1:    return;
LAB6:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB7;

}

static void Always_45_3(char *t0)
{
    char t13[8];
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

LAB0:    t1 = (t0 + 7080U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 9184);
    *((int *)t2) = 1;
    t3 = (t0 + 7112);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(46, ng0);
    t4 = (t0 + 2616U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB5;

LAB6:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2936U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 5256);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_add(t13, 19, t4, 19, t5, 19);
    t11 = (t0 + 5256);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 19, 0LL);

LAB10:
LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(46, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 5256);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 19, 0LL);
    goto LAB7;

LAB8:    xsi_set_current_line(47, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 5256);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 19, 0LL);
    goto LAB10;

}

static void Always_63_4(char *t0)
{
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

LAB0:    t1 = (t0 + 7328U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 9200);
    *((int *)t2) = 1;
    t3 = (t0 + 7360);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(64, ng0);
    t4 = (t0 + 2616U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB5;

LAB6:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 4936);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5096);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(64, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 5096);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 0LL);
    goto LAB7;

}

static void Cont_67_5(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 7576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 5096);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t6 = (t5 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 2);
    t10 = (t9 & 1);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 2);
    t13 = (t12 & 1);
    *((unsigned int *)t6) = t13;
    t14 = (t0 + 9504);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 1U;
    t20 = t19;
    t21 = (t5 + 4);
    t22 = *((unsigned int *)t5);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t27 = (t0 + 9216);
    *((int *)t27) = 1;

LAB1:    return;
}

static void Always_69_6(char *t0)
{
    char t9[8];
    char t10[8];
    char t30[8];
    char t57[8];
    char t58[8];
    char t78[8];
    char t79[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    int t37;
    int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    char *t93;

LAB0:    t1 = (t0 + 7824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 9232);
    *((int *)t2) = 1;
    t3 = (t0 + 7856);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(70, ng0);
    t4 = (t0 + 5096);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB5:    t7 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t7, 3);
    if (t8 == 1)
        goto LAB6;

LAB7:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB8;

LAB9:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB10;

LAB11:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB12;

LAB13:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB14;

LAB15:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB18;

LAB19:    t2 = ((char*)((ng11)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB20;

LAB21:
LAB23:
LAB22:    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4936);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB24:    goto LAB2;

LAB6:    xsi_set_current_line(71, ng0);
    t11 = (t0 + 2456U);
    t12 = *((char **)t11);
    memset(t10, 0, 8);
    t11 = (t12 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (~(t13));
    t15 = *((unsigned int *)t12);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t11) != 0)
        goto LAB27;

LAB28:    t19 = (t10 + 4);
    t20 = *((unsigned int *)t10);
    t21 = *((unsigned int *)t19);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB29;

LAB30:    t24 = *((unsigned int *)t10);
    t25 = (~(t24));
    t26 = *((unsigned int *)t19);
    t27 = (t25 || t26);
    if (t27 > 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t19) > 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t10) > 0)
        goto LAB35;

LAB36:    memcpy(t9, t28, 8);

LAB37:    t29 = (t0 + 4936);
    xsi_vlogvar_assign_value(t29, t9, 0, 0, 3);
    goto LAB24;

LAB8:    xsi_set_current_line(72, ng0);
    t3 = (t0 + 2456U);
    t4 = *((char **)t3);
    t3 = (t0 + 2936U);
    t5 = *((char **)t3);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t5);
    t15 = (t13 & t14);
    *((unsigned int *)t30) = t15;
    t3 = (t4 + 4);
    t7 = (t5 + 4);
    t11 = (t30 + 4);
    t16 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t7);
    t20 = (t16 | t17);
    *((unsigned int *)t11) = t20;
    t21 = *((unsigned int *)t11);
    t22 = (t21 != 0);
    if (t22 == 1)
        goto LAB38;

LAB39:
LAB40:    memset(t10, 0, 8);
    t19 = (t30 + 4);
    t45 = *((unsigned int *)t19);
    t46 = (~(t45));
    t47 = *((unsigned int *)t30);
    t48 = (t47 & t46);
    t49 = (t48 & 1U);
    if (t49 != 0)
        goto LAB41;

LAB42:    if (*((unsigned int *)t19) != 0)
        goto LAB43;

LAB44:    t28 = (t10 + 4);
    t50 = *((unsigned int *)t10);
    t51 = *((unsigned int *)t28);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB45;

LAB46:    t53 = *((unsigned int *)t10);
    t54 = (~(t53));
    t55 = *((unsigned int *)t28);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t28) > 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t10) > 0)
        goto LAB51;

LAB52:    memcpy(t9, t57, 8);

LAB53:    t77 = (t0 + 4936);
    xsi_vlogvar_assign_value(t77, t9, 0, 0, 3);
    goto LAB24;

LAB10:    xsi_set_current_line(75, ng0);
    t3 = (t0 + 2456U);
    t4 = *((char **)t3);
    t3 = (t0 + 2936U);
    t5 = *((char **)t3);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t5);
    t15 = (t13 & t14);
    *((unsigned int *)t30) = t15;
    t3 = (t4 + 4);
    t7 = (t5 + 4);
    t11 = (t30 + 4);
    t16 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t7);
    t20 = (t16 | t17);
    *((unsigned int *)t11) = t20;
    t21 = *((unsigned int *)t11);
    t22 = (t21 != 0);
    if (t22 == 1)
        goto LAB67;

LAB68:
LAB69:    memset(t10, 0, 8);
    t19 = (t30 + 4);
    t45 = *((unsigned int *)t19);
    t46 = (~(t45));
    t47 = *((unsigned int *)t30);
    t48 = (t47 & t46);
    t49 = (t48 & 1U);
    if (t49 != 0)
        goto LAB70;

LAB71:    if (*((unsigned int *)t19) != 0)
        goto LAB72;

LAB73:    t28 = (t10 + 4);
    t50 = *((unsigned int *)t10);
    t51 = *((unsigned int *)t28);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB74;

LAB75:    t53 = *((unsigned int *)t10);
    t54 = (~(t53));
    t55 = *((unsigned int *)t28);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB76;

LAB77:    if (*((unsigned int *)t28) > 0)
        goto LAB78;

LAB79:    if (*((unsigned int *)t10) > 0)
        goto LAB80;

LAB81:    memcpy(t9, t57, 8);

LAB82:    t77 = (t0 + 4936);
    xsi_vlogvar_assign_value(t77, t9, 0, 0, 3);
    goto LAB24;

LAB12:    xsi_set_current_line(78, ng0);
    t3 = (t0 + 2456U);
    t4 = *((char **)t3);
    t3 = (t0 + 2936U);
    t5 = *((char **)t3);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t5);
    t15 = (t13 & t14);
    *((unsigned int *)t30) = t15;
    t3 = (t4 + 4);
    t7 = (t5 + 4);
    t11 = (t30 + 4);
    t16 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t7);
    t20 = (t16 | t17);
    *((unsigned int *)t11) = t20;
    t21 = *((unsigned int *)t11);
    t22 = (t21 != 0);
    if (t22 == 1)
        goto LAB96;

LAB97:
LAB98:    memset(t10, 0, 8);
    t19 = (t30 + 4);
    t45 = *((unsigned int *)t19);
    t46 = (~(t45));
    t47 = *((unsigned int *)t30);
    t48 = (t47 & t46);
    t49 = (t48 & 1U);
    if (t49 != 0)
        goto LAB99;

LAB100:    if (*((unsigned int *)t19) != 0)
        goto LAB101;

LAB102:    t28 = (t10 + 4);
    t50 = *((unsigned int *)t10);
    t51 = *((unsigned int *)t28);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB103;

LAB104:    t53 = *((unsigned int *)t10);
    t54 = (~(t53));
    t55 = *((unsigned int *)t28);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB105;

LAB106:    if (*((unsigned int *)t28) > 0)
        goto LAB107;

LAB108:    if (*((unsigned int *)t10) > 0)
        goto LAB109;

LAB110:    memcpy(t9, t57, 8);

LAB111:    t77 = (t0 + 4936);
    xsi_vlogvar_assign_value(t77, t9, 0, 0, 3);
    goto LAB24;

LAB14:    xsi_set_current_line(81, ng0);
    t3 = (t0 + 2456U);
    t4 = *((char **)t3);
    memset(t30, 0, 8);
    t3 = (t4 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (~(t13));
    t15 = *((unsigned int *)t4);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB128;

LAB126:    if (*((unsigned int *)t3) == 0)
        goto LAB125;

LAB127:    t5 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t5) = 1;

LAB128:    memset(t10, 0, 8);
    t7 = (t30 + 4);
    t20 = *((unsigned int *)t7);
    t21 = (~(t20));
    t22 = *((unsigned int *)t30);
    t24 = (t22 & t21);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB129;

LAB130:    if (*((unsigned int *)t7) != 0)
        goto LAB131;

LAB132:    t12 = (t10 + 4);
    t26 = *((unsigned int *)t10);
    t27 = *((unsigned int *)t12);
    t31 = (t26 || t27);
    if (t31 > 0)
        goto LAB133;

LAB134:    t32 = *((unsigned int *)t10);
    t33 = (~(t32));
    t34 = *((unsigned int *)t12);
    t35 = (t33 || t34);
    if (t35 > 0)
        goto LAB135;

LAB136:    if (*((unsigned int *)t12) > 0)
        goto LAB137;

LAB138:    if (*((unsigned int *)t10) > 0)
        goto LAB139;

LAB140:    memcpy(t9, t19, 8);

LAB141:    t23 = (t0 + 4936);
    xsi_vlogvar_assign_value(t23, t9, 0, 0, 3);
    goto LAB24;

LAB16:    xsi_set_current_line(82, ng0);
    t3 = (t0 + 2456U);
    t4 = *((char **)t3);
    memset(t30, 0, 8);
    t3 = (t4 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (~(t13));
    t15 = *((unsigned int *)t4);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB145;

LAB143:    if (*((unsigned int *)t3) == 0)
        goto LAB142;

LAB144:    t5 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t5) = 1;

LAB145:    t7 = (t0 + 2936U);
    t11 = *((char **)t7);
    t20 = *((unsigned int *)t30);
    t21 = *((unsigned int *)t11);
    t22 = (t20 & t21);
    *((unsigned int *)t57) = t22;
    t7 = (t30 + 4);
    t12 = (t11 + 4);
    t18 = (t57 + 4);
    t24 = *((unsigned int *)t7);
    t25 = *((unsigned int *)t12);
    t26 = (t24 | t25);
    *((unsigned int *)t18) = t26;
    t27 = *((unsigned int *)t18);
    t31 = (t27 != 0);
    if (t31 == 1)
        goto LAB146;

LAB147:
LAB148:    memset(t10, 0, 8);
    t28 = (t57 + 4);
    t50 = *((unsigned int *)t28);
    t51 = (~(t50));
    t52 = *((unsigned int *)t57);
    t53 = (t52 & t51);
    t54 = (t53 & 1U);
    if (t54 != 0)
        goto LAB149;

LAB150:    if (*((unsigned int *)t28) != 0)
        goto LAB151;

LAB152:    t59 = (t10 + 4);
    t55 = *((unsigned int *)t10);
    t56 = *((unsigned int *)t59);
    t61 = (t55 || t56);
    if (t61 > 0)
        goto LAB153;

LAB154:    t62 = *((unsigned int *)t10);
    t63 = (~(t62));
    t64 = *((unsigned int *)t59);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB155;

LAB156:    if (*((unsigned int *)t59) > 0)
        goto LAB157;

LAB158:    if (*((unsigned int *)t10) > 0)
        goto LAB159;

LAB160:    memcpy(t9, t58, 8);

LAB161:    t93 = (t0 + 4936);
    xsi_vlogvar_assign_value(t93, t9, 0, 0, 3);
    goto LAB24;

LAB18:    xsi_set_current_line(85, ng0);
    t3 = (t0 + 2456U);
    t4 = *((char **)t3);
    memset(t30, 0, 8);
    t3 = (t4 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (~(t13));
    t15 = *((unsigned int *)t4);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB182;

LAB180:    if (*((unsigned int *)t3) == 0)
        goto LAB179;

LAB181:    t5 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t5) = 1;

LAB182:    t7 = (t0 + 2936U);
    t11 = *((char **)t7);
    t20 = *((unsigned int *)t30);
    t21 = *((unsigned int *)t11);
    t22 = (t20 & t21);
    *((unsigned int *)t57) = t22;
    t7 = (t30 + 4);
    t12 = (t11 + 4);
    t18 = (t57 + 4);
    t24 = *((unsigned int *)t7);
    t25 = *((unsigned int *)t12);
    t26 = (t24 | t25);
    *((unsigned int *)t18) = t26;
    t27 = *((unsigned int *)t18);
    t31 = (t27 != 0);
    if (t31 == 1)
        goto LAB183;

LAB184:
LAB185:    memset(t10, 0, 8);
    t28 = (t57 + 4);
    t50 = *((unsigned int *)t28);
    t51 = (~(t50));
    t52 = *((unsigned int *)t57);
    t53 = (t52 & t51);
    t54 = (t53 & 1U);
    if (t54 != 0)
        goto LAB186;

LAB187:    if (*((unsigned int *)t28) != 0)
        goto LAB188;

LAB189:    t59 = (t10 + 4);
    t55 = *((unsigned int *)t10);
    t56 = *((unsigned int *)t59);
    t61 = (t55 || t56);
    if (t61 > 0)
        goto LAB190;

LAB191:    t62 = *((unsigned int *)t10);
    t63 = (~(t62));
    t64 = *((unsigned int *)t59);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB192;

LAB193:    if (*((unsigned int *)t59) > 0)
        goto LAB194;

LAB195:    if (*((unsigned int *)t10) > 0)
        goto LAB196;

LAB197:    memcpy(t9, t58, 8);

LAB198:    t93 = (t0 + 4936);
    xsi_vlogvar_assign_value(t93, t9, 0, 0, 3);
    goto LAB24;

LAB20:    xsi_set_current_line(88, ng0);
    t3 = (t0 + 2456U);
    t4 = *((char **)t3);
    memset(t30, 0, 8);
    t3 = (t4 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (~(t13));
    t15 = *((unsigned int *)t4);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB219;

LAB217:    if (*((unsigned int *)t3) == 0)
        goto LAB216;

LAB218:    t5 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t5) = 1;

LAB219:    t7 = (t0 + 2936U);
    t11 = *((char **)t7);
    t20 = *((unsigned int *)t30);
    t21 = *((unsigned int *)t11);
    t22 = (t20 & t21);
    *((unsigned int *)t57) = t22;
    t7 = (t30 + 4);
    t12 = (t11 + 4);
    t18 = (t57 + 4);
    t24 = *((unsigned int *)t7);
    t25 = *((unsigned int *)t12);
    t26 = (t24 | t25);
    *((unsigned int *)t18) = t26;
    t27 = *((unsigned int *)t18);
    t31 = (t27 != 0);
    if (t31 == 1)
        goto LAB220;

LAB221:
LAB222:    memset(t10, 0, 8);
    t28 = (t57 + 4);
    t50 = *((unsigned int *)t28);
    t51 = (~(t50));
    t52 = *((unsigned int *)t57);
    t53 = (t52 & t51);
    t54 = (t53 & 1U);
    if (t54 != 0)
        goto LAB223;

LAB224:    if (*((unsigned int *)t28) != 0)
        goto LAB225;

LAB226:    t59 = (t10 + 4);
    t55 = *((unsigned int *)t10);
    t56 = *((unsigned int *)t59);
    t61 = (t55 || t56);
    if (t61 > 0)
        goto LAB227;

LAB228:    t62 = *((unsigned int *)t10);
    t63 = (~(t62));
    t64 = *((unsigned int *)t59);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB229;

LAB230:    if (*((unsigned int *)t59) > 0)
        goto LAB231;

LAB232:    if (*((unsigned int *)t10) > 0)
        goto LAB233;

LAB234:    memcpy(t9, t58, 8);

LAB235:    t93 = (t0 + 4936);
    xsi_vlogvar_assign_value(t93, t9, 0, 0, 3);
    goto LAB24;

LAB25:    *((unsigned int *)t10) = 1;
    goto LAB28;

LAB27:    t18 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB28;

LAB29:    t23 = ((char*)((ng4)));
    goto LAB30;

LAB31:    t28 = ((char*)((ng1)));
    goto LAB32;

LAB33:    xsi_vlog_unsigned_bit_combine(t9, 3, t23, 3, t28, 3);
    goto LAB37;

LAB35:    memcpy(t9, t23, 8);
    goto LAB37;

LAB38:    t24 = *((unsigned int *)t30);
    t25 = *((unsigned int *)t11);
    *((unsigned int *)t30) = (t24 | t25);
    t12 = (t4 + 4);
    t18 = (t5 + 4);
    t26 = *((unsigned int *)t4);
    t27 = (~(t26));
    t31 = *((unsigned int *)t12);
    t32 = (~(t31));
    t33 = *((unsigned int *)t5);
    t34 = (~(t33));
    t35 = *((unsigned int *)t18);
    t36 = (~(t35));
    t37 = (t27 & t32);
    t38 = (t34 & t36);
    t39 = (~(t37));
    t40 = (~(t38));
    t41 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t41 & t39);
    t42 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t42 & t40);
    t43 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t43 & t39);
    t44 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t44 & t40);
    goto LAB40;

LAB41:    *((unsigned int *)t10) = 1;
    goto LAB44;

LAB43:    t23 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB44;

LAB45:    t29 = ((char*)((ng6)));
    goto LAB46;

LAB47:    t59 = (t0 + 2456U);
    t60 = *((char **)t59);
    memset(t58, 0, 8);
    t59 = (t60 + 4);
    t61 = *((unsigned int *)t59);
    t62 = (~(t61));
    t63 = *((unsigned int *)t60);
    t64 = (t63 & t62);
    t65 = (t64 & 1U);
    if (t65 != 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t59) != 0)
        goto LAB56;

LAB57:    t67 = (t58 + 4);
    t68 = *((unsigned int *)t58);
    t69 = *((unsigned int *)t67);
    t70 = (t68 || t69);
    if (t70 > 0)
        goto LAB58;

LAB59:    t72 = *((unsigned int *)t58);
    t73 = (~(t72));
    t74 = *((unsigned int *)t67);
    t75 = (t73 || t74);
    if (t75 > 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t67) > 0)
        goto LAB62;

LAB63:    if (*((unsigned int *)t58) > 0)
        goto LAB64;

LAB65:    memcpy(t57, t76, 8);

LAB66:    goto LAB48;

LAB49:    xsi_vlog_unsigned_bit_combine(t9, 3, t29, 3, t57, 3);
    goto LAB53;

LAB51:    memcpy(t9, t29, 8);
    goto LAB53;

LAB54:    *((unsigned int *)t58) = 1;
    goto LAB57;

LAB56:    t66 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t66) = 1;
    goto LAB57;

LAB58:    t71 = ((char*)((ng4)));
    goto LAB59;

LAB60:    t76 = ((char*)((ng1)));
    goto LAB61;

LAB62:    xsi_vlog_unsigned_bit_combine(t57, 3, t71, 3, t76, 3);
    goto LAB66;

LAB64:    memcpy(t57, t71, 8);
    goto LAB66;

LAB67:    t24 = *((unsigned int *)t30);
    t25 = *((unsigned int *)t11);
    *((unsigned int *)t30) = (t24 | t25);
    t12 = (t4 + 4);
    t18 = (t5 + 4);
    t26 = *((unsigned int *)t4);
    t27 = (~(t26));
    t31 = *((unsigned int *)t12);
    t32 = (~(t31));
    t33 = *((unsigned int *)t5);
    t34 = (~(t33));
    t35 = *((unsigned int *)t18);
    t36 = (~(t35));
    t37 = (t27 & t32);
    t38 = (t34 & t36);
    t39 = (~(t37));
    t40 = (~(t38));
    t41 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t41 & t39);
    t42 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t42 & t40);
    t43 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t43 & t39);
    t44 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t44 & t40);
    goto LAB69;

LAB70:    *((unsigned int *)t10) = 1;
    goto LAB73;

LAB72:    t23 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB73;

LAB74:    t29 = ((char*)((ng7)));
    goto LAB75;

LAB76:    t59 = (t0 + 2456U);
    t60 = *((char **)t59);
    memset(t58, 0, 8);
    t59 = (t60 + 4);
    t61 = *((unsigned int *)t59);
    t62 = (~(t61));
    t63 = *((unsigned int *)t60);
    t64 = (t63 & t62);
    t65 = (t64 & 1U);
    if (t65 != 0)
        goto LAB83;

LAB84:    if (*((unsigned int *)t59) != 0)
        goto LAB85;

LAB86:    t67 = (t58 + 4);
    t68 = *((unsigned int *)t58);
    t69 = *((unsigned int *)t67);
    t70 = (t68 || t69);
    if (t70 > 0)
        goto LAB87;

LAB88:    t72 = *((unsigned int *)t58);
    t73 = (~(t72));
    t74 = *((unsigned int *)t67);
    t75 = (t73 || t74);
    if (t75 > 0)
        goto LAB89;

LAB90:    if (*((unsigned int *)t67) > 0)
        goto LAB91;

LAB92:    if (*((unsigned int *)t58) > 0)
        goto LAB93;

LAB94:    memcpy(t57, t76, 8);

LAB95:    goto LAB77;

LAB78:    xsi_vlog_unsigned_bit_combine(t9, 3, t29, 3, t57, 3);
    goto LAB82;

LAB80:    memcpy(t9, t29, 8);
    goto LAB82;

LAB83:    *((unsigned int *)t58) = 1;
    goto LAB86;

LAB85:    t66 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t66) = 1;
    goto LAB86;

LAB87:    t71 = ((char*)((ng6)));
    goto LAB88;

LAB89:    t76 = ((char*)((ng1)));
    goto LAB90;

LAB91:    xsi_vlog_unsigned_bit_combine(t57, 3, t71, 3, t76, 3);
    goto LAB95;

LAB93:    memcpy(t57, t71, 8);
    goto LAB95;

LAB96:    t24 = *((unsigned int *)t30);
    t25 = *((unsigned int *)t11);
    *((unsigned int *)t30) = (t24 | t25);
    t12 = (t4 + 4);
    t18 = (t5 + 4);
    t26 = *((unsigned int *)t4);
    t27 = (~(t26));
    t31 = *((unsigned int *)t12);
    t32 = (~(t31));
    t33 = *((unsigned int *)t5);
    t34 = (~(t33));
    t35 = *((unsigned int *)t18);
    t36 = (~(t35));
    t37 = (t27 & t32);
    t38 = (t34 & t36);
    t39 = (~(t37));
    t40 = (~(t38));
    t41 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t41 & t39);
    t42 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t42 & t40);
    t43 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t43 & t39);
    t44 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t44 & t40);
    goto LAB98;

LAB99:    *((unsigned int *)t10) = 1;
    goto LAB102;

LAB101:    t23 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB102;

LAB103:    t29 = ((char*)((ng8)));
    goto LAB104;

LAB105:    t59 = (t0 + 2456U);
    t60 = *((char **)t59);
    memset(t58, 0, 8);
    t59 = (t60 + 4);
    t61 = *((unsigned int *)t59);
    t62 = (~(t61));
    t63 = *((unsigned int *)t60);
    t64 = (t63 & t62);
    t65 = (t64 & 1U);
    if (t65 != 0)
        goto LAB112;

LAB113:    if (*((unsigned int *)t59) != 0)
        goto LAB114;

LAB115:    t67 = (t58 + 4);
    t68 = *((unsigned int *)t58);
    t69 = *((unsigned int *)t67);
    t70 = (t68 || t69);
    if (t70 > 0)
        goto LAB116;

LAB117:    t72 = *((unsigned int *)t58);
    t73 = (~(t72));
    t74 = *((unsigned int *)t67);
    t75 = (t73 || t74);
    if (t75 > 0)
        goto LAB118;

LAB119:    if (*((unsigned int *)t67) > 0)
        goto LAB120;

LAB121:    if (*((unsigned int *)t58) > 0)
        goto LAB122;

LAB123:    memcpy(t57, t76, 8);

LAB124:    goto LAB106;

LAB107:    xsi_vlog_unsigned_bit_combine(t9, 3, t29, 3, t57, 3);
    goto LAB111;

LAB109:    memcpy(t9, t29, 8);
    goto LAB111;

LAB112:    *((unsigned int *)t58) = 1;
    goto LAB115;

LAB114:    t66 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t66) = 1;
    goto LAB115;

LAB116:    t71 = ((char*)((ng7)));
    goto LAB117;

LAB118:    t76 = ((char*)((ng1)));
    goto LAB119;

LAB120:    xsi_vlog_unsigned_bit_combine(t57, 3, t71, 3, t76, 3);
    goto LAB124;

LAB122:    memcpy(t57, t71, 8);
    goto LAB124;

LAB125:    *((unsigned int *)t30) = 1;
    goto LAB128;

LAB129:    *((unsigned int *)t10) = 1;
    goto LAB132;

LAB131:    t11 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB132;

LAB133:    t18 = ((char*)((ng9)));
    goto LAB134;

LAB135:    t19 = ((char*)((ng8)));
    goto LAB136;

LAB137:    xsi_vlog_unsigned_bit_combine(t9, 3, t18, 3, t19, 3);
    goto LAB141;

LAB139:    memcpy(t9, t18, 8);
    goto LAB141;

LAB142:    *((unsigned int *)t30) = 1;
    goto LAB145;

LAB146:    t32 = *((unsigned int *)t57);
    t33 = *((unsigned int *)t18);
    *((unsigned int *)t57) = (t32 | t33);
    t19 = (t30 + 4);
    t23 = (t11 + 4);
    t34 = *((unsigned int *)t30);
    t35 = (~(t34));
    t36 = *((unsigned int *)t19);
    t39 = (~(t36));
    t40 = *((unsigned int *)t11);
    t41 = (~(t40));
    t42 = *((unsigned int *)t23);
    t43 = (~(t42));
    t37 = (t35 & t39);
    t38 = (t41 & t43);
    t44 = (~(t37));
    t45 = (~(t38));
    t46 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t46 & t44);
    t47 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t47 & t45);
    t48 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t48 & t44);
    t49 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t49 & t45);
    goto LAB148;

LAB149:    *((unsigned int *)t10) = 1;
    goto LAB152;

LAB151:    t29 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB152;

LAB153:    t60 = ((char*)((ng10)));
    goto LAB154;

LAB155:    t66 = (t0 + 2456U);
    t67 = *((char **)t66);
    memset(t79, 0, 8);
    t66 = (t67 + 4);
    t68 = *((unsigned int *)t66);
    t69 = (~(t68));
    t70 = *((unsigned int *)t67);
    t72 = (t70 & t69);
    t73 = (t72 & 1U);
    if (t73 != 0)
        goto LAB165;

LAB163:    if (*((unsigned int *)t66) == 0)
        goto LAB162;

LAB164:    t71 = (t79 + 4);
    *((unsigned int *)t79) = 1;
    *((unsigned int *)t71) = 1;

LAB165:    memset(t78, 0, 8);
    t76 = (t79 + 4);
    t74 = *((unsigned int *)t76);
    t75 = (~(t74));
    t80 = *((unsigned int *)t79);
    t81 = (t80 & t75);
    t82 = (t81 & 1U);
    if (t82 != 0)
        goto LAB166;

LAB167:    if (*((unsigned int *)t76) != 0)
        goto LAB168;

LAB169:    t83 = (t78 + 4);
    t84 = *((unsigned int *)t78);
    t85 = *((unsigned int *)t83);
    t86 = (t84 || t85);
    if (t86 > 0)
        goto LAB170;

LAB171:    t88 = *((unsigned int *)t78);
    t89 = (~(t88));
    t90 = *((unsigned int *)t83);
    t91 = (t89 || t90);
    if (t91 > 0)
        goto LAB172;

LAB173:    if (*((unsigned int *)t83) > 0)
        goto LAB174;

LAB175:    if (*((unsigned int *)t78) > 0)
        goto LAB176;

LAB177:    memcpy(t58, t92, 8);

LAB178:    goto LAB156;

LAB157:    xsi_vlog_unsigned_bit_combine(t9, 3, t60, 3, t58, 3);
    goto LAB161;

LAB159:    memcpy(t9, t60, 8);
    goto LAB161;

LAB162:    *((unsigned int *)t79) = 1;
    goto LAB165;

LAB166:    *((unsigned int *)t78) = 1;
    goto LAB169;

LAB168:    t77 = (t78 + 4);
    *((unsigned int *)t78) = 1;
    *((unsigned int *)t77) = 1;
    goto LAB169;

LAB170:    t87 = ((char*)((ng9)));
    goto LAB171;

LAB172:    t92 = ((char*)((ng8)));
    goto LAB173;

LAB174:    xsi_vlog_unsigned_bit_combine(t58, 3, t87, 3, t92, 3);
    goto LAB178;

LAB176:    memcpy(t58, t87, 8);
    goto LAB178;

LAB179:    *((unsigned int *)t30) = 1;
    goto LAB182;

LAB183:    t32 = *((unsigned int *)t57);
    t33 = *((unsigned int *)t18);
    *((unsigned int *)t57) = (t32 | t33);
    t19 = (t30 + 4);
    t23 = (t11 + 4);
    t34 = *((unsigned int *)t30);
    t35 = (~(t34));
    t36 = *((unsigned int *)t19);
    t39 = (~(t36));
    t40 = *((unsigned int *)t11);
    t41 = (~(t40));
    t42 = *((unsigned int *)t23);
    t43 = (~(t42));
    t37 = (t35 & t39);
    t38 = (t41 & t43);
    t44 = (~(t37));
    t45 = (~(t38));
    t46 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t46 & t44);
    t47 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t47 & t45);
    t48 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t48 & t44);
    t49 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t49 & t45);
    goto LAB185;

LAB186:    *((unsigned int *)t10) = 1;
    goto LAB189;

LAB188:    t29 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB189;

LAB190:    t60 = ((char*)((ng11)));
    goto LAB191;

LAB192:    t66 = (t0 + 2456U);
    t67 = *((char **)t66);
    memset(t79, 0, 8);
    t66 = (t67 + 4);
    t68 = *((unsigned int *)t66);
    t69 = (~(t68));
    t70 = *((unsigned int *)t67);
    t72 = (t70 & t69);
    t73 = (t72 & 1U);
    if (t73 != 0)
        goto LAB202;

LAB200:    if (*((unsigned int *)t66) == 0)
        goto LAB199;

LAB201:    t71 = (t79 + 4);
    *((unsigned int *)t79) = 1;
    *((unsigned int *)t71) = 1;

LAB202:    memset(t78, 0, 8);
    t76 = (t79 + 4);
    t74 = *((unsigned int *)t76);
    t75 = (~(t74));
    t80 = *((unsigned int *)t79);
    t81 = (t80 & t75);
    t82 = (t81 & 1U);
    if (t82 != 0)
        goto LAB203;

LAB204:    if (*((unsigned int *)t76) != 0)
        goto LAB205;

LAB206:    t83 = (t78 + 4);
    t84 = *((unsigned int *)t78);
    t85 = *((unsigned int *)t83);
    t86 = (t84 || t85);
    if (t86 > 0)
        goto LAB207;

LAB208:    t88 = *((unsigned int *)t78);
    t89 = (~(t88));
    t90 = *((unsigned int *)t83);
    t91 = (t89 || t90);
    if (t91 > 0)
        goto LAB209;

LAB210:    if (*((unsigned int *)t83) > 0)
        goto LAB211;

LAB212:    if (*((unsigned int *)t78) > 0)
        goto LAB213;

LAB214:    memcpy(t58, t92, 8);

LAB215:    goto LAB193;

LAB194:    xsi_vlog_unsigned_bit_combine(t9, 3, t60, 3, t58, 3);
    goto LAB198;

LAB196:    memcpy(t9, t60, 8);
    goto LAB198;

LAB199:    *((unsigned int *)t79) = 1;
    goto LAB202;

LAB203:    *((unsigned int *)t78) = 1;
    goto LAB206;

LAB205:    t77 = (t78 + 4);
    *((unsigned int *)t78) = 1;
    *((unsigned int *)t77) = 1;
    goto LAB206;

LAB207:    t87 = ((char*)((ng10)));
    goto LAB208;

LAB209:    t92 = ((char*)((ng8)));
    goto LAB210;

LAB211:    xsi_vlog_unsigned_bit_combine(t58, 3, t87, 3, t92, 3);
    goto LAB215;

LAB213:    memcpy(t58, t87, 8);
    goto LAB215;

LAB216:    *((unsigned int *)t30) = 1;
    goto LAB219;

LAB220:    t32 = *((unsigned int *)t57);
    t33 = *((unsigned int *)t18);
    *((unsigned int *)t57) = (t32 | t33);
    t19 = (t30 + 4);
    t23 = (t11 + 4);
    t34 = *((unsigned int *)t30);
    t35 = (~(t34));
    t36 = *((unsigned int *)t19);
    t39 = (~(t36));
    t40 = *((unsigned int *)t11);
    t41 = (~(t40));
    t42 = *((unsigned int *)t23);
    t43 = (~(t42));
    t37 = (t35 & t39);
    t38 = (t41 & t43);
    t44 = (~(t37));
    t45 = (~(t38));
    t46 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t46 & t44);
    t47 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t47 & t45);
    t48 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t48 & t44);
    t49 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t49 & t45);
    goto LAB222;

LAB223:    *((unsigned int *)t10) = 1;
    goto LAB226;

LAB225:    t29 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB226;

LAB227:    t60 = ((char*)((ng4)));
    goto LAB228;

LAB229:    t66 = (t0 + 2456U);
    t67 = *((char **)t66);
    memset(t79, 0, 8);
    t66 = (t67 + 4);
    t68 = *((unsigned int *)t66);
    t69 = (~(t68));
    t70 = *((unsigned int *)t67);
    t72 = (t70 & t69);
    t73 = (t72 & 1U);
    if (t73 != 0)
        goto LAB239;

LAB237:    if (*((unsigned int *)t66) == 0)
        goto LAB236;

LAB238:    t71 = (t79 + 4);
    *((unsigned int *)t79) = 1;
    *((unsigned int *)t71) = 1;

LAB239:    memset(t78, 0, 8);
    t76 = (t79 + 4);
    t74 = *((unsigned int *)t76);
    t75 = (~(t74));
    t80 = *((unsigned int *)t79);
    t81 = (t80 & t75);
    t82 = (t81 & 1U);
    if (t82 != 0)
        goto LAB240;

LAB241:    if (*((unsigned int *)t76) != 0)
        goto LAB242;

LAB243:    t83 = (t78 + 4);
    t84 = *((unsigned int *)t78);
    t85 = *((unsigned int *)t83);
    t86 = (t84 || t85);
    if (t86 > 0)
        goto LAB244;

LAB245:    t88 = *((unsigned int *)t78);
    t89 = (~(t88));
    t90 = *((unsigned int *)t83);
    t91 = (t89 || t90);
    if (t91 > 0)
        goto LAB246;

LAB247:    if (*((unsigned int *)t83) > 0)
        goto LAB248;

LAB249:    if (*((unsigned int *)t78) > 0)
        goto LAB250;

LAB251:    memcpy(t58, t92, 8);

LAB252:    goto LAB230;

LAB231:    xsi_vlog_unsigned_bit_combine(t9, 3, t60, 3, t58, 3);
    goto LAB235;

LAB233:    memcpy(t9, t60, 8);
    goto LAB235;

LAB236:    *((unsigned int *)t79) = 1;
    goto LAB239;

LAB240:    *((unsigned int *)t78) = 1;
    goto LAB243;

LAB242:    t77 = (t78 + 4);
    *((unsigned int *)t78) = 1;
    *((unsigned int *)t77) = 1;
    goto LAB243;

LAB244:    t87 = ((char*)((ng11)));
    goto LAB245;

LAB246:    t92 = ((char*)((ng8)));
    goto LAB247;

LAB248:    xsi_vlog_unsigned_bit_combine(t58, 3, t87, 3, t92, 3);
    goto LAB252;

LAB250:    memcpy(t58, t87, 8);
    goto LAB252;

}

static void Cont_98_7(char *t0)
{
    char t5[8];
    char t14[8];
    char t18[8];
    char t44[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    char *t17;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    int t68;
    int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;

LAB0:    t1 = (t0 + 8072U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(98, ng0);
    t2 = (t0 + 4776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t6 = (t5 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t6) = t13;
    t15 = (t0 + 4776);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t18, 0, 8);
    t19 = (t18 + 4);
    t20 = (t17 + 4);
    t21 = *((unsigned int *)t17);
    t22 = (t21 >> 1);
    t23 = (t22 & 1);
    *((unsigned int *)t18) = t23;
    t24 = *((unsigned int *)t20);
    t25 = (t24 >> 1);
    t26 = (t25 & 1);
    *((unsigned int *)t19) = t26;
    memset(t14, 0, 8);
    t27 = (t18 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t18);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t27) == 0)
        goto LAB4;

LAB6:    t33 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t33) = 1;

LAB7:    t34 = (t14 + 4);
    t35 = (t18 + 4);
    t36 = *((unsigned int *)t18);
    t37 = (~(t36));
    *((unsigned int *)t14) = t37;
    *((unsigned int *)t34) = 0;
    if (*((unsigned int *)t35) != 0)
        goto LAB9;

LAB8:    t42 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t42 & 1U);
    t43 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t43 & 1U);
    t45 = *((unsigned int *)t5);
    t46 = *((unsigned int *)t14);
    t47 = (t45 & t46);
    *((unsigned int *)t44) = t47;
    t48 = (t5 + 4);
    t49 = (t14 + 4);
    t50 = (t44 + 4);
    t51 = *((unsigned int *)t48);
    t52 = *((unsigned int *)t49);
    t53 = (t51 | t52);
    *((unsigned int *)t50) = t53;
    t54 = *((unsigned int *)t50);
    t55 = (t54 != 0);
    if (t55 == 1)
        goto LAB10;

LAB11:
LAB12:    t76 = (t0 + 9568);
    t77 = (t76 + 56U);
    t78 = *((char **)t77);
    t79 = (t78 + 56U);
    t80 = *((char **)t79);
    memset(t80, 0, 8);
    t81 = 1U;
    t82 = t81;
    t83 = (t44 + 4);
    t84 = *((unsigned int *)t44);
    t81 = (t81 & t84);
    t85 = *((unsigned int *)t83);
    t82 = (t82 & t85);
    t86 = (t80 + 4);
    t87 = *((unsigned int *)t80);
    *((unsigned int *)t80) = (t87 | t81);
    t88 = *((unsigned int *)t86);
    *((unsigned int *)t86) = (t88 | t82);
    xsi_driver_vfirst_trans(t76, 0, 0);
    t89 = (t0 + 9248);
    *((int *)t89) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t14) = 1;
    goto LAB7;

LAB9:    t38 = *((unsigned int *)t14);
    t39 = *((unsigned int *)t35);
    *((unsigned int *)t14) = (t38 | t39);
    t40 = *((unsigned int *)t34);
    t41 = *((unsigned int *)t35);
    *((unsigned int *)t34) = (t40 | t41);
    goto LAB8;

LAB10:    t56 = *((unsigned int *)t44);
    t57 = *((unsigned int *)t50);
    *((unsigned int *)t44) = (t56 | t57);
    t58 = (t5 + 4);
    t59 = (t14 + 4);
    t60 = *((unsigned int *)t5);
    t61 = (~(t60));
    t62 = *((unsigned int *)t58);
    t63 = (~(t62));
    t64 = *((unsigned int *)t14);
    t65 = (~(t64));
    t66 = *((unsigned int *)t59);
    t67 = (~(t66));
    t68 = (t61 & t63);
    t69 = (t65 & t67);
    t70 = (~(t68));
    t71 = (~(t69));
    t72 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t72 & t70);
    t73 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t73 & t71);
    t74 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t74 & t70);
    t75 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t75 & t71);
    goto LAB12;

}

static void Always_100_8(char *t0)
{
    char t13[8];
    char t22[8];
    char t30[8];
    char t31[8];
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
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    int t20;
    char *t21;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    int t29;
    char *t32;
    unsigned int t33;

LAB0:    t1 = (t0 + 8320U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 9264);
    *((int *)t2) = 1;
    t3 = (t0 + 8352);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(101, ng0);
    t4 = (t0 + 2616U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB5;

LAB6:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 2776U);
    t3 = *((char **)t2);
    t2 = (t0 + 4776);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t22, 0, 8);
    t11 = (t22 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t22) = t8;
    t9 = *((unsigned int *)t12);
    t10 = (t9 >> 0);
    t19 = (t10 & 1);
    *((unsigned int *)t11) = t19;
    xsi_vlogtype_concat(t13, 2, 2, 2U, t22, 1, t3, 1);
    t14 = (t0 + 4776);
    t15 = (t0 + 4776);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t18 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t30, t17, 2, t18, 32, 1);
    t21 = (t30 + 4);
    t28 = *((unsigned int *)t21);
    t20 = (!(t28));
    if (t20 == 1)
        goto LAB12;

LAB13:    t23 = (t0 + 4776);
    t24 = (t0 + 4776);
    t25 = (t24 + 72U);
    t26 = *((char **)t25);
    t27 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t31, t26, 2, t27, 32, 1);
    t32 = (t31 + 4);
    t33 = *((unsigned int *)t32);
    t29 = (!(t33));
    if (t29 == 1)
        goto LAB14;

LAB15:
LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(101, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4776);
    t14 = (t0 + 4776);
    t15 = (t14 + 72U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t13, t16, 2, t17, 32, 1);
    t18 = (t13 + 4);
    t19 = *((unsigned int *)t18);
    t20 = (!(t19));
    if (t20 == 1)
        goto LAB8;

LAB9:    t21 = (t0 + 4776);
    t23 = (t0 + 4776);
    t24 = (t23 + 72U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t22, t25, 2, t26, 32, 1);
    t27 = (t22 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (!(t28));
    if (t29 == 1)
        goto LAB10;

LAB11:    goto LAB7;

LAB8:    xsi_vlogvar_wait_assign_value(t12, t11, 0, *((unsigned int *)t13), 1, 0LL);
    goto LAB9;

LAB10:    xsi_vlogvar_wait_assign_value(t21, t11, 1, *((unsigned int *)t22), 1, 0LL);
    goto LAB11;

LAB12:    xsi_vlogvar_wait_assign_value(t14, t13, 0, *((unsigned int *)t30), 1, 0LL);
    goto LAB13;

LAB14:    xsi_vlogvar_wait_assign_value(t23, t13, 1, *((unsigned int *)t31), 1, 0LL);
    goto LAB15;

}

static void Always_108_9(char *t0)
{
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

LAB0:    t1 = (t0 + 8568U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 9280);
    *((int *)t2) = 1;
    t3 = (t0 + 8600);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(109, ng0);
    t4 = (t0 + 2616U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB5;

LAB6:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 3576U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 4056U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:
LAB13:
LAB10:
LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(109, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 5416);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 0LL);
    goto LAB7;

LAB8:    xsi_set_current_line(110, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t0 + 5416);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    goto LAB10;

LAB11:    xsi_set_current_line(111, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 5416);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    goto LAB13;

}

static void Always_135_10(char *t0)
{
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

LAB0:    t1 = (t0 + 8816U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(135, ng0);
    t2 = (t0 + 9296);
    *((int *)t2) = 1;
    t3 = (t0 + 8848);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(136, ng0);
    t4 = (t0 + 2616U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB5;

LAB6:    xsi_set_current_line(137, ng0);
    t2 = (t0 + 3896U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB8;

LAB9:
LAB10:
LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(136, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4456);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 16, 0LL);
    goto LAB7;

LAB8:    xsi_set_current_line(137, ng0);
    t4 = (t0 + 3256U);
    t5 = *((char **)t4);
    t4 = (t0 + 4456);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 16, 0LL);
    goto LAB10;

}


extern void work_m_00000000003873964078_2648976750_init()
{
	static char *pe[] = {(void *)Cont_33_0,(void *)Always_35_1,(void *)Cont_43_2,(void *)Always_45_3,(void *)Always_63_4,(void *)Cont_67_5,(void *)Always_69_6,(void *)Cont_98_7,(void *)Always_100_8,(void *)Always_108_9,(void *)Always_135_10};
	xsi_register_didat("work_m_00000000003873964078_2648976750", "isim/ReferenceDesign_tf_isim_beh.exe.sim/work/m_00000000003873964078_2648976750.didat");
	xsi_register_executes(pe);
}
