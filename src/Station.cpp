#include "../include/Station.hpp"

// Station Constructor
Station::Station(string name)
{
  this->name = name;
  trainPtrs = new list<ITrain*>;
}

// Station Destructor
Station::~Station()
{
  for (ITrain* t : *trainPtrs)
  {
    delete t;
  }
  delete trainPtrs;
}

// Getter for the name attribute
string Station::GetName()
{
  return name;
}

// Getter for the list of Train Pointers
list<ITrain*>* Station::GetTrainPtrs()
{
  return trainPtrs;
}

// Adds the passed train to 'trains' list of the station
void Station::ReceiveTrain(ITrain* train)
{
  if (train->IsMoving())
  {
    trainPtrs->push_back(train);
    train->SetIsMoving(false);
  }
  else
  {
    throw "Station cannot receive stationary train";
  }
}

// Receiving a string name as an argument, it determines the train to release
ITrain* Station::ReleaseTrain(string name)
{
  return new Train("place-holder");
}
