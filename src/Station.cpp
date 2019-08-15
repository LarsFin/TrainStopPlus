#include "../include/Station.hpp"

// Station Constructor
Station::Station(string name)
{
  this->name = name;
}

// Getter for the name attribute
string Station::GetName()
{
  return name;
}

// Getter for the list of Train Pointers
list<Train*> Station::GetTrainPtrs()
{
  return trainPtrs;
}
