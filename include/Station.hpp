#define Station_H

#include <exception>

using namespace std;

class Station
{
public:
  Station(string name);
  ~Station();

  // Getter signatures
  string GetName();
  list<Train*>* GetTrainPtrs(); // Should probably be a pointer to a list

  // Receive train
  void ReceiveTrain(Train* train);

private:
  string name;
  list<Train*>* trainPtrs;
};
