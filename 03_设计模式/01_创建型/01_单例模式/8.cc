#include <iostream>

// 使用 enum 实现类似单例模式
enum class Singleton {
    INSTANCE
};

// 定义一个函数来访问“单例”
Singleton& getSingleton() {
    static Singleton instance = Singleton::INSTANCE;
    return instance;
}

// 测试函数
void testSingleton() {
    Singleton& s1 = getSingleton();
    Singleton& s2 = getSingleton();
    if (&s1 == &s2) {
        std::cout << "s1 and s2 refer to the same instance." << std::endl;
    } else {
        std::cout << "s1 and s2 are different instances." << std::endl;
    }
}

int main() {
    testSingleton();

    return 0;
}