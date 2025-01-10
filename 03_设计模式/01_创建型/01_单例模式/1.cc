#include <iostream>

class Singleton {
public:
  static Singleton& getInstance() { return instance; }
  int a = 0;

private:
  Singleton() {}
  ~Singleton() {}
  Singleton &operator=(const Singleton &) = delete;
  Singleton(const Singleton &) = delete;
  static Singleton instance;
};

Singleton Singleton::instance;

int main() {
  Singleton &s1 = Singleton::getInstance();
  Singleton &s2 = Singleton::getInstance();
  if (&s1 == &s2) {
    std::cout << "s1 and s2 are the same instance." << std::endl;
  } else {
    std::cout << "s1 and s2 are different instances." << std::endl;
  }
  return 0;
}