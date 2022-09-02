/*
 * private.h
 *
 *  Created on: Jul 13, 2022
 *      Author: Nada
 */

#ifndef PRIVATE_H_
#define PRIVATE_H_

#define AHP

/** \brief Addresses of the high speed bus. */
#ifdef AHP
#define BASE_A 0x40058000
#define BASE_B 0x40059000
#define BASE_C 0x4005A000
#define BASE_D 0x4005B000
#define BASE_E 0x4005C000
#define BASE_F 0x4005D000
#endif

/** \brief Addresses of the APB bus. */
#ifndef AHP
#define BASE_A 0x40004000
#define BASE_B 0x40005000
#define BASE_C 0x40006000
#define BASE_D 0x40007000
#define BASE_E 0x40024000
#define BASE_F 0x40025000
#endif


#define GPIODATA       0x000     // GPIO Data
#define GPIODIR        0x400     // GPIO direction
#define GPIOIS         0x404     // GPIO Interrupt Sense
#define GPIOIBE        0x408     // GPIO Interrupt Both Edges
#define GPIOIEV        0x40C     // GPIO Interrupt Event
#define GPIOIM         0x410     // GPIO Interrupt Mask
#define GPIORIS        0x414     // GPIO Raw Interrupt Status
#define GPIOMIS        0x418     // GPIO Masked Interrupt Status
#define GPIOICR        0x41C     // GPIO Interrupt Clear
#define GPIOAFSEL      0x420     // GPIO Alternate Function Select
#define GPIODR2R       0x500     // GPIO 2-mA Drive Select
#define GPIODR4R       0x504     // GPIO 4-mA Drive Select
#define GPIODR8R       0x508     // GPIO 8-mA Drive Select
#define GPIOODR        0x50C     // GPIO Open Drain Select
#define GPIOPUR        0x510     // GPIO Pull-Up Select
#define GPIOPDR        0x514     // GPIO Pull-down Select
#define GPIOSLR        0x518     // GPIO Slew Rate Control Select
#define GPIODEN        0x51C     // GPIO Digital Enable
#define GPIOLOCK       0x520     // GPIO Lock
#define GPIOCR         0x524     // GPIO Commit
#define GPIOAMSEL      0x528     // GPIO Analog Mode Select
#define GPIOPCTL       0x52C     // GPIO Port Control
#define GPIOADCCTL     0x530     // GPIO ADC Control
#define GPIODMACTL     0x534     // GPIO DMA Control
#define GPIOPeriphID4         0xFD0
#define GPIOPeriphID5         0xFD4
#define GPIOPeriphID6         0xFD8
#define GPIOPeriphID7         0xFDC
#define GPIOPeriphID0         0xFE0
#define GPIOPeriphID1         0xFE4
#define GPIOPeriphID2         0xFE8
#define GPIOPeriphID3         0xFEC
#define GPIOPCellID0          0xFF0
#define GPIOPCellID1          0xFF4
#define GPIOPCellID2          0xFF8
#define GPIOPCellID3          0xFFC





#endif /* PRIVATE_H_ */
