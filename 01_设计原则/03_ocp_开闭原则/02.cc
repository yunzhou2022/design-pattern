#include <iostream>

// OOP: 三方： 提供方，调用方， 业务逻辑。

// 对拓展开放， 对修改关闭
// 开放- 提供方
// 关闭- 调用方
// 业务逻辑
//
using namespace std;

class Shape {
public:
  virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
  void draw() override { cout << "rectangle" << endl; }
};

class Circle : public Shape {
public:
  void draw() override { cout << "circle" << endl; }
};

class Triangle : public Shape {
public:
  void draw() override { cout << "triangle" << endl; }
};

class GraphicEditor {
public:
  void drawShape(Shape *s) { s->draw(); }
};

using namespace std;

int main() {
  auto editor = new GraphicEditor();
  editor->drawShape(new Circle());
  editor->drawShape(new Triangle());
  editor->drawShape(new Rectangle());
  return 0;
}
