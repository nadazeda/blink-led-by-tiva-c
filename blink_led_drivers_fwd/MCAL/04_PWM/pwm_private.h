/*
 * private.h
 *
 *  Created on: Jul 18, 2022
 *      Author: Nada
 */

#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_

//* Gating Control Register*/
#define  RCGCPWM        (*((volatile uint32 *)0x400FE640))

/* The following are defines for the bit fields in the RCGCPWM register.*/
#define  RCGCPWM1               0x00000002                    // PWM Module 1 Run Mode Clock
#define  RCGCPWM0               0x00000001                            // PWM Module 0 Run Mode Clock


/*System control RCC register*/
#define RCC            (*((volatile uint32 *)0x400FE060))


/*The following are defines for the bit fields in the RCC register for PWM configuration.*/
#define RCC_USEPWMDIV           0x00100000                     // Enable PWM Clock Divisor
#define RCC_PWMDIV_M            0x000E0000                     // PWM Unit Clock Divisor

/* General-Purpose Input/Output Run Mode Clock Gating Control*/
#define RCGCGPIO       (*((volatile uint32 *)0x400FE608))

// The following are defines for the bit fields in the RCGCGPIO register.

#define RCGCGPIO_5      0x00000020                          // GPIO Port F Run Mode Clock
#define RCGCGPIO_4      0x00000010                          // GPIO Port E Run Mode Clock
#define RCGCGPIO_3      0x00000008                         // GPIO Port D Run Mode Clock
#define RCGCGPIO_2      0x00000004                        // GPIO Port C Run Mode Clock
#define RCGCGPIO_1      0x00000002                       // GPIO Port B Run Mode Clock
#define RCGCGPIO_0      0x00000001                      // GPIO Port A Run Mode Clock

/* Mode Control register GPIO Alternate Function Select Port E*/
#define GPIO_PORTE_AFSEL      (*((volatile uint32 *)0x40024420))
#define GPIO_PORTE_AMSEL      (*((volatile uint32 *)0x40024528))
/* Pad Control Register GPIO  Digital Enable port E       */
#define GPIO_PORTE_DEN        (*((volatile uint32 *)0x4002451C))
/*Port Control Register GPIO Port E                    */
#define GPIO_PORTE_PCTL       (*((volatile uint32 *)0x4002452C))

/* The following are defines for the bit fields in the GPIO_PCTL register for port E.*/
#define GPIO_PCTL_PE4_M         0x000F0000              // PE4 Mask
#define GPIO_PCTL_PE4_M0PWM4    0x00040000              // M0PWM4 on PE4


/* Mode Control register GPIO Alternate Function Select Port B*/
#define GPIO_PORTB_AFSEL      (*((volatile uint32 *)0x40005420))
/*Pad Control Register GPIO  Digital Enable port B  */
#define GPIO_PORTB_AMSEL     (*((volatile uint32 *)0x40005528))
/* Pad Control Register GPIO  Digital Enable port B       */
#define GPIO_PORTB_DEN        (*((volatile uint32 *)0x4000551C))
/*Port Control Register GPIO Port E                    */
#define GPIO_PORTB_PCTL       (*((volatile uint32 *)0x4000552C))

/*The following are defines for the bit fields in the GPIO_PCTL register for port B.*/
#define GPIO_PCTL_PB4_M         0x000F0000              // PB4 Mask
#define GPIO_PCTL_PB4_M0PWM2    0x00040000              // M0PWM2 on PB4
#define GPIO_PCTL_PB6_M         0x0F000000  // PB6 Mask
#define GPIO_PCTL_PB6_M0PWM0    0x04000000  // M0PWM0 on PB6

/* Mode Control register GPIO Alternate Function Select Port C*/
#define GPIO_PORTC_AFSEL            (*((volatile uint32 *)0x40006420))
/*Pad Control Register GPIO  Digital Enable port C  */
#define GPIO_PORTC_AMSEL            (*((volatile uint32 *)0x40006528))
/* Pad Control Register GPIO  Digital Enable port C       */
#define GPIO_PORTC_DEN              (*((volatile uint32 *)0x4000651C))
/*Port Control Register GPIO Port C                    */
#define GPIO_PORTC_PCTL            (*((volatile uint32 *)0x4000652C))

/*The following are defines for the bit fields in the GPIO_PCTL register for port C.*/
#define GPIO_PCTL_PC4_M         0x000F0000              // PC4 Mask
#define GPIO_PCTL_PC4_M0PWM6    0x00040000              // M0PWM6 on PC4


/* Mode Control register GPIO Alternate Function Select Port D*/
#define GPIO_PORTD_AFSEL         (*((volatile uint32 *)0x40007420))
/*Pad Control Register GPIO  Digital Enable port D  */
#define GPIO_PORTD_AMSEL         (*((volatile uint32 *)0x40007528))
/* Pad Control Register GPIO  Digital Enable port D       */
#define GPIO_PORTD_DEN          (*((volatile uint32 *)0x4000751C))
/*Port Control Register GPIO Port C                    */
#define GPIO_PORTD_PCTL         (*((volatile uint32 *)0x4000752C))

/*The following are defines for the bit fields in the GPIO_PCTL register for port D.*/
#define GPIO_PCTL_PD0_M         0x0000000F              // PD0 Mask
#define GPIO_PCTL_PD0_M1PWM0    0x00000005              // M1PWM0 on PD0

/* Mode Control register GPIO Alternate Function Select Port A*/
#define GPIO_PORTA_AFSEL          (*((volatile uint32 *)0x40004420))
/*Pad Control Register GPIO  Digital Enable port A  */
#define GPIO_PORTA_AMSEL          (*((volatile uint32 *)0x40004528))
/*Pad Control Register GPIO  Digital Enable port A  */
#define GPIO_PORTA_DEN          (*((volatile uint32 *)0x4000451C))
/*Port Control Register GPIO Port A                    */
#define GPIO_PORTA_PCTL        (*((volatile uint32 *)0x4000452C))

