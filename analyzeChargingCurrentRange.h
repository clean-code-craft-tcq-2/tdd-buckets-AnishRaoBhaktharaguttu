#include "validateAndSortRange.h"

void getChargingCurrentRangeAndSamples(int* samplesOfChargingCurrent, int numSamples, char* rangeAndOccurences[]);
void buildRanges(int* sortedSamplesOfChargingCurrent, int numSamples, RangeStructure* rangeStructureArray);
void printOutputinCsv(size_t sizeOfRangeStructureArray, RangeStructure rangeStructureArray[], char* rangeAndOccurences[]);
