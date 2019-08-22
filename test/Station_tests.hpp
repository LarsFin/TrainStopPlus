#define Station_tests_H

#include "../src/Station.cpp"

using namespace std;
using namespace fakeit;

// Overload station builds for name set and not
Station* BuildStation();
Station* BuildStation(string name);

// Methods for building faked trains
Train* BuildFakeMovingTrain();

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
  Train& mockTrain = mock.get();
  Train* mockTrainPtr = &mockTrain;
  REQUIRE( stationPtr->GetTrainPtrs()->empty() ); // Station is empty
  stationPtr->ReceiveTrain(mockTrainPtr);
  REQUIRE( stationPtr->GetTrainPtrs()->size() == 1 ); // Station is not empty with 1 train
  REQUIRE( stationPtr->GetTrainPtrs()->front() == mockTrainPtr ); // Train in station is the one which was passed
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

// Returns a faked train
Train* BuildFakeMovingTrain()
{
  return new Train("~");
}

// Deallocate Station pointer
void DeallocateStationPtr(Station* stationPtr)
{
  delete stationPtr;
  stationPtr = nullptr;
}
