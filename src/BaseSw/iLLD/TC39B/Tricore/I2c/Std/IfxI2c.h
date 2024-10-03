/**
 * \file IfxI2c.h
 * \brief I2C  basic functionality
 * \ingroup IfxLld_I2c
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
 * \defgroup IfxLld_I2c_Std_enums Enumerations
 * \ingroup IfxLld_I2c_Std
 * \defgroup IfxLld_I2c_Std_functions Functions
 * \ingroup IfxLld_I2c_Std
 * \defgroup IfxLld_I2c_Std_structures Data Structures
 * \ingroup IfxLld_I2c_Std
 */

#ifndef IFXI2C_H
#define IFXI2C_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxI2c_cfg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Scu/Std/IfxScuCcu.h"
#include "IfxI2c_bf.h"
#include "_PinMap/IfxI2c_PinMap.h"
#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Master code for high speed mode
 */
#define IFXI2C_HIGHSPEED_MASTER_CODE (0xEU)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_I2c_Std_enums
 * \{ */
/** \brief Selects width of address bits (7 or 10 bits)
 * Definition in Ifx_I2C.ADDRCFG.B.TBAM
 */
typedef enum
{
    IfxI2c_AddressMode_7Bit  = 0, /**< \brief sets 7 bit address */
    IfxI2c_AddressMode_10Bit = 1  /**< \brief sets 10 bit address */
} IfxI2c_AddressMode;

typedef enum
{
    IfxI2c_BusStatus_idle        = 0, /**< \brief idle */
    IfxI2c_BusStatus_started     = 1, /**< \brief started */
    IfxI2c_BusStatus_busyMaster  = 2, /**< \brief busy Master */
    IfxI2c_BusStatus_remoteSlave = 3  /**< \brief remote Slave */
} IfxI2c_BusStatus;

/** \brief enables DTR interrupt flags
 * Definition in Ifx.I2C.IMSC.U
 */
typedef enum
{
    IfxI2c_DtrInterruptSource_lastSingleRequest = IFX_I2C_IMSC_LSREQ_INT_OFF,  /**< \brief last single service request */
    IfxI2c_DtrInterruptSource_singleRequest     = IFX_I2C_IMSC_SREQ_INT_OFF,   /**< \brief single service request */
    IfxI2c_DtrInterruptSource_lastBurstRequest  = IFX_I2C_IMSC_LBREQ_INT_OFF,  /**< \brief last burst service request */
    IfxI2c_DtrInterruptSource_burstRequest      = IFX_I2C_IMSC_BREQ_INT_OFF    /**< \brief burst service request */
} IfxI2c_DtrInterruptSource;

/** \brief enable error interrupt request source
 * Definition in Ifx.I2C.ERRIRQSM.U
 */
typedef enum
{
    IfxI2c_ErrorInterruptSource_rxFifoUnderflow = IFX_I2C_ERRIRQSM_RXF_UFL_OFF,  /**< \brief receive fifo underflow service request */
    IfxI2c_ErrorInterruptSource_rxFifoOverflow  = IFX_I2C_ERRIRQSM_RXF_OFL_OFF,  /**< \brief receive fifo overflow service request */
    IfxI2c_ErrorInterruptSource_txFifoUnderflow = IFX_I2C_ERRIRQSM_TXF_UFL_OFF,  /**< \brief transmit fifo underflow service request */
    IfxI2c_ErrorInterruptSource_txFifoOverflow  = IFX_I2C_ERRIRQSM_TXF_OFL_OFF   /**< \brief transmit fifo overflow service request */
} IfxI2c_ErrorInterruptSource;

/** \brief Select speed mode. Standard and Fast or High Speed mode.
 */
typedef enum
{
    IfxI2c_Mode_StandardAndFast = 0,  /**< \brief Sets Standard and Fast speed mode */
    IfxI2c_Mode_HighSpeed       = 1   /**< \brief Sets HighSpeed Mode */
} IfxI2c_Mode;

typedef enum
{
    IfxI2c_PinSelect_a = 0,
    IfxI2c_PinSelect_b = 1,
    IfxI2c_PinSelect_c = 2,
    IfxI2c_PinSelect_d = 3,
    IfxI2c_PinSelect_e = 4,
    IfxI2c_PinSelect_f = 5,
    IfxI2c_PinSelect_g = 6,
    IfxI2c_PinSelect_h = 7
} IfxI2c_PinSelect;

/** \brief enable protocol interrupt source
 * Definition in Ifx.I2C.PIRQSM.U
 */
typedef enum
{
    IfxI2c_ProtocolInterruptSource_addressMatch           = IFX_I2C_PIRQSM_AM_OFF,     /**< \brief address match service request */
    IfxI2c_ProtocolInterruptSource_generalCall            = IFX_I2C_PIRQSM_GC_OFF,     /**< \brief general call service request */
    IfxI2c_ProtocolInterruptSource_masterCode             = IFX_I2C_PIRQSM_MC_OFF,     /**< \brief master code service request */
    IfxI2c_ProtocolInterruptSource_arbitrationLost        = IFX_I2C_PIRQSM_AL_OFF,     /**< \brief arbitration lost service request */
    IfxI2c_ProtocolInterruptSource_notAcknowledgeReceived = IFX_I2C_PIRQSM_NACK_OFF,   /**< \brief not acknowledge received service request */
    IfxI2c_ProtocolInterruptSource_transmissionEnd        = IFX_I2C_PIRQSM_TX_END_OFF, /**< \brief transmission end service request */
    IfxI2c_ProtocolInterruptSource_receiveMode            = IFX_I2C_PIRQSM_RX_OFF      /**< \brief receive mode service request */
} IfxI2c_ProtocolInterruptSource;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_I2C.CLC1.B.EDIS
 */
typedef enum
{
    IfxI2c_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxI2c_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxI2c_SleepMode;

/** \} */

/** \brief set interrupt request
 * Definition in Ifx.I2C.ISR.U
 */
typedef enum
{
    IfxI2c_InterruptRequest_lastSingleRequest = IFX_I2C_ISR_LSREQ_INT_OFF,   /**< \brief last single request interrupt */
    IfxI2c_InterruptRequest_SingleRequest     = IFX_I2C_ISR_SREQ_INT_OFF,    /**< \brief single request interrupt */
    IfxI2c_InterruptRequest_lastBurstRequest  = IFX_I2C_ISR_LBREQ_INT_OFF,   /**< \brief last burst request interrupt */
    IfxI2c_InterruptRequest_burstRequest      = IFX_I2C_ISR_BREQ_INT_OFF,    /**< \brief burst request interrupt */
    IfxI2c_InterruptRequest_i2cError          = IFX_I2C_ISR_I2C_ERR_INT_OFF, /**< \brief i2c error interrupt */
    IfxI2c_InterruptRequest_i2cProtocol       = IFX_I2C_ISR_I2C_P_INT_OFF    /**< \brief i2c protocol interrupt */
} IfxI2c_InterruptRequest;

/** \brief Configure as master or slave
 * Definition in Ifx_I2C.ADDRCFG.B.MnS
 */
typedef enum
{
    IfxI2c_MasterNotSlave_slave  = 0, /**< \brief sets as slave */
    IfxI2c_MasterNotSlave_master = 1  /**< \brief sets as master */
} IfxI2c_MasterNotSlave;

/** \brief Selects RX burst size
 * Definition in Ifx_I2C.FIFOCFG.B.RXBS
 */
typedef enum
{
    IfxI2c_RxBurstSize_1Word = 0,  /**< \brief one word */
    IfxI2c_RxBurstSize_2Word = 1,  /**< \brief two word */
    IfxI2c_RxBurstSize_4Word = 2   /**< \brief four word */
} IfxI2c_RxBurstSize;

/** \brief Selects RX FIFO alignment
 * Definition in Ifx_I2C.FIFOCFG.B.RXFA
 */
typedef enum
{
    IfxI2c_RxFifoAlignment_byte     = 0,  /**< \brief byte aligned */
    IfxI2c_RxFifoAlignment_halfWord = 1,  /**< \brief half word aligned */
    IfxI2c_RxFifoAlignment_word     = 2   /**< \brief word aligned */
} IfxI2c_RxFifoAlignment;

/** \brief Selects RX FIFO flow control
 * Definition in Ifx_I2C.FIFOCFG.B.RXFC
 */
typedef enum
{
    IfxI2c_RxFifoFlowControl_disable = 0,  /**< \brief rx fifo not as flow controller */
    IfxI2c_RxFifoFlowControl_enable  = 1   /**< \brief rx fifo as flow controller */
} IfxI2c_RxFifoFlowControl;

/** \brief Selects TX burst size
 * Definition in Ifx_I2C.FIFOCFG.B.TXBS
 */
typedef enum
{
    IfxI2c_TxBurstSize_1Word = 0,  /**< \brief one word */
    IfxI2c_TxBurstSize_2Word = 1,  /**< \brief two word */
    IfxI2c_TxBurstSize_4Word = 2   /**< \brief four word */
} IfxI2c_TxBurstSize;

/** \brief Selects TX FIFO alignment
 * Definition in Ifx_I2C.FIFOCFG.B.TXFA
 */
typedef enum
{
    IfxI2c_TxFifoAlignment_byte     = 0,  /**< \brief byte aligned */
    IfxI2c_TxFifoAlignment_halfWord = 1,  /**< \brief half word aligned */
    IfxI2c_TxFifoAlignment_word     = 2   /**< \brief word aligned */
} IfxI2c_TxFifoAlignment;

/** \brief Selects TX FIFO flow control
 * Definition in Ifx_I2C.FIFOCFG.B.TXFC
 */
typedef enum
{
    IfxI2c_TxFifoFlowControl_disable = 0,  /**< \brief tx fifo not as flow controller */
    IfxI2c_TxFifoFlowControl_enable  = 1   /**< \brief tx fifo as flow controller */
} IfxI2c_TxFifoFlowControl;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Structure for Address configuration register
 */
typedef struct
{
    uint32             slaveAddress;               /**< \brief slave address, use default value 0 when used in master mode */
    IfxI2c_AddressMode addressMode;                /**< \brief Ten bit address mode */
    boolean            generalCallEnable;          /**< \brief General call enable */
    boolean            masterCodeEnable;           /**< \brief Master code enable */
    boolean            stopOnNotAcknowledge;       /**< \brief stop on Not-acknowledge */
    boolean            stopOnPacketEnd;            /**< \brief stop on packet end */
} IfxI2c_AddrConfig;

/** \brief Structure for FIFO configuration register
 */
typedef struct
{
    IfxI2c_RxBurstSize       rxBurstSize;                /**< \brief rx burst size */
    IfxI2c_TxBurstSize       txBurstSize;                /**< \brief tx burst size */
    IfxI2c_RxFifoAlignment   rxFifoAlignment;            /**< \brief rx fifo alignment */
    IfxI2c_TxFifoAlignment   txFifoAlignment;            /**< \brief tx fifo alignment */
    IfxI2c_RxFifoFlowControl rxFifoFlowControl;          /**< \brief rx fifo flow control */
    IfxI2c_TxFifoFlowControl txFifoFlowControl;          /**< \brief tx fifo flow control */
    boolean                  clearRequestBehavior;       /**< \brief clear request behavior configuration */
} IfxI2c_FifoConfig;

/** \addtogroup IfxLld_I2c_Std_structures
 * \{ */
/** \brief Pin Structure
 */
typedef struct
{
    IfxI2c_Scl_InOut *scl;
    IfxI2c_Sda_InOut *sda;
    IfxPort_PadDriver padDriver;
} IfxI2c_Pins;

/** \} */

/** \brief Structure for Address and FIFO configuration registers
 */
typedef struct
{
    IfxI2c_AddrConfig addressConfig;       /**< \brief address config */
    IfxI2c_FifoConfig fifoConfig;          /**< \brief fifo config */
} IfxI2c_Config;

/** \addtogroup IfxLld_I2c_Std_functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns if the bus is free
 */
IFX_INLINE boolean IfxI2c_busIsFree(Ifx_I2C *i2c);

/** \brief clears all DTR interrupt sources
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_clearAllDtrInterruptSources(Ifx_I2C *i2c);

/** \brief clears all Error Interrupt sources
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_clearAllErrorInterruptSources(Ifx_I2C *i2c);

/** \brief Clears all Protocol Interrupt sources
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_clearAllProtocolInterruptSources(Ifx_I2C *i2c);

/** \brief clears the specified source of DTR interrupt
 * \param i2c pointer to i2c registers
 * \param source DTR interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_clearDtrInterruptSource(Ifx_I2C *i2c, IfxI2c_DtrInterruptSource source);

/** \brief clears the specified source of error interrupt
 * \param i2c pointer to i2c registers
 * \param source error interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_clearErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source);

/** \brief clears the specified source of protocol interrupt
 * \param i2c pointer to i2c registers
 * \param source protocol interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_clearProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source);

/** \brief Data request is cleared automatically
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_clearRequestBuffer(Ifx_I2C *i2c);

/** \brief disables the specified source of DTR interupt
 * \param i2c pointer to i2c registers
 * \param source DTR interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_disableDtrInterruptSource(Ifx_I2C *i2c, IfxI2c_DtrInterruptSource source);

/** \brief disables the error interrupt flag
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_disableErrorInterruptFlag(Ifx_I2C *i2c);

/** \brief disables the specified source of error interrupt
 * \param i2c pointer to i2c registers
 * \param source error interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_disableErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source);

/** \brief disables the Protocol interrupt flag
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_disableProtocolInterruptFlag(Ifx_I2C *i2c);

/** \brief disables the specified source of protocol interrupt
 * \param i2c pointer to i2c registers
 * \param source protocol interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_disableProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source);

/** \brief enables the specified source of DTR interupt
 * \param i2c pointer to i2c registers
 * \param source DTR interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_enableDtrInterruptSource(Ifx_I2C *i2c, IfxI2c_DtrInterruptSource source);

/** \brief enables the error interrupt flag
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_enableErrorInterruptFlag(Ifx_I2C *i2c);

/** \brief enables the specified source of error interrupt
 * \param i2c pointer to i2c registers
 * \param source error interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_enableErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source);

/** \brief enables the protocol interrupt flag
 * \param i2c pointer to I2C registers
 * \return None
 */
IFX_INLINE void IfxI2c_enableProtocolInterruptFlag(Ifx_I2C *i2c);

/** \brief enables the specified source of protocol interrupt
 * \param i2c pointer to I2C registers
 * \param source protocol interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_enableProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source);

/**
 * \param i2c pointer to i2c registers
 * \return BusStatus
 */
IFX_INLINE IfxI2c_BusStatus IfxI2c_getBusStatus(Ifx_I2C *i2c);

/** \brief Returns the SRC pointer for I2C DTR interrupt
 * \param i2c pointer to i2c registers
 * \return SRC pointer for I2C DTR interrupt
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getDtrSrcPointer(Ifx_I2C *i2c);

/** \brief returns the status of specified DTR interrupt source
 * \param i2c pointer to i2c registers
 * \param source DTR interrupt source
 * \return status
 */
IFX_INLINE boolean IfxI2c_getDtrinterruptSourceStatus(Ifx_I2C *i2c, IfxI2c_DtrInterruptSource source);

/** \brief returns the current status of error interrupt flag
 * \param i2c pointer to i2c registers
 * \return status
 */
IFX_INLINE boolean IfxI2c_getErrorInterruptFlagStatus(Ifx_I2C *i2c);

/** \brief returns the status of the error interrupt source
 * \param i2c pointer to i2c registers
 * \param source error interrupt source
 * \return status
 */
IFX_INLINE boolean IfxI2c_getErrorInterruptSourceStatus(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source);

/** \brief Returns the SRC pointer for I2C Error interrupt
 * \param i2c pointer to i2c registers
 * \return SRC pointer for I2C Error Service interrupt
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getErrorSrcPointer(Ifx_I2C *i2c);

/** \brief returns the current raw status of protocol interrupt
 * \param i2c pointer to i2c registers
 * \return status
 */
IFX_INLINE boolean IfxI2c_getProtocolInterruptFlagStatus(Ifx_I2C *i2c);

/** \brief returns the status of  specified protocol interrupt source
 * \param i2c pointer to i2c registers
 * \param source protocol interrupt source
 * \return status
 */
IFX_INLINE boolean IfxI2c_getProtocolInterruptSourceStatus(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source);

/** \brief Returns the SRC pointer for I2C Protocol interrupt
 * \param i2c pointer to i2c registers
 * \return SRC pointer for I2C Protocol Service interrupt
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getProtocolSrcPointer(Ifx_I2C *i2c);

/** \brief Returns if the Fifo is requesting new data
 */
IFX_INLINE boolean IfxI2c_isFifoRequest(Ifx_I2C *i2c);

/**
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_run(Ifx_I2C *i2c);

/** \brief Sets width of I2C address to 7 or 10 bits
 * \param i2c pointer to i2c registers
 * \param mode selects 7 or 10 bits address
 * \return None
 */
IFX_INLINE void IfxI2c_setBitAddressMode(Ifx_I2C *i2c, IfxI2c_AddressMode mode);

/** \brief selects the pin
 * \param i2c pointer to i2c registers
 * \param pisel pin to be select
 * \return None
 */
IFX_INLINE void IfxI2c_setPinSelection(Ifx_I2C *i2c, IfxI2c_PinSelect pisel);

/** \brief Sets the number of bytes to be received
 * \param i2c pointer to i2c registers
 * \param size number of packets
 * \return None
 */
IFX_INLINE void IfxI2c_setReceivePacketSize(Ifx_I2C *i2c, Ifx_SizeT size);

/**
 * \param i2c pointer to i2c registers
 * \param address device address
 * \return None
 */
IFX_INLINE void IfxI2c_setSlaveDeviceAddress(Ifx_I2C *i2c, uint16 address);

/** \brief Sets the sensitivity of the module to sleep signal
 * \param i2c pointer to i2c registers
 * \param mode mode selection (enable / disable)
 * \return None
 */
IFX_INLINE void IfxI2c_setSleepMode(Ifx_I2C *i2c, IfxI2c_SleepMode mode);

/** \brief Sets the number of bytes to be tansmitted
 * \param i2c pointer to i2c registers
 * \param size number of packets
 * \return None
 */
IFX_INLINE void IfxI2c_setTransmitPacketSize(Ifx_I2C *i2c, Ifx_SizeT size);

/**
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_stop(Ifx_I2C *i2c);

/**
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_waitBusFree(Ifx_I2C *i2c);

/** \brief Writes a packet (4 bytes) into the Fifo
 * \param i2c pointer to i2c registers
 * \param packet specifies the byte to be transfer
 * \return None
 */
IFX_INLINE void IfxI2c_writeFifo(Ifx_I2C *i2c, uint32 packet);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Configures the Module as Master
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_EXTERN void IfxI2c_configureAsMaster(Ifx_I2C *i2c);

/** \brief Disables the I2c Module
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_EXTERN void IfxI2c_disableModule(Ifx_I2C *i2c);

/** \brief enables the DTR interrupt
 * \param i2c pointer to i2c registers
 * \param typeOfService Type of Service (Cpu or DMA)
 * \param priority priority of the interrupt
 * \return None
 */
IFX_EXTERN void IfxI2c_enableDtrInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority);

/** \brief Enables the Error interrupt
 * \param i2c pointer to i2c registers
 * \param typeOfService Type of Service (Cpu or DMA)
 * \param priority priority of the interrupt
 * \return None
 */
IFX_EXTERN void IfxI2c_enableErrorInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority);

