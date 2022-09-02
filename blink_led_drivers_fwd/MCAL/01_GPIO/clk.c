/*
 * clk.c
 *
 *  Created on: Jul 18, 2022
 *      Author: Nada
 */

#include "clk.h"

ClkError_t clock_Gating_set (Port_t obj)
{
    ClkError_t state = PASS ;


    if(obj == GPIOA)
    {
       WRITE_BIT(RCGCGPIO,0,HIGH)
    }
    else if(obj == GPIOB)
    {
        WRITE_BIT(RCGCGPIO,1,HIGH)

    }
    else if(obj == GPIOC)
    {

        WRITE_BIT(RCGCGPIO,2,HIGH)

    }
    else if(obj == GPIOD)
    {
        WRITE_BIT(RCGCGPIO,3,HIGH)

    }
    else if(obj == GPIOE)
    {
        WRITE_BIT(RCGCGPIO,4,HIGH)

    }
    else if(obj == GPIOF)
    {
        WRITE_BIT(RCGCGPIO,5,HIGH)

    }
    else
    {
        state = MODULE_NOT_EXIST;
    }
return state;
}






