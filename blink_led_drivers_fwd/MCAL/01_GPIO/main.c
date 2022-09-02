

/**
 * main.c
 */

#include "types.h"
#include "app.h"
#include "config.h"
#include "nvic_interface.h"
#include "timer_interface.h"
#include "pwm_private.h"


#define F_CPU  16000000

void take_times (float32 on, float32 off); 
void init_pwm (float32 off_count);

float32 on_count=0 ;
float32 off_count=0.0 ;


int main(void)
{ 
	take_times(0.005,0.005);
	
	
	// gpio init
	gpioinit_t data = {BASE_F,PIN2_ID,OUTPUT,{PULLUP_RES,CURRENT_2MA,OPEN_DRAIN_DISABLE,ALTERNATE_FUNCTION_DISABLE,DIGITAL_ENABLE}};
	init_Pin(&data);
	Dio_WriteChannel(BASE_F,PIN2_ID,HIGH);
	
//nvic init
	interrupt_enable(153);
	set_pending(153);
	
//timer init
	SysTick_EnableTimer();
	SysTick_EnableInterrupt();
	SysTick_ClockSelect(1);  // system clock
	SysTick_Single_interval(off_count,0,init_pwm);
	SysTick_handler();
	

	
	return 0;
}

/* function which take the on and off period for blink and dim the led */
void take_times (float32 on, float32 off)
	{
		on_count=  on   *F_CPU;
		off_count=(off * 0.000001) / 0.0625;

	}

	
	
void init_pwm (float32 off_count)
{
/* Clock setting for PWM and GPIO PORT */
RCGCPWM|= 2;       /* Enable clock to PWM1 module */
RCGCGPIO |= RCGCGPIO_5; /* Enable system clock to PORTF */
RCC &= ~(1<< RCC_PWMDIV_M);   /* Enable System Clock Divisor function  */


 /* Setting of PF2 pin for M1PWM6 channel output pin */
GPIO_PORTF_AFSEL |= (1<<2);  /* PF2 sets a alternate function */
GPIO_PORTF_PCTL=0x00000500;  /* make pf2 pwm output pin*/
GPIO_PORTF_DEN |= (1<<2);    /* set pf2 as a digital pin */




/* PWM1 channel 6 setting */
PWM1_3_CTL = 0;     /* disable generator 3 counter */
/*PWM1_3_GENA & = (~(1<<1));  select down count mode of counter 3 */
PWM1_3_LOAD = off_count; /*set load value for 1KHZ (16MHZ/16000) */
PWM1_3_CMPA=off_count/2; /* SET DUTY CYLE TO 50% BY LOADING OF 16000 TO pwm1cmpa */
PWM1_3_GENA |=(1<<2) |(1<<3) |(1<<7); /* SET PWM  output when counter reloaded and clear when match */
PWM1_3_CTL |=(1<<0);    /* enable generator 3 counter */
PWM1_ENABLE |= (1<<6);  /* enable PWM1 channel 6 output */
}
