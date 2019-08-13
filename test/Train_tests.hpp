#define Train_tests_H

#include "../src/Train.cpp"

using namespace std;

TEST_CASE( "Train is instantiated with passed name", "[Train]" )
{
  string expectedName("SWR044");
  Train train(expectedName);
  REQUIRE( train.GetName() == expectedName );
}

TEST_CASE( "Train has moving bool which is initialised as false", "[Train]" )
{
  bool expectedMotionState(false);
  Train train("Filler for now, should be instantiated at top!");
  REQUIRE( train.IsMoving() == expectedMotionState ); // This can surely be improved, like an auto false asserter
}