/** \brief Enables the I2c Module
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_EXTERN void IfxI2c_enableModule(Ifx_I2C *i2c);

/** \brief Enables the protocol interrupt
 * \param i2c pointer to i2c registers
 * \param typeOfService Type of Service (Cpu or DMA)
 * \param priority Priority of the interrupt
 * \return None
 */
IFX_EXTERN void IfxI2c_enableProtocolInterrupt(void *i2c, IfxSrc_Tos typeOfService, uint16 priority);

/**
 * \param i2c Resource index of the I2c
 * \return I2C module register address
 */
IFX_EXTERN Ifx_I2C *IfxI2c_getAddress(IfxI2c_Index i2c);

/** \brief Returns the real Baudrate
 * \return Baudrate
 */
IFX_EXTERN float32 IfxI2c_getBaudrate(Ifx_I2C *i2c);

/** \brief API to get the resource index of the I2C specified.
 * \param i2c Pointer to the I2C HW module (register memory map)
 * \return Resource index of the I2C
 */
IFX_EXTERN IfxI2c_Index IfxI2c_getIndex(Ifx_I2C *i2c);

/**
 * \return None
 */
IFX_EXTERN void IfxI2c_initSclSdaPin(const IfxI2c_Scl_InOut *scl, const IfxI2c_Sda_InOut *sda, IfxPort_PadDriver padDriver);

