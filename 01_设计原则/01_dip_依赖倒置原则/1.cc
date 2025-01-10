#include <iostream>
using namespace std;

class DingDing {
public:
  void sendMessage() { cout << "dd上老板找你" << endl; }
};

class Worker {
public:
  void getMessage(DingDing *dingding) { dingding->sendMessage(); }
};

int main() {
  Worker *worker = new Worker();
  worker->getMessage(new DingDing());
  return 0;
}
