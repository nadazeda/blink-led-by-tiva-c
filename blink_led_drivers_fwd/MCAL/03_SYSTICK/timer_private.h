/*
 * private.h
 *
 *  Created on: Jul 15, 2022
 *      Author: Nada
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_



/* SysTick registers bases */
#define STK_STCTRL      (( volatile uint32* )( 0xE000E010 ))

#define STK_STRELOAD    (( volatile uint32* )( 0xE000E014 ))

#define STK_STCURRENT   (( volatile uint32* )( 0xE000E018 ))

/*********************************************************************************/

/* location of control bits inside STCTRL register */

#define STK_ENABLE_BIT_POS      0
#define STK_INTEN_BIT_POS       1
#define STK_CLK_SRC_BIT_POS     2
#define STK_COUNT_BIT_POS       16


/*********************************************************************************/

void SysTick_ISR (void) ;



#endif /* TIMER_PRIVATE_H_ */
