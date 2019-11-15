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
static const char *ng0 = "D:/CSULB_Classes/CECS_460/Projects/Project_2/UART/bit_time_counter.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};
static int ng5[] = {333333, 0};
static int ng6[] = {1, 0};
static int ng7[] = {83333, 0};
static int ng8[] = {41667, 0};
static int ng9[] = {20833, 0};
static unsigned int ng10[] = {4U, 0U};
static int ng11[] = {10417, 0};
static unsigned int ng12[] = {5U, 0U};
static int ng13[] = {5208, 0};
static unsigned int ng14[] = {6U, 0U};
static int ng15[] = {2604, 0};
static unsigned int ng16[] = {7U, 0U};
static int ng17[] = {1736, 0};
static unsigned int ng18[] = {8U, 0U};
static int ng19[] = {868, 0};
static unsigned int ng20[] = {9U, 0U};
static int ng21[] = {434, 0};
static unsigned int ng22[] = {10U, 0U};
static int ng23[] = {217, 0};
static unsigned int ng24[] = {11U, 0U};
static int ng25[] = {109, 0};



static void Always_38_0(char *t0)
{
    char t9[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    char *t10;

LAB0:    t1 = (t0 + 3328U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 4392);
    *((int *)t2) = 1;
    t3 = (t0 + 3360);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(39, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);

LAB5:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t4, 2);
    if (t6 == 1)
        goto LAB6;

LAB7:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB8;

LAB9:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB10;

LAB11:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB12;

LAB13:
LAB14:    goto LAB2;

LAB6:    xsi_set_current_line(40, ng0);
    t7 = ((char*)((ng1)));
    t8 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t8, t7, 0, 0, 19, 0LL);
    goto LAB14;

LAB8:    xsi_set_current_line(41, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 19, 0LL);
    goto LAB14;

LAB10:    xsi_set_current_line(42, ng0);
    t3 = (t0 + 2408);
    t4 = (t3 + 56U);
    t7 = *((char **)t4);
    t8 = ((char*)((ng2)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 19, t7, 19, t8, 19);
    t10 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 19, 0LL);
    goto LAB14;

LAB12:    xsi_set_current_line(43, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 19, 0LL);
    goto LAB14;

}

static void Always_47_1(char *t0)
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

LAB0:    t1 = (t0 + 3576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 4408);
    *((int *)t2) = 1;
    t3 = (t0 + 3608);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(48, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB5;

LAB6:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 19, 0LL);

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(49, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 19, 0LL);
    goto LAB7;

}

static void Always_60_2(char *t0)
{
    char t9[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    char *t10;

LAB0:    t1 = (t0 + 3824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 4424);
    *((int *)t2) = 1;
    t3 = (t0 + 3856);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(61, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);

LAB5:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t4, 4);
    if (t6 == 1)
        goto LAB6;

LAB7:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB8;

LAB9:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB10;

LAB11:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB12;

LAB13:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB14;

LAB15:    t2 = ((char*)((ng12)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng14)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB18;

LAB19:    t2 = ((char*)((ng16)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB20;

LAB21:    t2 = ((char*)((ng18)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB22;

LAB23:    t2 = ((char*)((ng20)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng22)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB26;

LAB27:    t2 = ((char*)((ng24)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB28;

LAB29:
LAB31:
LAB30:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t2, 32, t3, 32);
    t4 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t4, t9, 0, 0, 19, 0LL);

LAB32:    goto LAB2;

LAB6:    xsi_set_current_line(62, ng0);
    t7 = ((char*)((ng5)));
    t8 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t7, 32, t8, 32);
    t10 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB8:    xsi_set_current_line(63, ng0);
    t3 = ((char*)((ng7)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB10:    xsi_set_current_line(64, ng0);
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB12:    xsi_set_current_line(65, ng0);
    t3 = ((char*)((ng9)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB14:    xsi_set_current_line(66, ng0);
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB16:    xsi_set_current_line(67, ng0);
    t3 = ((char*)((ng13)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB18:    xsi_set_current_line(68, ng0);
    t3 = ((char*)((ng15)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB20:    xsi_set_current_line(69, ng0);
    t3 = ((char*)((ng17)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB22:    xsi_set_current_line(70, ng0);
    t3 = ((char*)((ng19)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB24:    xsi_set_current_line(71, ng0);
    t3 = ((char*)((ng21)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB26:    xsi_set_current_line(72, ng0);
    t3 = ((char*)((ng23)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

LAB28:    xsi_set_current_line(73, ng0);
    t3 = ((char*)((ng25)));
    t4 = ((char*)((ng6)));
    memset(t9, 0, 8);
    xsi_vlog_signed_minus(t9, 32, t3, 32, t4, 32);
    t7 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t7, t9, 0, 0, 19, 0LL);
    goto LAB32;

}

static void Cont_78_3(char *t0)
{
    char t3[8];
    char t4[8];
    char t10[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;

LAB0:    t1 = (t0 + 4072U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(78, ng0);
    t2 = (t0 + 2408);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2088);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t10, 0, 8);
    t11 = (t6 + 4);
    t12 = (t9 + 4);
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t9);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB7;

LAB4:    if (t22 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t10) = 1;

LAB7:    memset(t4, 0, 8);
    t26 = (t10 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t10);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t26) != 0)
        goto LAB10;

LAB11:    t33 = (t4 + 4);
    t34 = *((unsigned int *)t4);
    t35 = *((unsigned int *)t33);
    t36 = (t34 || t35);
    if (t36 > 0)
        goto LAB12;

LAB13:    t38 = *((unsigned int *)t4);
    t39 = (~(t38));
    t40 = *((unsigned int *)t33);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t33) > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t4) > 0)
        goto LAB18;

LAB19:    memcpy(t3, t42, 8);

LAB20:    t43 = (t0 + 4520);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    memset(t47, 0, 8);
    t48 = 1U;
    t49 = t48;
    t50 = (t3 + 4);
    t51 = *((unsigned int *)t3);
    t48 = (t48 & t51);
    t52 = *((unsigned int *)t50);
    t49 = (t49 & t52);
    t53 = (t47 + 4);
    t54 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t54 | t48);
    t55 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t55 | t49);
    xsi_driver_vfirst_trans(t43, 0, 0);
    t56 = (t0 + 4440);
    *((int *)t56) = 1;

LAB1:    return;
LAB6:    t25 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB11;

LAB10:    t32 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB11;

LAB12:    t37 = ((char*)((ng2)));
    goto LAB13;

LAB14:    t42 = ((char*)((ng1)));
    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 1, t37, 1, t42, 1);
    goto LAB20;

LAB18:    memcpy(t3, t37, 8);
    goto LAB20;

}


extern void work_m_00000000003808734566_1606674845_init()
{
	static char *pe[] = {(void *)Always_38_0,(void *)Always_47_1,(void *)Always_60_2,(void *)Cont_78_3};
	xsi_register_didat("work_m_00000000003808734566_1606674845", "isim/Tx_Engine_tf_isim_beh.exe.sim/work/m_00000000003808734566_1606674845.didat");
	xsi_register_executes(pe);
}
