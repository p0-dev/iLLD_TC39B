/**
 * \file IfxQspi.c
 * \brief QSPI  basic functionality
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxQspi.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float IfxQspi_calcRealBaudrate(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId)
{
    int           cs    = channelId % 8;
    float         fQspi = IfxScuCcu_getQspiFrequency();
    Ifx_QSPI_ECON econ[8];
    econ[cs].U = qspi->ECON[cs].U;
    fQspi      = fQspi / (qspi->GLOBALCON.B.TQ + 1);
    fQspi      = fQspi / (econ[cs].B.Q + 1);
    fQspi      = fQspi / ((econ[cs].B.A + 1) + econ[cs].B.B + econ[cs].B.C);
    return fQspi;
}


uint32 IfxQspi_calculateBasicConfigurationValue(Ifx_QSPI *qspi, const IfxQspi_ChannelId channelId, const SpiIf_ChMode *chMode, const float baudrate)
{
    IFX_UNUSED_PARAMETER(baudrate);

    Ifx_QSPI_BACON     bacon;
    IfxQspi_DelayConst delayConst[3];
    bacon.U = 0;

    IfxQspi_calculateDelayConstants(qspi, channelId, chMode, delayConst);

    bacon.B.LAST   = 0;                   /* 1-bits Last Word in a Frame, will be set via recalcBasicConfiguration before transfer */

    bacon.B.IPRE   = delayConst[0].pre;   /* 3-bits Prescaler for the Idle Delay */
    bacon.B.IDLE   = delayConst[0].delay; /* 3-bits Idle Delay Length */
    bacon.B.LPRE   = delayConst[1].pre;   /* 3-bits Prescaler for the Leading Delay */
    bacon.B.LEAD   = delayConst[1].delay; /* 3-bits Leading Delay Length */
    bacon.B.TPRE   = delayConst[2].pre;   /* 3-bits Prescaler for the Trailing Delay */
    bacon.B.TRAIL  = delayConst[2].delay; /* 2-bits Trailing Delay Length */
    bacon.B.PARTYP = (chMode->parityMode == Ifx_ParityMode_even) ? 0 : 1;
    bacon.B.UINT   = 0;                   /* 1-bits User Interrupt at the PT1 Event in the Subsequent Frames */
    bacon.B.MSB    = (chMode->dataHeading == SpiIf_DataHeading_lsbFirst) ? 0 : 1;
    bacon.B.BYTE   = 0;                   /* only support bitwise selection in B.DL */
    bacon.B.DL     = chMode->dataWidth - 1;
    bacon.B.CS     = channelId;

    return bacon.U;
}


