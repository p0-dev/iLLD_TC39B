/**
 * \file IfxCan_cfg.h
 * \brief CAN on-chip implementation data
 * \ingroup IfxLld_Can
 *
 * \version iLLD_1_0_1_18_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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
 *
 * \defgroup IfxLld_Can CAN
 * \ingroup IfxLld
 * \defgroup IfxLld_Can_Impl Implementation Interface
 * \ingroup IfxLld_Can
 * \defgroup IfxLld_Can_Std Standard Interface
 * \ingroup IfxLld_Can
 * \defgroup IfxLld_Can_Impl_Enum Enumerations
 * \ingroup IfxLld_Can_Impl
 */

#ifndef IFXCAN_CFG_H
#define IFXCAN_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxCan_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of CAN modules
 */
#define IFXCAN_NUM_MODULES (3)

/** \brief Number of nodes per each CAN module
 */
#define IFXCAN_NUM_NODES   4

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Can_Impl_Enum
 * \{ */
/** \brief List of the available can resources
 */
typedef enum
{
    IfxCan_Index_none = -1,  /**< \brief Not Selected */
    IfxCan_Index_0    = 0,   /**< \brief CAN index 0  */
    IfxCan_Index_1,          /**< \brief CAN index 1  */
    IfxCan_Index_2           /**< \brief CAN index 2  */
} IfxCan_Index;

/** \brief CAN Node number
 */
typedef enum
{
    IfxCan_NodeId_none = -1, /**< \brief None of the CAN Nodes */
    IfxCan_NodeId_0,         /**< \brief Node Id 0  */
    IfxCan_NodeId_1,         /**< \brief Node Id 1  */
    IfxCan_NodeId_2,         /**< \brief Node Id 2  */
    IfxCan_NodeId_3          /**< \brief Node Id 3  */
} IfxCan_NodeId;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxCan_cfg_indexMap[IFXCAN_NUM_MODULES];

#endif /* IFXCAN_CFG_H */