/** \brief Releases the bus, i.e puts a stop condition on the bus
 * \return None
 */
IFX_EXTERN void IfxI2c_releaseBus(Ifx_I2C *i2c);

/**
 * \return None
 */
IFX_EXTERN void IfxI2c_resetFifo(Ifx_I2C *i2c);

/** \brief resets the I2c kernel
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_EXTERN void IfxI2c_resetModule(Ifx_I2C *i2c);

/** \brief Calculates the desired baudrate
 * \param i2c pointer to i2c registers
 * \param baudrate specifies the baud rate
 * \return None
 */
IFX_EXTERN void IfxI2c_setBaudrate(Ifx_I2C *i2c, float32 baudrate);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief sets the interrupt request
 * \param i2c pointer to I2C registers
 * \param source Interrupt request source
 * \return None
 */
IFX_INLINE void IfxI2c_setInterruptRequest(Ifx_I2C *i2c, IfxI2c_InterruptRequest source);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Configures the Module as Slave
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_EXTERN void IfxI2c_configureAsSlave(Ifx_I2C *i2c);

/** \brief Configures the Address and Fifo registers
 * \param i2c pointer to i2c registers
 * \param config pointer to address and fifo configuration structures
 * \return None
 */
IFX_EXTERN void IfxI2c_configureAddrFifo(Ifx_I2C *i2c, const IfxI2c_Config *config);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE boolean IfxI2c_busIsFree(Ifx_I2C *i2c)
{
    boolean free = FALSE;

    if (i2c->BUSSTAT.B.BS == IfxI2c_BusStatus_idle)
    {
        free = TRUE;
    }

    return free;
}


