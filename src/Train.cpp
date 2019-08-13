#include "../include/Train.hpp"

// Train Constructor
Train::Train(string name)
{
  this->name = name;
}

// Getter for name of Train
string Train::GetName()
{
  return name;
}
