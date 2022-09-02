/*******************************************************************************************************************************
 * dio.h
 *
 *  Created on: Jul 13, 2022
 *      Author: Nada
 *********************************************************************************************************************************/

#ifndef DIO_H_
#define DIO_H_


#include "private.h"
#include "types.h"
#include "macros.h"
#include "config.h"



/* Value unlock port to enable the Commit register.*/
#define UNLOCK     0x4C4F434B
/* Value to lock port to disable the Commit register*/
#define LOCK        0xFFFFFFFF


#define MAX_NUM_OF_PORTS           6
#define MAX_NUM_OF_PINS_PER_PORT   8
#define GPIODATA_MASK         0x3FC


#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7




CommonError_t Dio_ReadPort(uint32 base , uint8 *data);
CommonError_t Dio_WritePort(uint32 base , uint8 val);
CommonError_t Dio_set_Port_Direction(uint32 base , uint8 dirVal);
CommonError_t Dio_set_Pin_Direction(uint32 base , uint8 pin , uint8 dir);
CommonError_t Dio_ReadChannel(uint32 base , uint8 pin , uint8 *data);
CommonError_t Dio_WriteChannel(uint32 base , uint8 pin , uint8 dir);
CommonError_t Dio_FlipChannel(uint32 base , uint8 pin);
CommonError_t Dio_ReadChannelGroup(uint32 base , uint16 mask , uint8 *data);
CommonError_t Dio_WriteChannelGroup(uint32 base , uint8 val, uint8 mask);

CommonError_t Pin_Alternate_Function_Select(uint32 base , uint8 pin , gpioConfig_t *value);
CommonError_t Port_Alternate_Function_Select(uint32 base , gpioConfig_t *value);
CommonError_t Pin_Set_Configration(uint32 base , uint8 pin,gpioConfig_t *value);
CommonError_t Port_Set_Configration(uint32 base, gpioConfig_t *value);
CommonError_t port_UnLock(uint32 base , uint8 value);
CommonError_t port_Commit(uint32 base , uint8 value);
CommonError_t pin_Commit(uint32 base , uint8 pin , uint8 value);

CommonError_t Pin_Interrupt_Config (uint32 base,uint8 pin, InterruptSenseTypes_t obj);
CommonError_t Pin_Interrupt_UnMask(uint32 base , uint8 pin , uint8 val);
CommonError_t Pin_Interrupt_Clear(uint32 base , uint8 pin);
CommonError_t Get_Raw_Interrupt_Status(uint32 base , uint8 *status);
CommonError_t Get_Masked_Interrupt_Status(uint32 base , uint8 *status);




#endif /* DIO_H_ */
