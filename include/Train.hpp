#define Train_H

using namespace std;

class Train
{
public:
  Train(string name);

  string GetName();
  bool IsMoving();

private:
  string name;
  bool isMoving = false;
};
