/**
  ******************************************************************************
  * @file    air401xx.h
  * @brief   CMSIS AIR401xx Device Peripheral Access Layer Header File.
  * @version v1.0.0
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) AirM2M.
  * All rights reserved.</center></h2>
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup air401xx
  * @{
  */
#ifndef __AIR401XX_H
#define __AIR401XX_H

/**
  * @brief AIR401 Family
  */
#if !defined (AIR401)
#define AIR401
#endif /* AIR401 */

/**  Uncomment the line below according to the target AIR401 device used in your
  *  application.
  */

#if !defined (AIR401_DEV) 
#endif
/**  Tip: To avoid modifying this file each time you need to switch between these
  *       devices, you can define the device in your toolchain compiler preprocessor.
  */

#if (defined(AIR401_DEV))
#define AIR401PRE
#endif

/**
  * @brief CMSIS Device version number V1.0.0
  */
#define __AIR401_DEVICE_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define __AIR401_DEVICE_VERSION_SUB1   (0x00) /*!< [23:16] sub1 version */
#define __AIR401_DEVICE_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
#define __AIR401_DEVICE_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __AIR401_DEVICE_VERSION        ((__AIR401_DEVICE_VERSION_MAIN << 24)\
                                        |(__AIR401_DEVICE_VERSION_SUB1 << 16)\
                                        |(__AIR401_DEVICE_VERSION_SUB2 << 8 )\
                                        |(__AIR401_DEVICE_VERSION_RC))

/**
  * @brief Device_Included
  */
#if defined(AIR401_DEV)
#include "air401_dev.h"
#else
#error "Please select first the target AIR401xx device used in your application (in air401xx.h file)"
#endif /* Device_Included */

/**
  * @brief Exported_types
  */
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum 
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;

/**
  * @brief Exported_macros
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/* Use of interrupt control for register exclusive access */
/* Atomic 32-bit register access macro to set one or several bits */
#define ATOMIC_SET_BIT(REG, BIT)                             \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    SET_BIT((REG), (BIT));                                   \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 32-bit register access macro to clear one or several bits */
#define ATOMIC_CLEAR_BIT(REG, BIT)                           \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    CLEAR_BIT((REG), (BIT));                                 \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 32-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK)            \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    MODIFY_REG((REG), (CLEARMSK), (SETMASK));                \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 16-bit register access macro to set one or several bits */
#define ATOMIC_SETH_BIT(REG, BIT) ATOMIC_SET_BIT(REG, BIT)                                   \

/* Atomic 16-bit register access macro to clear one or several bits */
#define ATOMIC_CLEARH_BIT(REG, BIT) ATOMIC_CLEAR_BIT(REG, BIT)                               \

/* Atomic 16-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFYH_REG(REG, CLEARMSK, SETMASK) ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK) \

#define HW32_REG(ADDRESS)     ( * ((volatile unsigned           int * )(ADDRESS)))

#define HW16_REG(ADDRESS)     ( * ((volatile unsigned short     int * )(ADDRESS)))

#define HW8_REG(ADDRESS)      ( * ((volatile unsigned          char * )(ADDRESS)))

#define M32(ADDRESS)          HW32_REG(ADDRESS)

#define M16(ADDRESS)          HW16_REG(ADDRESS)

#define M8(ADDRESS)           HW8_REG(ADDRESS)

/**
  * @}
  */

/**
  * @brief Comment the line below if you will not use the peripherals drivers.
  *        In this case, these drivers will not be included and the application code will
  *        be based on direct access to peripherals registers
  */
#if !defined  (USE_HAL_DRIVER)
/*#define USE_HAL_DRIVER */
#endif /* USE_HAL_DRIVER */

#if defined (USE_HAL_DRIVER)
#include "air401xx_hal.h"
#endif /* Device_Included */
#endif /* USE_HAL_DRIVER */

#endif /* __AIR401xx_H */

#ifdef __cplusplus
}
#endif /* __cplusplus */

/************************ (C) COPYRIGHT AirM2M *****END OF FILE******************/

