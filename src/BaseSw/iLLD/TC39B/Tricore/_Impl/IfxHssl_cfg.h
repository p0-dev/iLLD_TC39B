/**
 * \file IfxHssl_cfg.h
 * \brief HSSL on-chip implementation data
 * \ingroup IfxLld_Hssl
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
 * \defgroup IfxLld_Hssl HSSL
 * \ingroup IfxLld
 * \defgroup IfxLld_Hssl_Impl Implementation
 * \ingroup IfxLld_Hssl
 * \defgroup IfxLld_Hssl_Std Standard Driver
 * \ingroup IfxLld_Hssl
 * \defgroup IfxLld_Hssl_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Hssl_Impl
 */

#ifndef IFXHSSL_CFG_H
#define IFXHSSL_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxHssl_reg.h"
#include "IfxHsct_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXHSSL_NUM_CHANNELS    4

#define IFXHSSL_NUM_MODULES     2

#define IFXHSSL_JTAG_ID_ADDRESS (0xF0000464u)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Hssl_Impl_Enumerations
 * \{ */
/** \brief List of the available Hsct resources
 */
typedef enum
{
    IfxHssl_hsctIndex_none = -1,  /**< \brief Not Selected */
    IfxHssl_hsctIndex_0    = 0,   /**< \brief HSCT index 0  */
    IfxHssl_hsctIndex_1           /**< \brief HSCT index 1  */
} IfxHssl_hsctIndex;

/** \brief List of the available Hssl resources
 */
typedef enum
{
    IfxHssl_hsslIndex_none = -1,  /**< \brief Not Selected */
    IfxHssl_hsslIndex_0    = 0,   /**< \brief HSSL index 0  */
    IfxHssl_hsslIndex_1           /**< \brief HSSL index 1  */
} IfxHssl_hsslIndex;

/** \} */

/** \addtogroup IfxLld_Hssl_Impl_Enumerations
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxHssl_cfg_hsctIndexMap[IFXHSSL_NUM_MODULES];

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxHssl_cfg_hsslIndexMap[IFXHSSL_NUM_MODULES];

/** \} */

#endif /* IFXHSSL_CFG_H */
