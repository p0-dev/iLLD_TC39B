/**
 * \file IfxPsi5s_PinMap.c
 * \brief PSI5S I/O map
 * \ingroup IfxLld_Psi5s
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

#include "IfxPsi5s_PinMap.h"

IfxPsi5s_Clk_Out IfxPsi5s_CLK_P02_4_OUT = {&MODULE_PSI5S, {&MODULE_P02, 4}, IfxPort_OutputIdx_alt4};
IfxPsi5s_Clk_Out IfxPsi5s_CLK_P33_10_OUT = {&MODULE_PSI5S, {&MODULE_P33,10}, IfxPort_OutputIdx_alt5};
IfxPsi5s_Rx_In IfxPsi5s_RXA_P00_3_IN = {&MODULE_PSI5S, {&MODULE_P00, 3}, Ifx_RxSel_a};
IfxPsi5s_Rx_In IfxPsi5s_RXB_P02_5_IN = {&MODULE_PSI5S, {&MODULE_P02, 5}, Ifx_RxSel_b};
IfxPsi5s_Rx_In IfxPsi5s_RXC_P33_5_IN = {&MODULE_PSI5S, {&MODULE_P33, 5}, Ifx_RxSel_c};
IfxPsi5s_Tx_Out IfxPsi5s_TX_P00_4_OUT = {&MODULE_PSI5S, {&MODULE_P00, 4}, IfxPort_OutputIdx_alt2};
IfxPsi5s_Tx_Out IfxPsi5s_TX_P02_6_OUT = {&MODULE_PSI5S, {&MODULE_P02, 6}, IfxPort_OutputIdx_alt2};
IfxPsi5s_Tx_Out IfxPsi5s_TX_P33_6_OUT = {&MODULE_PSI5S, {&MODULE_P33, 6}, IfxPort_OutputIdx_alt7};


const IfxPsi5s_Clk_Out *IfxPsi5s_Clk_Out_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_CLK_OUT_NUM_ITEMS] = {
    {
        &IfxPsi5s_CLK_P02_4_OUT,
        &IfxPsi5s_CLK_P33_10_OUT
    }
};

const IfxPsi5s_Rx_In *IfxPsi5s_Rx_In_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_RX_IN_NUM_ITEMS] = {
    {
        &IfxPsi5s_RXA_P00_3_IN,
        &IfxPsi5s_RXB_P02_5_IN,
        &IfxPsi5s_RXC_P33_5_IN
    }
};

const IfxPsi5s_Tx_Out *IfxPsi5s_Tx_Out_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_TX_OUT_NUM_ITEMS] = {
    {
        &IfxPsi5s_TX_P00_4_OUT,
        &IfxPsi5s_TX_P02_6_OUT,
        &IfxPsi5s_TX_P33_6_OUT
    }
};
