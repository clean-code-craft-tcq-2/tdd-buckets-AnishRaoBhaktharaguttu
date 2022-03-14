#include <stdio.h>
#include <stdlib.h>
#include "analyzeChargingCurrentRange.h"
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

char* getChargingCurrentRangeAndSamples(int* samplesOfChargingCurrent, int numSamples){
	printf("Entered the input printing section\n");
	for(int i =0; i<7; i++){
		printf("%d ", samplesOfChargingCurrent[i]);		
	}
	char *rangeAndOccurences = (char*)malloc(100);
 	RangeStructure *rangeStructureArray = (RangeStructure*)malloc(sizeof(RangeStructure) * 20);

	//Deduce the size of the samples

	printf("The size of the input array is %d\n", (int)numSamples);
	
	//Validate the input charging samples
	if(negativeNumberInArray(samplesOfChargingCurrent, numSamples)){
		//Sort the input array
	        int* sortedSamplesOfChargingCurrent = sortChargingSamples(samplesOfChargingCurrent, numSamples);
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
    
	printf("Entered the build range input printing section\n");
	for(int i =0; i<7; i++){
		printf("%d ", sortedSamplesOfChargingCurrent[i]);		
	}
	
    int rangeStart = sortedSamplesOfChargingCurrent[0];
    int lastValue = sortedSamplesOfChargingCurrent[0];
    int occurences = 1;
    for (int i = 1; i < numSamples; i++) {
        int value = sortedSamplesOfChargingCurrent[i];
        if (value != lastValue + 1) {
	    printf("Value when entering end of range is %d ", value); 
	    printf("Condition ended\n");
            // When it enters this condition, the range has ended
	    rangeStructureArray[i].LowerLimit = rangeStart;
	    printf("Start of range: %d\n ", rangeStart); 
	    rangeStructureArray[i].UpperLimit = lastValue;
            printf("End of range: %d\n ", lastValue); 
	    rangeStructureArray[i].Occurences = occurences;
	    printf("Occurences: %d\n ", occurences); 
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
    char *rangeAndOccurences = (char*)malloc(100);
    for(int i =0; i<2; i++){
	printf("Entered the range printing section");
	sprintf(rangeAndOccurences, "%d-%d, %d", rangeStructureArray[i].LowerLimit, rangeStructureArray[i].UpperLimit, rangeStructureArray[i].Occurences);
	printf("%s\n", rangeAndOccurences);
	}	
	
    return rangeStructureArray;
}
