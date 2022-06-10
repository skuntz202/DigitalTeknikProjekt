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
static const char *ng0 = "C:/Users/tniel/OneDrive - Danmarks Tekniske Universitet/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/Three_week_course_F22/PWM.vhd";
extern char *IEEE_P_3620187407;

unsigned char ieee_p_3620187407_sub_4060537613_3965413181(char *, char *, char *, char *, char *);
char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );
char *ieee_p_3620187407_sub_436351764_3965413181(char *, char *, char *, char *, int );


static void work_a_2525893486_3212880686_p_0(char *t0)
{
    char t16[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned char t12;
    unsigned char t13;
    unsigned char t14;
    unsigned char t15;
    unsigned int t17;
    unsigned int t18;
    unsigned char t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;

LAB0:    xsi_set_current_line(28, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 992U);
    t11 = xsi_signal_has_event(t1);
    if (t11 == 1)
        goto LAB10;

LAB11:    t4 = (unsigned char)0;

LAB12:    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 4200);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(29, ng0);
    t1 = (t0 + 7892);
    t6 = (t0 + 4296);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast(t6);
    goto LAB3;

LAB5:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 2152U);
    t7 = *((char **)t2);
    t2 = (t0 + 7808U);
    t8 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t16, t7, t2, 1);
    t9 = (t16 + 12U);
    t17 = *((unsigned int *)t9);
    t18 = (1U * t17);
    t19 = (8U != t18);
    if (t19 == 1)
        goto LAB13;

LAB14:    t10 = (t0 + 4296);
    t20 = (t10 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t8, 8U);
    xsi_driver_first_trans_fast(t10);
    goto LAB3;

LAB7:    t2 = (t0 + 1832U);
    t6 = *((char **)t2);
    t14 = *((unsigned char *)t6);
    t15 = (t14 == (unsigned char)3);
    t3 = t15;
    goto LAB9;

LAB10:    t2 = (t0 + 1032U);
    t5 = *((char **)t2);
    t12 = *((unsigned char *)t5);
    t13 = (t12 == (unsigned char)3);
    t4 = t13;
    goto LAB12;

LAB13:    xsi_size_not_matching(8U, t18, 0);
    goto LAB14;

}

static void work_a_2525893486_3212880686_p_1(char *t0)
{
    char t5[16];
    char t21[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    int t8;
    unsigned int t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned char t20;
    unsigned int t22;
    unsigned char t23;
    char *t24;

LAB0:    xsi_set_current_line(38, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7760U);
    t3 = (t0 + 7900);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 7;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (7 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t10 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t3, t5);
    if (t10 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7760U);
    t3 = (t0 + 7908);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 7;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (7 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t10 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t3, t5);
    if (t10 != 0)
        goto LAB5;

LAB6:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7760U);
    t3 = (t0 + 7932);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 7;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (7 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t10 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t3, t5);
    if (t10 != 0)
        goto LAB28;

LAB29:
LAB3:    t1 = (t0 + 4216);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(39, ng0);
    t7 = (t0 + 4360);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t7);
    goto LAB3;

LAB5:    xsi_set_current_line(43, ng0);
    t7 = (t0 + 2312U);
    t11 = *((char **)t7);
    t7 = (t0 + 7824U);
    t12 = (t0 + 2152U);
    t13 = *((char **)t12);
    t12 = (t0 + 7808U);
    t15 = ieee_p_3620187407_sub_4060537613_3965413181(IEEE_P_3620187407, t11, t7, t13, t12);
    if (t15 != 0)
        goto LAB7;

LAB9:    xsi_set_current_line(46, ng0);
    t1 = (t0 + 4360);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t6 = *((char **)t4);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB8:    xsi_set_current_line(49, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 7808U);
    t3 = (t0 + 7916);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 7;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (7 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t10 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t3, t5);
    if (t10 != 0)
        goto LAB10;

LAB12:
LAB11:    goto LAB3;

