

#ifndef SYSTEM_DRIVERS_IRQ_INC_TIMER_REG_H_
#define SYSTEM_DRIVERS_IRQ_INC_TIMER_REG_H_

#include "types.h"

/**
  * @brief External Interrupt/Event Controller
  */

typedef struct
{
  __IO IMR;    /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
  __IO EMR;    /*!< EXTI Event mask register,                Address offset: 0x04 */
  __IO RTSR;   /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
  __IO FTSR;   /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
  __IO SWIER;  /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
  __IO PR;     /*!< EXTI Pending register,                   Address offset: 0x14 */
} EXTI_t;

/** \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  __IO ISER[8];                 /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
  __IO    RESERVED0[24];
  __IO ICER[8];                 /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register         */
  __IO     RSERVED1[24];
  __IO  ISPR[8];                 /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register          */
  __IO     RESERVED2[24];
  __IO  ICPR[8];                 /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register        */
  __IO     RESERVED3[24];
  __IO  IABR[8];                 /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register           */
  __IO     RESERVED4[56];
  uint8_t  IP[240];                 /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
  __IO     RESERVED5[644];
  __O   STIR;                    /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register     */
}  NVIC_Type;

#define NVIC_STIR_INTID_Pos                 0                                          /*!< STIR: INTLINESNUM Position */
#define NVIC_STIR_INTID_Msk                (0x1FFUL << NVIC_STIR_INTID_Pos)            /*!< STIR: INTLINESNUM Mask */

/** \ingroup  CMSIS_core_register
    \defgroup CMSIS_SCB     System Control Block (SCB)
    \brief      Type definitions for the System Control Block Registers
  @{
 */

/** \brief  Structure type to access the System Control Block (SCB).
 */
typedef struct
{
  __I   CPUID;                   /*!< Offset: 0x000 (R/ )  CPUID Base Register                                   */
  __IO  ICSR;                    /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register                  */
  __IO  VTOR;                    /*!< Offset: 0x008 (R/W)  Vector Table Offset Register                          */
  __IO  AIRCR;                   /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register      */
  __IO  SCR;                     /*!< Offset: 0x010 (R/W)  System Control Register                               */
  __IO  CCR;                     /*!< Offset: 0x014 (R/W)  Configuration Control Register                        */
  __IO   SHP[12];                 /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  __IO  SHCSR;                   /*!< Offset: 0x024 (R/W)  System Handler Control and State Register             */
  __IO  CFSR;                    /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register                    */
  __IO  HFSR;                    /*!< Offset: 0x02C (R/W)  HardFault Status Register                             */
  __IO  DFSR;                    /*!< Offset: 0x030 (R/W)  Debug Fault Status Register                           */
  __IO  MMFAR;                   /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register                      */
  __IO  BFAR;                    /*!< Offset: 0x038 (R/W)  BusFault Address Register                             */
  __IO  AFSR;                    /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register                       */
  __I   PFR[2];                  /*!< Offset: 0x040 (R/ )  Processor Feature Register                            */
  __I   DFR;                     /*!< Offset: 0x048 (R/ )  Debug Feature Register                                */
  __I   ADR;                     /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register                            */
  __I   MMFR[4];                 /*!< Offset: 0x050 (R/ )  Memory Model Feature Register                         */
  __I   ISAR[5];                 /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register                   */
       uint32 RESERVED0[5];
  __IO  CPACR;                   /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register                   */
} SCB_Type;
/** \brief  Structure type to access the System Timer (SysTick).
 */
typedef struct
{
  __IO  CTRL;                    /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IO  LOAD;                    /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register       */
  __IO  VAL;                     /*!< Offset: 0x008 (R/W)  SysTick Current Value Register      */
  __I   CALIB;                   /*!< Offset: 0x00C (R/ )  SysTick Calibration Register        */
} SysTick_Type;

typedef struct
{
    uint32 RESERVED0[1];
  __I  ICTR;                    /*!< Offset: 0x004 (R/ )  Interrupt Controller Type Register      */
  __IO ACTLR;                   /*!< Offset: 0x008 (R/W)  Auxiliary Control Register              */
} SCnSCB_Type;
#endif /* SYSTEM_DRIVERS_IRQ_INC_TIMER_REG_H_ */
