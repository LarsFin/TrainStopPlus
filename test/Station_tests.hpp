#define Station_tests_H

#include "../src/Station.cpp"

using namespace std;

TEST_CASE( "Station is instantiated with passed name", "[Station]" )
{
  string expectedName("Waterloo");
  Station station(expectedName);
  REQUIRE( station.GetName() == expectedName );
}
