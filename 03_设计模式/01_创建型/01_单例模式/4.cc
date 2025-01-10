#include <iostream>

// 使用局部静态变量的特性来实现单例模式
class Singleton {
public:
  static Singleton &getInstance() {
    static Singleton instance;
    return instance;
  }

  void showMessage() { std::cout << "Hello from Singleton!" << std::endl; }

private:
  Singleton() { std::cout << "Singleton instance created." << std::endl; }

  ~Singleton() { std::cout << "Singleton instance destroyed." << std::endl; }

  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;
};

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