uint32 IfxQspi_calculateExtendedConfigurationValue(Ifx_QSPI *qspi, const uint8 cs, const SpiIf_ChConfig *chConfig)
{
    IFX_UNUSED_PARAMETER(cs);

    Ifx_QSPI_ECON econ;
    econ.U = 0;

    const int     maxB   = 3;
    float32       tQspi  = 1.0f / IfxQspi_getTimeQuantaFrequency(qspi);
    float32       fBaud  = (chConfig->baudrate);
    int           abcMin = (2);
    int           abcMax = (4 + 0 + 4);
    int           q, bestQ = 1, abc, bestAbc = abcMax, halfBaud = 0;
    sint8         diffB  = 0;
    float32       error, bestError;
    float32       tTmp, tBaudTmp;
    boolean       done = FALSE;

    if (fBaud == 0.0f)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_WARNING, FALSE);   /* chosen baud rate is 0 */
        fBaud = 1.0f;
    }

    float32 tBaud = 1.0f / fBaud;

    bestError = 1e6;

    for (abc = abcMax; abc >= abcMin; abc--)
    {
        tTmp = tQspi * abc;
        q    = (int)((tBaud / tTmp) + 0.5f);

        if (q > 64)
        {
            q = 64;
        }

        else if ((q * abc) < 4)
        {
            q = 2;
        }

        else if (q < 1)
        {
            q = 1;
        }

        tBaudTmp = tTmp * q;
        error    = __absf(tBaudTmp - tBaud);

        if (__leqf(error, bestError)) /* we have a equal/better error case */
        {
            /* process this case only if lesser error / or if ABC is even */
            if (__neqf(error, bestError) || (((uint32)bestAbc & (uint32)0x1) == 0))
            {
                bestError = error;
                bestAbc   = abc;
                bestQ     = q;
            }

            /* break out if ABC is even and error = 0 */
            if (((uint32)bestAbc & (uint32)0x1) == 0)
            {
                done = (__neqf(error, 0.0f)) ? FALSE : TRUE;

                if (done != FALSE)
                {
                    break;
                }
            }
        }
    }

    /* Exchange Q and ABC, if ABC is odd and Q is even.
     * This is because: A+1+B+C is ideally even for
     * achieving 50% duty cycle of the clock.
     */
    if ((bestQ <= abcMax)
        && (((uint32)bestAbc & (uint32)0x1) != 0)
        && (((uint32)bestQ & (uint32)0x1) == 0))
    {
        q       = bestQ;
        bestQ   = bestAbc;
        bestAbc = q;
    }

    /* NOTE: In assigning values to A,B,C:
     *  the "sampling point" (which is A+B) has to be as far as possible
     *  from the "shifting point" (end of A+B+C).
     * The duty cycle is calculated as the ratio of A : B+C
     * Therefore, to keep 50% duty cycle: A = B+C
     * Thus, we cannot influence the value of A, once A+B+C is found out
     * (A+1 is always (A+B+C)/2).
     * However, in between B and C - we should try to maximize B (and minimize C).
     * The goal will be to do this - keep max value of B always and keep only any remaining value for C .
     */
    halfBaud     = bestAbc / 2;
    diffB        = halfBaud - maxB;

    econ.B.Q     = bestQ - 1;
    econ.B.A     = halfBaud + (bestAbc % 2) - 1;  /* A + 1 = Half of Baud count */
    econ.B.C     = (diffB > 0) ? diffB : 0;
    econ.B.B     = (diffB > 0) ? maxB : halfBaud;

    econ.B.CPH   = (chConfig->mode.shiftClock == SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge) ? 1 : 0;
    econ.B.CPOL  = (chConfig->mode.clockPolarity == SpiIf_ClockPolarity_idleLow) ? 0 : 1;
    econ.B.PAREN = chConfig->mode.parityCheck;

    return econ.U;
}


uint32 IfxQspi_calculatePrescaler(Ifx_QSPI *qspi, float baudrate)
{
    float  error, bestError;
    float  halfBaud = baudrate / 2;
    float  fQspiIn  = IfxQspi_getModuleFrequency(qspi);
    bestError = 10e6;
    uint32 i, bestPre = 0;

    for (i = 0; i < 8; i++)
    {
        float tempHalfBaud = fQspiIn / (1U << (4 * i));
        error = __absf(tempHalfBaud - halfBaud);

        if (__leqf(error, bestError))
        {
            bestError = error;
            bestPre   = i;
        }
    }

    return bestPre;
}


