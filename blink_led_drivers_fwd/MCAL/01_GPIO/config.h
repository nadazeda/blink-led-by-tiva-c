/*
 * config.h
 *
 *  Created on: Jul 18, 2022
 *      Author: Nada
 */

#ifndef CONFIG_H_
#define CONFIG_H_




/* Enumerate of the common types of errors in the gpio */
typedef enum {
    PASSED , INVALID_PORT , INVALID_PIN_NUM , DIRECTION_ERROR ,
    INVALID_MASK , INCORRECT_VALUE , INCORRECT_INTERRUPT
}CommonError_t;





/* Enumerate of the Resistance types in the gpio */
typedef enum
{
    NO_INT_RES,
    PULLUP_RES,
    PULLDOWN_RES

}ResTypes_t;

/* Enumerate of the current types in the gpio */
typedef enum{
     CURRENT_2MA,
     CURRENT_4MA,
     CURRENT_8MA
}CurrentTypes_t;


/* Enumerate of the interrupt signal types in the gpio */
typedef enum
{
    FALING_EDGE,
    RAISNG_EDGE,
    BOTH_EDGES,
    LOW_LEVEL,
    HIGH_LEVEL
} InterruptSenseTypes_t;


/* Enumerate of the open drain in the gpio */

typedef enum
{
    OPEN_DRAIN_DISABLE,
    OPEN_DRAIN_ENABLE

}OpenDrain_t;


/* Enumerate of the Alternate function  */

typedef enum
{
    ALTERNATE_FUNCTION_DISABLE,
    ALTERNATE_FUNCTION_ENABLE

}AlternalteFunction_t;


typedef enum
{
    DIGITAL_DISABLE = 0,
    ANALOG_DISABLE  = 0,
    DIGITAL_ENABLE ,
    ANALOG_ENABLE=1,
}gpiomode_t;


typedef struct
{
    ResTypes_t restype;
    CurrentTypes_t  CurrentType;
    OpenDrain_t    opendrain;
    AlternalteFunction_t  altrenate_function;
    gpiomode_t mode;

}gpioConfig_t;




#endif /* CONFIG_H_ */
