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

/* This file is designed for use with ISim build 0xc3576ebc */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/tniel/Desktop/Skole arbejde/DTU/Digital techniques/Three_week_course_F22/Protokol.vhd";
extern char *IEEE_P_3620187407;

unsigned char ieee_p_3620187407_sub_4042748798_3965413181(char *, char *, char *, char *, char *);


static void work_a_1982020340_3212880686_p_0(char *t0)
{
    char t13[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    static char *nl0[] = {&&LAB16, &&LAB17, &&LAB18, &&LAB15, &&LAB14};

LAB0:    xsi_set_current_line(26, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 992U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 4432);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(27, ng0);
    t1 = (t0 + 4512);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)4;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(30, ng0);
    t2 = (t0 + 2312U);
    t6 = *((char **)t2);
    t2 = (t0 + 4576);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t6, 8U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(31, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t1 = (t0 + 4640);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(32, ng0);
    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 4704);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(34, ng0);
    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t1 = (t0 + 8368U);
    t5 = (t0 + 8443);
    t7 = (t13 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 7;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t14 = (7 - 0);
    t15 = (t14 * 1);
    t15 = (t15 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t15;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t13);
    if (t3 != 0)
        goto LAB10;

LAB12:
LAB11:    xsi_set_current_line(38, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (char *)((nl0) + t3);
    goto **((char **)t1);

LAB7:    t2 = (t0 + 1032U);
    t5 = *((char **)t2);
    t9 = *((unsigned char *)t5);
    t10 = (t9 == (unsigned char)3);
    t3 = t10;
    goto LAB9;

LAB10:    xsi_set_current_line(35, ng0);
    t8 = (t0 + 4768);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t8);
    goto LAB11;

LAB13:    goto LAB3;

LAB14:    xsi_set_current_line(40, ng0);
    t5 = (t0 + 8451);
    t7 = (t0 + 4832);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    memcpy(t16, t5, 8U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(41, ng0);
    t1 = (t0 + 8459);
    t5 = (t0 + 4896);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t1, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(42, ng0);
    t1 = (t0 + 8467);
    t5 = (t0 + 4960);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t1, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(43, ng0);
    t1 = (t0 + 4512);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB13;

LAB15:    xsi_set_current_line(46, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 8304U);
    t5 = (t0 + 8475);
    t7 = (t13 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 7;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t14 = (7 - 0);
    t15 = (t14 * 1);
    t15 = (t15 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t15;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t13);
    if (t3 != 0)
        goto LAB19;

LAB21:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 8304U);
    t5 = (t0 + 8483);
    t7 = (t13 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 7;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t14 = (7 - 0);
    t15 = (t14 * 1);
    t15 = (t15 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t15;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t13);
    if (t3 != 0)
        goto LAB22;

LAB23:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 8304U);
    t5 = (t0 + 8491);
    t7 = (t13 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 7;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t14 = (7 - 0);
    t15 = (t14 * 1);
    t15 = (t15 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t15;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t13);
    if (t3 != 0)
        goto LAB24;

LAB25:
LAB20:    goto LAB13;

LAB16:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 8304U);
    t5 = (t0 + 8499);
    t7 = (t13 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 7;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t14 = (7 - 0);
    t15 = (t14 * 1);
    t15 = (t15 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t15;
    t3 = ieee_p_3620187407_sub_4042748798_3965413181(IEEE_P_3620187407, t2, t1, t5, t13);
    if (t3 != 0)
        goto LAB26;

LAB28:
LAB27:    goto LAB13;

LAB17:    xsi_set_current_line(66, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 8304U);
    t5 = (t0 + 8515);
    t7 = (t13 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 7;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t14 = (7 - 0);
    t15 = (t14 * 1);
    t15 = (t15 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t15;
    t3 = ieee_p_3620187407_sub_4042748798_3965413181(IEEE_P_3620187407, t2, t1, t5, t13);
    if (t3 != 0)
        goto LAB32;

LAB34:
LAB33:    goto LAB13;

LAB18:    xsi_set_current_line(77, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 8304U);
    t5 = (t0 + 8531);
    t7 = (t13 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 7;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t14 = (7 - 0);
    t15 = (t14 * 1);
    t15 = (t15 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t15;
    t3 = ieee_p_3620187407_sub_4042748798_3965413181(IEEE_P_3620187407, t2, t1, t5, t13);
    if (t3 != 0)
        goto LAB38;

LAB40:
LAB39:    goto LAB13;

LAB19:    xsi_set_current_line(47, ng0);
    t8 = (t0 + 4512);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)0;
    xsi_driver_first_trans_fast(t8);
    goto LAB20;

LAB22:    xsi_set_current_line(49, ng0);
    t8 = (t0 + 4512);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)1;
    xsi_driver_first_trans_fast(t8);
    goto LAB20;

LAB24:    xsi_set_current_line(51, ng0);
    t8 = (t0 + 4512);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)2;
    xsi_driver_first_trans_fast(t8);
    goto LAB20;

LAB26:    xsi_set_current_line(56, ng0);
    t8 = (t0 + 1352U);
    t11 = *((char **)t8);
    t8 = (t0 + 4832);
    t12 = (t8 + 56U);
    t16 = *((char **)t12);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t11, 8U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(57, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 8304U);
    t5 = (t0 + 2312U);
    t6 = *((char **)t5);
    t5 = (t0 + 8368U);
    t3 = ieee_p_3620187407_sub_4042748798_3965413181(IEEE_P_3620187407, t2, t1, t6, t5);
    if (t3 != 0)
        goto LAB29;

LAB31:
LAB30:    goto LAB27;

LAB29:    xsi_set_current_line(58, ng0);
    t7 = (t0 + 1352U);
    t8 = *((char **)t7);
    t7 = (t0 + 5024);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t8, 8U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(60, ng0);
    t1 = (t0 + 8507);
    t5 = (t0 + 5088);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t1, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(61, ng0);
    t1 = (t0 + 4512);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB30;

LAB32:    xsi_set_current_line(67, ng0);
    t8 = (t0 + 1352U);
    t11 = *((char **)t8);
    t8 = (t0 + 4896);
    t12 = (t8 + 56U);
    t16 = *((char **)t12);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t11, 8U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(68, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 8304U);
    t5 = (t0 + 2472U);
    t6 = *((char **)t5);
    t5 = (t0 + 8368U);
    t3 = ieee_p_3620187407_sub_4042748798_3965413181(IEEE_P_3620187407, t2, t1, t6, t5);
    if (t3 != 0)
        goto LAB35;

LAB37:
LAB36:    goto LAB33;

LAB35:    xsi_set_current_line(69, ng0);
    t7 = (t0 + 1352U);
    t8 = *((char **)t7);
    t7 = (t0 + 5024);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t8, 8U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(71, ng0);
    t1 = (t0 + 8523);
    t5 = (t0 + 5088);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t1, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(72, ng0);
    t1 = (t0 + 4512);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB36;

LAB38:    xsi_set_current_line(78, ng0);
    t8 = (t0 + 1352U);
    t11 = *((char **)t8);
    t8 = (t0 + 4960);
    t12 = (t8 + 56U);
    t16 = *((char **)t12);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t11, 8U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(79, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 8304U);
    t5 = (t0 + 2632U);
    t6 = *((char **)t5);
    t5 = (t0 + 8368U);
    t3 = ieee_p_3620187407_sub_4042748798_3965413181(IEEE_P_3620187407, t2, t1, t6, t5);
    if (t3 != 0)
        goto LAB41;

LAB43:
LAB42:    goto LAB39;

LAB41:    xsi_set_current_line(80, ng0);
    t7 = (t0 + 1352U);
    t8 = *((char **)t7);
    t7 = (t0 + 5024);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t8, 8U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(82, ng0);
    t1 = (t0 + 8539);
    t5 = (t0 + 5088);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t1, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(83, ng0);
    t1 = (t0 + 4512);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB42;

}


extern void work_a_1982020340_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1982020340_3212880686_p_0};
	xsi_register_didat("work_a_1982020340_3212880686", "isim/protokol_tb1_isim_beh.exe.sim/work/a_1982020340_3212880686.didat");
	xsi_register_executes(pe);
}
