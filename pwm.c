#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FREQ 120000 //in Hz  Max freq of 19.2Mhz
#define DUTY 50 // 0-100

int main (void)
{
	if (wiringPiSetupGpio() == -1)
		exit (1) ;

	printf ("Setting pin 12 to %dHz at %d%% duty cycle \n",FREQ, DUTY) ;
	
	pwmSetMode(PWM_MODE_MS); //set pwm mode to mark-space. PWM_MODE_BAL does really weird things
	pinMode(18,PWM_OUTPUT);
	pwmSetClock(19200000/(2*FREQ));
	pwmSetRange (100) ;
	pwmWrite (18, DUTY); // 18 corresponds to physical pin 12
	delay (1000);
}
