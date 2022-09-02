/*
 * clk.h
 *
 *  Created on: Jul 18, 2022
 *      Author: Nada
 */

#ifndef CLK_H_
#define CLK_H_



#include "clk_private.h"
#include "macros.h"

typedef enum {
    PASS=1 ,
    MODULE_NOT_EXIST
}ClkError_t;

/* Enumerates the existing modules controlled by system control module */
typedef enum
{
    GPIOA=1 , GPIOB , GPIOC , GPIOD , GPIOE , GPIOF
}Port_t;


ClkError_t clock_Gating_set (Port_t obj);






#endif /* CLK_H_ */
