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
static const char *ng0 = "C:/Users/tniel/OneDrive - Danmarks Tekniske Universitet/Dokumenter/GitHub/DigitalTeknikProjekt/FPGA/SigGenSpiControl_knap/putin.vhd";
extern char *IEEE_P_3620187407;
extern char *IEEE_P_2592010699;



static void work_a_1152221224_3212880686_p_0(char *t0)
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
    char *t11;
    char *t12;
    char *t13;
    static char *nl0[] = {&&LAB11, &&LAB12, &&LAB13, &&LAB14};

LAB0:    xsi_set_current_line(29, ng0);
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
LAB3:    t1 = (t0 + 4680);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(30, ng0);
    t1 = (t0 + 4776);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 4840);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(33, ng0);
    t1 = (t0 + 9152);
    t5 = (t0 + 4904);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t1, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 2952U);
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

LAB10:    goto LAB3;

LAB11:    xsi_set_current_line(37, ng0);
    t5 = (t0 + 9154);
    t7 = (t0 + 4904);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t5, 2U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(38, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB15;

LAB17:    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB18;

LAB19:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB20;

LAB21:    xsi_set_current_line(45, ng0);
    t1 = (t0 + 4776);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB16:    goto LAB10;

LAB12:    xsi_set_current_line(49, ng0);
    t1 = (t0 + 9156);
    t5 = (t0 + 4904);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t1, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(50, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB22;

LAB24:    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB25;

LAB26:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB27;

LAB28:    xsi_set_current_line(57, ng0);
    t1 = (t0 + 4776);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);

LAB23:    goto LAB10;

LAB13:    xsi_set_current_line(61, ng0);
    t1 = (t0 + 9158);
    t5 = (t0 + 4904);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t1, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(62, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB29;

LAB31:    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB32;

LAB33:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB34;

LAB35:    xsi_set_current_line(69, ng0);
    t1 = (t0 + 4776);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB30:    goto LAB10;

LAB14:    xsi_set_current_line(73, ng0);
    t1 = (t0 + 9160);
    t5 = (t0 + 4904);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t1, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(74, ng0);
    t1 = (t0 + 4840);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(75, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB36;

LAB38:
LAB37:    goto LAB10;

LAB15:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 1832U);
    t5 = *((char **)t1);
    t1 = (t0 + 4968);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t5, 8U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB16;

LAB18:    xsi_set_current_line(41, ng0);
    t1 = (t0 + 4776);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB16;

LAB20:    xsi_set_current_line(43, ng0);
    t1 = (t0 + 4776);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB16;

LAB22:    xsi_set_current_line(51, ng0);
    t1 = (t0 + 1832U);
    t5 = *((char **)t1);
    t1 = (t0 + 5032);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t5, 8U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB23;

LAB25:    xsi_set_current_line(53, ng0);
    t1 = (t0 + 4776);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB23;

LAB27:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 4776);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB23;

LAB29:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 1832U);
    t5 = *((char **)t1);
    t1 = (t0 + 5096);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    memcpy(t11, t5, 8U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB30;

LAB32:    xsi_set_current_line(65, ng0);
    t1 = (t0 + 4776);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB30;

LAB34:    xsi_set_current_line(67, ng0);
    t1 = (t0 + 4776);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB30;

LAB36:    xsi_set_current_line(76, ng0);
    t1 = (t0 + 4776);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB37;

}

static void work_a_1152221224_3212880686_p_1(char *t0)
{
    char t5[16];
    char t21[16];
    char t29[16];
    char t31[16];
    char t45[16];
    char t54[16];
    char t56[16];
    char t70[16];
    char t72[16];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    int t8;
    unsigned int t9;
    unsigned char t10;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t22;
    char *t23;
    int t24;
    unsigned char t25;
    char *t27;
    char *t28;
    char *t30;
    char *t32;
    char *t33;
    int t34;
    unsigned char t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t46;
    char *t47;
    int t48;
    unsigned int t49;
    unsigned char t50;
    char *t52;
    char *t53;
    char *t55;
    char *t57;
    char *t58;
    int t59;
    unsigned char t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    char *t68;
    char *t69;
    char *t71;
    char *t73;
    char *t74;
    int t75;
    unsigned int t76;
    unsigned char t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;

LAB0:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t1 = (t0 + 9112U);
    t3 = (t0 + 9162);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 0;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (0 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t10 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t3, t5);
    if (t10 != 0)
        goto LAB3;

LAB4:    t17 = (t0 + 2792U);
    t18 = *((char **)t17);
    t17 = (t0 + 9112U);
    t19 = (t0 + 9183);
    t22 = (t21 + 0U);
    t23 = (t22 + 0U);
    *((int *)t23) = 0;
    t23 = (t22 + 4U);
    *((int *)t23) = 3;
    t23 = (t22 + 8U);
    *((int *)t23) = 1;
    t24 = (3 - 0);
    t9 = (t24 * 1);
    t9 = (t9 + 1);
    t23 = (t22 + 12U);
    *((unsigned int *)t23) = t9;
    t25 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t18, t17, t19, t21);
    if (t25 != 0)
        goto LAB5;