uint32 IfxQspi_calculateTimeQuantumLength(Ifx_QSPI *qspi, float maxBaudrate)
{
#define ABCQMIN (4)
#define ABCQMAX (8 * 63)

    IFX_UNUSED_PARAMETER(qspi);

    uint32 abcq  = ABCQMIN, bestTq;
    float  realTQ, deltaMax, bestDelta, achievedMax, tq;
    float  fQspi = IfxScuCcu_getQspiFrequency();

    if (__leqf(maxBaudrate, 0.0f))
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE); /* Max baud rate is 0!! */
    }

    realTQ    = fQspi / (4.0f * maxBaudrate);
    bestTq    = __max((uint32)__roundf(realTQ), 1);
    bestDelta = __absf(maxBaudrate - (fQspi / bestTq));

    for (abcq = ABCQMIN; abcq <= ABCQMAX; abcq++)
    {
        realTQ      = fQspi / (maxBaudrate * abcq);
        tq          = (float)(realTQ + 0.5f);
        achievedMax = fQspi / (tq * abcq);
        deltaMax    = __absf(maxBaudrate - achievedMax);

        if (__leqf(deltaMax, bestDelta) && (tq >= 1))
        {
            bestDelta = deltaMax;
            bestTq    = (uint32)tq;
        }

        if ((bestDelta == 0) || (tq < 1))
        {
            break; //exit the for loop
        }
    }

    return __max(bestTq - 1, 0);
}


Ifx_QSPI *IfxQspi_getAddress(IfxQspi_Index qspi)
{
    Ifx_QSPI *module;

    if (qspi < IFXQSPI_NUM_MODULES)
    {
        module = (Ifx_QSPI *)IfxQspi_cfg_indexMap[qspi].module;
    }
    else
    {
        module = NULL_PTR;
    }

    return module;
}


