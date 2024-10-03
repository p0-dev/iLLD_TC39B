/**
 * \file IfxAsclin_cfg.h
 * \brief ASCLIN on-chip implementation data
 * \ingroup IfxLld_Asclin
 *
 * \version iLLD_1_0_1_18_0
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Asclin ASCLIN
 * \ingroup IfxLld
 * \defgroup IfxLld_Asclin_Impl Implementation
 * \ingroup IfxLld_Asclin
 * \defgroup IfxLld_Asclin_Std Standard Driver
 * \ingroup IfxLld_Asclin
 * \defgroup IfxLld_Asclin_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Asclin_Impl
 */

#ifndef IFXASCLIN_CFG_H
#define IFXASCLIN_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxAsclin_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXASCLIN_NUM_MODULES (12)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Asclin_Impl_Enumerations
 * \{ */
/** \brief List of the available Asclin resources
 */
typedef enum
{
    IfxAsclin_Index_none = -1,  /**< \brief Not Selected */
    IfxAsclin_Index_0    = 0,   /**< \brief ASCLIN Index 0  */
    IfxAsclin_Index_1,          /**< \brief ASCLIN Index 1  */
    IfxAsclin_Index_2,          /**< \brief ASCLIN Index 2  */
    IfxAsclin_Index_3,          /**< \brief ASCLIN Index 3  */
    IfxAsclin_Index_4,          /**< \brief ASCLIN Index 4  */
    IfxAsclin_Index_5,          /**< \brief ASCLIN Index 5  */
    IfxAsclin_Index_6,          /**< \brief ASCLIN Index 6  */
    IfxAsclin_Index_7,          /**< \brief ASCLIN Index 7  */
    IfxAsclin_Index_8,          /**< \brief ASCLIN Index 8  */
    IfxAsclin_Index_9,          /**< \brief ASCLIN Index 9  */
    IfxAsclin_Index_10,         /**< \brief ASCLIN Index 10  */
    IfxAsclin_Index_11          /**< \brief ASCLIN Index 11  */
} IfxAsclin_Index;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxAsclin_cfg_indexMap[IFXASCLIN_NUM_MODULES];

#endif /* IFXASCLIN_CFG_H */
