/*
 * program.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Nada
 */




#include "timer_config.h"
#include "timer_interface.h"
#include "timer_private.h"
#include "types.h"
#include "macros.h"



/* used to indicate single or periodic notification, TRUE for single */
boolean SysTick_Single_Flag = FALSE ;

/* used to hold number of rounds of ticks */
uint8 SysTick_Rounds_for_Isr = 0 ;

/* used in case of periodic notification to reset it */
uint8 SysTick_Rounds_for_Isr_Temp = 0 ;

/* callback function */
void (* SysTick_CallBack ) (void) = NULL_PTR;


/** use this function to start SysTick Timer operation ***/


void SysTick_EnableTimer (void)
{

    SET_BIT_( *STK_STCTRL, STK_ENABLE_BIT_POS ) ;

    return ;
}


/** use this function to stop SysTick Timer operation ***/

void SysTick_DisableTimer (void)
{

    RESET_BIT_( *STK_STCTRL, STK_ENABLE_BIT_POS) ;

    return ;
}


/* * this function will Enable interrupt of SysTick Timer***/


void SysTick_EnableInterrupt (void)
{

    SET_BIT_( *STK_STCTRL, STK_INTEN_BIT_POS ) ;

    return ;
}


/* * this function will disable interrupt of SysTick Timer***/

void SysTick_DisableInterrupt (void)
{

    RESET_BIT_( *STK_STCTRL,STK_INTEN_BIT_POS ) ;

    return ;
}


/*
 * this function will select Clock of Timer
 * it will select system clock if function input TRUE
 * it will select PIOSC/4 if function input FALSE
 */

void SysTick_ClockSelect ( boolean SystemClock )
{

    ASSIGN_BIT( *STK_STCTRL, STK_CLK_SRC_BIT_POS, SystemClock ) ;

    return ;
}


/* this function will return state of Timer flag when this function is used Timer flag will be cleared */

boolean SysTick_Get_Timer_Flag (void)
{
    return GET_BIT( *STK_STCTRL, STK_COUNT_BIT_POS ) ;
}



/* this function will clear all timer data and cancel any running operation****/


void SysTick_ClearTimer (void)
{

    *STK_STCURRENT = 0;
    *STK_STRELOAD = 0;
    return ;
}




void SysTick_BusyWait ( uint32 Ticks, uint8 Round_Number )
{



    *STK_STCURRENT = 0 ;
    *STK_STRELOAD = Ticks  ;
    SET_BIT_( *STK_STCTRL, STK_ENABLE_BIT_POS ) ;

    do
    {
        while( ! (GET_BIT( *STK_STCTRL, STK_COUNT_BIT_POS )) ) ;

    }
    while( Round_Number -- ) ;

    /* clear timer  */
    *STK_STRELOAD = 0  ;
    *STK_STCURRENT = 0 ;

    return ;
}


void SysTick_Single_interval ( uint32 Ticks, uint8 Round_Number, void (* Ptr) (uint32) )
{



    *STK_STCURRENT = 0 ;
    *STK_STRELOAD = Ticks  ;

    SysTick_Single_Flag = TRUE ;
    SysTick_Rounds_for_Isr = Round_Number ;
    SysTick_CallBack =Ptr ;


    
}



void SysTick_periodic_interval ( uint32 Ticks, uint8 Round_Number, void (* Ptr) (void) )
{

    *STK_STCURRENT = 0 ;
    *STK_STRELOAD = Ticks  ;

    SysTick_Single_Flag = FALSE ;
    SysTick_Rounds_for_Isr = Round_Number ;
    SysTick_Rounds_for_Isr_Temp = Round_Number ;
    SysTick_CallBack =Ptr ;

   
}


/* this is handler of SysTick timer called when timer flag is set */
void SysTick_handler (void)
{
    /* to clear timer flag */
    GET_BIT( *STK_STCTRL, STK_COUNT_BIT_POS ) ;

    if ( SysTick_Rounds_for_Isr )
    {
        SysTick_Rounds_for_Isr -- ;
    }
    else
    {


        SysTick_CallBack () ;
        if ( SysTick_Single_Flag )
        {
            /* case of single interval */
            /* clear timer operation */
            *STK_STRELOAD = 0  ;
            *STK_STCURRENT = 0 ;
            SysTick_CallBack =  NULL_PTR ;

        }
        else
        {
            /* case of periodic notification */
            /* resetting periodic notification */
            SysTick_Rounds_for_Isr = SysTick_Rounds_for_Isr_Temp ;
        }
    }
    return ;
}


