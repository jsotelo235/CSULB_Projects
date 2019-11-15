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
static const char *ng0 = "D:/301/Lab3/LabProject2/hex_to_7segment.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {79U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {18U, 0U};
static unsigned int ng6[] = {3U, 0U};
static unsigned int ng7[] = {6U, 0U};
static unsigned int ng8[] = {4U, 0U};
static unsigned int ng9[] = {76U, 0U};
static unsigned int ng10[] = {5U, 0U};
static unsigned int ng11[] = {36U, 0U};
static unsigned int ng12[] = {32U, 0U};
static unsigned int ng13[] = {7U, 0U};
static unsigned int ng14[] = {15U, 0U};
static unsigned int ng15[] = {8U, 0U};
static unsigned int ng16[] = {9U, 0U};
static unsigned int ng17[] = {10U, 0U};
static unsigned int ng18[] = {11U, 0U};
static unsigned int ng19[] = {96U, 0U};
static unsigned int ng20[] = {12U, 0U};
static unsigned int ng21[] = {49U, 0U};
static unsigned int ng22[] = {13U, 0U};
static unsigned int ng23[] = {66U, 0U};
static unsigned int ng24[] = {14U, 0U};
static unsigned int ng25[] = {48U, 0U};
static unsigned int ng26[] = {113U, 0U};
static unsigned int ng27[] = {126U, 0U};



static void Always_47_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    t1 = (t0 + 3328U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 3648);
    *((int *)t2) = 1;
    t3 = (t0 + 3360);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(48, ng0);
    t4 = (t0 + 1048U);
    t5 = *((char **)t4);

LAB5:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t4, 4);
    if (t6 == 1)
        goto LAB6;

LAB7:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB8;

LAB9:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB10;

LAB11:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB12;

LAB13:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB14;

LAB15:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB18;

LAB19:    t2 = ((char*)((ng13)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB20;

LAB21:    t2 = ((char*)((ng15)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB22;

LAB23:    t2 = ((char*)((ng16)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng17)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB26;

LAB27:    t2 = ((char*)((ng18)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB28;

LAB29:    t2 = ((char*)((ng20)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB30;

LAB31:    t2 = ((char*)((ng22)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB32;

LAB33:    t2 = ((char*)((ng24)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB34;

LAB35:    t2 = ((char*)((ng14)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB36;

LAB37:
LAB39:
LAB38:    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng27)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    t4 = (t0 + 2248);
    xsi_vlogvar_assign_value(t4, t2, 1, 0, 1);
    t7 = (t0 + 2088);
    xsi_vlogvar_assign_value(t7, t2, 2, 0, 1);
    t8 = (t0 + 1928);
    xsi_vlogvar_assign_value(t8, t2, 3, 0, 1);
    t9 = (t0 + 1768);
    xsi_vlogvar_assign_value(t9, t2, 4, 0, 1);
    t10 = (t0 + 1608);
    xsi_vlogvar_assign_value(t10, t2, 5, 0, 1);
    t11 = (t0 + 1448);
    xsi_vlogvar_assign_value(t11, t2, 6, 0, 1);

LAB40:    goto LAB2;

LAB6:    xsi_set_current_line(49, ng0);
    t7 = ((char*)((ng2)));
    t8 = (t0 + 2408);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 1);
    t9 = (t0 + 2248);
    xsi_vlogvar_assign_value(t9, t7, 1, 0, 1);
    t10 = (t0 + 2088);
    xsi_vlogvar_assign_value(t10, t7, 2, 0, 1);
    t11 = (t0 + 1928);
    xsi_vlogvar_assign_value(t11, t7, 3, 0, 1);
    t12 = (t0 + 1768);
    xsi_vlogvar_assign_value(t12, t7, 4, 0, 1);
    t13 = (t0 + 1608);
    xsi_vlogvar_assign_value(t13, t7, 5, 0, 1);
    t14 = (t0 + 1448);
    xsi_vlogvar_assign_value(t14, t7, 6, 0, 1);
    goto LAB40;

LAB8:    xsi_set_current_line(50, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB10:    xsi_set_current_line(51, ng0);
    t3 = ((char*)((ng5)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB12:    xsi_set_current_line(52, ng0);
    t3 = ((char*)((ng7)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB14:    xsi_set_current_line(53, ng0);
    t3 = ((char*)((ng9)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB16:    xsi_set_current_line(54, ng0);
    t3 = ((char*)((ng11)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB18:    xsi_set_current_line(55, ng0);
    t3 = ((char*)((ng12)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB20:    xsi_set_current_line(56, ng0);
    t3 = ((char*)((ng14)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB22:    xsi_set_current_line(57, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB24:    xsi_set_current_line(58, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB26:    xsi_set_current_line(59, ng0);
    t3 = ((char*)((ng15)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB28:    xsi_set_current_line(60, ng0);
    t3 = ((char*)((ng19)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB30:    xsi_set_current_line(61, ng0);
    t3 = ((char*)((ng21)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB32:    xsi_set_current_line(62, ng0);
    t3 = ((char*)((ng23)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB34:    xsi_set_current_line(63, ng0);
    t3 = ((char*)((ng25)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

LAB36:    xsi_set_current_line(64, ng0);
    t3 = ((char*)((ng26)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 1, 0, 1);
    t8 = (t0 + 2088);
    xsi_vlogvar_assign_value(t8, t3, 2, 0, 1);
    t9 = (t0 + 1928);
    xsi_vlogvar_assign_value(t9, t3, 3, 0, 1);
    t10 = (t0 + 1768);
    xsi_vlogvar_assign_value(t10, t3, 4, 0, 1);
    t11 = (t0 + 1608);
    xsi_vlogvar_assign_value(t11, t3, 5, 0, 1);
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t3, 6, 0, 1);
    goto LAB40;

}


extern void work_m_00000000003979396308_3057664381_init()
{
	static char *pe[] = {(void *)Always_47_0};
	xsi_register_didat("work_m_00000000003979396308_3057664381", "isim/lab3_top_module_isim_beh.exe.sim/work/m_00000000003979396308_3057664381.didat");
	xsi_register_executes(pe);
}
