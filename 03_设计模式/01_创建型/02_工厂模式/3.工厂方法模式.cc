#include <cstdlib>
#include <iostream>

using namespace std;

class Pizza {
public:
  virtual void prepare() = 0;
  void bake(){};
  void cut(){};
  void box(){};
};

class BJGreekPizza : public Pizza {
public:
  void prepare() override { cout << "BJGreekPizza prepare" << endl; }
};

class BJCheesePizza : public Pizza {
public:
  void prepare() override { cout << "BJCheesePizza prepare" << endl; }
};

class SHGreekPizza : public Pizza {
public:
  void prepare() override { cout << "SHGreekPizza prepare" << endl; }
};

class SHCheesePizza : public Pizza {
public:
  void prepare() override { cout << "SHCheesePizza prepare" << endl; }
};

enum PizzaType { UNKNOWN, GREEKPIZZA, CHEESEPIZZA };

class OrderPizza {
public:
  virtual Pizza *createPizza(PizzaType type) = 0;
};

class BJSimpleFactory : public OrderPizza {
public:
  Pizza *createPizza(PizzaType type) override {
    Pizza *pizza = nullptr;
    switch (type) {
    case GREEKPIZZA:
      pizza = new BJGreekPizza();
      break;
    case CHEESEPIZZA:
      pizza = new BJCheesePizza();
      break;
    default:
      cout << "Unknown pizza type" << endl;
      return nullptr;
    }
    return pizza;
  }
};

class SHSimpleFactory : public OrderPizza {
public:
  Pizza *createPizza(PizzaType type) {
    Pizza *pizza = nullptr;
    switch (type) {
    case GREEKPIZZA:
      pizza = new SHGreekPizza();
      break;
    case CHEESEPIZZA:
      pizza = new SHCheesePizza();
      break;
    default:
      cout << "Unknown pizza type" << endl;
      return nullptr;
    }
    return pizza;
  }
};

class PizzaStore {
public:
  PizzaStore() {
    int area = rand() % 2;
    OrderPizza *factory = nullptr;
    switch (area) {
    case 0:
      factory = new BJSimpleFactory();
      break;
    default:
      factory = new SHSimpleFactory();
      break;
    }

    int type = rand() % 3;
    Pizza *pizza = factory->createPizza((PizzaType)type);
    if (pizza) {
      pizza->prepare();
      pizza->bake();
      pizza->cut();
      pizza->box();
      delete pizza;
    }
  };
};

int main() {
  srand(time(0));
  PizzaStore store;
  return 0;
}