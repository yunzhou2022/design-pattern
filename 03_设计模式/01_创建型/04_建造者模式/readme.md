# 建造者模式

建造者模式（Builder Pattern）是一种创建型设计模式，它允许你分步骤创建复杂对象。该模式提供了一种创建对象的最佳方式，使得同样的构建过程可以创建不同的表示。

## 主要角色

1. **建造者（Builder）**：定义创建产品各个部分的接口。
2. **具体建造者（ConcreteBuilder）**：实现Builder接口，构建和装配各个部件。
3. **产品（Product）**：表示被构建的复杂对象。具体建造者创建该产品的内部表示并定义它的装配过程。
4. **指挥者（Director）**：构建一个使用Builder接口的对象。它主要用于创建一个复杂对象。

## 优点

- **更好的控制**：可以精确地控制对象的创建过程。
- **灵活性**：可以通过不同的具体建造者来创建不同的产品。

## 缺点

- **复杂性增加**：增加了系统的复杂性，因为需要定义多个具体建造者。

## 示例代码

```java
// 产品类
public class Product {
  private String partA;
  private String partB;
  private String partC;

  // getters and setters
}

// 抽象建造者
public abstract class Builder {
  protected Product product = new Product();

  public abstract void buildPartA();
  public abstract void buildPartB();
  public abstract void buildPartC();

  public Product getResult() {
    return product;
  }
}

// 具体建造者
public class ConcreteBuilder extends Builder {
  @Override
  public void buildPartA() {
    product.setPartA("Part A");
  }

  @Override
  public void buildPartB() {
    product.setPartB("Part B");
  }

  @Override
  public void buildPartC() {
    product.setPartC("Part C");
  }
}

// 指挥者
public class Director {
  private Builder builder;

  public Director(Builder builder) {
    this.builder = builder;
  }

  public void construct() {
    builder.buildPartA();
    builder.buildPartB();
    builder.buildPartC();
  }
}

// 使用示例
public class Client {
  public static void main(String[] args) {
    Builder builder = new ConcreteBuilder();
    Director director = new Director(builder);
    director.construct();
    Product product = builder.getResult();
    // 使用产品
  }
}
```

## 适用场景

- 当创建复杂对象的算法应该独立于该对象的组成部分以及它们的装配方式时。
- 当构造过程必须允许被构造的对象有不同的表示时。
### C++ 示例代码

```cpp
// 产品类
class Product {
private:
  std::string partA;
  std::string partB;
  std::string partC;

public:
  void setPartA(const std::string& part) { partA = part; }
  void setPartB(const std::string& part) { partB = part; }
  void setPartC(const std::string& part) { partC = part; }

  // getters and other methods
};

// 抽象建造者
class Builder {
protected:
  Product* product;

public:
  Builder() { product = new Product(); }
  virtual ~Builder() { delete product; }

  virtual void buildPartA() = 0;
  virtual void buildPartB() = 0;
  virtual void buildPartC() = 0;

  Product* getResult() { return product; }
};

// 具体建造者
class ConcreteBuilder : public Builder {
public:
  void buildPartA() override { product->setPartA("Part A"); }
  void buildPartB() override { product->setPartB("Part B"); }
  void buildPartC() override { product->setPartC("Part C"); }
};

// 指挥者
class Director {
private:
  Builder* builder;

public:
  Director(Builder* b) : builder(b) {}

  void construct() {
    builder->buildPartA();
    builder->buildPartB();
    builder->buildPartC();
  }
};

// 使用示例
int main() {
  ConcreteBuilder* builder = new ConcreteBuilder();
  Director director(builder);
  director.construct();
  Product* product = builder->getResult();
  // 使用产品
  delete builder;
  return 0;
}
```

### JavaScript 示例代码

```javascript
// 产品类
class Product {
  constructor() {
    this.partA = '';
    this.partB = '';
    this.partC = '';
  }

  setPartA(part) { this.partA = part; }
  setPartB(part) { this.partB = part; }
  setPartC(part) { this.partC = part; }
}

// 抽象建造者
class Builder {
  constructor() {
    this.product = new Product();
  }

  buildPartA() {}
  buildPartB() {}
  buildPartC() {}

  getResult() {
    return this.product;
  }
}

// 具体建造者
class ConcreteBuilder extends Builder {
  buildPartA() { this.product.setPartA('Part A'); }
  buildPartB() { this.product.setPartB('Part B'); }
  buildPartC() { this.product.setPartC('Part C'); }
}

// 指挥者
class Director {
  constructor(builder) {
    this.builder = builder;
  }

  construct() {
    this.builder.buildPartA();
    this.builder.buildPartB();
    this.builder.buildPartC();
  }
}

// 使用示例
const builder = new ConcreteBuilder();
const director = new Director(builder);
director.construct();
const product = builder.getResult();
// 使用产品
```