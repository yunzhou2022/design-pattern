# 原型模式

原型模式是一种创建型设计模式，它允许对象通过复制现有对象来创建新对象，而不是通过类构造器实例化。这种模式适用于创建成本较高的对象，或者需要避免重复初始化的情况。

## C++ 实现

```cpp
#include <iostream>
#include <string>
#include <unordered_map>

// 原型接口
class Prototype {
public:
  virtual ~Prototype() {}
  virtual Prototype* clone() const = 0;
  virtual void print() const = 0;
};

// 具体原型类
class ConcretePrototype : public Prototype {
private:
  std::string name;
public:
  ConcretePrototype(const std::string& name) : name(name) {}
  ConcretePrototype(const ConcretePrototype& other) : name(other.name) {}

  Prototype* clone() const override {
    return new ConcretePrototype(*this);
  }

  void print() const override {
    std::cout << "ConcretePrototype: " << name << std::endl;
  }
};

// 原型工厂
class PrototypeFactory {
private:
  std::unordered_map<std::string, Prototype*> prototypes;
public:
  ~PrototypeFactory() {
    for (auto& pair : prototypes) {
      delete pair.second;
    }
  }

  void registerPrototype(const std::string& key, Prototype* prototype) {
    prototypes[key] = prototype;
  }

  Prototype* createPrototype(const std::string& key) const {
    return prototypes.at(key)->clone();
  }
};

int main() {
  PrototypeFactory factory;
  factory.registerPrototype("type1", new ConcretePrototype("Type 1"));
  factory.registerPrototype("type2", new ConcretePrototype("Type 2"));

  Prototype* prototype1 = factory.createPrototype("type1");
  Prototype* prototype2 = factory.createPrototype("type2");

  prototype1->print();
  prototype2->print();

  delete prototype1;
  delete prototype2;

  return 0;
}
```

## JavaScript 实现

```javascript
// 原型对象
const prototype = {
  clone() {
    const cloneObj = Object.create(this);
    cloneObj.name = this.name;
    return cloneObj;
  },
  print() {
    console.log(`Prototype: ${this.name}`);
  }
};

// 创建具体原型
const concretePrototype1 = Object.create(prototype);
concretePrototype1.name = "Type 1";

const concretePrototype2 = Object.create(prototype);
concretePrototype2.name = "Type 2";

// 使用原型创建新对象
const clone1 = concretePrototype1.clone();
const clone2 = concretePrototype2.clone();

clone1.print();
clone2.print();
```

原型模式通过克隆现有对象来创建新对象，避免了重复的初始化过程，提高了创建对象的效率。

## 深拷贝实现

### C++ 实现

在 C++ 中，可以通过递归复制对象的所有成员来实现深拷贝。以下是一个简单的深拷贝示例：

```cpp
#include <iostream>
#include <vector>

class DeepCopyExample {
private:
  std::vector<int> data;
public:
  DeepCopyExample(const std::vector<int>& data) : data(data) {}

  // 深拷贝构造函数
  DeepCopyExample(const DeepCopyExample& other) : data(other.data) {}

  void print() const {
    for (int value : data) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
};

int main() {
  std::vector<int> data = {1, 2, 3, 4, 5};
  DeepCopyExample original(data);
  DeepCopyExample copy = original;

  original.print();
  copy.print();

  return 0;
}
```

### JavaScript 实现

在 JavaScript 中，可以使用 `JSON.parse` 和 `JSON.stringify` 方法来实现深拷贝。以下是一个简单的深拷贝示例：

```javascript
const original = {
  name: "Original",
  data: [1, 2, 3, 4, 5]
};

// 深拷贝
const copy = JSON.parse(JSON.stringify(original));

console.log("Original:", original);
console.log("Copy:", copy);
```

深拷贝确保新对象与原对象完全独立，修改新对象不会影响原对象。