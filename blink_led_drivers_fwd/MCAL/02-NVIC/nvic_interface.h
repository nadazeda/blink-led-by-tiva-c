/***********************************************************************************************************
 * interface.h
 *
 *  Created on: Jul 14, 2022
 *      Author: Nada
 ****************************************************************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#include "types.h"

void interrupt_enable (uint8 interrupt_number);
void interrupt_disable (uint8 interrupt_number);
void set_pending (uint8 interrupt_number);
void clear_pending (uint8 interrupt_number);
uint8 Git_active_flag (uint8 interrupt_number);
void Trigger_Interrupt ( uint8 interrupt_number );
uint8 Set_priority (sint8 interrupt_number , uint8 group_priority ,uint8 sub_group_priority , uint32 group);



#define GROUP_4_SUB_0    0X05FA0400     /*3 bits for group in PRI*/
#define GROUP_3_SUB_2    0X05FA0500     /*2 bits for group & 1 bit for subgroup in PRI*/
#define GROUP_2_SUB_1    0X05FA0600     /*1 bit for group & 2 bits for subgroup in PRI*/
#define GROUP_0_SUB_4    0X05FA0700     /*3 bits for sub group in PRI*/







#endif /* NVIC_INTERFACE_H_ */
