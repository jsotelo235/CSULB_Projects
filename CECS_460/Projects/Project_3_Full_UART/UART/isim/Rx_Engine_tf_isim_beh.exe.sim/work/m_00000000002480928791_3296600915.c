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
static const char *ng0 = "D:/CSULB_Classes/CECS_460/Projects/Project_3_Full_UART/UART/Rx_Remap.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};



static void Always_34_0(char *t0)
{
    char t7[8];
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 2528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 2848);
    *((int *)t2) = 1;
    t3 = (t0 + 2560);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(35, ng0);
    t4 = (t0 + 1048U);
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
LAB15:
LAB14:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    memset(t8, 0, 8);
    t2 = (t8 + 4);
    t4 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (t12 >> 2);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 2);
    *((unsigned int *)t2) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 255U);
    t17 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t17 & 255U);
    t9 = ((char*)((ng1)));
    xsi_vlogtype_concat(t7, 10, 10, 2U, t9, 2, t8, 8);
    t10 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t10, t7, 0, 0, 10, 0LL);

LAB16:    goto LAB2;

LAB6:    xsi_set_current_line(36, ng0);
    t9 = (t0 + 1208U);
    t10 = *((char **)t9);
    memset(t8, 0, 8);
    t9 = (t8 + 4);
    t11 = (t10 + 4);
    t12 = *((unsigned int *)t10);
    t13 = (t12 >> 2);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t11);
    t15 = (t14 >> 2);
    *((unsigned int *)t9) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 255U);
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 255U);
    t18 = ((char*)((ng1)));
    xsi_vlogtype_concat(t7, 10, 10, 2U, t18, 2, t8, 8);
    t19 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t19, t7, 0, 0, 10, 0LL);
    goto LAB16;

LAB8:    xsi_set_current_line(37, ng0);
    t3 = (t0 + 1208U);
    t4 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4);
    t9 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 1);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t9);
    t15 = (t14 >> 1);
    *((unsigned int *)t3) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 511U);
    t17 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t17 & 511U);
    t10 = ((char*)((ng1)));
    xsi_vlogtype_concat(t7, 10, 10, 2U, t10, 1, t8, 9);
    t11 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t11, t7, 0, 0, 10, 0LL);
    goto LAB16;

LAB10:    xsi_set_current_line(38, ng0);
    t3 = (t0 + 1208U);
    t4 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4);
    t9 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 1);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t9);
    t15 = (t14 >> 1);
    *((unsigned int *)t3) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 511U);
    t17 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t17 & 511U);
    t10 = ((char*)((ng1)));
    xsi_vlogtype_concat(t7, 10, 10, 2U, t10, 1, t8, 9);
    t11 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t11, t7, 0, 0, 10, 0LL);
    goto LAB16;

LAB12:    xsi_set_current_line(39, ng0);
    t3 = (t0 + 1208U);
    t4 = *((char **)t3);
    t3 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 10, 0LL);
    goto LAB16;

}


extern void work_m_00000000002480928791_3296600915_init()
{
	static char *pe[] = {(void *)Always_34_0};
	xsi_register_didat("work_m_00000000002480928791_3296600915", "isim/Rx_Engine_tf_isim_beh.exe.sim/work/m_00000000002480928791_3296600915.didat");
	xsi_register_executes(pe);
}
