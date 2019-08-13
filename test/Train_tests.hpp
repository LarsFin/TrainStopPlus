#define Train_tests_H

#include "../src/Train.cpp"

using namespace std;

TEST_CASE( "Train is instantiated with passed name", "[Train]" )
{
  string expectedName("SWR044");
  Train train(expectedName);
  REQUIRE( train.GetName() == expectedName );
}
