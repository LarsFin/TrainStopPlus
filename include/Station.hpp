#define Station_H

using namespace std;

class Station
{
public:
  Station(string name);

  string GetName();

private:
  string name;
};
