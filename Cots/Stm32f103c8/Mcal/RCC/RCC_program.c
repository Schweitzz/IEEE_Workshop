/**************************************************/
/******* Author    : Kareem Amr Ahmed     *********/
/******* Date      : 01 sep 2023          *********/
/******* Version   : 1.0                  *********/
/******* File Name : RCC_PROGRAM_C        *********/
/**************************************************/


/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*****************************< Function Implementations *****************************/
Std_ReturnType MCAL_Rcc_InitSysClock(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    #if RCC_SYSCLK == RCC_HSE
        
        /**< Enable the external clock to be the source for the system clock. */
        #if RCC_CLK_BYPASS == RCC_RC_CLK_
            SET_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose RC as a SYSCLK */
        #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
            CLR_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose CRYSTAL as a SYSCLK */
        #else 
            #error "Wrong Choice !!"
        #endif /**< RCC_CLK_BYPASS */

        /**< Enable the High-Speed External clock. */
        SET_BIT(RCC_CR, RCC_CR_HSEON);

        /**< Wait until the High-Speed External clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_HSERDY));

        /**< Select High-Speed External clock as the system clock source. */
        RCC_CFGR = 0x00000001;

        Local_FunctionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_HSI
        
        /**< Enable the High-Speed Internal clock. */
        SET_BIT(RCC_CR, RCC_CR_HSION);

        /**< Wait until the High-Speed Internal clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_HSIRDY));

        /**< Select High-Speed Internal clock as the system clock source. */
        RCC_CFGR = 0x00000000;

        Local_FunctionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_PLL
        /*Setting multiplication factor*/
        #if GET_BIT(MULTIPLICATION_FACTOR,1);  
        SET_BIT(RCC_CFGR, PLLMUL); 
        #else
        CLR_BIT(RCC_CFGR, PLLMUL);
        #endif
        #if  GET_BIT(MULTIPLICATION_FACTOR,2)  
        SET_BIT(RCC_CFGR, (PLLMUL+1));
        #else
        CLR_BIT(RCC_CFGR, PLLMUL);
        #endif
        #if  GET_BIT(MULTIPLICATION_FACTOR,3) 
        SET_BIT(RCC_CFGR, (PLLMUL+2)); 
        #else
        CLR_BIT(RCC_CFGR, PLLMUL);
        #endif
        #if (GET_BIT(MULTIPLICATION_FACTOR,4);)  
        SET_BIT(RCC_CFGR, (PLLMUL+3)); 
        #else
        CLR_BIT(RCC_CFGR, PLLMUL);
        #endif
        
        #if RCC_PLL_CLK==RCC_PLL_HSI_CLK 


        /**< Enable the High-Speed Internal clock. */
        SET_BIT(RCC_CR, RCC_CR_HSION);

        /**< Wait until the High-Speed Internal clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_HSIRDY));
        
        /*setting PLL source*/
        CLR_BIT(RCC_CFGR,PLLSRC);

        /**< Enable PLL clock. */
        SET_BIT(RCC_CR, RCC_CR_PLLON);

        /**< Wait until PLL clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_PLLRDY));
        Local_FunctionStatus = E_OK;

        /*swithcing clock to pll*/
        SET_BIT(RCC_CFGR,SW);
        SET_BIT(RCC_CFGR,SW+1);


        #elif RCC_PLL_CLK==RCC_PLL_HSE_RC_CLK 
        #endif /*PLL clock setup*/
    #else
        #error "Wrong Choice !!"

    #endif /**< RCC_SYSCLK */

    return Local_FunctionStatus;
}

Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        /**< Enable the peripheral on the AHB bus. */
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB1 bus. */
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB2 bus. */
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;
}

Std_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        /**< Disable the peripheral on the AHB bus. */
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Disable the peripheral on the APB1 bus. */
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Disable the peripheral on the APB2 bus. */
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;
}
/*****************************< End of Function Implementations *****************************/