IFX_INLINE void IfxI2c_clearAllDtrInterruptSources(Ifx_I2C *i2c)
{
    i2c->ICR.U = (1 << IFX_I2C_ICR_LSREQ_INT_OFF) | (1 << IFX_I2C_ICR_SREQ_INT_OFF) | (1 << IFX_I2C_ICR_LBREQ_INT_OFF) | (1 << IFX_I2C_ICR_BREQ_INT_OFF);
}


IFX_INLINE void IfxI2c_clearAllErrorInterruptSources(Ifx_I2C *i2c)
{
    i2c->ERRIRQSC.U = (1 << IFX_I2C_ERRIRQSC_RXF_UFL_OFF) | (1 << IFX_I2C_ERRIRQSC_RXF_OFL_OFF) | (1 << IFX_I2C_ERRIRQSC_TXF_UFL_OFF) | (1 << IFX_I2C_ERRIRQSC_TXF_OFL_OFF);
}


IFX_INLINE void IfxI2c_clearAllProtocolInterruptSources(Ifx_I2C *i2c)
{
    i2c->PIRQSC.U = (1 << IFX_I2C_PIRQSC_AM_OFF) | (1 << IFX_I2C_PIRQSC_GC_OFF) | (1 << IFX_I2C_PIRQSC_MC_OFF) | (1 << IFX_I2C_PIRQSC_AL_OFF) | (1 << IFX_I2C_PIRQSC_NACK_OFF) | (1 << IFX_I2C_PIRQSC_TX_END_OFF) | (1 << IFX_I2C_PIRQSC_RX_OFF);
}


