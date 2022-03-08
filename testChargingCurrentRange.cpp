#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

TEST_CASE("Checks the range of the charging current and the number of samples within the range") {
	int samplesOfChargingCurrent[] = {4,5};
	const char* expectedRangeAndSamples = "4-5, 2";
	char* chargingCurrentRangeAndSamples = getChargingCurrentRangeAndSamples(samplesOfChargingCurrent);
	REQUIRE(strcmp(chargingCurrentRangeAndSamples, expectedRangeAndSamples) == 0);
}