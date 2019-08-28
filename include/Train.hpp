#define Train_H

#include "ITrain.hpp"

using namespace std;

class Train : public ITrain
{
public:
  Train(string name);
  ~Train() {};

  // Getter signatures
  string GetName();
  bool IsMoving();

  // Setter signatures
  void SetIsMoving(bool moving);

private:
  string name;
  bool isMoving = false;
};
