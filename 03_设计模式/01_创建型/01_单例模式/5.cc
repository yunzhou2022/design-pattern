#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Singleton {
public:
  static Singleton &getInstance() { return instance; }

  void showMessage() { cout << "Singleton instance using enum!" << endl; }

private:
  int counter = 0;

public:
  void addOne() {
    counter++;
  }

  int getCounter() const { return counter; }
  // enum class SingletonEnum { INSTANCE };
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;
  static Singleton instance;
};

Singleton Singleton::instance;

void incrementCounter() {
  Singleton &singleton = Singleton::getInstance();
  singleton.addOne();
}

int main() {
  Singleton &singleton = Singleton::getInstance();
  singleton.showMessage();

  vector<thread> threads;
  for (int i = 0; i < 500; ++i) {
    threads.emplace_back(incrementCounter);
  }

  for (auto &thread : threads) {
    thread.join();
  }

  cout << "Counter: " << singleton.getCounter() << endl;

  return 0;
}