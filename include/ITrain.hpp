#define ITrain_H

using namespace std;

class ITrain
{
public:
  ITrain() {};
  virtual ~ITrain() {};

  // Getter signatures
  virtual string GetName() = 0;
  virtual bool IsMoving() = 0;

  // Setter signatures
  virtual void SetIsMoving(bool moving) = 0;
};
