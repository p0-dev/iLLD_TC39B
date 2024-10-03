/**
 * \file IfxCpu_IntrinsicsHighTec.h
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
 * \defgroup IfxLld_Cpu_Intrinsics_Tasking Intrinsics for TASKING compiler
 * \ingroup IfxLld_Cpu_Intrinsics
 *
 */

#ifndef IFXCPU_INTRINSICSHIGHTEC_H
#define IFXCPU_INTRINSICSHIGHTEC_H

/******************************************************************************/
#include "Ifx_Types.h"

#include <tricoreintrin.h>

/******************************************************************************/
/* *INDENT-OFF* */
#define STRINGIFY(x)    #x

#define IFX_WEAK        __attribute__ ((weak))
/** Function call without return
 */
#define Ifx__non_return_call(fun)  __asm__ volatile ("ji %0"::"a"(fun))

IFX_INLINE void Ifx__moveToDataParam0(unsigned int var)
{
  __asm__ volatile ("mov\t %%d4, %0"::"d"(var));
}

IFX_INLINE void Ifx__moveToAddrParam0(const void *var)
{
  __asm__ volatile ("mov.aa\t %%a4, %0"::"a"(var));
}

IFX_INLINE void Ifx__jumpToFunction(const void *fun)
{
  Ifx__non_return_call(fun);
}

/** \defgroup IfxLld_Cpu_Intrinsics_HighTec_any_type Cross type arithmetic operation
 *
 * Macro compatible with float, fix point, signed integer and unsigned integer
 *
 * \ingroup IfxLld_Cpu_Intrinsics_HighTec
 * \{
 */
