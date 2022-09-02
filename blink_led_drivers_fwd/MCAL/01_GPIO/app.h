/*
 * app.h
 *
 *  Created on: Jul 18, 2022
 *      Author: Nada
 */

#ifndef APP_H_
#define APP_H_


#include "dio.h"
#include"clk.h"


typedef struct
{

    uint32 base;
    uint8 pin_num;
    uint8 dir;

    gpioConfig_t configPadObj;

}gpioinit_t;

CommonError_t init_Pin(gpioinit_t *obj);
CommonError_t init_port(gpioinit_t *obj);




#endif /* APP_H_ */
