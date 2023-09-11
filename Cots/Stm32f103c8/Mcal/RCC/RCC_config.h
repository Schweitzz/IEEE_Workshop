/**************************************************/
/******* Author    : Kareem Amr Ahmed     *********/
/******* Date      : 01 sep 2023          *********/
/******* Version   : 1.0                  *********/
/******* File Name : RCC_CONFIG_H         *********/
/**************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and type.
 * @{
 */

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */
#define RCC_SYSCLK            RCC_PLL


/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS        RCC_CRYSTAL_CLK_
                                
#endif /**< RCC_SYSCLK */

/**
 * @brief Configure the clock type for PLL when using RCC_PLL.
 * @note Choose one of the available options:
 *       RCC_PLL_HSI_CLK          High-Speed Internal Clock Source (HSI) for PLL
 *       RCC_PLL_HSE_RC_CLK       High-Speed External Clock Source (HSE,RC) for PLL
 *       RCC_PLL_HSE_CRYSTAL_CLK  High-Speed External Clock Source (HSE,crystal) for PLL
 * 
 */
#if RCC_SYSCLK == RCC_PLL

#define RCC_PLL_CLK       RCC_PLL_HSI_CLK 
                                
#endif /**< RCC_SYSCLK */

/**
 * @brief Configure PLL multiplication factor when using RCC_PLL.
 * @note Choose one of the available options:
 *       PLL_input_clock_x2  
 *       PLL_input_clock_x3  
 *       PLL_input_clock_x4  
 *       PLL_input_clock_x5  
 *       PLL_input_clock_x6  
 *       PLL_input_clock_x7  
 *       PLL_input_clock_x8  
 *       PLL_input_clock_x9  
 *       PLL_input_clock_x10 
 *       PLL_input_clock_x11 
 *       PLL_input_clock_x12 
 *       PLL_input_clock_x13 
 *       PLL_input_clock_x14 
 *       PLL_input_clock_x15 
 *       PLL_input_clock_x16 
 */
#define MULTIPLICATION_FACTOR==PLL_input_clock_x9 
                                
 /**< RCC_SYSCLK */
/** @} */ // end of RCC_System_Clock_Config


                                
#endif /**< RCC_CONFIG_H_ */