LAB7:    xsi_set_current_line(44, ng0);
    t14 = (t0 + 4360);
    t16 = (t14 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t14);
    goto LAB8;

LAB10:    xsi_set_current_line(50, ng0);
    t7 = (t0 + 2472U);
    t11 = *((char **)t7);
    t15 = *((unsigned char *)t11);
    t20 = (t15 == (unsigned char)3);
    if (t20 != 0)
        goto LAB13;

LAB15:    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t10 = *((unsigned char *)t2);
    t15 = (t10 == (unsigned char)2);
    if (t15 != 0)
        goto LAB21;

LAB22:
LAB14:    goto LAB11;

LAB13:    xsi_set_current_line(51, ng0);
    t7 = (t0 + 2312U);
    t12 = *((char **)t7);
    t7 = (t0 + 7824U);
    t13 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t21, t12, t7, 1);
    t14 = (t21 + 12U);
    t9 = *((unsigned int *)t14);
    t22 = (1U * t9);
    t23 = (8U != t22);
    if (t23 == 1)
        goto LAB16;

LAB17:    t16 = (t0 + 4424);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t24 = *((char **)t19);
    memcpy(t24, t13, 8U);
    xsi_driver_first_trans_fast(t16);
    xsi_set_current_line(52, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t1 = (t0 + 7824U);
    t3 = (t0 + 1512U);
    t4 = *((char **)t3);
    t3 = (t0 + 7776U);
    t10 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t4, t3);
    if (t10 != 0)
        goto LAB18;

LAB20:
LAB19:    goto LAB14;

LAB16:    xsi_size_not_matching(8U, t22, 0);
    goto LAB17;

LAB18:    xsi_set_current_line(53, ng0);
    t6 = (t0 + 4488);
    t7 = (t6 + 56U);
    t11 = *((char **)t7);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)2;
    xsi_driver_first_trans_fast(t6);
    goto LAB19;

LAB21:    xsi_set_current_line(57, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t1 = (t0 + 7824U);
    t4 = ieee_p_3620187407_sub_436351764_3965413181(IEEE_P_3620187407, t5, t3, t1, 1);
    t6 = (t5 + 12U);
    t9 = *((unsigned int *)t6);
    t22 = (1U * t9);
    t20 = (8U != t22);
    if (t20 == 1)
        goto LAB23;

LAB24:    t7 = (t0 + 4424);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t4, 8U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(58, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t1 = (t0 + 7824U);
    t3 = (t0 + 7924);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 7;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (7 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t10 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t3, t5);
    if (t10 != 0)
        goto LAB25;

LAB27:
LAB26:    goto LAB14;

LAB23:    xsi_size_not_matching(8U, t22, 0);
    goto LAB24;

LAB25:    xsi_set_current_line(59, ng0);
    t7 = (t0 + 4488);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)3;
    xsi_driver_first_trans_fast(t7);
    goto LAB26;

LAB28:    xsi_set_current_line(66, ng0);
    t7 = (t0 + 1512U);
    t11 = *((char **)t7);
    t7 = (t0 + 7776U);
    t12 = (t0 + 2152U);
    t13 = *((char **)t12);
    t12 = (t0 + 7808U);
    t15 = ieee_p_3620187407_sub_4060537613_3965413181(IEEE_P_3620187407, t11, t7, t13, t12);
    if (t15 != 0)
        goto LAB30;

LAB32:    xsi_set_current_line(69, ng0);
    t1 = (t0 + 4360);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t6 = *((char **)t4);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB31:    goto LAB3;

LAB30:    xsi_set_current_line(67, ng0);
    t14 = (t0 + 4360);
    t16 = (t14 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t14);
    goto LAB31;

}


extern void work_a_2525893486_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2525893486_3212880686_p_0,(void *)work_a_2525893486_3212880686_p_1};
	xsi_register_didat("work_a_2525893486_3212880686", "isim/Top_tb1_isim_beh.exe.sim/work/a_2525893486_3212880686.didat");
	xsi_register_executes(pe);
}
