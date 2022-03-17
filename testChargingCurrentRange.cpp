#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "analyzeChargingCurrentRange.h"

TEST_CASE("Checks the range of the charging current and the number of samples within the range") {
	int samplesOfChargingCurrent[] = {1,3,5,2,7,9,4};
	char* rangeAndOccurences[3];
	const char* expectedRangeAndSamples = "1-5, 5, 7-7, 1, 9-9, 1";
	getChargingCurrentRangeAndSamples(samplesOfChargingCurrent, 7, rangeAndOccurences);
// 	printf("Range, Readings \n");
// 	for(int i =0; i<3; i++){
// 	printf("%s\n", rangeAndOccurences[i]);
// 	}
	REQUIRE(strcmp(rangeAndOccurences[0], "1-5, 5") == 0);
	REQUIRE(strcmp(rangeAndOccurences[1], "7-7, 1") == 0);
	REQUIRE(strcmp(rangeAndOccurences[2], "9-9, 1") == 0);
}
