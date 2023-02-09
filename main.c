/*
 * main.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Eng AFS
 */
#include "adc.h"
#include "LCD.h"
#include "DC_Motor.h"
#include "LM_35_sensor.h"
#include "PWM.h"
#include <util/delay.h>

uint8 temp;
uint8 speed;

ADC_ConfigType ADC={
		ADC_V256,
		ADC_SCALER_8
};
int main(void)
{
	DcMotor_Init();
	DcMotor_Rotate(clockwise,128);
	PWM_Timer0_Init(128);
	LCD_init();
    ADC_init(&ADC);

    LCD_displayStringRowColumn(0,0,"Temp=");
    LCD_displayStringRowColumn(1,0,"Speed=");

	while(1)
	{
		/* getting temp */
		temp=LM35_getTemperature();

		if(temp<30)
		{
			DcMotor_Rotate(stop,0);
			LCD_displayStringRowColumn(1,0,"Fan is Off");
		}
		else if(temp >= 30)
		{
			DcMotor_Rotate(clockwise,64);
			LCD_displayStringRowColumn(1,0,"Fan is ON");
		}
		else if(temp >= 60)
		{
			DcMotor_Rotate(clockwise,128);
			LCD_displayStringRowColumn(1,0,"Fan is ON");
			LCD_displayStringRowColumn(1,10," ");

		}
		else if(temp >= 90)
		{
			DcMotor_Rotate(clockwise,192);
			LCD_displayStringRowColumn(1,0,"Fan is ON");
			LCD_displayStringRowColumn(1,10," ");

		}
		else
		{
			DcMotor_Rotate(clockwise,255);
			LCD_displayStringRowColumn(1,0,"Fan is ON");
			LCD_displayStringRowColumn(1,10," ");

		}
		LCD_moveCursor(0,5);
		LCD_intgerToString(temp);
		 _delay_ms(1000);
	}
}
