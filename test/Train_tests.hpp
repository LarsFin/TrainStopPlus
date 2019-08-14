#define Train_tests_H

#include "../src/Train.cpp"

using namespace std;

// Allocate heap memory to local Train Object
Train* BuildTrain();
Train* BuildTrain(string name);

// Deallocate heap memory to avoid memory leaks
void DeallocateTrainPtr(Train* tPtr);

TEST_CASE( "Train is instantiated with passed name", "[Train]" )
{
  string expectedName("SWR042");
  Train* trainPtr = BuildTrain(expectedName);
  REQUIRE( trainPtr->GetName() == expectedName );
  DeallocateTrainPtr(trainPtr);
}

TEST_CASE( "Train has moving bool which is initialised as false", "[Train]" )
{
  Train* trainPtr = BuildTrain();
  REQUIRE_FALSE( trainPtr->IsMoving() );
  DeallocateTrainPtr(trainPtr);
}

// Allocate heap memory to local Train Object
Train* BuildTrain()
{
  Train* trainPtr = new Train("default");
  return trainPtr;
}

// Allocate heap memory to local Train Object with passed string for name
Train* BuildTrain(string name)
{
  Train* trainPtr = new Train(name);
  return trainPtr;
}

// Deallocate heap memory
void DeallocateTrainPtr(Train* tPtr)
{
  delete tPtr;
  tPtr = nullptr;
}
