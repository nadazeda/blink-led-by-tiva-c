/***********************************************************************************************************************
 * macros.h
 *
 *  Created on: Jul 10, 2022
 *      Author: Nada mohamed
 ***************************************************************************************************************************/

#ifndef MACROS_H_
#define MACROS_H_

#include "types.h"




/*  Macro to set a value in a 32bit register  */


#define WRITE_REG(address ,value)                        *(volatile uint32*)(address) = value


/*  Macro to read a value in a 32bit register  */

#define READ_REG(address)                                 *(volatile uint32*)(address)



/*  Macro to set a bit in a 32bit register  */
#define SET_BIT(address,bit)                                        (HW_READ_REG_32BIT(address) |=(1<<bit))*/
#define SET_BIT_(reg, n)     (reg |= (1<<n))
#define RESET_BIT_(reg, n)     (reg &=  ~(1<<n))

 /*  Macro to set a bit in a 32bit register */
#define RESET_BIT(address,bit)                                       (HW_READ_REG_32BIT(address) &=~(1<<bit))
 /*  multi line Macro to write value of a bit in a 32bit register */
#define WRITE_BIT( address,pin,value)\
{\
    if(value == HIGH){\
        *(volatile uint32*)(address) |= (1<<pin);\
    }else if(value == LOW){\
        *(volatile uint32*)(address) &= ~(1<<pin);\
    }\
}
#define ASSIGN_BIT(reg,num,state)   reg =  (reg & ~(1 <<(num))) | (state<<(num))
/* Toggle a certain bit in a 32bit register */
#define TOGGLE_BIT (address,bit)                  (HW_READ_REG_32BIT(address) ^ = (1<<bit))


#define GET_BIT(address,bit) (((address) >> (bit)) & 0x01)





#endif /* MACROS_H_ */
