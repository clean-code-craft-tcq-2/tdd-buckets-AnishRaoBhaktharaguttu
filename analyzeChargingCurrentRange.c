#include <stdio.h>
#include <stdlib.h>
#include "validateAndSortRange.h"
#include "analyzeChargingCurrentRange.h"

char* getChargingCurrentRangeAndSamples(int samplesOfChargingCurrent[]){
	struct RangeStructure rangeStructureArray[20];
	size_t numSamples = 0;

	//Validate the input charging samples
	if(negativeNumberInArray(samplesOfChargingCurrent)){
		//Deduce the size of the samples
		numSamples = sizeof(samplesOfChargingCurrent) / sizeof(samplesOfChargingCurrent[0]);
		printf("The size of the input array is %d\n", numSamples);
                
		//Sort the input array
	         int sortedSamplesOfChargingCurrent[numSamples] = sortChargingSamples(int* samplesOfChargingCurrent, int numSamples);
		for (int n=0; n<numSamples; n++)
			printf("%d\n", sortedSamplesOfChargingCurrent);
	}
	return chargingCurrentRangeAndSamples;
}

