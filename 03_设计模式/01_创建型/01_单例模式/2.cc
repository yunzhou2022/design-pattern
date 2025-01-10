#include <iostream>

// This is a thread-unsafe implementation of Singleton pattern.
class Singleton {
public:
  static Singleton *getInstance() {
    if (instance == nullptr) {
      instance = new Singleton();
    }

    return instance;
  }

private:
  Singleton(){};
  ~Singleton(){};
  static Singleton *instance; // declaration
  Singleton &operator=(const Singleton &) = delete;
};

Singleton *Singleton::instance = nullptr; // definition

int main() {
  Singleton *s1 = Singleton::getInstance();
  Singleton *s2 = Singleton::getInstance();
  if (s1 == s2) {
    std::cout << "s1 and s2 are the same instance." << std::endl;
  } else {
    std::cout << "s1 and s2 are different instances." << std::endl;
  }
  return 0;
}