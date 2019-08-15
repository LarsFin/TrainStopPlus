#define Train_H

using namespace std;

class Train
{
public:
  Train(string name);

  // Getter signatures
  string GetName();
  bool IsMoving();

  // Setter signatures
  void SetIsMoving(bool moving);

private:
  string name;
  bool isMoving = false;
};
