#include <stdio.h>
#include <stdlib.h>
#include "analyzeChargingCurrentRange.h"
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

void getChargingCurrentRangeAndSamples(int* samplesOfChargingCurrent, int numSamples, char* rangeAndOccurences[]){
	printf("Entered the input printing section\n");
	for(int i =0; i<numSamples; i++){
		printf("%d ", samplesOfChargingCurrent[i]);		
	}
 	RangeStructure rangeStructureArray[3];
	
	//Validate the input charging samples
	if(negativeNumberInArray(samplesOfChargingCurrent, numSamples)){
		//Sort the input array
	        int* sortedSamplesOfChargingCurrent = sortChargingSamples(samplesOfChargingCurrent, numSamples);		
		buildRanges(sortedSamplesOfChargingCurrent, numSamples, rangeStructureArray);
	        size_t sizeOfRangeStructureArray = (sizeof(rangeStructureArray) / sizeof(rangeStructureArray[0]));
                // Allocate memory to character array
		for (int i=0; i < (int)sizeOfRangeStructureArray; i++) {
		rangeAndOccurences[i] = (char*)malloc(10);
	        }
		printOutputinCsv(sizeOfRangeStructureArray, rangeStructureArray[], rangeAndOccurences[]);
	}
}

void printOutputinCsv(size_t sizeOfRangeStructureArray, RangeStructure rangeStructureArray[], char* rangeAndOccurences[]){
   for(int i =0; i<(int)sizeOfRangeStructureArray; i++){
	sprintf(rangeAndOccurences[i], "%d-%d, %d", rangeStructureArray[i].LowerLimit, rangeStructureArray[i].UpperLimit, rangeStructureArray[i].Occurences);
	printf("Range, Readings \n");
	printf("%s\n", rangeAndOccurences[i]);
	}
}

void buildRanges(int sortedSamplesOfChargingCurrent[], int numSamples, RangeStructure rangeStructureArray[20]) {
	
    int rangeStart = sortedSamplesOfChargingCurrent[0];
    int lastValue = sortedSamplesOfChargingCurrent[0];
    int occurences = 0;
    int rangeStructureArrayIndex = 0;
    for (int i = 1; i < numSamples; i++) {
	occurences++;
        int value = sortedSamplesOfChargingCurrent[i];
        if (value != lastValue + 1) {
	    printf("\nCondition ended\n");
	    printf("Value when entering end of range is %d\n ", value); 
            // When it enters this condition, the range has ended
	    rangeStructureArray[rangeStructureArrayIndex].LowerLimit = rangeStart;
	    printf("Start of range: %d\n ", rangeStart); 
	    rangeStructureArray[rangeStructureArrayIndex].UpperLimit = lastValue;
            printf("End of range: %d\n ", lastValue); 
	    rangeStructureArray[rangeStructureArrayIndex].Occurences = occurences;
	    printf("Occurences: %d\n ", occurences);
	    rangeStart = value;
	    occurences = 0;
	    if(i==numSamples-1){
	       // Conclude last range
		occurences++;    
    		rangeStructureArray[rangeStructureArrayIndex+1].LowerLimit = rangeStart;
    		rangeStructureArray[rangeStructureArrayIndex+1].UpperLimit = value;
    		rangeStructureArray[rangeStructureArrayIndex+1].Occurences = occurences;
	    }
	    rangeStructureArrayIndex++;
        }
	lastValue = value;
    } 
}
