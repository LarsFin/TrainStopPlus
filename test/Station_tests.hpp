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
  list<ITrain*>* expectedTypePtr = new list<ITrain*>;
  REQUIRE( typeid(stationPtr->GetTrainPtrs()) == typeid(expectedTypePtr) );
  delete expectedTypePtr;
  DeallocateStationPtr(stationPtr);
}

TEST_CASE( "Station can receive train", "[ReceiveTrain]" )
{
  Station* stationPtr = BuildStation();

  Mock<ITrain> mock;
  When(Method(mock,IsMoving)).Return(true);
  Fake(Method(mock,SetIsMoving));
  ITrain* mockTrainPtr = &(mock.get());

  REQUIRE( stationPtr->GetTrainPtrs()->empty() ); // Station is empty
  stationPtr->ReceiveTrain(mockTrainPtr);
  REQUIRE( stationPtr->GetTrainPtrs()->size() == 1 ); // Station is not empty with 1 train
  REQUIRE( stationPtr->GetTrainPtrs()->front() == mockTrainPtr ); // Train in station is the one which was passed
  DeallocateStationPtr(stationPtr);
}

TEST_CASE( "Station cannot receive non moving train", "[ReceiveTrain]" )
{
  Station* stationPtr = BuildStation();

  Mock<ITrain> mock;
  When(Method(mock,IsMoving)).Return(false);
  ITrain* mockTrainPtr = &(mock.get());

  REQUIRE_THROWS_WITH( stationPtr->ReceiveTrain(mockTrainPtr), "Station cannot receive stationary train" );
  REQUIRE( stationPtr->GetTrainPtrs()->empty() );
  DeallocateStationPtr(stationPtr);
}

TEST_CASE( "Trains received by station should be stopped", "[ReceiveTrain]" )
{
  Station* stationPtr = BuildStation();

  Mock<ITrain> mock;
  When(Method(mock,IsMoving)).Return(true);
  Fake(Method(mock,SetIsMoving));
  ITrain* mockTrainPtr = &(mock.get());

  stationPtr->ReceiveTrain(mockTrainPtr);
  Verify(Method(mock,SetIsMoving).Using(false)).Once();
  DeallocateStationPtr(stationPtr);
}

TEST_CASE( "Trains can leave stations", "[ReleaseTrain]" )
{
  Station* stationPtr = BuildStation();
  string mockTrainName = "mock-train";

  Mock<ITrain> mock;
  When(Method(mock,IsMoving)).Return(true);
  Fake(Method(mock,SetIsMoving));
  ITrain* mockTrainPtr = &(mock.get());

  stationPtr->ReceiveTrain(mockTrainPtr);
  REQUIRE( stationPtr->GetTrainPtrs()->size() == 1 );

  When(Method(mock,IsMoving)).Return(false);
  When(Method(mock,GetName)).Return(mockTrainName);

  ITrain* releasedTrain = stationPtr->ReleaseTrain(mockTrainName);

  REQUIRE( stationPtr->GetTrainPtrs()->empty() );
  REQUIRE( releasedTrain == mockTrainPtr );

  DeallocateStationPtr(stationPtr);
}

TEST_CASE( "Cannot release trains which aren't at the station", "[ReleaseTrain]" )
{
  Station* stationPtr = BuildStation();
  string nonExistantTrainName = "non-existant-train";

  stringstream ss;
  ss << "The train " << nonExistantTrainName << " does not exist within the station";

  REQUIRE_THROWS_WITH( stationPtr->ReleaseTrain(nonExistantTrainName), ss.str() );

  DeallocateStationPtr(stationPtr);
}

TEST_CASE( "Trains which depart from Stations should begin their journey", "[ReleaseTrain]" )
{
  Station* stationPtr = BuildStation();
  string mockTrainName = "mock-train";

  Mock<ITrain> mock;
  When(Method(mock,IsMoving)).Return(true);
  Fake(Method(mock,SetIsMoving));
  ITrain* mockTrainPtr = &(mock.get());

  stationPtr->ReceiveTrain(mockTrainPtr);
  REQUIRE( stationPtr->GetTrainPtrs()->size() == 1 );

  When(Method(mock,IsMoving)).Return(false);
  When(Method(mock,GetName)).Return(mockTrainName);

  stationPtr->ReleaseTrain(mockTrainName);

  Verify(Method(mock,SetIsMoving).Using(true)).Once();

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