LAB6:    t41 = (t0 + 2792U);
    t42 = *((char **)t41);
    t41 = (t0 + 9112U);
    t43 = (t0 + 9199);
    t46 = (t45 + 0U);
    t47 = (t46 + 0U);
    *((int *)t47) = 0;
    t47 = (t46 + 4U);
    *((int *)t47) = 3;
    t47 = (t46 + 8U);
    *((int *)t47) = 1;
    t48 = (3 - 0);
    t49 = (t48 * 1);
    t49 = (t49 + 1);
    t47 = (t46 + 12U);
    *((unsigned int *)t47) = t49;
    t50 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t42, t41, t43, t45);
    if (t50 != 0)
        goto LAB9;

LAB10:
LAB13:    t66 = (t0 + 9215);
    t68 = (t0 + 1992U);
    t69 = *((char **)t68);
    t71 = ((IEEE_P_2592010699) + 4024);
    t73 = (t72 + 0U);
    t74 = (t73 + 0U);
    *((int *)t74) = 0;
    t74 = (t73 + 4U);
    *((int *)t74) = 11;
    t74 = (t73 + 8U);
    *((int *)t74) = 1;
    t75 = (11 - 0);
    t76 = (t75 * 1);
    t76 = (t76 + 1);
    t74 = (t73 + 12U);
    *((unsigned int *)t74) = t76;
    t74 = (t0 + 9048U);
    t68 = xsi_base_array_concat(t68, t70, t71, (char)97, t66, t72, (char)97, t69, t74, (char)101);
    t76 = (12U + 8U);
    t77 = (20U != t76);
    if (t77 == 1)
        goto LAB15;

LAB16:    t78 = (t0 + 5160);
    t79 = (t78 + 56U);
    t80 = *((char **)t79);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    memcpy(t82, t68, 20U);
    xsi_driver_first_trans_fast_port(t78);

LAB2:    t83 = (t0 + 4696);
    *((int *)t83) = 1;

LAB1:    return;
LAB3:    t7 = (t0 + 9163);
    t12 = (t0 + 5160);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t7, 20U);
    xsi_driver_first_trans_fast_port(t12);
    goto LAB2;

LAB5:    t23 = (t0 + 9187);
    t27 = (t0 + 2312U);
    t28 = *((char **)t27);
    t30 = ((IEEE_P_2592010699) + 4024);
    t32 = (t31 + 0U);
    t33 = (t32 + 0U);
    *((int *)t33) = 0;
    t33 = (t32 + 4U);
    *((int *)t33) = 11;
    t33 = (t32 + 8U);
    *((int *)t33) = 1;
    t34 = (11 - 0);
    t9 = (t34 * 1);
    t9 = (t9 + 1);
    t33 = (t32 + 12U);
    *((unsigned int *)t33) = t9;
    t33 = (t0 + 9080U);
    t27 = xsi_base_array_concat(t27, t29, t30, (char)97, t23, t31, (char)97, t28, t33, (char)101);
    t9 = (12U + 8U);
    t35 = (20U != t9);
    if (t35 == 1)
        goto LAB7;

LAB8:    t36 = (t0 + 5160);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    t39 = (t38 + 56U);
    t40 = *((char **)t39);
    memcpy(t40, t27, 20U);
    xsi_driver_first_trans_fast_port(t36);
    goto LAB2;

LAB7:    xsi_size_not_matching(20U, t9, 0);
    goto LAB8;

LAB9:    t47 = (t0 + 9203);
    t52 = (t0 + 2152U);
    t53 = *((char **)t52);
    t55 = ((IEEE_P_2592010699) + 4024);
    t57 = (t56 + 0U);
    t58 = (t57 + 0U);
    *((int *)t58) = 0;
    t58 = (t57 + 4U);
    *((int *)t58) = 11;
    t58 = (t57 + 8U);
    *((int *)t58) = 1;
    t59 = (11 - 0);
    t49 = (t59 * 1);
    t49 = (t49 + 1);
    t58 = (t57 + 12U);
    *((unsigned int *)t58) = t49;
    t58 = (t0 + 9064U);
    t52 = xsi_base_array_concat(t52, t54, t55, (char)97, t47, t56, (char)97, t53, t58, (char)101);
    t49 = (12U + 8U);
    t60 = (20U != t49);
    if (t60 == 1)
        goto LAB11;

LAB12:    t61 = (t0 + 5160);
    t62 = (t61 + 56U);
    t63 = *((char **)t62);
    t64 = (t63 + 56U);
    t65 = *((char **)t64);
    memcpy(t65, t52, 20U);
    xsi_driver_first_trans_fast_port(t61);
    goto LAB2;

LAB11:    xsi_size_not_matching(20U, t49, 0);
    goto LAB12;

LAB14:    goto LAB2;

LAB15:    xsi_size_not_matching(20U, t76, 0);
    goto LAB16;

}


extern void work_a_1152221224_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1152221224_3212880686_p_0,(void *)work_a_1152221224_3212880686_p_1};
	xsi_register_didat("work_a_1152221224_3212880686", "isim/top_tb1_isim_beh.exe.sim/work/a_1152221224_3212880686.didat");
	xsi_register_executes(pe);
}
