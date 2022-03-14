#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "analyzeChargingCurrentRange.h"

TEST_CASE("Checks the range of the charging current and the number of samples within the range") {
	int samplesOfChargingCurrent[] = {1,3,5,2,7,9,4};
	const char* expectedRangeAndSamples = "7-9, 2";
	char* chargingCurrentRangeAndSamples = getChargingCurrentRangeAndSamples(samplesOfChargingCurrent, 7);
	REQUIRE(strcmp(chargingCurrentRangeAndSamples, expectedRangeAndSamples) == 0);
}
