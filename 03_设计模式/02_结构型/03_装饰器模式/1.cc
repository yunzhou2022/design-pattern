#include <iostream>
using namespace std;

class Coffe {
private:
  int price;
  string desc;

public:
  virtual int getPrice() {
    cout << "virtual get Price" << endl;
    return price;
  }
  virtual string getDesc() { return desc; }
};

class Cappuccino : public Coffe {
public:
  int getPrice() override { return 20; }
  string getDesc() override { return "Cappuccino"; }
};

class Latte : public Coffe {
public:
  int getPrice() override { return 15; }
  string getDesc() override { return "Latte"; }
};

class Decorator : public Coffe {
protected:
  Coffe *coffe;

public:
  Decorator(Coffe *coffe) : coffe(coffe) {}
  int getPrice() {
    cout << "get Price" << endl;
    return coffe->getPrice() + Coffe::getPrice();
  }
  string getDesc() { return coffe->getDesc() + Coffe::getDesc(); }
};

class Milk : public Decorator {
public:
  Milk(Coffe *coffe) : Decorator(coffe) {}
  int getPrice() override { return coffe->getPrice() + 3; }
  string getDesc() override { return coffe->getDesc() + "milk"; }
};

int main() {
  Coffe *x = new Milk(new Cappuccino());
  cout << x->getPrice() << endl;
  cout << x->getDesc() << endl;

  x = new Milk(x);
  cout << x->getPrice() << endl;
  cout << x->getDesc() << endl;

  x = new Milk(x);
  cout << x->getPrice() << endl;
  cout << x->getDesc() << endl;

  return 0;
}