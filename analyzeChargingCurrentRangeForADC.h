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

void interpretChargingCurrentValue(int ADC_currentValues[], size_t numSamples, int* chargingCurrentValues);
float convertADCValueIntoCurrentValue(float conversionFactor, float scalingFactor, int minCurrentValue, int maxCurrentValue);
void checkIfInputADCValuesAreValid(int* ADC_currentValues, size_t numSamples, int *valid_ADC_currentValues);
extern void validateAndGetChargingCurrentRangeAndSamplesForADC(int* ADC_currentValues, int *chargingCurrentSamples, int* valid_ADC_currentValues, size_t numSamples);
