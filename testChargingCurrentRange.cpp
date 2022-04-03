#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "analyzeChargingCurrentRange.h"

TEST_CASE("Checks the range of the charging current and the number of samples within the range") {
	int samplesOfChargingCurrent[] = {1,3,5,2,7,9,4};
	char* rangeAndOccurences[3];
	getChargingCurrentRangeAndSamples(samplesOfChargingCurrent, 7, rangeAndOccurences);
	REQUIRE(strcmp(rangeAndOccurences[0], "1-5, 5") == 0);
	REQUIRE(strcmp(rangeAndOccurences[1], "7-7, 1") == 0);
	REQUIRE(strcmp(rangeAndOccurences[2], "9-9, 1") == 0);
}

TEST_CASE("Checks invalid use case -  Negative values") {
	int samplesOfChargingCurrent[] = {1,3,-5,2,7,9,4};
	char* rangeAndOccurences[3];
	getChargingCurrentRangeAndSamples(samplesOfChargingCurrent, 7, rangeAndOccurences);
}

TEST_CASE("Checks invalid use case - No values") {
	int samplesOfChargingCurrent[] = {};
	char* rangeAndOccurences[3];
	getChargingCurrentRangeAndSamples(samplesOfChargingCurrent, 0, rangeAndOccurences);
}

TEST_CASE("Checks for the current values for given ADC (12 bit resolution) and the range") {
	int ADC_currentValues[] = {700, 400, 3096, 2056, 4095, 3200};
	char* rangeAndOccurences[5];
	// Expected Output
	//const char *expectedOutput[4] = {"1-2, 2", "5-5, 1", "8-8, 2"}
	getChargingCurrentRangeAndSamplesFromADC(ADC_currentValues, 6, rangeAndOccurences);
}
