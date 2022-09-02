/*
 * dio.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Nada
 */
#include "dio.h"
#include "macros.h"


CommonError_t Dio_set_Port_Direction(uint32 base , uint8 value)
{
    CommonError_t state = PASSED;
        if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
        {
            WRITE_REG(base+GPIODIR,value);
        }
        else
        {
            state = INVALID_PORT;
        }
        return state;
    }

CommonError_t Dio_WritePort(uint32 base , uint8 value)
{
    CommonError_t state = PASSED;
        if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
        {
            WRITE_REG(base+GPIODATA+GPIODATA_MASK,value);
        }
        else
        {
            state = INVALID_PORT;
        }
        return state;
    }


CommonError_t Dio_ReadPort(uint32 base , uint8 *data)
{
    CommonError_t state = PASSED;
        if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F){
            *data = READ_REG(base+GPIODATA+GPIODATA_MASK);
        }else {
            state = INVALID_PORT;
        }
        return state;
    }




CommonError_t Dio_set_Pin_Direction(uint32 base , uint8 pin , uint8 direction)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F){
        if(pin > MAX_NUM_OF_PINS_PER_PORT)
        {
            state = INVALID_PIN_NUM;
        }
        else
        {
            if(direction == INPUT)
            {
              WRITE_BIT(base+GPIODIR,pin,direction)
            }
            else if(direction == OUTPUT)
            {
              WRITE_BIT(base+GPIODIR,pin,direction)
            }else{
                state =DIRECTION_ERROR;
            }
        }
    }
    else
    {
        state = INVALID_PORT;
    }
    return state;
}



CommonError_t Dio_WriteChannel(uint32 base , uint8 pin , uint8 value)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
    {
        if(pin > MAX_NUM_OF_PINS_PER_PORT)
        {
            state = INVALID_PIN_NUM;
        }
        else
        {
            if(value == LOW)
            {
                WRITE_BIT(base+GPIODATA+GPIODATA_MASK,pin,value)
            }
            else if(value == HIGH)
            {

                WRITE_BIT(base+GPIODATA+GPIODATA_MASK,pin,value)
            }
            else
            {
                state =DIRECTION_ERROR;
            }
        }
    }
    else
    {
        state = INVALID_PORT;
    }
    return state;
}


CommonError_t Dio_ReadChannel(uint32 base , uint8 pin , uint8 *data)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
    {
        if(pin > MAX_NUM_OF_PINS_PER_PORT)
        {
            state = INVALID_PIN_NUM;
        }
        else
        {

               *data= READ_REG(base+GPIODATA+GPIODATA_MASK);

        }
    }
    else
    {
        state = INVALID_PORT;
    }
    return state;
}

CommonError_t Dio_WriteChannelGroup(uint32 base , uint8 value, uint8 mask)
{
    CommonError_t state = PASSED;
        if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
        {
            if( mask >= GPIODATA_MASK)
            {
                state = INVALID_MASK;
            }
            else
            {
                WRITE_REG(base+GPIODATA+(mask>>2),value);
            }
        }
        else
        {
            state = INVALID_PORT;
        }
        return state;
    }


CommonError_t Dio_ReadChannelGroup(uint32 base , uint16 mask , uint8 *data)
{
    CommonError_t state = PASSED;
        if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F){
            if(mask > GPIODATA_MASK)
            {
                state = INVALID_MASK;
            }
            else
            {
            *data = (READ_REG (base+ GPIODATA +(mask>>2)));
            }
        }
        else
        {
            state = INVALID_PORT;
        }
        return state;
    }





CommonError_t Pin_Alternate_Function_Select(uint32 base , uint8 pin , gpioConfig_t *value)
{
    CommonError_t state = PASSED;
        if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
        {
            if(pin > MAX_NUM_OF_PINS_PER_PORT)
            {
                state = INVALID_PIN_NUM;
            }
            else
            {
                if(value->altrenate_function == ALTERNATE_FUNCTION_DISABLE || value->altrenate_function == ALTERNATE_FUNCTION_ENABLE )
                {
                    WRITE_BIT(base+GPIOAFSEL,pin,value->altrenate_function)
                }
                else
                {
                    state = INCORRECT_VALUE;
                }
            }

        }else {
            state = INVALID_PORT;
        }
        return state;
    }

