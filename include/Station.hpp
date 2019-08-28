#define Station_H

#include <exception>
#include "IStation.hpp"

using namespace std;

class Station : public IStation
{
public:
  Station(string name);
  ~Station();

  // Getter signatures
  string GetName();
  list<ITrain*>* GetTrainPtrs();

  // Receive train
  void ReceiveTrain(ITrain* train);

private:
  string name;
  list<ITrain*>* trainPtrs;
};
