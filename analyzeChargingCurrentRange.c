#include <stdio.h>
#include <stdlib.h>
#include "analyzeChargingCurrentRange.h"
#include "analyzeChargingCurrentRangeForADC.h"

#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

void getChargingCurrentRangeAndSamples(int* samplesOfChargingCurrent, int numSamples, char* rangeAndOccurences[]){
 	RangeStructure rangeStructureArray[3];
	//Validate the input charging samples
	if(negativeNumberInArray(samplesOfChargingCurrent, numSamples)){
		//Sort the input array
	        int* sortedSamplesOfChargingCurrent = sortChargingSamples(samplesOfChargingCurrent, numSamples);		
		buildRanges(sortedSamplesOfChargingCurrent, numSamples, rangeStructureArray);
	        size_t sizeOfRangeStructureArray = (sizeof(rangeStructureArray) / sizeof(rangeStructureArray[0]));
		printf("Size of the range array: ");
		printf("%zu", sizeOfRangeStructureArray);
                // Allocate memory to character array
		for (int i=0; i < (int)sizeOfRangeStructureArray; i++) {
		rangeAndOccurences[i] = (char*)malloc(10);
	        }
		printOutputinCsv(sizeOfRangeStructureArray, rangeStructureArray, rangeAndOccurences);
	}else{
		printf("The charging samples are not valid");
	}
	printf("Execution complete !!! \n");
}

void printOutputinCsv(size_t sizeOfRangeStructureArray, RangeStructure rangeStructureArray[], char* rangeAndOccurences[]){
   for(int i =0; i<(int)sizeOfRangeStructureArray; i++){
	sprintf(rangeAndOccurences[i], "%d-%d, %d", rangeStructureArray[i].LowerLimit, rangeStructureArray[i].UpperLimit, rangeStructureArray[i].Occurences);
	printf("Range, Readings \n");
	printf("%s\n", rangeAndOccurences[i]);
	}
    printf("Printing in csv output successful \n");
}

void buildRanges(int sortedSamplesOfChargingCurrent[], int numSamples, RangeStructure rangeStructureArray[20]) { 
    printf("The sorted samples inside build Range are: ");
    for(int k = 0; k< numSamples; k++){
    printf("%d", sortedSamplesOfChargingCurrent[k]);
    }
    printf("Number of samples inside build Range: ");
    printf("%d\n", numSamples);
    int rangeStart = sortedSamplesOfChargingCurrent[0];
    int lastValue = sortedSamplesOfChargingCurrent[0];
    int occurences = 0;
    int rangeStructureArrayIndex = 0;
    for (int i = 1; i < numSamples; i++) {
	occurences++;
        int value = sortedSamplesOfChargingCurrent[i];
        if (value != lastValue + 1) {	 
            // When it enters this condition, the range has ended
	    rangeStructureArray[rangeStructureArrayIndex].LowerLimit = rangeStart;  
	    rangeStructureArray[rangeStructureArrayIndex].UpperLimit = lastValue;
	    rangeStructureArray[rangeStructureArrayIndex].Occurences = occurences;
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

void getChargingCurrentRangeAndSamplesFromADC(int *ADC_currentValues, int numSamples, char* rangeAndOccurences[]){
	 int chargingCurrentSamples[numSamples];
         int valid_ADC_currentValues[numSamples];
	 size_t numValidSamples; 

	validateAndGetChargingCurrentRangeAndSamplesForADC(ADC_currentValues, chargingCurrentSamples, valid_ADC_currentValues, numSamples, &numValidSamples);
	getChargingCurrentRangeAndSamples(chargingCurrentSamples, (int)numValidSamples, rangeAndOccurences);
}
