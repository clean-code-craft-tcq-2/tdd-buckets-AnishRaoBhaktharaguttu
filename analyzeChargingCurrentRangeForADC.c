#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ADC_RESOLUTION 12
#define MIN_CURRENT_VALUE 0
#define MAX_CURRENT_VALUE 10

//Define the Parameter Operating Structure
typedef struct {
  int minCurrentValue;
  int maxCurrentValue;
  int maxPossibleInteger;
  int currentRange;
  float scaleFactor;
} ADC_OperatingStructure;

float convertADCValueIntoCurrentValue(float conversionFactor, ADC_OperatingStructure adc_OperatingStructure){
	float currentValue;	
	currentValue = MIN_CURRENT_VALUE  + (MAX_CURRENT_VALUE * conversionFactor * adc_OperatingStructure.scaleFactor);
	return currentValue;
}

void checkIfInputADCValuesAreValid(int* ADC_currentValues, int numSamples, int *valid_ADC_currentValues, size_t* numberOfValidSamples) {
	int errorValue;
	size_t i=0;
	
	errorValue = pow(2, ADC_RESOLUTION) - 1;
	
	for(int j = 0; j < numSamples; j++){
		if(ADC_currentValues[i] != errorValue){
			valid_ADC_currentValues[j] = ADC_currentValues[i];
			j++;
		}
	}
	*numberOfValidSamples = i;	
}

//Sets up the structure for the ADC with all necessary operating values
ADC_OperatingStructure setupParameterOperatingStructure(){
       ADC_OperatingStructure adc_OperatingStructure;
       adc_OperatingStructure.minCurrentValue = MIN_CURRENT_VALUE;
       adc_OperatingStructure.maxCurrentValue = MAX_CURRENT_VALUE;
       adc_OperatingStructure.maxPossibleInteger = pow(2,ADC_RESOLUTION) - 2;
       adc_OperatingStructure.currentRange = MAX_CURRENT_VALUE - MIN_CURRENT_VALUE;
       adc_OperatingStructure.scaleFactor = float(adc_OperatingStructure.currentRange) / float(MAX_CURRENT_VALUE);
       return adc_OperatingStructure;
}

void getChargingCurrentRangeAndSamplesForADC(int* ADC_currentValues, size_t numSamples, int* chargingCurrentSamples) {
	float currentValue;
    ADC_OperatingStructure adc_OperatingStructure = setupParameterOperatingStructure();
  	for (size_t i=0; i<numSamples; i++){
      float conversionFactor = float(ADC_currentValues[i]) / float(adc_OperatingStructure.maxPossibleInteger);
      currentValue = convertADCValueIntoCurrentValue(conversionFactor, adc_OperatingStructure);
      chargingCurrentSamples[i] =  abs(round(currentValue));
    }
}



void validateAndGetChargingCurrentRangeAndSamplesForADC(int* ADC_currentValues, int *chargingCurrentSamples, int* valid_ADC_currentValues, int numSamples, size_t *numberOfValidSamples){
	checkIfInputADCValuesAreValid(ADC_currentValues, numSamples, valid_ADC_currentValues, numberOfValidSamples);
	getChargingCurrentRangeAndSamplesForADC(valid_ADC_currentValues, numSamples, chargingCurrentSamples);	
}
