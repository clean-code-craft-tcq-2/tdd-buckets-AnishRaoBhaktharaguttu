#include <stdio.h>
#include <stdlib.h>
#include "analyzeChargingCurrentRange.h"

char* getChargingCurrentRangeAndSamples(int samplesOfChargingCurrent[]){
	int lowerRangeLimit = 0, upperRangeLimit = 0, numSamples = 0;
	char *chargingCurrentRangeAndSamples = (char*)malloc(100);
	//Deduce the size of the samples
	numSamples = sizeof(samplesOfChargingCurrent) / sizeof(samplesOfChargingCurrent[0]);
	lowerRangeLimit = getTheLowerLimitOfTheRange(samplesOfChargingCurrent, numSamples);
	upperRangeLimit = getTheUpperLimitOfTheRange(samplesOfChargingCurrent, numSamples);	        
	sprintf(chargingCurrentRangeAndSamples, "%d-%d, %d", lowerRangeLimit, upperRangeLimit, numSamples);
	printf("%s\n", chargingCurrentRangeAndSamples);
	return chargingCurrentRangeAndSamples;
}

int getTheLowerLimitOfTheRange(int* samplesOfChargingCurrent, int numSamples){
	int lowerRangeLimit = samplesOfChargingCurrent[0];
	for (int i = 0; i < numSamples; i++) {
		if(samplesOfChargingCurrent[i] < lowerRangeLimit){
			lowerRangeLimit = samplesOfChargingCurrent[i];
		}
	}
	return lowerRangeLimit;
}

int getTheUpperLimitOfTheRange(int* samplesOfChargingCurrent, int numSamples){
	int upperRangeLimit = samplesOfChargingCurrent[0];
	for (int i = 0; i < numSamples; i++) {
		if(samplesOfChargingCurrent[i] > upperRangeLimit){
			upperRangeLimit = samplesOfChargingCurrent[i];
		}
	}
	return upperRangeLimit;
}
