#include <stdio.h>
#include <stdlib.h>
#include "analyzeChargingCurrentRange.h"
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

char* getChargingCurrentRangeAndSamples(int* samplesOfChargingCurrent){
	printf("Entered the input printing section\n");
	for(int i =0; i<6; i++){
		printf("%d ", samplesOfChargingCurrent[i]);		
	}
	char *rangeAndOccurences = (char*)malloc(100);
 	RangeStructure *rangeStructureArray = (RangeStructure*)malloc(sizeof(RangeStructure) * 20);
	size_t numSamples = 0;

	//Deduce the size of the samples
	numSamples = SIZEOF(samplesOfChargingCurrent);
	printf("The size of the input array is %ld\n", numSamples);
	
	//Validate the input charging samples
	if(negativeNumberInArray(samplesOfChargingCurrent, (int)numSamples)){
		//Sort the input array
	        int* sortedSamplesOfChargingCurrent = sortChargingSamples(samplesOfChargingCurrent, (int)numSamples);
		printf("The sorted array elements are\n");
		for (int n=0; n<numSamples; n++)
			printf("%d ", sortedSamplesOfChargingCurrent[n]);
		
		RangeStructure* rangeStructureArray = buildRanges(sortedSamplesOfChargingCurrent, numSamples);
		
		size_t sizeOfRangeStructureArray = (sizeof(rangeStructureArray) / sizeof(rangeStructureArray[0]));
		printf("The size of the range structure array is %ld\n", sizeOfRangeStructureArray);
		for(int i =0; i<(int)sizeOfRangeStructureArray; i++){
			printf("Entered the range printing section");
			sprintf(rangeAndOccurences, "%d-%d, %d", rangeStructureArray[i].LowerLimit, rangeStructureArray[i].UpperLimit, rangeStructureArray[i].Occurences);
			printf("Range, Readings \n");
			printf("%s\n", rangeAndOccurences);
		}
	
	}
	return rangeAndOccurences;
}

RangeStructure *buildRanges(int sortedSamplesOfChargingCurrent[], int numSamples) {
    RangeStructure *rangeStructureArray = (RangeStructure*)malloc(sizeof(RangeStructure) * 20);
    
    int rangeStart = sortedSamplesOfChargingCurrent[0];
    int lastValue = sortedSamplesOfChargingCurrent[0];
    int occurences = 1;
    for (int i = 1; i < numSamples; i++) {
        int value = sortedSamplesOfChargingCurrent[i];
        if (value != lastValue + 1) {
            // When it enters this condition, the range has ended
	    rangeStructureArray[i].LowerLimit = rangeStart;
	    rangeStructureArray[i].UpperLimit = lastValue;
	    rangeStructureArray[i].Occurences = occurences;
	    rangeStart = value;
	    occurences = 1;
	    lastValue = value;
	    if(i==numSamples-1){
	       // Conclude last range
    		rangeStructureArray[i+1].LowerLimit = rangeStart;
    		rangeStructureArray[i+1].UpperLimit = lastValue;
    		rangeStructureArray[i+1].Occurences = occurences;  
	    }
        }
	occurences++;
    }
    return rangeStructureArray;
}
