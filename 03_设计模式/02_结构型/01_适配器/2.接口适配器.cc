#include <iostream>

using namespace std;

class Interface {
public:
  virtual void output5VDC() = 0;
  virtual void output12VAC() = 0;
  virtual void output220VAC() = 0;
};

class Adapter : public Interface {
public:
  void output5VDC() {}
  void output12VAC() {}
  void output220VAC() {}
};

class DC5V : public Adapter {
public:
  void output5VDC() { cout << "5V DC" << endl; }
};

int main() {
  DC5V dc5v;
  dc5v.output5VDC();
  return 0;
}