IFX_INLINE void IfxI2c_clearDtrInterruptSource(Ifx_I2C *i2c, IfxI2c_DtrInterruptSource source)
{
    i2c->ICR.U = (1 << source);
}


IFX_INLINE void IfxI2c_clearErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source)
{
    i2c->ERRIRQSC.U = (1 << source);
}


IFX_INLINE void IfxI2c_clearProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source)
{
    i2c->PIRQSC.U = (1 << source);
}


IFX_INLINE void IfxI2c_clearRequestBuffer(Ifx_I2C *i2c)
{
    i2c->FIFOCFG.B.CRBC = 1;
}


IFX_INLINE void IfxI2c_disableDtrInterruptSource(Ifx_I2C *i2c, IfxI2c_DtrInterruptSource source)
{
    i2c->IMSC.U &= ~(1 << source);
}


IFX_INLINE void IfxI2c_disableErrorInterruptFlag(Ifx_I2C *i2c)
{
    i2c->IMSC.B.I2C_ERR_INT = 0;
}


IFX_INLINE void IfxI2c_disableErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source)
{
    i2c->ERRIRQSM.U &= ~(1 << source);
}


IFX_INLINE void IfxI2c_disableProtocolInterruptFlag(Ifx_I2C *i2c)
{
    i2c->IMSC.B.I2C_P_INT = 0;
}