CommonError_t Port_Alternate_Function_Select(uint32 base , gpioConfig_t *value)
{
    CommonError_t state = PASSED;
        if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
        {

                if(value->altrenate_function == ALTERNATE_FUNCTION_DISABLE || value->altrenate_function == ALTERNATE_FUNCTION_ENABLE )
                {
                    WRITE_REG(base+GPIOAFSEL,value->altrenate_function);
                }
                else
                {
                    state = INCORRECT_VALUE;
                }
            }

        else
        {
            state = INVALID_PORT;
        }
        return state;
    }



CommonError_t Pin_Set_Configration(uint32 base , uint8 pin,gpioConfig_t *value)
{
    CommonError_t state = PASSED;
        if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
        {
            if(pin > MAX_NUM_OF_PINS_PER_PORT)
            {
                state = INVALID_PIN_NUM;
            }
            else
            {
                if(value->CurrentType == CURRENT_2MA)
                {
                    WRITE_BIT(base+GPIODR2R,pin,HIGH)
                }
                else if(value->CurrentType == CURRENT_4MA)
                {
                    WRITE_BIT(base+GPIODR4R,pin,HIGH)
                }
                else if(value->CurrentType  == CURRENT_8MA)
                {
                    WRITE_BIT(base+GPIODR8R,pin,HIGH)
                }
                if(value->restype == PULLUP_RES)
                {
                    WRITE_BIT(base+GPIOPUR,pin,HIGH)
                }
                else if(value->restype == PULLDOWN_RES)
                {
                    WRITE_BIT(base+GPIOPDR,pin,HIGH)
                }
                if(value->opendrain==OPEN_DRAIN_ENABLE )
                {
                    WRITE_BIT(base+GPIOODR,pin,HIGH)
                }
                else if(value->opendrain==OPEN_DRAIN_DISABLE )
                {
                    WRITE_BIT(base+GPIOODR,pin,HIGH)
                }
                if(value->mode == DIGITAL_ENABLE)
                {
                    WRITE_BIT(base+GPIODEN,pin,HIGH)
                }
                else if(value->mode == DIGITAL_DISABLE)
                {
                    WRITE_BIT(base+GPIODEN,pin,HIGH)
                }
                if(value->mode == ANALOG_ENABLE)
                {
                    WRITE_BIT(base+GPIOAMSEL,pin,HIGH)
                }
                else if(value->mode == ANALOG_DISABLE)
                {
                    WRITE_BIT(base+GPIOAMSEL,pin,HIGH)
                }


            }
        }
        else
        {
            state = INVALID_PORT;
        }
        return state;
    }


CommonError_t Port_Set_Configration(uint32 base, gpioConfig_t *value)
{
    CommonError_t state = PASSED;
        if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
        {


                if(value->CurrentType == CURRENT_2MA)
                {
                    WRITE_REG(base+GPIODR2R,HIGH);
                }
                else if(value->CurrentType == CURRENT_4MA)
                {
                    WRITE_REG(base+GPIODR4R,HIGH);
                }
                else if(value->CurrentType  == CURRENT_8MA)
                {
                    WRITE_REG(base+GPIODR8R,HIGH);
                }
                if(value->restype == PULLUP_RES)
                {
                    WRITE_REG(base+GPIOPUR,HIGH);
                }
                else if(value->restype == PULLDOWN_RES)
                {
                    WRITE_REG(base+GPIOPDR,HIGH);
                }
                if(value->opendrain==OPEN_DRAIN_ENABLE )
                {
                    WRITE_REG(base+GPIOODR,HIGH);
                }
                else if(value->opendrain==OPEN_DRAIN_DISABLE )
                {
                    WRITE_REG(base+GPIOODR,HIGH);
                }
                if(value->mode == DIGITAL_ENABLE)
                {
                    WRITE_REG(base+GPIODEN,HIGH);
                }
                else if(value->mode == DIGITAL_DISABLE)
                {
                    WRITE_REG(base+GPIODEN,HIGH);
                }
                if(value->mode == ANALOG_ENABLE)
                {
                    WRITE_REG(base+GPIOAMSEL,HIGH);
                }
                else if(value->mode == ANALOG_DISABLE)
                {
                    WRITE_REG(base+GPIOAMSEL,HIGH);
                }



        }
        else
        {
            state = INVALID_PORT;
        }
        return state;
    }
