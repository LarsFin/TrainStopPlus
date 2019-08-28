#define Train_H

using namespace std;

class Train
{
public:
  Train(string name);
  virtual ~Train() {}; // Made virtual for mocking

  // Getter signatures
  string GetName();
  virtual bool IsMoving();

  // Setter signatures
  void SetIsMoving(bool moving);

private:
  string name;
  bool isMoving = false;
};
