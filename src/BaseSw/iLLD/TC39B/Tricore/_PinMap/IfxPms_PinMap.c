/**
 * \file IfxPms_PinMap.c
 * \brief PMS I/O map
 * \ingroup IfxLld_Pms
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

#include "IfxPms_PinMap.h"

IfxPms_Dcdcsync_Out IfxPms_DCDCSYNC_P32_2_OUT = {&MODULE_PMS, {&MODULE_P32, 2}, IfxPort_OutputIdx_alt6};
IfxPms_Dcdcsync_Out IfxPms_DCDCSYNC_P32_4_OUT = {&MODULE_PMS, {&MODULE_P32, 4}, IfxPort_OutputIdx_alt2};
IfxPms_Hwcfg_In IfxPms_HWCFG1IN_P14_5_IN = {&MODULE_PMS, {&MODULE_P14, 5}};
IfxPms_Hwcfg_In IfxPms_HWCFG2IN_P14_2_IN = {&MODULE_PMS, {&MODULE_P14, 2}};
IfxPms_Hwcfg_In IfxPms_HWCFG3IN_P14_3_IN = {&MODULE_PMS, {&MODULE_P14, 3}};
IfxPms_Hwcfg_In IfxPms_HWCFG4IN_P10_5_IN = {&MODULE_PMS, {&MODULE_P10, 5}};
IfxPms_Hwcfg_In IfxPms_HWCFG5IN_P10_6_IN = {&MODULE_PMS, {&MODULE_P10, 6}};
IfxPms_Hwcfg_In IfxPms_HWCFG6IN_P14_4_IN = {&MODULE_PMS, {&MODULE_P14, 4}};
IfxPms_Wkp_In IfxPms_PINAWKP_P14_1_IN = {&MODULE_PMS, {&MODULE_P14, 1}, Ifx_RxSel_a};
IfxPms_Wkp_In IfxPms_PINBWKP_P33_12_IN = {&MODULE_PMS, {&MODULE_P33,12}, Ifx_RxSel_b};


const IfxPms_Dcdcsync_Out *IfxPms_Dcdcsync_Out_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_DCDCSYNC_OUT_NUM_ITEMS] = {
    {
        &IfxPms_DCDCSYNC_P32_2_OUT,
        &IfxPms_DCDCSYNC_P32_4_OUT
    }
};

const IfxPms_Hwcfg_In *IfxPms_Hwcfg_In_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_HWCFG_IN_NUM_ITEMS] = {
    {
        &IfxPms_HWCFG6IN_P14_4_IN,
        &IfxPms_HWCFG3IN_P14_3_IN,
        &IfxPms_HWCFG1IN_P14_5_IN,
        &IfxPms_HWCFG2IN_P14_2_IN,
        &IfxPms_HWCFG5IN_P10_6_IN,
        &IfxPms_HWCFG4IN_P10_5_IN
    }
};

const IfxPms_Wkp_In *IfxPms_Wkp_In_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_WKP_IN_NUM_ITEMS] = {
    {
        &IfxPms_PINAWKP_P14_1_IN,
        &IfxPms_PINBWKP_P33_12_IN
    }
};
