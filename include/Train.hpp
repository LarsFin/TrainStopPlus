#define Train_H

using namespace std;

class Train
{
public:
  Train(string name);

  string GetName();

private:
  string name;
};
