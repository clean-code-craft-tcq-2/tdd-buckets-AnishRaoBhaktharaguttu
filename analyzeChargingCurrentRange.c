#include <stdio.h>
#include <stdlib.h>
#include "validateAndSortRange.h"
#include "analyzeChargingCurrentRange.h"

char* getChargingCurrentRangeAndSamples(int samplesOfChargingCurrent[]){
	char *rangeAndOccurences = (char*)malloc(100);
 	struct RangeStructure *rangeStructureArray = malloc(sizeof(struct RangeStructure) * 20);
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
		
		struct RangeStructure* rangeStructureArray = buildRanges(sortedSamplesOfChargingCurrent, numSamples);
		
		sizeOfRangeStructureArray = sizeof(rangeStructureArray) / sizeof(rangeStructureArray[0]);
		for(int i =0; i<sizeOfRangeStructureArray; i++){
		sprintf(rangeAndOccurences, "%d-%d, %lu", rangeStructureArray[i].LowerLimit, rangeStructureArray[i].UpperLimit, rangeStructureArray[i].Occurences);
		printf("Range, Readings \n");
		printf("%s\n", rangeAndOccurences);
		}
	
	}
	return rangeAndOccurences;
}

struct RangeStructure* buildRanges(int sortedSamplesOfChargingCurrent[], int numSamples) {
    struct RangeStructure *rangeStructureArray = malloc(sizeof(struct RangeStructure) * 20);
    
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
