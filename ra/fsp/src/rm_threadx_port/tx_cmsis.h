/**************************************************************************/

/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** ThreadX Component                                                     */
/**                                                                       */
/**   CMSIS                                                               */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#ifndef TX_CMSIS_H
#define TX_CMSIS_H

#if defined(__GNUC__) && !defined(__ARMCC_VERSION)

/* Ignore GCC warnings in CMSIS code. */
 #pragma GCC diagnostic ignored "-Wsign-conversion"
 #pragma GCC diagnostic push
#endif

#include <stddef.h>
#include "../../src/bsp/mcu/all/bsp_exceptions.h"

/* Workaround for LLVM. __ARM_ARCH_8_1M_MAIN__ is defined for CM85 parts. But CMSIS_5 does not support this */
#if defined(__llvm__) && !defined(__CLANG_TIDY__) && defined(__ARM_ARCH_8_1M_MAIN__)
 #undef __ARM_ARCH_8_1M_MAIN__
 #define __ARM_ARCH_8M_MAIN__    1
#endif
#include "cmsis_compiler.h"

/* Workaround for compilers that are not defining __ARM_ARCH_8_1M_MAIN__ for CM85 parts. */
#if BSP_CFG_MCU_PART_SERIES == 8
 #undef __ARM_ARCH_8M_MAIN__
 #define __ARM_ARCH_8_1M_MAIN__    1
#endif

#include "bsp_api.h"                   /* This include brings in a workaround for defining __ARM_ARCH_8_1M_MAIN__. It should be removed when this behaviour is fixed. */

#if   __ARM_ARCH_7EM__
 #define __MPU_PRESENT             1   /*!< MPU present or not                                                    */
 #define __NVIC_PRIO_BITS          4   /*!< Number of Bits used for Priority Levels                               */
 #define __Vendor_SysTickConfig    0   /*!< Set to 1 if different SysTick Config is used                          */
 #define __FPU_PRESENT             1   /*!< FPU present or not                                                    */
 #include "core_cm4.h"
#elif __ARM_ARCH_8M_BASE__
 #define __MPU_PRESENT             1   /*!< MPU present or not                                                    */
 #define __NVIC_PRIO_BITS          2   /*!< Number of Bits used for Priority Levels                               */
 #define __Vendor_SysTickConfig    0   /*!< Set to 1 if different SysTick Config is used                          */
 #define __FPU_PRESENT             0   /*!< FPU present or not                                                    */
 #include "core_cm23.h"                /*!< Cortex-M23 processor and core peripherals                             */
#elif __ARM_ARCH_8M_MAIN__
 #define __MPU_PRESENT             1   /*!< MPU present or not                                                    */
 #define __NVIC_PRIO_BITS          4   /*!< Number of Bits used for Priority Levels                               */
 #define __Vendor_SysTickConfig    0   /*!< Set to 1 if different SysTick Config is used                          */
 #define __FPU_PRESENT             1   /*!< FPU present or not                                                    */
 #define __DSP_PRESENT             1   /*!< DSP present or not                                                    */
 #include "core_cm33.h"
#elif __ARM_ARCH_8_1M_MAIN__
 #define __MPU_PRESENT             1   /*!< MPU present or not                                                    */
 #define __NVIC_PRIO_BITS          4   /*!< Number of Bits used for Priority Levels                               */
 #define __Vendor_SysTickConfig    0   /*!< Set to 1 if different SysTick Config is used                          */
 #define __FPU_PRESENT             1   /*!< FPU present or not                                                    */
 #define __DSP_PRESENT             1   /*!< DSP present or not                                                    */
 #include "core_cm85.h"
#else
 #error Unsupported Architecture
#endif

#if defined(__GNUC__) && !defined(__ARMCC_VERSION)

/* Restore warning settings for 'sign-conversion' to as specified on command line. */
 #pragma GCC diagnostic pop
#endif

#endif                                 /* TX_CMSIS_H */