CommonError_t port_UnLock(uint32 base , uint8 value)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
    {
        if(value == TRUE)
        {
            WRITE_REG(base+GPIOLOCK,UNLOCK);
        }
        else if(value == FALSE)
        {
            WRITE_REG(base+GPIOLOCK,LOCK);
        }
        else
        {
            state = INCORRECT_VALUE;
        }
    }
    else
    {
        state = INVALID_PORT;
    }
    return state;
}



CommonError_t Port_Commit(uint32 base , uint8 value)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C|| base == BASE_D || base == BASE_E|| base == BASE_F)
    {
        WRITE_REG(base+GPIOCR,value);
    }
    else
    {
        state = INVALID_PORT;
    }
    return state;
}


CommonError_t pin_Commit(uint32 base , uint8 pin , uint8 value)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
    {
        if(pin > MAX_NUM_OF_PINS_PER_PORT)
        {
            state = INVALID_PIN_NUM;
        }
        else
        {
            if(value == TRUE || value == FALSE)
            {
                WRITE_BIT(base+GPIOCR,pin,value)
            }
            else
            {
                state = INCORRECT_VALUE;
            }
        }
    }
    else
    {
        state = INVALID_PORT;
    }
    return state;
}




CommonError_t Pin_Interrupt_Config (uint32 base,uint8 pin, InterruptSenseTypes_t obj)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F){
    if(pin >MAX_NUM_OF_PINS_PER_PORT)
    {
        state = INVALID_PIN_NUM;
    }
    else
    {
   WRITE_BIT(base+GPIOIM,pin,HIGH)
     if(obj == LOW_LEVEL || obj == HIGH_LEVEL ){
         /*Enable Level sensitive interrupt.*/
         WRITE_BIT(base+GPIOIS,pin,HIGH)
         if(obj == LOW_LEVEL)
         {
             WRITE_BIT(base+GPIOIEV,pin,LOW)
         }
         else if(obj  == HIGH_LEVEL)
         {
             WRITE_BIT(base+GPIOIEV,pin,HIGH)
         }
         else
         {
             state = INCORRECT_INTERRUPT;
         }
     }
     else if(obj  == FALING_EDGE || obj == RAISNG_EDGE ||obj == BOTH_EDGES){
         /*Enable edge sensitive interrupt.*/
         WRITE_BIT(base+GPIOIS,pin,LOW)
         if(obj  == BOTH_EDGES)
					 {
             /*Enable interrupts on both edges*/
             WRITE_BIT(base+GPIOIBE,pin,HIGH)
         }
         else if(obj == FALING_EDGE)
         {
             WRITE_BIT(base+GPIOIEV,pin,LOW)
         }
         else if(obj == RAISNG_EDGE)
         {
             WRITE_BIT(base+GPIOIEV,pin,HIGH)
         }
     }
     else
     {
         state = INCORRECT_INTERRUPT;
     }
    }
    }else{
        state = INVALID_PORT;
    }
    return state;
}

CommonError_t Pin_Interrupt_UnMask(uint32 base , uint8 pin , uint8 val)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
    {
    if(pin > MAX_NUM_OF_PINS_PER_PORT)
    {
        state = INVALID_PIN_NUM;
    }
    else
    {
        if(val == TRUE || val == FALSE)
        {
           WRITE_BIT(base+GPIOIM,pin,val)
        }
        else
        {
            state = INCORRECT_VALUE;
        }
    }
    }
    else
    {
        state = INVALID_PORT;
    }
    return state;
}

CommonError_t Pin_Interrupt_Clear(uint32 base , uint8 pin)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F)
    {
    if(pin > MAX_NUM_OF_PINS_PER_PORT)
    {
        state = INVALID_PIN_NUM;
    }
    else
    {
        WRITE_BIT(base+GPIOICR,pin,HIGH)
        }
    }
    else
    {
        state = INVALID_PORT;
    }
    return state;
}

CommonError_t Get_Raw_Interrupt_Status(uint32 base , uint8 *status)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F){
        *status = READ_REG (base+GPIORIS);

    }
    else
    {
        state = INVALID_PORT;
    }
    return state;
}

CommonError_t Get_Masked_Interrupt_Status(uint32 base , uint8 *status)
{
    CommonError_t state = PASSED;
    if(base == BASE_A || base == BASE_B|| base == BASE_C||base == BASE_D || base == BASE_E|| base == BASE_F){
        *status = READ_REG(base+GPIOMIS);

    }
    else
    {
        state = INVALID_PORT;
    }
    return state;
}

