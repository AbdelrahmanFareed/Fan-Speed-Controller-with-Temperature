/*
 * LM_35_sensor.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Eng AFS
 */


#include "LM_35_sensor.h"
#include "adc.h"

#define ADC_REF_VOLT_VALUE   2.56

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;
	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	//millivolt = (((uint32)adc_value*2560UL)/(ADC_MAXIMUM_VALUE));
	//temp_value;
	return temp_value;
}
