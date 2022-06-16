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
static const char *ng0 = "C:/Users/tniel/OneDrive/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/Three_week_course_F22/Freq_calc.vhd";
extern char *IEEE_P_1242562249;
extern char *IEEE_P_3620187407;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);


static void work_a_3240190358_3212880686_p_0(char *t0)
{
    char t21[16];
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
    unsigned char t11;
    int t12;
    unsigned char t13;
    int t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t22;
    char *t23;

LAB0:    xsi_set_current_line(31, ng0);
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
LAB3:    t1 = (t0 + 4112);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 4192);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 1;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1032U);
    t6 = *((char **)t2);
    t2 = (t0 + 7356U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t6, t2);
    t13 = (t12 > 100);
    if (t13 == 1)
        goto LAB13;

LAB14:    t7 = (t0 + 1032U);
    t8 = *((char **)t7);
    t7 = (t0 + 7356U);
    t14 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t8, t7);
    t15 = (t14 == 0);
    t11 = t15;

LAB15:    if (t11 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 7356U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t5 = (t0 + 4256);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t16 = *((char **)t8);
    *((int *)t16) = t12;
    xsi_driver_first_trans_fast(t5);

LAB11:    xsi_set_current_line(42, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7372U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t3 = (t12 == 0);
    if (t3 != 0)
        goto LAB16;

LAB18:    xsi_set_current_line(45, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7372U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t5 = (t0 + 4320);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t16 = *((char **)t8);
    *((int *)t16) = t12;
    xsi_driver_first_trans_fast(t5);

LAB17:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t12 = *((int *)t2);
    t14 = (256 - t12);
    t1 = (t0 + 4384);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = t14;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(51, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t12 = *((int *)t2);
    t14 = (101 - t12);
    t1 = (t0 + 4448);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = t14;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(55, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB19;

LAB21:    xsi_set_current_line(68, ng0);
    t1 = (t0 + 4192);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 1;
    xsi_driver_first_trans_fast_port(t1);

LAB20:    goto LAB3;

LAB7:    t2 = (t0 + 1192U);
    t5 = *((char **)t2);
    t9 = *((unsigned char *)t5);
    t10 = (t9 == (unsigned char)3);
    t3 = t10;
    goto LAB9;

LAB10:    xsi_set_current_line(37, ng0);
    t16 = (t0 + 4256);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((int *)t20) = 100;
    xsi_driver_first_trans_fast(t16);
    goto LAB11;

LAB13:    t11 = (unsigned char)1;
    goto LAB15;

LAB16:    xsi_set_current_line(43, ng0);
    t5 = (t0 + 4320);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t16 = *((char **)t8);
    *((int *)t16) = 255;
    xsi_driver_first_trans_fast(t5);
    goto LAB17;

LAB19:    xsi_set_current_line(56, ng0);
    t1 = (t0 + 1832U);
    t5 = *((char **)t1);
    t1 = (t0 + 7388U);
    t6 = (t0 + 7456);
    t8 = (t21 + 0U);
    t16 = (t8 + 0U);
    *((int *)t16) = 0;
    t16 = (t8 + 4U);
    *((int *)t16) = 7;
    t16 = (t8 + 8U);
    *((int *)t16) = 1;
    t12 = (7 - 0);
    t22 = (t12 * 1);
    t22 = (t22 + 1);
    t16 = (t8 + 12U);
    *((unsigned int *)t16) = t22;
    t9 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t5, t1, t6, t21);
    if (t9 != 0)
        goto LAB22;

LAB24:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 7388U);
    t5 = (t0 + 7464);
    t7 = (t21 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 7;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (7 - 0);
    t22 = (t12 * 1);
    t22 = (t22 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t22;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t21);
    if (t3 != 0)
        goto LAB25;

LAB26:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 7388U);
    t5 = (t0 + 7472);
    t7 = (t21 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 7;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (7 - 0);
    t22 = (t12 * 1);
    t22 = (t22 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t22;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t21);
    if (t3 != 0)
        goto LAB27;

LAB28:
LAB23:    goto LAB20;

LAB22:    xsi_set_current_line(57, ng0);
    t16 = (t0 + 2632U);
    t17 = *((char **)t16);
    t14 = *((int *)t17);
    t16 = (t0 + 4192);
    t18 = (t16 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t23 = *((char **)t20);
    *((int *)t23) = t14;
    xsi_driver_first_trans_fast_port(t16);
    goto LAB23;

LAB25:    xsi_set_current_line(61, ng0);
    t8 = (t0 + 4192);
    t16 = (t8 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((int *)t19) = 1;
    xsi_driver_first_trans_fast_port(t8);
    goto LAB23;

LAB27:    xsi_set_current_line(64, ng0);
    t8 = (t0 + 2632U);
    t16 = *((char **)t8);
    t14 = *((int *)t16);
    t8 = (t0 + 4192);
    t17 = (t8 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((int *)t20) = t14;
    xsi_driver_first_trans_fast_port(t8);
    goto LAB23;

}


extern void work_a_3240190358_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3240190358_3212880686_p_0};
	xsi_register_didat("work_a_3240190358_3212880686", "isim/Top_tb1_isim_beh.exe.sim/work/a_3240190358_3212880686.didat");
	xsi_register_executes(pe);
}
