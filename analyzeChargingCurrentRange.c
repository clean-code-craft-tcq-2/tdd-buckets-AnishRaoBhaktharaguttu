#include <stdio.h>
#include <stdlib.h>
#include "analyzeChargingCurrentRange.h"

char* getChargingCurrentRangeAndSamples(int samplesOfChargingCurrent[]){
	int lowerRangeLimit = 0, upperRangeLimit = 0;
	size_t numSamples = 0;
	char *chargingCurrentRangeAndSamples = (char*)malloc(50);
	//Deduce the size of the samples
	numSamples = sizeof(samplesOfChargingCurrent) / sizeof(samplesOfChargingCurrent[0]);
	printf("%d\n", numSamples);
	//Get the lower limit and upper limit of the range
	lowerRangeLimit = getTheLowerLimitOfTheRange(samplesOfChargingCurrent, numSamples);
	upperRangeLimit = getTheUpperLimitOfTheRange(samplesOfChargingCurrent, numSamples);	        
	sprintf(chargingCurrentRangeAndSamples, "%d-%d, %d", lowerRangeLimit, upperRangeLimit, numSamples);
	printf("%s\n", chargingCurrentRangeAndSamples);
	return chargingCurrentRangeAndSamples;
}

int getTheLowerLimitOfTheRange(int* samplesOfChargingCurrent, size_t numSamples){
	int lowerRangeLimit = samplesOfChargingCurrent[0];
	for (size_t i = 0; i < numSamples; i++) {
		if(samplesOfChargingCurrent[i] < lowerRangeLimit){
			lowerRangeLimit = samplesOfChargingCurrent[i];
		}
	}
	return lowerRangeLimit;
}

int getTheUpperLimitOfTheRange(int* samplesOfChargingCurrent, size_t numSamples){
	int upperRangeLimit = samplesOfChargingCurrent[0];
	for (size_t i = 0; i < numSamples; i++) {
		if(samplesOfChargingCurrent[i] > upperRangeLimit){
			upperRangeLimit = samplesOfChargingCurrent[i];
		}
	}
	return upperRangeLimit;
}
