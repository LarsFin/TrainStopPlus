#define Station_tests_H

#include "../src/Station.cpp"

#include "iostream"

using namespace std;
using namespace fakeit;

// Overload station builds for name set and not
Station* BuildStation();
Station* BuildStation(string name);

// Deallocate heap pointer
void DeallocateStationPtr(Station* stationPtr);


//############################################################################//
// Station Tests
//############################################################################//

TEST_CASE( "Station is instantiated with passed name", "[Station]" )
{
  string expectedName("Waterloo");
  Station* stationPtr = BuildStation(expectedName);
  REQUIRE( stationPtr->GetName() == expectedName );
  DeallocateStationPtr(stationPtr);
}

TEST_CASE( "Station is instantiated with list of train pointers", "[GetTrainPtrs]" )
{
  Station* stationPtr = BuildStation();
  list<Train*>* expectedTypePtr = new list<Train*>;
  REQUIRE( typeid(stationPtr->GetTrainPtrs()) == typeid(expectedTypePtr) );
  delete expectedTypePtr;
  DeallocateStationPtr(stationPtr);
}

TEST_CASE( "Station can receive train", "[ReceiveTrain]" )
{
  Station* stationPtr = BuildStation();

  Mock<Train> mock;
  When(Method(mock,IsMoving)).Return(true);
  Train* mockTrainPtr = &(mock.get());

  REQUIRE( stationPtr->GetTrainPtrs()->empty() ); // Station is empty
  stationPtr->ReceiveTrain(mockTrainPtr);
  REQUIRE( stationPtr->GetTrainPtrs()->size() == 1 ); // Station is not empty with 1 train
  REQUIRE( stationPtr->GetTrainPtrs()->front() == mockTrainPtr ); // Train in station is the one which was passed
  DeallocateStationPtr(stationPtr);
}

TEST_CASE( "Station cannot receive non moving train", "[ReceiveTrain]" )
{
  Station* stationPtr = BuildStation();

  Mock<Train> mock;
  When(Method(mock,IsMoving)).Return(false);
  Train* mockTrainPtr = &(mock.get());

  REQUIRE_THROWS_WITH( stationPtr->ReceiveTrain(mockTrainPtr), "Station cannot receive stationary train" );
  REQUIRE( stationPtr->GetTrainPtrs()->empty() );
  DeallocateStationPtr(stationPtr);
}

//############################################################################//


// Using name "default"
Station* BuildStation()
{
  Station* stationPtr = new Station("default");
  return stationPtr;
}

// Using passed name
Station* BuildStation(string name)
{
  Station* stationPtr = new Station(name);
  return stationPtr;
}

// Deallocate Station pointer
void DeallocateStationPtr(Station* stationPtr)
{
  delete stationPtr;
  stationPtr = nullptr;
}
