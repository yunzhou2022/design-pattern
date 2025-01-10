#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

class Singleton {
public:
  static Singleton &getInstance() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 添加更多延迟
    static Singleton instance;
    return instance;
  }

  void addOne() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // 添加延迟
    std::lock_guard<std::mutex> guard(mutex_);
    counter++;
  }

  int getCounter() const { return counter; }

private:
  int counter = 0;
  std::mutex mutex_;

  Singleton() {
    cout << "Singleton instance created at: " << this << " at time: "
         << chrono::system_clock::now().time_since_epoch().count() << endl;
  }
  ~Singleton() {}
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;
  static Singleton *instance; // 修改为指针类型˜
  enum class SingletonState { kInit, kDestroy };
};

void createInstance() {
  Singleton &singleton = Singleton::getInstance();
  singleton.addOne();
}

int main() {
  vector<thread> threads;
  for (int i = 0; i < 100; ++i) { // 增加线程数量
    threads.emplace_back(createInstance);
  }

  for (auto &thread : threads) {
    thread.join();
  }

  Singleton &singleton = Singleton::getInstance();

  cout << "Counter: " << singleton.getCounter() << endl;

  return 0;
}