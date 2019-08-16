#include "../include/Station.hpp"

// Station Constructor
Station::Station(string name)
{
  this->name = name;
  trainPtrs = new list<Train*>;
}

// Station Destructor
Station::~Station()
{
  for (Train* t : *trainPtrs)
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
list<Train*>* Station::GetTrainPtrs()
{
  return trainPtrs;
}

// Adds the passed train to 'trains' list of the station
void Station::ReceiveTrain(Train* train)
{
  trainPtrs->push_back(train);
}
