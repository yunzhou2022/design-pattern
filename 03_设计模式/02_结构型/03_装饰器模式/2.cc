#include <iostream>
#include <memory>
using namespace std;

class Coffee {
public:
  virtual int getPrice() const = 0;
  virtual string getDesc() const = 0;
  virtual ~Coffee() = default;
};

class Cappuccino : public Coffee {
public:
  int getPrice() const override { return 20; }
  string getDesc() const override { return "Cappuccino"; }
};

class Latte : public Coffee {
public:
  int getPrice() const override { return 15; }
  string getDesc() const override { return "Latte"; }
};

class Decorator : public Coffee {
protected:
  shared_ptr<Coffee> coffee;

public:
  Decorator(shared_ptr<Coffee> coffee) : coffee(coffee) {}
  virtual int getPrice() const override { return coffee->getPrice(); }
  virtual string getDesc() const override { return coffee->getDesc(); }
};

class Milk : public Decorator {
public:
  Milk(shared_ptr<Coffee> coffee) : Decorator(coffee) {}
  int getPrice() const override { return coffee->getPrice() + 3; }
  string getDesc() const override { return coffee->getDesc() + " + Milk"; }
};

int main() {
  shared_ptr<Coffee> coffee = make_shared<Milk>(make_shared<Cappuccino>());
  cout << coffee->getPrice() << endl;
  cout << coffee->getDesc() << endl;

  coffee = make_shared<Milk>(coffee);
  cout << coffee->getPrice() << endl;
  cout << coffee->getDesc() << endl;

  coffee = make_shared<Milk>(coffee);
  cout << coffee->getPrice() << endl;
  cout << coffee->getDesc() << endl;

  return 0;
}
