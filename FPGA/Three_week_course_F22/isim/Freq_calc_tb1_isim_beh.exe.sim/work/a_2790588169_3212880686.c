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
static const char *ng0 = "C:/Users/tniel/OneDrive/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/Three_week_course_F22/Freq_calc.vhd";
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);


static void work_a_2790588169_3212880686_p_0(char *t0)
{
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
    int t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    int t16;
    int t17;
    int t18;

LAB0:    xsi_set_current_line(25, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1152U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 3792);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(26, ng0);
    t1 = (t0 + 3872);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 1;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 1032U);
    t6 = *((char **)t2);
    t2 = (t0 + 6784U);
    t11 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t6, t2);
    t7 = (t0 + 3936);
    t8 = (t7 + 56U);
    t12 = *((char **)t8);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((int *)t14) = t11;
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(29, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t1 = (t0 + 6800U);
    t11 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t15 = (t11 * 2);
    t5 = (t0 + 4000);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t12 = *((char **)t8);
    *((int *)t12) = t15;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(31, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t11 = *((int *)t2);
    t4 = (t11 != 1);
    if (t4 == 1)
        goto LAB13;

LAB14:    t1 = (t0 + 1992U);
    t5 = *((char **)t1);
    t15 = *((int *)t5);
    t9 = (t15 != 1);
    t3 = t9;

LAB15:    if (t3 != 0)
        goto LAB10;

LAB12:
LAB11:    xsi_set_current_line(35, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t11 = *((int *)t2);
    t4 = (t11 != 1);
    if (t4 == 1)
        goto LAB19;

LAB20:    t1 = (t0 + 1992U);
    t5 = *((char **)t1);
    t15 = *((int *)t5);
    t9 = (t15 != 1);
    t3 = t9;

LAB21:    if (t3 != 0)
        goto LAB16;

LAB18:
LAB17:    goto LAB3;

LAB7:    t2 = (t0 + 1192U);
    t5 = *((char **)t2);
    t9 = *((unsigned char *)t5);
    t10 = (t9 == (unsigned char)3);
    t3 = t10;
    goto LAB9;

LAB10:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 1992U);
    t6 = *((char **)t1);
    t16 = *((int *)t6);
    t17 = (512 / t16);
    t1 = (t0 + 4064);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t12 = (t8 + 56U);
    t13 = *((char **)t12);
    *((int *)t13) = t17;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(33, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t11 = *((int *)t2);
    t15 = (1024 / t11);
    t1 = (t0 + 4128);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = t15;
    xsi_driver_first_trans_fast(t1);
    goto LAB11;

LAB13:    t3 = (unsigned char)1;
    goto LAB15;

LAB16:    xsi_set_current_line(36, ng0);
    t1 = (t0 + 2152U);
    t6 = *((char **)t1);
    t16 = *((int *)t6);
    t1 = (t0 + 2312U);
    t7 = *((char **)t1);
    t17 = *((int *)t7);
    t18 = (t16 * t17);
    t1 = (t0 + 3872);
    t8 = (t1 + 56U);
    t12 = *((char **)t8);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((int *)t14) = t18;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB17;

LAB19:    t3 = (unsigned char)1;
    goto LAB21;

}


extern void work_a_2790588169_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2790588169_3212880686_p_0};
	xsi_register_didat("work_a_2790588169_3212880686", "isim/Freq_calc_tb1_isim_beh.exe.sim/work/a_2790588169_3212880686.didat");
	xsi_register_executes(pe);
}
