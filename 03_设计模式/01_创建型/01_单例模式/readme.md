# 单例模式

单例模式是一种创建型设计模式，它确保一个类只有一个实例，并提供一个全局访问点来访问该实例。

## C++ 示例

```cpp
#include <iostream>
#include <mutex>

class Singleton {
public:
  static Singleton& getInstance() {
    static Singleton instance;
    return instance;
  }

  void showMessage() {
    std::cout << "Hello from Singleton!" << std::endl;
  }

private:
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
};

int main() {
  Singleton& singleton = Singleton::getInstance();
  singleton.showMessage();
  return 0;
}
```

## JavaScript 示例

```javascript
class Singleton {
  constructor() {
    if (!Singleton.instance) {
      Singleton.instance = this;
    }
    return Singleton.instance;
  }

  showMessage() {
    console.log("Hello from Singleton!");
  }
}

const instance = new Singleton();
Object.freeze(instance);

instance.showMessage();
```

## 八种单例模式的写法

### C++ 实现

#### 1. 饿汉式

```cpp
class Singleton {
public:
  static Singleton& getInstance() {
    return instance;
  }

private:
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  static Singleton instance;
};

Singleton Singleton::instance;
```

**优势**: 实现简单，线程安全。
**劣势**: 类加载时即创建实例，可能造成资源浪费。

#### 2. 懒汉式

```cpp
class Singleton {
public:
  static Singleton* getInstance() {
    if (instance == nullptr) {
      instance = new Singleton();
    }
    return instance;
  }

private:
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;
```

**优势**: 延迟实例化，节省资源。
**劣势**: 非线程安全。

#### 3. 线程安全懒汉式

```cpp
class Singleton {
public:
  static Singleton* getInstance() {
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == nullptr) {
      instance = new Singleton();
    }
    return instance;
  }

private:
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton* instance;
  static std::mutex mutex;
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;
```

**优势**: 线程安全。
**劣势**: 每次获取实例都需要加锁，性能开销大。

#### 4. 双重检查锁

```cpp
class Singleton {
public:
  static Singleton* getInstance() {
    if (instance == nullptr) {
      std::lock_guard<std::mutex> lock(mutex);
      if (instance == nullptr) {
        instance = new Singleton();
      }
    }
    return instance;
  }

private:
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton* instance;
  static std::mutex mutex;
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;
```

**优势**: 线程安全，性能较好。
**劣势**: 实现复杂。

#### 5. 静态内部类

```cpp
class Singleton {
public:
  static Singleton& getInstance() {
    static Singleton instance;
    return instance;
  }

private:
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
};
```

**优势**: 延迟加载，线程安全。
**劣势**: 无法传递参数。

#### 6. 枚举

```cpp
enum class Singleton {
  INSTANCE;

  void showMessage() {
    std::cout << "Hello from Singleton!" << std::endl;
  }
};
```

**优势**: 简单，线程安全，防止反序列化创建新对象。
**劣势**: 不常用，无法延迟加载。

#### 7. 使用智能指针

```cpp
#include <memory>

class Singleton {
public:
  static std::shared_ptr<Singleton> getInstance() {
    static std::shared_ptr<Singleton> instance(new Singleton());
    return instance;
  }

private:
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
};
```

**优势**: 自动管理内存，线程安全。
**劣势**: 依赖智能指针库。

#### 8. 使用原子操作

```cpp
#include <atomic>

class Singleton {
public:
  static Singleton* getInstance() {
    Singleton* temp = instance.load(std::memory_order_acquire);
    if (temp == nullptr) {
      std::lock_guard<std::mutex> lock(mutex);
      temp = instance.load(std::memory_order_relaxed);
      if (temp == nullptr) {
        temp = new Singleton();
        instance.store(temp, std::memory_order_release);
      }
    }
    return temp;
  }

private:
  Singleton() {}
  ~Singleton() {}
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static std::atomic<Singleton*> instance;
  static std::mutex mutex;
};

std::atomic<Singleton*> Singleton::instance(nullptr);
std::mutex Singleton::mutex;
```

**优势**: 高效，线程安全。
**劣势**: 实现复杂。

### JavaScript 实现

#### 1. 饿汉式

```javascript
class Singleton {
  constructor() {
    if (!Singleton.instance) {
      Singleton.instance = this;
    }
    return Singleton.instance;
  }
}

const instance = new Singleton();
Object.freeze(instance);
```

**优势**: 实现简单，实例全局唯一。
**劣势**: 类加载时即创建实例，可能造成资源浪费。

#### 2. 懒汉式

```javascript
class Singleton {
  constructor() {
    if (!Singleton.instance) {
      Singleton.instance = this;
    }
    return Singleton.instance;
  }
}

Singleton.getInstance = function () {
  if (!Singleton.instance) {
    Singleton.instance = new Singleton();
  }
  return Singleton.instance;
};
```

**优势**: 延迟实例化，节省资源。
**劣势**: 非线程安全。

#### 3. 线程安全懒汉式

```javascript
class Singleton {
  constructor() {
    if (!Singleton.instance) {
      Singleton.instance = this;
    }
    return Singleton.instance;
  }
}

Singleton.getInstance = function () {
  if (!Singleton.instance) {
    Singleton.instance = new Singleton();
  }
  return Singleton.instance;
};

Object.freeze(Singleton.getInstance());
```

**优势**: 线程安全。
**劣势**: 实现复杂。

#### 4. 双重检查锁

```javascript
class Singleton {
  constructor() {
    if (!Singleton.instance) {
      Singleton.instance = this;
    }
    return Singleton.instance;
  }
}

Singleton.getInstance = function () {
  if (!Singleton.instance) {
    if (!Singleton.instance) {
      Singleton.instance = new Singleton();
    }
  }
  return Singleton.instance;
};
```

**优势**: 线程安全，性能较好。
**劣势**: 实现复杂。

#### 5. 静态内部类

```javascript
class Singleton {
  constructor() {
    if (!Singleton.instance) {
      Singleton.instance = this;
    }
    return Singleton.instance;
  }
}

Singleton.getInstance = (function () {
  let instance;
  return function () {
    if (!instance) {
      instance = new Singleton();
    }
    return instance;
  };
})();
```

**优势**: 延迟加载，线程安全。
**劣势**: 无法传递参数。

#### 6. 枚举

```javascript
const Singleton = Object.freeze({
  INSTANCE: {
    showMessage: function () {
      console.log("Hello from Singleton!");
    },
  },
});
```

**优势**: 简单，线程安全。
**劣势**: 不常用，无法延迟加载。

#### 7. 使用闭包

```javascript
const Singleton = (function () {
  let instance;

  function createInstance() {
    return {
      showMessage: function () {
        console.log("Hello from Singleton!");
      },
    };
  }

  return {
    getInstance: function () {
      if (!instance) {
        instance = createInstance();
      }
      return instance;
    },
  };
})();
```

**优势**: 延迟加载，线程安全。
**劣势**: 实现复杂。

#### 8. 使用模块

```javascript
const Singleton = (function () {
  const instance = {
    showMessage: function () {
      console.log("Hello from Singleton!");
    },
  };

  return {
    getInstance: function () {
      return instance;
    },
  };
})();
```

**优势**: 简单，线程安全。
**劣势**: 无法延迟加载。
