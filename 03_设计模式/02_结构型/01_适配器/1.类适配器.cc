#include <iostream>

using namespace std;

class AC220V {
public:
  int output220VAC() { cout << "220V AC" << endl; return 220; }
};

class DC5V {
public:
  void output5VDC() { cout << "5V DC" << endl; }
};

class IphoneAdaper : public AC220V {
public:
  int output5VDC() {
    int source = output220VAC();
    cout << "AC -> DC" << endl;
    cout << "5V DC" << endl;
    int target = source / 44;
    return target;
  }
};

class Iphone {
public:
  void chage(int voltage) {
    if(voltage == 5) {
      cout << "charging" << endl;
    } else {
      cout << "error" << endl;
    }
  }
};

int main() {
  Iphone iphone;
  IphoneAdaper iphoneAdaper;
  iphone.chage(iphoneAdaper.output5VDC());
  return 0;
}