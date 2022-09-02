/*
 * interface.h
 *
 *  Created on: Jul 15, 2022
 *      Author: Nada
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "types.h"


void SysTick_EnableTimer (void);
void SysTick_DisableTimer (void);
void SysTick_EnableInterrupt (void);
void SysTick_DisableInterrupt (void);
void SysTick_ClockSelect ( boolean SystemClock );
boolean SysTick_Get_Timer_Flag (void);
void SysTick_ClearTimer (void);
void SysTick_BusyWait ( uint32 Ticks, uint8 Round_Number );
void SysTick_Single_interval ( uint32 Ticks, uint8 Round_Number, void (* Ptr) (uint32) );
void SysTick_periodic_interval ( uint32 Ticks, uint8 Round_Number, void (* Ptr) (void) );
void SysTick_handler (void);






#endif /* TIMER_INTERFACE_H_ */
