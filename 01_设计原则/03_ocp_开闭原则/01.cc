#include <iostream>
// 对拓展开放， 对修改关闭
// 开放- 提供方
// 关闭- 调用方
//
//
using namespace std;

class Shape {
public:
  int m_type;
};

class Rectangle : public Shape {
public:
  Rectangle() { m_type = 1; }
};

class Circle : public Shape {
public:
  Circle() { m_type = 2; }
};

class Triangle : public Shape {
public:
  Triangle() { m_type = 3; }
};

class GraphicEditor {
public:
  void drawShape(Shape *s) {
    if (s->m_type == 1) {
      drawRectangle();
    }
    if (s->m_type == 2) {
      drawCircle();
    }
    if (s->m_type == 3) {
      drawTriangle();
    }
  }

  void drawRectangle() { cout << "rectangle" << endl; }
  void drawTriangle() { cout << "triangle" << endl; }
  void drawCircle() { cout << "circle" << endl; }
};

using namespace std;

int main() {
  auto editor = new GraphicEditor();
  editor->drawShape(new Circle());
  editor->drawShape(new Rectangle());
  editor->drawShape(new Triangle());
  return 0;
}
