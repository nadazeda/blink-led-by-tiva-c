/**************************************************************************************************************************
 * program.c
 *
 *  Created on: Jul 14, 2022
 *      Author: Nada
 ************************************************************************************************************************/

#include <nvic_config.h>
#include <nvic_interface.h>
#include <NVIC_private.h>
#include "types.h"
#include "macros.h"



void interrupt_enable (uint8 interrupt_number)
{
    if ( interrupt_number<=31)
    {
        Interrupt_0_31_Set_Enable=(1<<interrupt_number);
    }
    else if (interrupt_number>=32 && interrupt_number<=63)
    {
        interrupt_number-=32;
        Interrupt_32_63_Set_Enable=(1<<interrupt_number);
    }
    else if (interrupt_number>=64 && interrupt_number<=95)
    {
        interrupt_number-=64;
        Interrupt_64_95_Set_Enable=(1<<interrupt_number);
    }
    else if (interrupt_number>=96 && interrupt_number<=127)
    {   interrupt_number-=96;
    Interrupt_96_127_Set_Enable=(1<<interrupt_number);
    }
    else if (interrupt_number>=128 && interrupt_number<=138)
    {
        interrupt_number-=128;
        Interrupt_128_138_Set_Enable=(1<<interrupt_number);
    }
    else
  {
    /* do no thing */
  }
}


void interrupt_disable (uint8 interrupt_number)
{
    if ( interrupt_number<=31)
    {
        Interrupt_0_31_Set_Enable=(1<<interrupt_number);
    }
    else if (interrupt_number>=32 && interrupt_number<=63)
    {
        interrupt_number-=32;
        Interrupt_32_63_clear_Enable=(1<<interrupt_number);
    }
    else if (interrupt_number>=64 && interrupt_number<=95)
    {
        interrupt_number-=64;
        Interrupt_64_95_clear_Enable=(1<<interrupt_number);
    }
    else if (interrupt_number>=96 && interrupt_number<=127)
    {   interrupt_number-=96;
    Interrupt_96_127_clear_Enable=(1<<interrupt_number);
    }
    else if (interrupt_number>=128 && interrupt_number<=138)
    {
        interrupt_number-=128;
        Interrupt_128_138_clear_Enable=(1<<interrupt_number);
    }
    else
  {
    /* do no thing */
  }
}





void set_pending (uint8 interrupt_number)
{
    if ( interrupt_number<=31)
    {
        Interrupt_0_31_Set_pending=(1<<interrupt_number);
    }
    else if (interrupt_number>=32 && interrupt_number<=63)
    {
        interrupt_number-=32;
        Interrupt_32_63_Set_pending=(1<<interrupt_number);
    }
    else if (interrupt_number>=64 && interrupt_number<=95)
    {
        interrupt_number-=64;
        Interrupt_64_95_Set_pending=(1<<interrupt_number);
    }
    else if (interrupt_number>=96 && interrupt_number<=127)
    {   interrupt_number-=96;
    Interrupt_96_127_Set_pending=(1<<interrupt_number);
    }
    else if (interrupt_number>=128 && interrupt_number<=138)
    {
        interrupt_number-=128;
        Interrupt_128_138_Set_pending=(1<<interrupt_number);
    }
    else
  {
    /* do no thing */
  }
}




void clear_pending (uint8 interrupt_number)
{
    if ( interrupt_number<=31)
    {
        Interrupt_0_31_clear_pending=(1<<interrupt_number);
    }
    else if (interrupt_number>=32 && interrupt_number<=63)
    {
        interrupt_number-=32;
        Interrupt_32_63_clear_pending=(1<<interrupt_number);
    }
    else if (interrupt_number>=64 && interrupt_number<=95)
    {
        interrupt_number-=64;
        Interrupt_64_95_clear_pending=(1<<interrupt_number);
    }
    else if (interrupt_number>=96 && interrupt_number<=127)
    {   interrupt_number-=96;
    Interrupt_96_127_clear_pending=(1<<interrupt_number);
    }
    else if (interrupt_number>=128 && interrupt_number<=138)
    {
        interrupt_number-=128;
        Interrupt_128_138_clear_pending=(1<<interrupt_number);
    }
    else
  {
    /* do no thing */
  }
}

uint8 Git_active_flag (uint8 interrupt_number)
{
    uint8 result;
    if ( interrupt_number<=31)
    {
        result=GET_BIT(Interrupt_0_31_active_bit,interrupt_number);
    }
    else if (interrupt_number>=32 && interrupt_number<=63)
    {
        interrupt_number-=32;
        result=GET_BIT(Interrupt_32_63_active_bit,interrupt_number);
    }
    else if (interrupt_number>=64 && interrupt_number<=95)
    {
        interrupt_number-=64;
        result=GET_BIT(Interrupt_64_95_active_bit,interrupt_number);
    }
    else if (interrupt_number>=96 && interrupt_number<=127)
    {   interrupt_number-=96;
        result=GET_BIT(Interrupt_96_127_active_bit,interrupt_number);
    }
    else if (interrupt_number>=128 && interrupt_number<=138)
    {
        interrupt_number-=128;
        result=GET_BIT(Interrupt_128_138_active_bit,interrupt_number);

    }
    else
  {
    /* do no thing */
  }
    return result;
}


uint8 Set_priority (sint8 interrupt_number , uint8 group_priority ,uint8 sub_group_priority , uint32 group)
{
    uint8 priority = sub_group_priority|(group_priority<<((group-0X05FA0400)/0x100));
   /* check external peripheral*/

    if(interrupt_number>=0)
    {
        NVIC_PRIORITY[interrupt_number]=priority<<5;
    }
    APINT_SCB=group;
}


void Trigger_Interrupt ( uint8 interrupt_number )
{

    NVIC_TRIGGER = interrupt_number ;

    return ;
}
