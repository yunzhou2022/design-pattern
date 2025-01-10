#include <iostream>
#include <mutex>

// 使用双重检查锁定确保线程安全， 同时避免不必要的加锁开销
class Singleton {
public:
  static Singleton *getInstance() {
    if (instance == nullptr) {
      std::lock_guard<std::mutex> lock(mutex);
      if (instance == nullptr) {
        instance = new Singleton();
      }
    }
    return instance;
  }

private:
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;

  static Singleton *instance;
  static std::mutex mutex;
};

Singleton *Singleton::instance = nullptr;
std::mutex Singleton::mutex;

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