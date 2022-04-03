#include "validateAndSortRange.h"

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

void getChargingCurrentRangeAndSamples(int* samplesOfChargingCurrent, int numSamples, char* rangeAndOccurences[]);
void buildRanges(int* sortedSamplesOfChargingCurrent, int numSamples, RangeStructure* rangeStructureArray);
void printOutputinCsv(size_t sizeOfRangeStructureArray, RangeStructure rangeStructureArray[], char* rangeAndOccurences[]);
void getChargingCurrentRangeAndSamplesFromADC(int *ADC_currentValues, size_t numSamples, char* rangeAndOccurences[]);
