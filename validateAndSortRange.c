#include <stdlib.h> 
#include "validateAndSortRange.h"

// Function to validate if the charging samples are non empty non negative
int negativeNumberInArray(int *chargingSamples, int numSamples){
    if(numSamples > 0){
      for (int i = 0; i < numSamples; i++) {
          if (chargingSamples[i] < 0)
              return 0;
      }
      return 1;
    }
    return 0;
}

//Comparison function for the sorting algorithm
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

//Function to sort the given charging samples
int* sortChargingSamples(int* chargingSamples, numSamples){
     return qsort (chargingSamples, numSamples, sizeof(int), compare);
}