IFX_INLINE void IfxI2c_disableProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source)
{
    i2c->PIRQSM.U &= ~(1 << source);
}


IFX_INLINE void IfxI2c_enableDtrInterruptSource(Ifx_I2C *i2c, IfxI2c_DtrInterruptSource source)
{
    i2c->IMSC.U |= (1 << source);
}


IFX_INLINE void IfxI2c_enableErrorInterruptFlag(Ifx_I2C *i2c)
{
    i2c->IMSC.B.I2C_ERR_INT = 1;
}


IFX_INLINE void IfxI2c_enableErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source)
{
    i2c->ERRIRQSM.U |= (1 << source);
}


IFX_INLINE void IfxI2c_enableProtocolInterruptFlag(Ifx_I2C *i2c)
{
    i2c->IMSC.B.I2C_P_INT = 1;
}


IFX_INLINE void IfxI2c_enableProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source)
{
    i2c->PIRQSM.U |= (1 << source);
}


IFX_INLINE IfxI2c_BusStatus IfxI2c_getBusStatus(Ifx_I2C *i2c)
{
    return (IfxI2c_BusStatus)i2c->BUSSTAT.B.BS;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getDtrSrcPointer(Ifx_I2C *i2c)
{
    if (i2c == &MODULE_I2C0)
    {
        return &MODULE_SRC.I2C.I2C[0].DTR;
    }
    else
    {
        return &MODULE_SRC.I2C.I2C[1].DTR;
    }
}


IFX_INLINE boolean IfxI2c_getDtrinterruptSourceStatus(Ifx_I2C *i2c, IfxI2c_DtrInterruptSource source)
{
    return (i2c->RIS.U & (1 << source)) ? TRUE : FALSE;
}


IFX_INLINE boolean IfxI2c_getErrorInterruptFlagStatus(Ifx_I2C *i2c)
{
    return i2c->RIS.B.I2C_ERR_INT;
}


IFX_INLINE boolean IfxI2c_getErrorInterruptSourceStatus(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source)
{
    return (i2c->ERRIRQSS.U & (1 << source)) ? TRUE : FALSE;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getErrorSrcPointer(Ifx_I2C *i2c)
{
    if (i2c == &MODULE_I2C0)
    {
        return &MODULE_SRC.I2C.I2C[0].ERR;
    }
    else
    {
        return &MODULE_SRC.I2C.I2C[1].ERR;
    }
}


IFX_INLINE boolean IfxI2c_getProtocolInterruptFlagStatus(Ifx_I2C *i2c)
{
    return i2c->RIS.B.I2C_P_INT;
}


IFX_INLINE boolean IfxI2c_getProtocolInterruptSourceStatus(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source)
{
    return (i2c->PIRQSS.U & (1 << source)) ? TRUE : FALSE;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getProtocolSrcPointer(Ifx_I2C *i2c)
{
    if (i2c == &MODULE_I2C0)
    {
        return &MODULE_SRC.I2C.I2C[0].P;
    }
    else
    {
        return &MODULE_SRC.I2C.I2C[1].P;
    }
}


IFX_INLINE boolean IfxI2c_isFifoRequest(Ifx_I2C *i2c)
{
    return i2c->RIS.U & 0x0F ? TRUE : FALSE;
}


IFX_INLINE void IfxI2c_run(Ifx_I2C *i2c)
{
    i2c->RUNCTRL.U = 1;
}


IFX_INLINE void IfxI2c_setBitAddressMode(Ifx_I2C *i2c, IfxI2c_AddressMode mode)
{
    i2c->ADDRCFG.B.TBAM = mode;
}


IFX_INLINE void IfxI2c_setPinSelection(Ifx_I2C *i2c, IfxI2c_PinSelect pisel)
{
    i2c->GPCTL.B.PISEL = pisel;
}


IFX_INLINE void IfxI2c_setReceivePacketSize(Ifx_I2C *i2c, Ifx_SizeT size)
{
    i2c->MRPSCTRL.B.MRPS = size;
}


IFX_INLINE void IfxI2c_setSlaveDeviceAddress(Ifx_I2C *i2c, uint16 address)
{
    i2c->ADDRCFG.B.ADR = address;
}


IFX_INLINE void IfxI2c_setSleepMode(Ifx_I2C *i2c, IfxI2c_SleepMode mode)
{
    i2c->CLC1.B.EDIS = mode;
}


IFX_INLINE void IfxI2c_setTransmitPacketSize(Ifx_I2C *i2c, Ifx_SizeT size)
{
    i2c->TPSCTRL.B.TPS = size;
}


IFX_INLINE void IfxI2c_stop(Ifx_I2C *i2c)
{
    i2c->RUNCTRL.U = 0;
}


IFX_INLINE void IfxI2c_waitBusFree(Ifx_I2C *i2c)
{
    while (IfxI2c_getBusStatus(i2c) != IfxI2c_BusStatus_idle)
    {}
}


IFX_INLINE void IfxI2c_writeFifo(Ifx_I2C *i2c, uint32 packet)
{
    i2c->TXD.U = packet;
}


IFX_INLINE void IfxI2c_setInterruptRequest(Ifx_I2C *i2c, IfxI2c_InterruptRequest source)
{
    i2c->ISR.U |= (1 << source);
}


#endif /* IFXI2C_H */
