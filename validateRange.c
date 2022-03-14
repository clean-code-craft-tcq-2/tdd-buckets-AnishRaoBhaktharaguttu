#include "validateRange.h"

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
