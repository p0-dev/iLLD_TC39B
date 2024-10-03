/**
 * \file IfxEdsadc_PinMap.c
 * \brief EDSADC I/O map
 * \ingroup IfxLld_Edsadc
 *
 * \version iLLD_1_0_1_18_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include "IfxEdsadc_PinMap.h"

IfxEdsadc_Cgpwm_Out IfxEdsadc_CGPWMN_P00_5_OUT = {&MODULE_EDSADC, {&MODULE_P00, 5}, IfxPort_OutputIdx_alt2};
IfxEdsadc_Cgpwm_Out IfxEdsadc_CGPWMN_P02_0_OUT = {&MODULE_EDSADC, {&MODULE_P02, 0}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Cgpwm_Out IfxEdsadc_CGPWMN_P33_11_OUT = {&MODULE_EDSADC, {&MODULE_P33,11}, IfxPort_OutputIdx_alt6};
IfxEdsadc_Cgpwm_Out IfxEdsadc_CGPWMP_P00_6_OUT = {&MODULE_EDSADC, {&MODULE_P00, 6}, IfxPort_OutputIdx_alt2};
IfxEdsadc_Cgpwm_Out IfxEdsadc_CGPWMP_P02_1_OUT = {&MODULE_EDSADC, {&MODULE_P02, 1}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Cgpwm_Out IfxEdsadc_CGPWMP_P33_12_OUT = {&MODULE_EDSADC, {&MODULE_P33,12}, IfxPort_OutputIdx_alt6};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN0A_P00_11_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {&MODULE_P00,11}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN0B_P33_5_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {&MODULE_P33, 5}, Ifx_RxSel_b};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN10A_P01_13_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_10, {&MODULE_P01,13}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN11A_P01_15_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_11, {&MODULE_P01,15}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN12A_P02_13_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_12, {&MODULE_P02,13}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN13A_P02_15_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_13, {&MODULE_P02,15}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN1A_P00_9_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P00, 9}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN1B_P33_3_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P33, 3}, Ifx_RxSel_b};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN2A_P00_5_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {&MODULE_P00, 5}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN2B_P33_1_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {&MODULE_P33, 1}, Ifx_RxSel_b};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN3A_P00_3_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {&MODULE_P00, 3}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN3B_P02_7_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {&MODULE_P02, 7}, Ifx_RxSel_b};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN4A_P00_7_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P00, 7}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN4B_P02_5_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P02, 5}, Ifx_RxSel_b};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN5A_P00_1_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P00, 1}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN5B_P02_3_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P02, 3}, Ifx_RxSel_b};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN6A_P00_14_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_6, {&MODULE_P00,14}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN7A_P01_2_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {&MODULE_P01, 2}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN7B_P00_1_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {&MODULE_P00, 1}, Ifx_RxSel_b};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN8A_P01_5_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_8, {&MODULE_P01, 5}, Ifx_RxSel_a};
IfxEdsadc_Dscin_In IfxEdsadc_DSCIN9A_P01_9_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_9, {&MODULE_P01, 9}, Ifx_RxSel_a};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT0_P00_11_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {&MODULE_P00,11}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT0_P33_5_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {&MODULE_P33, 5}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT10_P01_13_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_10, {&MODULE_P01,13}, IfxPort_OutputIdx_alt7};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT11_P01_15_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_11, {&MODULE_P01,15}, IfxPort_OutputIdx_alt7};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT12_P02_13_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_12, {&MODULE_P02,13}, IfxPort_OutputIdx_alt7};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT13_P02_15_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_13, {&MODULE_P02,15}, IfxPort_OutputIdx_alt7};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT1_P00_9_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P00, 9}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT1_P33_3_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P33, 3}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT2_P00_5_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {&MODULE_P00, 5}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT2_P33_1_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {&MODULE_P33, 1}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT3_P00_3_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {&MODULE_P00, 3}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT3_P02_7_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {&MODULE_P02, 7}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT4_P00_7_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P00, 7}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT4_P02_5_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P02, 5}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT5_P00_1_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P00, 1}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT5_P02_3_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P02, 3}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT6_P00_14_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_6, {&MODULE_P00,14}, IfxPort_OutputIdx_alt4};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT7_P00_1_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {&MODULE_P00, 1}, IfxPort_OutputIdx_alt5};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT7_P01_2_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {&MODULE_P01, 2}, IfxPort_OutputIdx_alt6};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT8_P01_5_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_8, {&MODULE_P01, 5}, IfxPort_OutputIdx_alt6};
IfxEdsadc_Dscout_Out IfxEdsadc_DSCOUT9_P01_9_OUT = {&MODULE_EDSADC, IfxEdsadc_ChannelId_9, {&MODULE_P01, 9}, IfxPort_OutputIdx_alt6};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN0A_P00_12_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {&MODULE_P00,12}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN0B_P33_6_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {&MODULE_P33, 6}, Ifx_RxSel_b};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN10A_P01_12_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_10, {&MODULE_P01,12}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN11A_P01_14_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_11, {&MODULE_P01,14}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN12A_P02_12_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_12, {&MODULE_P02,12}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN13A_P02_14_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_13, {&MODULE_P02,14}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN1A_P00_10_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P00,10}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN1B_P33_4_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P33, 4}, Ifx_RxSel_b};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN2A_P00_6_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {&MODULE_P00, 6}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN2B_P33_2_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {&MODULE_P33, 2}, Ifx_RxSel_b};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN3A_P00_4_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {&MODULE_P00, 4}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN3B_P02_8_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {&MODULE_P02, 8}, Ifx_RxSel_b};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN4A_P00_8_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P00, 8}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN4B_P02_6_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P02, 6}, Ifx_RxSel_b};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN5A_P00_2_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P00, 2}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN5B_P02_4_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P02, 4}, Ifx_RxSel_b};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN6A_P00_13_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_6, {&MODULE_P00,13}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN7A_P01_15_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {&MODULE_P01,15}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN7B_P00_2_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {&MODULE_P00, 2}, Ifx_RxSel_b};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN8A_P01_6_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_8, {&MODULE_P01, 6}, Ifx_RxSel_a};
IfxEdsadc_Dsdin_In IfxEdsadc_DSDIN9A_P01_8_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_9, {&MODULE_P01, 8}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS0NA_AN3_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {NULL_PTR, 3}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS0NB_AN13_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {NULL_PTR,13}, Ifx_RxSel_b};
IfxEdsadc_Dsn_In IfxEdsadc_DS10NA_AN59_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_10, {NULL_PTR,59}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS11NA_P40_15_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_11, {&MODULE_P40,15}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS12NA_P41_3_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_12, {&MODULE_P41, 3}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS13NA_AN73_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_13, {NULL_PTR,73}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS1NA_P40_7_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P40, 7}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS1NB_P40_9_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P40, 9}, Ifx_RxSel_b};
IfxEdsadc_Dsn_In IfxEdsadc_DS1NC_AN45_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {NULL_PTR,45}, Ifx_RxSel_c};
IfxEdsadc_Dsn_In IfxEdsadc_DS1ND_AN47_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {NULL_PTR,47}, Ifx_RxSel_d};
IfxEdsadc_Dsn_In IfxEdsadc_DS2NA_AN21_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {NULL_PTR,21}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS2NB_P40_1_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {&MODULE_P40, 1}, Ifx_RxSel_b};
IfxEdsadc_Dsn_In IfxEdsadc_DS3NA_AN1_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {NULL_PTR, 1}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS3NB_AN15_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {NULL_PTR,15}, Ifx_RxSel_b};
IfxEdsadc_Dsn_In IfxEdsadc_DS4NA_P00_7_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P00, 7}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS4NB_P00_9_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P00, 9}, Ifx_RxSel_b};
IfxEdsadc_Dsn_In IfxEdsadc_DS5NA_P00_1_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P00, 1}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS5NB_P00_3_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P00, 3}, Ifx_RxSel_b};
IfxEdsadc_Dsn_In IfxEdsadc_DS6NA_AN53_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_6, {NULL_PTR,53}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS6NB_P41_5_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_6, {&MODULE_P41, 5}, Ifx_RxSel_b};
IfxEdsadc_Dsn_In IfxEdsadc_DS7NA_AN61_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {NULL_PTR,61}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS7NB_P41_7_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {&MODULE_P41, 7}, Ifx_RxSel_b};
IfxEdsadc_Dsn_In IfxEdsadc_DS8NA_P41_1_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_8, {&MODULE_P41, 1}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS9NA_AN51_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_9, {NULL_PTR,51}, Ifx_RxSel_a};
IfxEdsadc_Dsn_In IfxEdsadc_DS9NB_P41_3_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_9, {&MODULE_P41, 3}, Ifx_RxSel_b};
IfxEdsadc_Dsp_In IfxEdsadc_DS0PA_AN2_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {NULL_PTR, 2}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS0PB_AN12_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {NULL_PTR,12}, Ifx_RxSel_b};
IfxEdsadc_Dsp_In IfxEdsadc_DS10PA_AN58_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_10, {NULL_PTR,58}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS11PA_AN66_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_11, {NULL_PTR,66}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS12PA_P41_2_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_12, {&MODULE_P41, 2}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS13PA_AN72_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_13, {NULL_PTR,72}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS1PA_P40_6_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P40, 6}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS1PB_P40_8_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P40, 8}, Ifx_RxSel_b};
IfxEdsadc_Dsp_In IfxEdsadc_DS1PC_AN44_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {NULL_PTR,44}, Ifx_RxSel_c};
IfxEdsadc_Dsp_In IfxEdsadc_DS1PD_AN46_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {NULL_PTR,46}, Ifx_RxSel_d};
IfxEdsadc_Dsp_In IfxEdsadc_DS2PA_AN20_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {NULL_PTR,20}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS2PB_P40_0_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {&MODULE_P40, 0}, Ifx_RxSel_b};
IfxEdsadc_Dsp_In IfxEdsadc_DS3PA_AN0_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {NULL_PTR, 0}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS3PB_AN14_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {NULL_PTR,14}, Ifx_RxSel_b};
IfxEdsadc_Dsp_In IfxEdsadc_DS4PA_P00_8_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P00, 8}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS4PB_P00_10_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P00,10}, Ifx_RxSel_b};
IfxEdsadc_Dsp_In IfxEdsadc_DS5PA_P00_2_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P00, 2}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS5PB_P00_4_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P00, 4}, Ifx_RxSel_b};
IfxEdsadc_Dsp_In IfxEdsadc_DS6PA_AN52_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_6, {NULL_PTR,52}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS6PB_P41_4_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_6, {&MODULE_P41, 4}, Ifx_RxSel_b};
IfxEdsadc_Dsp_In IfxEdsadc_DS7PA_AN60_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {NULL_PTR,60}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS7PB_P41_6_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {&MODULE_P41, 6}, Ifx_RxSel_b};
IfxEdsadc_Dsp_In IfxEdsadc_DS8PA_P41_0_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_8, {&MODULE_P41, 0}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS9PA_AN50_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_9, {NULL_PTR,50}, Ifx_RxSel_a};
IfxEdsadc_Dsp_In IfxEdsadc_DS9PB_P41_2_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_9, {&MODULE_P41, 2}, Ifx_RxSel_b};
IfxEdsadc_Itr_In IfxEdsadc_ITR0E_P33_0_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {&MODULE_P33, 0}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR0F_P33_4_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_0, {&MODULE_P33, 4}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR10E_P01_13_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_10, {&MODULE_P01,13}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR10F_P01_12_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_10, {&MODULE_P01,12}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR11E_P01_15_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_11, {&MODULE_P01,15}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR11F_P01_14_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_11, {&MODULE_P01,14}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR12E_P02_13_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_12, {&MODULE_P02,13}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR12F_P02_12_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_12, {&MODULE_P02,12}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR13E_P02_15_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_13, {&MODULE_P02,15}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR13F_P02_14_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_13, {&MODULE_P02,14}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR1E_P33_1_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P33, 1}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR1F_P33_5_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_1, {&MODULE_P33, 5}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR2E_P33_2_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {&MODULE_P33, 2}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR2F_P33_6_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_2, {&MODULE_P33, 6}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR3E_P02_8_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {&MODULE_P02, 8}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR3F_P00_9_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_3, {&MODULE_P00, 9}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR4E_P02_7_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P02, 7}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR4F_P00_6_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_4, {&MODULE_P00, 6}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR5E_P02_6_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P02, 6}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR5F_P00_3_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_5, {&MODULE_P00, 3}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR6E_P01_0_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_6, {&MODULE_P01, 0}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR6F_P00_15_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_6, {&MODULE_P00,15}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR7E_P01_4_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {&MODULE_P01, 4}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR7F_P01_3_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_7, {&MODULE_P01, 3}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR8E_P01_1_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_8, {&MODULE_P01, 1}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR8F_P01_7_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_8, {&MODULE_P01, 7}, Ifx_RxSel_f};
IfxEdsadc_Itr_In IfxEdsadc_ITR9E_P01_11_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_9, {&MODULE_P01,11}, Ifx_RxSel_e};
IfxEdsadc_Itr_In IfxEdsadc_ITR9F_P01_10_IN = {&MODULE_EDSADC, IfxEdsadc_ChannelId_9, {&MODULE_P01,10}, Ifx_RxSel_f};
IfxEdsadc_Sg_In IfxEdsadc_SGNA_P00_4_IN = {&MODULE_EDSADC, {&MODULE_P00, 4}, Ifx_RxSel_a};
IfxEdsadc_Sg_In IfxEdsadc_SGNB_P33_13_IN = {&MODULE_EDSADC, {&MODULE_P33,13}, Ifx_RxSel_b};


const IfxEdsadc_Cgpwm_Out *IfxEdsadc_Cgpwm_Out_pinTable[IFXEDSADC_PINMAP_NUM_MODULES][IFXEDSADC_PINMAP_CGPWM_OUT_NUM_ITEMS] = {
    {
        &IfxEdsadc_CGPWMN_P00_5_OUT,
        &IfxEdsadc_CGPWMP_P00_6_OUT,
        &IfxEdsadc_CGPWMN_P02_0_OUT,
        &IfxEdsadc_CGPWMP_P02_1_OUT,
        &IfxEdsadc_CGPWMN_P33_11_OUT,
        &IfxEdsadc_CGPWMP_P33_12_OUT
    }
};

const IfxEdsadc_Dscin_In *IfxEdsadc_Dscin_In_pinTable[IFXEDSADC_PINMAP_NUM_MODULES][IFXEDSADC_PINMAP_NUM_CHANNELS][IFXEDSADC_PINMAP_DSCIN_IN_NUM_ITEMS] = {
    {
        {
            &IfxEdsadc_DSCIN0A_P00_11_IN,
            &IfxEdsadc_DSCIN0B_P33_5_IN
        },
        {
            &IfxEdsadc_DSCIN1A_P00_9_IN,
            &IfxEdsadc_DSCIN1B_P33_3_IN
        },
        {
            &IfxEdsadc_DSCIN2A_P00_5_IN,
            &IfxEdsadc_DSCIN2B_P33_1_IN
        },
        {
            &IfxEdsadc_DSCIN3A_P00_3_IN,
            &IfxEdsadc_DSCIN3B_P02_7_IN
        },
        {
            &IfxEdsadc_DSCIN4A_P00_7_IN,
            &IfxEdsadc_DSCIN4B_P02_5_IN
        },
        {
            &IfxEdsadc_DSCIN5A_P00_1_IN,
            &IfxEdsadc_DSCIN5B_P02_3_IN
        },
        {
            &IfxEdsadc_DSCIN6A_P00_14_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCIN7A_P01_2_IN,
            &IfxEdsadc_DSCIN7B_P00_1_IN
        },
        {
            &IfxEdsadc_DSCIN8A_P01_5_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCIN9A_P01_9_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCIN10A_P01_13_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCIN11A_P01_15_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCIN12A_P02_13_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCIN13A_P02_15_IN,
            NULL_PTR
        }
    }
};

const IfxEdsadc_Dscout_Out *IfxEdsadc_Dscout_Out_pinTable[IFXEDSADC_PINMAP_NUM_MODULES][IFXEDSADC_PINMAP_NUM_CHANNELS][IFXEDSADC_PINMAP_DSCOUT_OUT_NUM_ITEMS] = {
    {
        {
            &IfxEdsadc_DSCOUT0_P00_11_OUT,
            &IfxEdsadc_DSCOUT0_P33_5_OUT
        },
        {
            &IfxEdsadc_DSCOUT1_P00_9_OUT,
            &IfxEdsadc_DSCOUT1_P33_3_OUT
        },
        {
            &IfxEdsadc_DSCOUT2_P00_5_OUT,
            &IfxEdsadc_DSCOUT2_P33_1_OUT
        },
        {
            &IfxEdsadc_DSCOUT3_P00_3_OUT,
            &IfxEdsadc_DSCOUT3_P02_7_OUT
        },
        {
            &IfxEdsadc_DSCOUT4_P00_7_OUT,
            &IfxEdsadc_DSCOUT4_P02_5_OUT
        },
        {
            &IfxEdsadc_DSCOUT5_P00_1_OUT,
            &IfxEdsadc_DSCOUT5_P02_3_OUT
        },
        {
            &IfxEdsadc_DSCOUT6_P00_14_OUT,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCOUT7_P00_1_OUT,
            &IfxEdsadc_DSCOUT7_P01_2_OUT
        },
        {
            &IfxEdsadc_DSCOUT8_P01_5_OUT,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCOUT9_P01_9_OUT,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCOUT10_P01_13_OUT,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCOUT11_P01_15_OUT,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCOUT12_P02_13_OUT,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSCOUT13_P02_15_OUT,
            NULL_PTR
        }
    }
};

const IfxEdsadc_Dsdin_In *IfxEdsadc_Dsdin_In_pinTable[IFXEDSADC_PINMAP_NUM_MODULES][IFXEDSADC_PINMAP_NUM_CHANNELS][IFXEDSADC_PINMAP_DSDIN_IN_NUM_ITEMS] = {
    {
        {
            &IfxEdsadc_DSDIN0A_P00_12_IN,
            &IfxEdsadc_DSDIN0B_P33_6_IN
        },
        {
            &IfxEdsadc_DSDIN1A_P00_10_IN,
            &IfxEdsadc_DSDIN1B_P33_4_IN
        },
        {
            &IfxEdsadc_DSDIN2A_P00_6_IN,
            &IfxEdsadc_DSDIN2B_P33_2_IN
        },
        {
            &IfxEdsadc_DSDIN3A_P00_4_IN,
            &IfxEdsadc_DSDIN3B_P02_8_IN
        },
        {
            &IfxEdsadc_DSDIN4A_P00_8_IN,
            &IfxEdsadc_DSDIN4B_P02_6_IN
        },
        {
            &IfxEdsadc_DSDIN5A_P00_2_IN,
            &IfxEdsadc_DSDIN5B_P02_4_IN
        },
        {
            &IfxEdsadc_DSDIN6A_P00_13_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSDIN7A_P01_15_IN,
            &IfxEdsadc_DSDIN7B_P00_2_IN
        },
        {
            &IfxEdsadc_DSDIN8A_P01_6_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSDIN9A_P01_8_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSDIN10A_P01_12_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSDIN11A_P01_14_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSDIN12A_P02_12_IN,
            NULL_PTR
        },
        {
            &IfxEdsadc_DSDIN13A_P02_14_IN,
            NULL_PTR
        }
    }
};

const IfxEdsadc_Dsn_In *IfxEdsadc_Dsn_In_pinTable[IFXEDSADC_PINMAP_NUM_MODULES][IFXEDSADC_PINMAP_NUM_CHANNELS][IFXEDSADC_PINMAP_DSN_IN_NUM_ITEMS] = {
    {
        {
            &IfxEdsadc_DS0NA_AN3_IN,
            &IfxEdsadc_DS0NB_AN13_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS1NA_P40_7_IN,
            &IfxEdsadc_DS1NB_P40_9_IN,
            &IfxEdsadc_DS1NC_AN45_IN,
            &IfxEdsadc_DS1ND_AN47_IN
        },
        {
            &IfxEdsadc_DS2NA_AN21_IN,
            &IfxEdsadc_DS2NB_P40_1_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS3NA_AN1_IN,
            &IfxEdsadc_DS3NB_AN15_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS4NA_P00_7_IN,
            &IfxEdsadc_DS4NB_P00_9_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS5NA_P00_1_IN,
            &IfxEdsadc_DS5NB_P00_3_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS6NA_AN53_IN,
            &IfxEdsadc_DS6NB_P41_5_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS7NA_AN61_IN,
            &IfxEdsadc_DS7NB_P41_7_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS8NA_P41_1_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS9NA_AN51_IN,
            &IfxEdsadc_DS9NB_P41_3_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS10NA_AN59_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS11NA_P40_15_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS12NA_P41_3_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS13NA_AN73_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        }
    }
};

const IfxEdsadc_Dsp_In *IfxEdsadc_Dsp_In_pinTable[IFXEDSADC_PINMAP_NUM_MODULES][IFXEDSADC_PINMAP_NUM_CHANNELS][IFXEDSADC_PINMAP_DSP_IN_NUM_ITEMS] = {
    {
        {
            &IfxEdsadc_DS0PA_AN2_IN,
            &IfxEdsadc_DS0PB_AN12_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS1PA_P40_6_IN,
            &IfxEdsadc_DS1PB_P40_8_IN,
            &IfxEdsadc_DS1PC_AN44_IN,
            &IfxEdsadc_DS1PD_AN46_IN
        },
        {
            &IfxEdsadc_DS2PA_AN20_IN,
            &IfxEdsadc_DS2PB_P40_0_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS3PA_AN0_IN,
            &IfxEdsadc_DS3PB_AN14_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS4PA_P00_8_IN,
            &IfxEdsadc_DS4PB_P00_10_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS5PA_P00_2_IN,
            &IfxEdsadc_DS5PB_P00_4_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS6PA_AN52_IN,
            &IfxEdsadc_DS6PB_P41_4_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS7PA_AN60_IN,
            &IfxEdsadc_DS7PB_P41_6_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS8PA_P41_0_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS9PA_AN50_IN,
            &IfxEdsadc_DS9PB_P41_2_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS10PA_AN58_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS11PA_AN66_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS12PA_P41_2_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEdsadc_DS13PA_AN72_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        }
    }
};

const IfxEdsadc_Itr_In *IfxEdsadc_Itr_In_pinTable[IFXEDSADC_PINMAP_NUM_MODULES][IFXEDSADC_PINMAP_NUM_CHANNELS][IFXEDSADC_PINMAP_ITR_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR0E_P33_0_IN,
            &IfxEdsadc_ITR0F_P33_4_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR1E_P33_1_IN,
            &IfxEdsadc_ITR1F_P33_5_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR2E_P33_2_IN,
            &IfxEdsadc_ITR2F_P33_6_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR3E_P02_8_IN,
            &IfxEdsadc_ITR3F_P00_9_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR4E_P02_7_IN,
            &IfxEdsadc_ITR4F_P00_6_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR5E_P02_6_IN,
            &IfxEdsadc_ITR5F_P00_3_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR6E_P01_0_IN,
            &IfxEdsadc_ITR6F_P00_15_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR7E_P01_4_IN,
            &IfxEdsadc_ITR7F_P01_3_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR8E_P01_1_IN,
            &IfxEdsadc_ITR8F_P01_7_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR9E_P01_11_IN,
            &IfxEdsadc_ITR9F_P01_10_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR10E_P01_13_IN,
            &IfxEdsadc_ITR10F_P01_12_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR11E_P01_15_IN,
            &IfxEdsadc_ITR11F_P01_14_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR12E_P02_13_IN,
            &IfxEdsadc_ITR12F_P02_12_IN
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            &IfxEdsadc_ITR13E_P02_15_IN,
            &IfxEdsadc_ITR13F_P02_14_IN
        }
    }
};

const IfxEdsadc_Sg_In *IfxEdsadc_Sg_In_pinTable[IFXEDSADC_PINMAP_NUM_MODULES][IFXEDSADC_PINMAP_SG_IN_NUM_ITEMS] = {
    {
        &IfxEdsadc_SGNA_P00_4_IN,
        &IfxEdsadc_SGNB_P33_13_IN
    }
};
