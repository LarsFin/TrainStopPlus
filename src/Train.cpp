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

// Getter for state of motion of Train
bool Train::IsMoving()
{
  return isMoving;
}

// Setter for state of motion of Train
void Train::SetIsMoving(bool state)
{

}
