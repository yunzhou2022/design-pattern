#include <iostream>
using namespace std;

class Brand {
public:
  virtual void open() = 0;
  virtual void close() = 0;
  virtual void work() = 0;
  // virtual ~Brand() = default;
};

class Computer {
public:
  Brand *brand = nullptr;
  Computer(Brand *brand) : brand(brand) {}
  virtual void open() { brand->open(); }
  virtual void close() { brand->close(); }
  virtual void work() { brand->work(); }
};

class Huawei : public Brand {
public:
  void open() { cout << "Huawei open" << endl; }
  void close() { cout << "Huawei  lose" << endl; }
  void work() { cout << "Huawei work" << endl; }
};

class Mi : public Brand {
public:
  void open() { cout << "MI open" << endl; }
  void close() { cout << "MI close" << endl; }
  void work() { cout << "MI work" << endl; }
};

class Pad : public Computer {
public:
  Pad(Brand *brand) : Computer(brand) {}
  void open() {
    brand->open();
    cout << "Pad open" << endl;
  }
  void close() {
    brand->close();
    cout << "Pad close" << endl;
  }
  void work() {
    brand->work();
    cout << "Pad work" << endl;
  }
};

class DeskPC : public Computer {
public:
  DeskPC(Brand *b) : Computer(b) {}
  void open() {
    brand->open();
    cout << "DeksPC open" << endl;
  }
  void close() {
    brand->close();
    cout << "DeskPC close" << endl;
  }
  void work() {
    brand->work();
    cout << "DeskPC work" << endl;
  }
};

int main() {
  Computer *miDeskPC = new DeskPC(new Mi());
  miDeskPC->open();
  miDeskPC->work();
  miDeskPC->close();

  return 0;
}