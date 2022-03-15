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
 	RangeStructure rangeStructureArray[20];
	//RangeStructure *rangeStructureArray= (RangeStructure*)malloc(sizeof(RangeStructure) * 20);

	//Deduce the size of the samples

	printf("The size of the input array is %d\n", (int)numSamples);
	
	//Validate the input charging samples
	if(negativeNumberInArray(samplesOfChargingCurrent, numSamples)){
		//Sort the input array
	        int* sortedSamplesOfChargingCurrent = sortChargingSamples(samplesOfChargingCurrent, numSamples);
		printf("The sorted array elements are\n");
		for (int n=0; n<numSamples; n++)
			printf("%d ", sortedSamplesOfChargingCurrent[n]);
		
		buildRanges(sortedSamplesOfChargingCurrent, numSamples, rangeStructureArray);
		
		size_t sizeOfRangeStructureArray = (sizeof(rangeStructureArray) / sizeof(rangeStructureArray[0]));
		printf("The size of the range structure array is %lu\n", sizeOfRangeStructureArray);
		printf("****************************************************\n");
		printf("Entered the Main range printing section");
		for(int i =0; i<(int)sizeOfRangeStructureArray; i++){
			printf("Entered the range printing section");
			sprintf(rangeAndOccurences, "%d-%d, %d", rangeStructureArray[i].LowerLimit, rangeStructureArray[i].UpperLimit, rangeStructureArray[i].Occurences);
			printf("Range, Readings \n");
			printf("%s\n", rangeAndOccurences);
		}
	
	}
	return rangeAndOccurences;
}

void buildRanges(int sortedSamplesOfChargingCurrent[], int numSamples, RangeStructure rangeStructureArray[20]) {
    //RangeStructure *rangeStructureArray = (RangeStructure*)malloc(sizeof(RangeStructure) * 20);
    
	printf("Entered the build range input printing section\n");
	for(int i =0; i<7; i++){
		printf("%d ", sortedSamplesOfChargingCurrent[i]);		
	}
	
    int rangeStart = sortedSamplesOfChargingCurrent[0];
    int lastValue = sortedSamplesOfChargingCurrent[0];
    int occurences = 1;
    int rangeStructureArrayIndex = 0;
    for (int i = 1; i < numSamples; i++) {
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
	    occurences = 1;
	    if(i==numSamples-1){
	       // Conclude last range
    		rangeStructureArray[rangeStructureArrayIndex+1].LowerLimit = rangeStart;
    		rangeStructureArray[rangeStructureArrayIndex+1].UpperLimit = lastValue;
    		rangeStructureArray[rangeStructureArrayIndex+1].Occurences = occurences;  
	    }
	    rangeStructureArrayIndex++;
        }
	lastValue = value;
	occurences++;
    }
    char *rangeAndOccurences = (char*)malloc(20); 
    printf("****************************************************\n");
    printf("Entered the Build range printing section");
    for(int i =0; i<2; i++){
	
	sprintf(rangeAndOccurences, "%d-%d, %d", rangeStructureArray[i].LowerLimit, rangeStructureArray[i].UpperLimit, rangeStructureArray[i].Occurences);
	printf("%s\n", rangeAndOccurences);
	} 
    printf("****************************************************\n");
}
