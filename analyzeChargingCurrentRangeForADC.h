void interpretChargingCurrentValue(int ADC_currentValues[], size_t numSamples, int* chargingCurrentValues);
float convertADCValueIntoCurrentValue(float conversionFactor, float scalingFactor, int minCurrentValue, int maxCurrentValue);
void checkIfInputADCValuesAreValid(int* ADC_currentValues, size_t numSamples, int *valid_ADC_currentValues);
extern void validateAndGetChargingCurrentRangeAndSamplesForADC(int* ADC_currentValues, int *chargingCurrentSamples, int* valid_ADC_currentValues, int numSamples, size_t *numValidSamples);
