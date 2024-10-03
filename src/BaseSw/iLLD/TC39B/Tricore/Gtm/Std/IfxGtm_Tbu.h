/**
 * \file IfxGtm_Tbu.h
 * \brief GTM  basic functionality
 * \ingroup IfxLld_Gtm
 *
 * \version iLLD_1_0_1_18_0
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
 *
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
 *
 * \defgroup IfxLld_Gtm_Std_Tbu Tbu Basic Functionality
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Tbu_Enumerations TBU Enumerations
 * \ingroup IfxLld_Gtm_Std_Tbu
 * \defgroup IfxLld_Gtm_Std_Tbu_Basic_Functions TBU Basic Functions
 * \ingroup IfxLld_Gtm_Std_Tbu
 */

#ifndef IFXGTM_TBU_H
#define IFXGTM_TBU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Tbu_Enumerations
 * \{ */
/** \brief GTM TOM TBU Time stamps
 */
typedef enum
{
    IfxGtm_Tbu_Ts_0,
    IfxGtm_Tbu_Ts_1,
    IfxGtm_Tbu_Ts_2,
    IfxGtm_Tbu_Ts_3
} IfxGtm_Tbu_Ts;

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Tbu_Basic_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enables the channel
 * \param gtm Pointer to GTM module
 * \param channel TBU Time stamps
 * \return None
 */
IFX_INLINE void IfxGtm_Tbu_enableChannel(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel);

/** \brief Function to check if a TBU channel is enabled.
 * Returns TRUE if the corresponding channel is enabled
 * Returns FALSE if the corresponding channel is disabled.
 * \param gtm Pointer to GTM SFR
 * \param channel Channel of TBU
 * \return TRUE: channel is enabled
 */
IFX_INLINE boolean IfxGtm_Tbu_isChannelEnabled(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the clock frequency
 * \param gtm Pointer to GTM module
 * \param channel TBU Time stamps
 * \return frequency
 */
IFX_EXTERN float32 IfxGtm_Tbu_getClockFrequency(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_Tbu_enableChannel(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel)
{
    uint32 shift = channel * 2;

    __ldmst_c(&gtm->TBU.CHEN.U, (3U << shift), (IfxGtm_FeatureControl_enable << shift));
}


IFX_INLINE boolean IfxGtm_Tbu_isChannelEnabled(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel)
{
    uint32 shift         = channel * 2;
    uint32 enable_status = (gtm->TBU.CHEN.U & ((uint32)3 << shift)) >> shift;

    return enable_status == (uint32)IfxGtm_FeatureControl_enabled;
}


#endif /* IFXGTM_TBU_H */