/*The following are defines for the bit fields in the GPIO_PCTL register for port A.*/
#define GPIO_PCTL_PA6_M         0x0F000000              // PA6 Mask
#define GPIO_PCTL_PA6_M1PWM2    0x05000000              // M1PWM2 on PA6

/* Mode Control register GPIO Alternate Function Select Port F*/
#define GPIO_PORTF_AFSEL          (*((volatile uint32 *)0x40025420))
/*Pad Control Register GPIO  Digital Enable port F  */
#define GPIO_PORTF_AMSEL          (*((volatile uint32 *)0x40025528))
/* Pad Control Register GPIO  Digital Enable port F       */
#define GPIO_PORTF_DEN             (*((volatile uint32 *)0x4002551C))
/*Port Control Register GPIO Port F                    */
#define GPIO_PORTF_PCTL            (*((volatile uint32 *)0x4002552C))

/*The following are defines for the bit fields in the GPIO_PCTL register for port F.*/
#define GPIO_PCTL_PF0_M         0x0000000F  // PF0 Mask
#define GPIO_PCTL_PF0_M1PWM4    0x00000005  // M1PWM4 on PF0
#define GPIO_PCTL_PF2_M         0x00000F00  // PF2 Mask
#define GPIO_PCTL_PF2_M1PWM6    0x00000500  // M1PWM6 on PF2


#define PWM0_0_CTL            (*((volatile uint32 *)0x40028040))
#define PWM0_0_GENA           (*((volatile uint32 *)0x40028060))
#define PWM0_1_CTL            (*((volatile uint32 *)0x40028080))
#define PWM0_1_GENA           (*((volatile uint32 *)0x400280A0))
#define PWM0_2_CTL            (*((volatile uint32 *)0x400280C0))
#define PWM0_2_GENA           (*((volatile uint32 *)0x400280E0))
#define PWM0_3_CTL            (*((volatile uint32 *)0x40028100))
#define PWM0_3_GENA           (*((volatile uint32 *)0x40028120))



#define PWM1_1_CTL            (*((volatile uint32 *)0x40029080))
#define PWM1_1_GENA           (*((volatile uint32 *)0x400290A0))
#define PWM0_ENABLE           (*((volatile uint32 *)0x40028008))
#define PWM1_ENABLE           (*((volatile uint32 *)0x40029008))



/*The following are defines for the bit fields in the PWM_O_0_CTL register.*/
#define PWM_0_CTL_ENABLE        0x00000001  // PWM Block Enable
#define PWM_1_CTL_ENABLE        0x00000001  // PWM Block Enable

/*The following are defines for the bit fields in the PWM_O_ENABLE register.*/
#define PWM_ENABLE_PWM0EN       0x00000001  // MnPWM0 Output Enable
#define PWM_ENABLE_PWM2EN       0x00000004  // MnPWM2 Output Enable
#define PWM_ENABLE_PWM4EN       0x00000010  // MnPWM4 Output Enable
#define PWM_ENABLE_PWM6EN       0x00000040  // MnPWM6 Output Enable


/*The following are defines for the bit fields in the PWM_O_0_GENA register.*/
#define PWM_0_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_1_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down

#define PWM_0_GENA_ACTLOAD_ZERO 0x00000008  // Drive pwmA Low
#define PWM_1_GENA_ACTLOAD_ZERO 0x00000008  // Drive pwmA Low

/*The following are defines for the bit fields in the PWM_O_1_GENA register.*/
#define PWM_1_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_1_GENA_ACTLOAD_ZERO 0x00000008  // Drive pwmA Low



#define PWM0_0_LOAD          (*((volatile uint32 *)0x40028050))
#define PWM0_0_CMPA           (*((volatile uint32 *)0x40028058))
#define PWM0_1_LOAD           (*((volatile uint32 *)0x40028090))
#define PWM0_1_CMPA           (*((volatile uint32 *)0x40028098))
#define PWM0_2_LOAD           (*((volatile uint32 *)0x400280D0))
#define PWM0_2_CMPA           (*((volatile uint32 *)0x400280D8))
#define PWM0_3_LOAD           (*((volatile uint32 *)0x40028110))
#define PWM0_3_CMPA           (*((volatile uint32 *)0x40028118))
#define PWM1_3_CTL            (*((volatile uint32 *)0x40029100))
#define PWM1_3_GENA           (*((volatile uint32 *)0x40029120))
#define PWM1_0_CTL            (*((volatile uint32 *)0x40029040))
#define PWM1_0_GENA           (*((volatile uint32 *)0x40029060))
#define PWM1_2_CTL            (*((volatile uint32 *)0x400290C0))
#define PWM1_2_GENA           (*((volatile uint32 *)0x400290E0))
#define PWM1_0_LOAD           (*((volatile uint32 *)0x40029050))
#define PWM1_0_CMPA           (*((volatile uint32 *)0x40029058))
#define PWM1_1_LOAD           (*((volatile uint32 *)0x40029090))
#define PWM1_1_CMPA           (*((volatile uint32 *)0x40029098))
#define PWM1_2_LOAD           (*((volatile uint32 *)0x400290D0))
#define PWM1_2_CMPA           (*((volatile uint32 *)0x400290D8))
#define PWM1_3_LOAD           (*((volatile uint32 *)0x40029110))
#define PWM1_3_CMPA           (*((volatile uint32 *)0x40029118))


#endif /* PWM_PRIVATE_H_ */