IfxQspi_Index IfxQspi_getIndex(Ifx_QSPI *qspi)
{
    uint32        index;
    IfxQspi_Index result;

    result = IfxQspi_Index_none;

    for (index = 0; index < IFXQSPI_NUM_MODULES; index++)
    {
        if (IfxQspi_cfg_indexMap[index].module == qspi)
        {
            result = (IfxQspi_Index)IfxQspi_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


void IfxQspi_read16(Ifx_QSPI *qspi, uint16 *data, Ifx_SizeT count)
{
    volatile Ifx_QSPI_RXEXIT *rxFifo = &qspi->RXEXIT;

    while (count > 0)
    {
        *(data++) = (uint16)rxFifo->U;
        count--;
    }
}


void IfxQspi_read32(Ifx_QSPI *qspi, uint32 *data, Ifx_SizeT count)
{
    volatile Ifx_QSPI_RXEXIT *rxFifo = &qspi->RXEXIT;

    while (count > 0)
    {
        *(data++) = rxFifo->U;
        count--;
    }
}


void IfxQspi_read8(Ifx_QSPI *qspi, uint8 *data, Ifx_SizeT count)
{
    volatile Ifx_QSPI_RXEXIT *rxFifo = &qspi->RXEXIT;

    while (count > 0)
    {
        *(data++) = (uint8)rxFifo->U;
        count--;
    }
}


uint32 IfxQspi_recalcBasicConfiguration(uint32 oldBACON, Ifx_SizeT numOfData, boolean shortData, boolean lastData)
{
    Ifx_QSPI_BACON bacon;
    bacon.U = oldBACON;

    if (shortData == FALSE)
    {
        bacon.B.DL   = numOfData;
        bacon.B.BYTE = 1;
    }

    bacon.B.LAST = lastData;
    return bacon.U;
}


void IfxQspi_resetModule(Ifx_QSPI *qspi)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    qspi->KRST0.B.RST = 1;          /* Only if both Kernel reset bits are set a reset is executed */
    qspi->KRST1.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    while (0 == qspi->KRST0.B.RSTSTAT)  /* Wait until reset is executed */

    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    qspi->KRSTCLR.B.CLR = 1;            /* Clear Kernel reset status bit */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxQspi_setSlaveSelectOutputControl(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, boolean outputEnable, boolean activeLevel)
{
    uint16        mask = 1 << channelId;

    Ifx_QSPI_SSOC ssoc;
    ssoc.U = qspi->SSOC.U;

    if (outputEnable)
    {
        ssoc.B.OEN |= mask;
    }
    else
    {
        ssoc.B.OEN &= ~mask;
    }

    if (activeLevel)
    {
        ssoc.B.AOL |= mask;
    }
    else
    {
        ssoc.B.AOL &= ~mask;
    }

    qspi->SSOC.U = ssoc.U;
}


void IfxQspi_write16(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint16 *data, Ifx_SizeT count)
{
    int                          cs        = channelId % 8;
    volatile Ifx_QSPI_DATAENTRY *dataEntry = &qspi->DATAENTRY[cs];

    while (count > 0)
    {
        dataEntry->U = *(data++);
        count--;
    }
}


void IfxQspi_write32(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint32 *data, Ifx_SizeT count)
{
    int                          cs        = channelId % 8;
    volatile Ifx_QSPI_DATAENTRY *dataEntry = &qspi->DATAENTRY[cs];

    while (count > 0)
    {
        dataEntry->U = *(data++);
        count--;
    }
}


void IfxQspi_write8(Ifx_QSPI *qspi, IfxQspi_ChannelId channelId, uint8 *data, Ifx_SizeT count)
{
    int                          cs        = channelId % 8;
    volatile Ifx_QSPI_DATAENTRY *dataEntry = &qspi->DATAENTRY[cs];

    while (count > 0)
    {
        dataEntry->U = *(data++);
        count--;
    }
}


void IfxQspi_calculateDelayConstants(const Ifx_QSPI *qspi, const IfxQspi_ChannelId channelId, const SpiIf_ChMode *chMode, IfxQspi_DelayConst *delayConst)
{
    uint32                            divFactor;
    const SpiIf_SlsoTiming_HalfTsclk *dlyFactorPtr;
    float32                           scaleTemp;
    uint8                             preTemp;
    uint8                             preFinal   = 0U;
    uint8                             delayTemp;
    uint8                             delayFinal = 0U;
    boolean                           matchFound;
    uint8                             index;
    uint8                             cs = channelId % 8;

    /* obtain the peripheral frequency / sclk frequency multiplication factor */
    divFactor = (qspi->GLOBALCON.B.TQ + 1) * (qspi->ECON[cs].B.Q + 1) * (qspi->ECON[cs].B.A + 1 + qspi->ECON[cs].B.B + qspi->ECON[cs].B.C);

    /* The user defined delay factor is here - point to it */
    dlyFactorPtr = &(chMode->csInactiveDelay);

    for (index = 0; index < 3; index++)
    {
        /* multiply the div_factor and delay_factor and divide by 2 - this is product of (4^pre)*(delay_mult) */
        scaleTemp = (dlyFactorPtr[index] * divFactor) / (float32)2.0;

        /* loop through the possible pre values to find pre and delay */
        matchFound = FALSE;

        for (preTemp = 0; preTemp < 8; preTemp++)
        {
            delayTemp = (uint8)((scaleTemp / (1 << (2 * preTemp))) + 0.5f); /* divide the scale_temp by ( 4 ^ pre_temp) to find delay_temp */

            if (delayTemp <= 8)                                             /* if delay_temp is <= 8; we can get a good value pair */
            {
                if ((float32)(delayTemp << (2 * preTemp)) >= scaleTemp)     /* greater delays are tolerated. less is not */
                {
                    delayFinal = __max(delayTemp - 1, 0);                   /* subtract 1 to set to register */
                    preFinal   = preTemp;
                    matchFound = TRUE;
                    break;
                }
                else if (delayTemp < (uint8)8)            /* delay is less than 8 - add 1 and finalize parameters */
                {
                    delayTemp += 1;
                    delayFinal = __max(delayTemp - 1, 0); /* subtract 1 to set to register */
                    preFinal   = preTemp;
                    matchFound = TRUE;
                    break;
                }
                else
                {
                    /* do nothing - proceed to next pre_temp value */
                }
            }
        }

        if (matchFound == FALSE)
        {
            /* max limit reached. set max values for pre and delay and exit */
            delayFinal = 7;
            preFinal   = 7;
        }

        /* write back to delay const structure before looping to next factor */
        delayConst[index].delay = delayFinal;
        delayConst[index].pre   = preFinal;
    }
}
