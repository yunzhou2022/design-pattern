#include <iostream>

// Subject interface
class Subject {
public:
  virtual void request() const = 0;
};

// RealSubject class
class RealSubject : public Subject {
public:
  void request() const override {
    std::cout << "RealSubject: Handling request.\n";
  }
};

// Proxy class
class Proxy : public Subject {
private:
  RealSubject* realSubject;

public:
  Proxy(RealSubject* realSubject) : realSubject(realSubject) {}

  void request() const override {
    if (this->checkAccess()) {
      this->realSubject->request();
      this->logAccess();
    }
  }

private:
  bool checkAccess() const {
    std::cout << "Proxy: Checking access prior to firing a real request.\n";
    return true;
  }

  void logAccess() const {
    std::cout << "Proxy: Logging the time of request.\n";
  }
};

// Client code
void clientCode(const Subject& subject) {
  subject.request();
}

int main() {
  std::cout << "Client: Executing the client code with a real subject:\n";
  RealSubject* realSubject = new RealSubject;
  clientCode(*realSubject);
  std::cout << "\n";

  std::cout << "Client: Executing the same client code with a proxy:\n";
  Proxy* proxy = new Proxy(realSubject);
  clientCode(*proxy);

  delete realSubject;
  delete proxy;

  return 0;
}