/*
 * app.c
 *
 *  Created on: Jul 18, 2022
 *      Author: Nada
 */




#include "app.h"




CommonError_t init_Pin(gpioinit_t *obj)
{
    CommonError_t state = PASSED;
    /**< Enable GPIO Clock*/
    if(obj->base == BASE_A){
        clock_Gating_set(GPIOA);
    }
    else if(obj->base == BASE_B)
    {
        clock_Gating_set(GPIOB);
    }
    else if(obj->base == BASE_C)
    {
        clock_Gating_set(GPIOC);
    }
    else if(obj->base == BASE_D)
    {
        clock_Gating_set(GPIOD);
    }
    else if(obj->base == BASE_E)
    {
        clock_Gating_set(GPIOE);
    }
    else if(obj->base == BASE_F)
    {
        clock_Gating_set(GPIOF);
    }
    port_UnLock(obj->base,TRUE);
    pin_Commit(obj->base,obj->pin_num,TRUE);
    state = Dio_set_Pin_Direction(obj->base,obj->pin_num,obj->dir);
    if(state == PASSED)
    {
    Pin_Alternate_Function_Select (obj->base,obj->pin_num,&(obj->configPadObj));
    Pin_Set_Configration(obj->base,obj->pin_num,&(obj->configPadObj));
    }

    return state;
}

CommonError_t init_port(gpioinit_t *obj)
{
    CommonError_t state = PASSED;

    if(obj->base == BASE_A)
    {
        clock_Gating_set(GPIOA);
    }
    else if(obj->base == BASE_B)
    {
        clock_Gating_set(GPIOB);
    }
    else if(obj->base == BASE_C)
    {
        clock_Gating_set(GPIOC);
    }
    else if(obj->base == BASE_D)
    {
        clock_Gating_set(GPIOD);
    }
    else if(obj->base == BASE_E)
    {
        clock_Gating_set(GPIOE);
    }
    else if(obj->base == BASE_F)
    {
        clock_Gating_set(GPIOF);
    }
    port_UnLock (obj->base,TRUE);
    Port_Commit (obj->base,TRUE);
    state = Dio_set_Port_Direction(obj->base,obj->dir);
    if(state == PASSED)
    {
    Port_Alternate_Function_Select (obj->base,&(obj->configPadObj));
    Port_Set_Configration(obj->base,&(obj->configPadObj));
    }

    return state;
}