#define Ifx__minX(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define Ifx__maxX(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define Ifx__saturateX(X,Min,Max)          ( Ifx__minX(Ifx__maxX(X, Min), Max) )
#define Ifx__checkrangeX(X,Min,Max)        (((X) >= (Min)) && ((X) <= (Max)))
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_HighTec_singed_integer Signed integer operation
 * \ingroup IfxLld_Cpu_Intrinsics_HighTec
 * \{
 */
#define Ifx__saturate(X,Min,Max)           ( Ifx__min(Ifx__max(X, Min), Max) )
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_HighTec_unsinged_integer Unsigned integer operation
 * \ingroup IfxLld_Cpu_Intrinsics_HighTec
 * \{
 */
#define Ifx__saturateu(X,Min,Max)           ( Ifx__minu(Ifx__maxu(X, Min), Max) )
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_HighTecmin_max Minimum and Maximum of (sint16) Integers
 These intrinsic functions return the minimum or maximum of a sint16, uint16 or sint16
 * \ingroup IfxLld_Cpu_Intrinsics_HighTec
 * \{
 */

/** Return maximum of two integers
 */
IFX_INLINE sint32 Ifx__max(sint32 a, sint32 b)
{
    sint32 res;
    __asm__ volatile ("max %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return maximum of two sint16
 */
IFX_INLINE sint32 Ifx__maxs(sint16 a, sint16 b)
{
    sint32 res;
    __asm__ volatile ("max.h %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}
/** Return maximum of two unsigned integers
 */
IFX_INLINE uint32 Ifx__maxu(uint32 a, uint32 b)
{
    uint32 res;
    __asm__ volatile ("max.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return minimum of two integers
 */
IFX_INLINE sint32 Ifx__min(sint32 a, sint32 b)
{
    sint32 res;
    __asm__ volatile ("min %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return minimum of two sint16
 */
IFX_INLINE sint16 Ifx__mins(sint16 a, sint16 b)
{
    sint16 res;
    __asm__ volatile ("min.h %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return minimum of two unsigned integers
 */
IFX_INLINE uint32 Ifx__minu(uint32 a, uint32 b)
{
    uint32 res;
    __asm__ volatile ("min.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** \} */

/** \defgroup intrinsicsHighTec_float Floating point operation
 * \ingroup IfxLld_Cpu_Intrinsics_HighTec
 * \{
 */

#define Ifx__sqrf(X)                       ((X) * (X))
#define Ifx__sqrtf(X)                      sqrtf(X)
#define Ifx__checkrange(X,Min,Max)         (((X) >= (Min)) && ((X) <= (Max)))

#define Ifx__roundf(X)                     ((((X) - (sint32)(X)) > 0.5f) ? (1 + (sint32)(X)) : ((sint32)(X)))
#define Ifx__absf(X)                       ( ((X) < 0.0f) ? -(X) : (X) )
#define Ifx__minf(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define Ifx__maxf(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define Ifx__saturatef(X,Min,Max)          ( Ifx__minf(Ifx__maxf(X, Min), Max) )
#define Ifx__checkrangef(X,Min,Max)        (((X) >= (Min)) && ((X) <= (Max)))

#define Ifx__abs_stdreal(X)                ( ((X) > 0.0f) ? (X) : -(X) )
#define Ifx__min_stdreal(X,Y)              ( ((X) < (Y)) ? (X) : (Y) )
#define Ifx__max_stdreal(X,Y)              ( ((X) > (Y)) ? (X) : (Y) )
#define Ifx__saturate_stdreal(X,Min,Max)   ( Ifx__min_stdreal(Ifx__max_stdreal(X, Min), Max) )

#define Ifx__neqf(X,Y)                     ( ((X) > (Y)) ||  ((X) < (Y)) )     /**< X != Y */
#define Ifx__leqf(X,Y)                     ( !((X) > (Y)) )     /**< X <= Y */
#define Ifx__geqf(X,Y)                     ( !((X) < (Y)) )     /**< X >= Y */
/** \} */

/** Same as __extr() but return bit-field as unsigned integer
 */
#define Ifx__extru(src, pos, width) \
 __builtin_tricore_extr_u(src, pos, width)

/** Load a single bit.
 */
//#define __getbit(address,bitoffset ) __extru( *(address), bitoffset, 1 )
#define Ifx__getbit(address, bitoffset) ((*(address) & (1U << (bitoffset))) != 0)

/** Atomic load-modify-store.
 */
#define Ifx__imaskldmst(address, value, bitoffset, bits) \
  __builtin_tricore_imask_ldmst((volatile int *)address, value, bitoffset, bits)

/** Extract bit-field (width bits starting at bit 0) from src and insert it in trg at pos.
 */
#define Ifx__insert(src, val, pos, width) \
 __builtin_tricore_insert(src, val, pos, width)

/** Disable interrupts.
 */
#define Ifx__disable __builtin_tricore_disable

/** Enable interrupts immediately at function entry
 */
#define Ifx__enable __builtin_tricore_enable

/** \defgroup IfxLld_Cpu_Intrinsics_HighTecmiscellaneous Miscellaneous Intrinsic Functions
 * \ingroup IfxLld_Cpu_Intrinsics_HighTec
 * \{
 */

/**  Write back and invalidate cache index "p". Generates CACHEI.WI [Ab].
 */
IFX_INLINE void Ifx__cacheiwi(uint8* p)
{
    __asm__ volatile("cachei.wi [%0]0"::"a"(p));
}
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_HighTecregister Register Handling
 The next table provides an overview of the intrinsic functions that you can use to access control registers.
 * \ingroup IfxLld_Cpu_Intrinsics_HighTec
 * \{
 */

/**  Return absolute value
 */
#define Ifx__abs(a) __builtin_abs(a)

/**  Count leading zeros in int
 */
#define  Ifx__clz(a) __builtin_clz(a)

/**  Move contents of the addressed core SFR into a data register
 */
#define Ifx__mfcr(regaddr)  \
 ({ sint32 res; __asm__ volatile ("mfcr %0,%1": "=d" (res) :"i"(regaddr): "memory"); res; })

/** \} */

/**  Move contents of a data register (second int) to the addressed core SFR (first int)
 */
#define Ifx__mtcr(regaddr,val) __asm__ volatile ("mtcr %0,%1\n\tisync"::"i"(regaddr),"d"(val):"memory")

/**  Return saturated byte
 */
IFX_INLINE sint8 Ifx__satb(sint32 a)
{
    sint8 res;
    __asm__ volatile ("sat.b %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Return saturated uint8
 */
IFX_INLINE uint8 Ifx__satbu(uint32 a)
{
    uint8 res;
    __asm__ volatile ("sat.bu %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Return saturated halfword
 */
IFX_INLINE sint16 Ifx__sath(sint32 a)
{
    sint16 res;
    __asm__ volatile ("sat.h %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Return saturated unsigned halfword
 */
IFX_INLINE uint16 Ifx__sathu(uint32 a)
{
    uint16 res;
    __asm__ volatile ("sat.hu %0,%1":"=d"(res):"d"(a));
    return res;
}
/** \defgroup IfxLld_Cpu_Intrinsics_HighTecsaturation Saturation Arithmetic Support
 These intrinsics support saturation arithmetic
 * \ingroup IfxLld_Cpu_Intrinsics_HighTec
 * \{
 */

/** add signed with saturation
 */
IFX_INLINE sint32 Ifx__adds(sint32 a, sint32 b)
{
    sint32 res;
    __asm__ volatile ("adds %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** add unsigned with saturation
 */
IFX_INLINE uint32 Ifx__addsu(uint32 a, uint32 b)
{
    uint32 res;
    __asm__ volatile ("adds.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** substract signed with saturation
 */
IFX_INLINE sint32 Ifx__subs(sint32 a, sint32 b)
{
    sint32 res;
    __asm__ volatile ("subs %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** substract unsigned with saturation
 */
IFX_INLINE uint32 Ifx__subsu(uint32 a, uint32 b)
{
    uint32 res;
    __asm__ volatile ("subs.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}
/** \} */


/** \defgroup IfxLld_Cpu_Intrinsics_HighTeccsingle_assembly Insert Single Assembly Instruction
 The next table provides an overview of the intrinsic functions that you can use to insert a single assembly
 instruction.You can also use inline assembly but these intrinsics provide a shorthand for frequently used
 assembly instructions.
 * \ingroup IfxLld_Cpu_Intrinsics_HighTec
 * \{
 */

/** Insert DEBUG instruction
 */
#define Ifx__debug __builtin_tricore_debug

/** Insert a memory barrier
 */
#define Ifx__mem_barrier __asm__ volatile("":::"memory");

/** Insert DSYNC instruction
 */
#define Ifx__dsync __builtin_tricore_dsync

/** Insert ISYNC instruction
 */
#define Ifx__isync __builtin_tricore_isync

/** Insert LDMST instruction. Note that all operands must be word-aligned.
 */
#define Ifx__ldmst(address, mask, value) \
  __builtin_tricore_ldmst((volatile int *)address, value, mask)

/** Insert NOP instruction
 */
#define Ifx__nop __builtin_tricore_nop

/** Insert SWAP instruction. Note that all operands must be word-aligned.
 */
#define Ifx__swap(place, value) __builtin_tricore_swap_w((volatile int *)place, value)

/** Insert n NOP instruction
 */
#define Ifx__NOP(n)   __asm(".rept " #n "\n\tnop\n\t.endr\n")

/** \} */

/**__mtcr (CPU_CCTRL, 0);
*/
IFX_INLINE void Ifx__stopPerfCounters()
{
  __builtin_tricore_mtcr_by_name("CCTRL", 0);
  __builtin_tricore_isync();
}

/** \brief This function is a implementation of a binary semaphore using compare and swap instruction
 * \param address address of resource.
 * \param value This variable is updated with status of address
 * \param condition if the value of address matches with the value of condition, then swap of value & address occurs.
 *
 */
IFX_INLINE unsigned int Ifx__cmpAndSwap (unsigned int volatile *address,
           unsigned int value, unsigned int condition)
{
  unsigned long long reg64;

  __asm__ __volatile__ (
    "mov\t%A[reg], %[cond], %[val]\n\t"
    "cmpswap.w [%[addr]]0, %A[reg]" :
    [reg] "=d" (reg64) :
    [addr] "a" (address),
    [cond] "d" (condition),
    [val] "d" (value) :
    "memory");
  return reg64;
}

IFX_INLINE void* Ifx__getA11(void)
{
    uint32 *res;
    __asm__ volatile ("mov.aa %0, %%a11": "=a" (res) : :"a11");
    return res;
}

IFX_INLINE uint32 IfxCpu_calculateCrc32(uint32 *startaddress, uint8 length) 
{
    uint32 returnvalue = 0; /* set seed value to 0 */
    for (;length > 0; length--) 
    { 
    	  /* calculate the CRC over all data */
        returnvalue = __builtin_tricore_crc32b_w(returnvalue, *startaddress);
        startaddress++; 
    } 
    return returnvalue;
}

/** \brief Function calculates a user defined CRC
 *
 * Bit31    15      12         10       9        8                2         Bit0
 *  ---------------------------------------------------------------------------
 * |        |        |         |        |        |                |    input   |
 * | poly-  | CRC    |    0    | inver  | bit    |        0       |    data    |
 * | nomial | width  |         | sion   | order  |                |    width   |
 * |        | (1-16) |         |        |        |                |    (1-8)   |
 *  ---------------------------------------------------------------------------
 *
 * \param startaddress value to be converted.
 * \param seedValue Seed value for CRC.
 * \param length length of data.
 * \param value Parameters of CRC algorithm.
 * \return Returns the calculated CRC value.
 *
 */
IFX_INLINE uint16 Ifx__calculateCrcN(uint8 *startaddress, uint16 seedValue, uint8 length, uint32 value)
{
	uint16 returnvalue = seedValue;
	for (;length > 0; length--)
	{
		__asm__ volatile("crcn %0,%0,%1,%2" :"+d"(returnvalue) : "d"(value), "d" (*startaddress) : "memory");
		startaddress++;
	}
    return returnvalue;
}

IFX_INLINE uint32 IfxCpu_getRandomVal(uint32 a, uint32 x, uint32 m)
{
	uint32 result;
  __asm__ volatile (
    "      mul.u     %%e14,%1,%2       # d15 = Eh; d14 = El    \n"
    "        mov       %%d12,%%d14       #   e12 = El            \n"
    "        mov       %%d13, 0          #                       \n"
    "        madd.u    %%e14,%%e12,%%d15, 5 # e14 = El + 5 * d15    \n"
    " cmp_m_%=: jge.u     %%d14,%3,sub_m_%=    #                       \n"
    "        jz        %%d15,done_%=        #                       \n"
    " sub_m_%=: subx      %%d14,%%d14,%3    #  e12=e12-m            \n"
    "        subc      %%d15,%%d15,%%d13 # d13=d13-0             \n"
    "        loopu     cmp_m_%=             #                       \n"
    " done_%=:  mov       %0,%%d14          #                       \n"
    : "=d"(result) : "d"(a), "d"(x), "d"(m) : "d12","d13","d14","d15");
  return result;
}


/* Macros for backward compatibility of the intrinsics*/
/******************************************************************************/
#ifndef IFX_CFG_DISABLE_DEFAULT_INTRINSICS

#ifndef __moveToDataParam0
#define __moveToDataParam0 Ifx__moveToDataParam0
#endif

#ifndef __moveToAddrParam0
#define __moveToAddrParam0 Ifx__moveToAddrParam0
#endif

#ifndef __jumpToFunction
#define __jumpToFunction Ifx__jumpToFunction
#endif

#ifndef __minX
#define __minX Ifx__minX
#endif

#ifndef __maxX
#define __maxX Ifx__maxX
#endif

#ifndef __saturateX
#define __saturateX Ifx__saturateX
#endif

#ifndef __checkrangeX
#define __checkrangeX Ifx__checkrangeX
#endif

#ifndef __saturate
#define __saturate Ifx__saturate
#endif

#ifndef __saturateu
#define __saturateu Ifx__saturateu
#endif

#ifndef __max
#define __max Ifx__max
#endif

#ifndef __maxs
#define __maxs Ifx__maxs
#endif

#ifndef __maxu
#define __maxu Ifx__maxu
#endif

#ifndef __min
#define __min Ifx__min
#endif

#ifndef __mins
#define __mins Ifx__mins
#endif

#ifndef __minu
#define __minu Ifx__minu
#endif

#ifndef __sqrtf
#define __sqrtf Ifx__sqrtf
#endif

#ifndef __sqrf
#define __sqrf Ifx__sqrf
#endif

#ifndef __checkrange
#define __checkrange Ifx__checkrange
#endif

#ifndef __roundf
#define __roundf Ifx__roundf
#endif

#ifndef __absf
#define __absf Ifx__absf
#endif

#ifndef __saturatef
#define __saturatef Ifx__saturatef
#endif

#ifndef __minf
#define __minf Ifx__minf
#endif

#ifndef __maxf
#define __maxf Ifx__maxf
#endif

#ifndef __checkrangef
#define __checkrangef Ifx__checkrangef
#endif

#ifndef __abs_stdreal
#define __abs_stdreal Ifx__abs_stdreal
#endif

#ifndef __saturate_stdreal
#define __saturate_stdreal Ifx__saturate_stdreal
#endif

#ifndef __min_stdreal
#define __min_stdreal Ifx__min_stdreal
#endif

#ifndef __max_stdreal
#define __max_stdreal Ifx__max_stdreal
#endif

#ifndef __neqf
#define __neqf Ifx__neqf
#endif

#ifndef __leqf
#define __leqf Ifx__leqf
#endif

#ifndef __geqf
#define __geqf Ifx__geqf
#endif

#ifndef __extru
#define __extru Ifx__extru
#endif

#ifndef __getbit
#define __getbit Ifx__getbit
#endif

#ifndef __insert
#define __insert Ifx__insert
#endif

#ifndef __imaskldmst
#define __imaskldmst Ifx__imaskldmst
#endif

#ifndef __disable
#define __disable Ifx__disable
#endif

#ifndef __enable
#define __enable Ifx__enable
#endif

#ifndef __abs
#define __abs Ifx__abs
#endif

#ifndef __clz
#define __clz Ifx__clz
#endif

#ifndef __mfcr
#define __mfcr Ifx__mfcr
#endif

#ifndef __mtcr
#define __mtcr Ifx__mtcr
#endif


#ifndef __satb
#define __satb Ifx__satb
#endif

#ifndef __satbu
#define __satbu Ifx__satbu
#endif

#ifndef __sath
#define __sath Ifx__sath
#endif

#ifndef __sathu
#define __sathu Ifx__sathu
#endif

#ifndef __adds
#define __adds Ifx__adds
#endif

#ifndef __addsu
#define __addsu Ifx__addsu
#endif

#ifndef __subs
#define __subs Ifx__subs
#endif

#ifndef __subsu
#define __subsu Ifx__subsu
#endif

#ifndef __debug
#define __debug Ifx__debug
#endif

#ifndef __mem_barrier
#define __mem_barrier Ifx__mem_barrier
#endif

#ifndef __dsync
#define __dsync Ifx__dsync
#endif

#ifndef __isync
#define __isync Ifx__isync
#endif

#ifndef __ldmst
#define __ldmst Ifx__ldmst
#endif

#ifndef __nop
#define __nop Ifx__nop
#endif

#ifndef __swap
#define __swap Ifx__swap
#endif

#ifndef NOP
#define NOP Ifx__NOP
#endif

#ifndef __stopPerfCounters
#define __stopPerfCounters Ifx__stopPerfCounters
#endif

#ifndef __cmpAndSwap
#define __cmpAndSwap Ifx__cmpAndSwap
#endif

#ifndef __getA11
#define __getA11 Ifx__getA11
#endif

#endif
/******************************************************************************/
/* *INDENT-ON* */
/******************************************************************************/
#endif /* IFXCPU_INTRINSICSHIGHTEC_H */
