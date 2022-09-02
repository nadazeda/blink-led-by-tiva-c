/***********************************************************************************************
 * private.h
 *
 *  Created on: Jul 14, 2022
 *      Author: Nada
 **************************************************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_




#define Interrupt_0_31_Set_Enable          *(( volatile uint32* )( 0xE000E100 ))
#define Interrupt_32_63_Set_Enable         *(( volatile uint32* )( 0xE000E104 ))
#define Interrupt_64_95_Set_Enable         *(( volatile uint32* )( 0xE000E108 ))
#define Interrupt_96_127_Set_Enable        *(( volatile uint32* )( 0xE000E10C ))
#define Interrupt_128_138_Set_Enable       *(( volatile uint32* )( 0xE000E110 ))

#define Interrupt_0_31_clear_Enable          *(( volatile uint32* )( 0xE000E180 ))
#define Interrupt_32_63_clear_Enable         *(( volatile uint32* )( 0xE000E184 ))
#define Interrupt_64_95_clear_Enable         *(( volatile uint32* )( 0xE000E188 ))
#define Interrupt_96_127_clear_Enable        *(( volatile uint32* )( 0xE000E18C ))
#define Interrupt_128_138_clear_Enable       *(( volatile uint32* )( 0xE000E190 ))


#define Interrupt_0_31_Set_pending          *(( volatile uint32* )( 0xE000E200 ))
#define Interrupt_32_63_Set_pending         *(( volatile uint32* )( 0xE000E204 ))
#define Interrupt_64_95_Set_pending         *(( volatile uint32* )( 0xE000E208 ))
#define Interrupt_96_127_Set_pending        *(( volatile uint32* )( 0xE000E20C ))
#define Interrupt_128_138_Set_pending       *(( volatile uint32* )( 0xE000E210 ))



#define Interrupt_0_31_clear_pending          *(( volatile uint32* )( 0xE000E280 ))
#define Interrupt_32_63_clear_pending         *(( volatile uint32* )( 0xE000E284 ))
#define Interrupt_64_95_clear_pending         *(( volatile uint32* )( 0xE000E288 ))
#define Interrupt_96_127_clear_pending        *(( volatile uint32* )( 0xE000E28C ))
#define Interrupt_128_138_clear_pending       *(( volatile uint32* )( 0xE000E290 ))


#define Interrupt_0_31_active_bit             *(( volatile uint32* )( 0xE000E300 ))
#define Interrupt_32_63_active_bit            *(( volatile uint32* )( 0xE000E304 ))
#define Interrupt_64_95_active_bit            *(( volatile uint32* )( 0xE000E308 ))
#define Interrupt_96_127_active_bit           *(( volatile uint32* )( 0xE000E30C ))
#define Interrupt_128_138_active_bit          *(( volatile uint32* )( 0xE000E310 ))

#define NVIC_PRIORITY                          (( volatile uint8* )( 0xE000E400 ))
#define APINT_SCB                             *(( volatile uint32* )( 0xE000ED0C ))

#define NVIC_TRIGGER                          *(( volatile uint32* )( 0xE000EF00 ))




#endif /* NVIC_PRIVATE_H_ */
