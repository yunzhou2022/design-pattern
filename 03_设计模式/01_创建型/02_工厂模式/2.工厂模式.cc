#include <cstdlib>
#include <iostream>

using namespace std;

class Pizza {
public:
  virtual void prepare() = 0;
  virtual void bake() = 0;
  virtual void cut() = 0;
  virtual void box() = 0;
};

class GreekPizza : public Pizza {
public:
  void prepare() override { cout << "GreekPizza prepare" << endl; }
  void bake() override { cout << "GreekPizza bake" << endl; }
  void cut() override { cout << "GreekPizza cut" << endl; }
  void box() override { cout << "GreekPizza box" << endl; }
};

class CheesePizza : public Pizza {
public:
  void prepare() override { cout << "CheesePizza prepare" << endl; }
  void bake() override { cout << "CheesePizza bake" << endl; }
  void cut() override { cout << "CheesePizza cut" << endl; }
  void box() override { cout << "CheesePizza box" << endl; }
};

enum PizzaType { UNKNOWN, GREEKPIZZA, CHEESEPIZZA };

class SimpleFactory {
public:
  Pizza *createPizza(PizzaType type) {
    Pizza *pizza = nullptr;
    switch (type) {
    case GREEKPIZZA:
      pizza = new GreekPizza();
      break;
    case CHEESEPIZZA:
      pizza = new CheesePizza();
      break;
    default:
      cout << "Unknown pizza type" << endl;
      return nullptr;
    }
    return pizza;
  }
};

class OrderPizza {
public:
  OrderPizza(SimpleFactory *factory) {
    int type = rand() % 3;
    Pizza *pizza = factory->createPizza((PizzaType) type);
    if (pizza) {
      pizza->prepare();
      pizza->bake();
      pizza->cut();
      pizza->box();
      delete pizza;
    }
  }
};

class PizzaStore{
  public:
  PizzaStore(){
    new OrderPizza(new SimpleFactory());
  }
};

int main() {
  srand(time(0));
  // OrderPizza order(new SimpleFactory());
  PizzaStore shop;
  return 0;
}