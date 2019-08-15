#define Station_H

using namespace std;

class Station
{
public:
  Station(string name);

  string GetName();
  list<Train*> GetTrainPtrs();

private:
  string name;
  list<Train*> trainPtrs;
};
