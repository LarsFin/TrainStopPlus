#define Station_H

using namespace std;

class IStation
{
public:
  IStation() {};
  virtual ~IStation() {};

  // Getter signatures
  virtual string GetName() = 0;
  virtual list<ITrain*>* GetTrainPtrs() = 0;

  // Receive train
  virtual void ReceiveTrain(ITrain* train) = 0;
};
