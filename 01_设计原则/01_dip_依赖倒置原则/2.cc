#include <iostream>
using namespace std;

class IMessage {
public:
  virtual void sendMessage() = 0;
};

class DingDing : public IMessage {
public:
  void sendMessage() override { cout << "dd上老板找你" << endl; }
};

class Wechat : public IMessage {
public:
  void sendMessage() override { cout << "wechat上老板找你" << endl; }
};

class Worker {
public:
  void getMessage(IMessage *msg) { msg->sendMessage(); }
};

int main() {
  Worker *worker = new Worker();
  worker->getMessage(new DingDing());
  worker->getMessage(new Wechat());
  return 0;
}
