#include <stdio.h>
#include <stdlib.h>
#include "analyzeChargingCurrentRange.h"

char* getChargingCurrentRangeAndSamples(int samplesOfChargingCurrent[]){
	int lowerRangeLimit = 0, upperRangeLimit = 0, numSamples = 0;
	char *chargingCurrentRangeAndSamples = (char*)malloc(100);
	sprintf(chargingCurrentRangeAndSamples, "%d-%d, %d, lowerRangeLimit, upperRangeLimit, numSamples);
	return chargingCurrentRangeAndSamples;
}
