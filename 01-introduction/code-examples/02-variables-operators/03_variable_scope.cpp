#include <iostream>

// 全局变量（在所有函数外部）
int globalVar = 100;
const double PI = 3.14159; // 全局常量

// 函数声明
void demonstrateScope();

int main() {
  std::cout << "=== 变量作用域演示 ===" << std::endl;

  // 局部变量（只在main函数内可见）
  int localVar = 50;

  std::cout << "main函数中：" << std::endl;
  std::cout << "  全局变量: " << globalVar << std::endl;
  std::cout << "  局部变量: " << localVar << std::endl;
  std::cout << "  全局常量PI: " << PI << std::endl;

  // 块作用域
  {
    int blockVar = 25; // 只在这个块内可见
    std::cout << "\n代码块内：" << std::endl;
    std::cout << "  块变量: " << blockVar << std::endl;
    std::cout << "  局部变量: " << localVar << std::endl; // 可以访问外层变量
    std::cout << "  全局变量: " << globalVar << std::endl;

    // 可以修改外层变量
    localVar = 60;
    globalVar = 200;
  }

  // std::cout << blockVar << std::endl;  // 错误！blockVar超出作用域

  std::cout << "\n代码块后：" << std::endl;
  std::cout << "  局部变量（已修改）: " << localVar << std::endl;
  std::cout << "  全局变量（已修改）: " << globalVar << std::endl;

  // 调用其他函数
  demonstrateScope();

  return 0;
}

void demonstrateScope() {
  std::cout << "\ndemonstrateScope函数中：" << std::endl;
  std::cout << "  全局变量: " << globalVar << std::endl;
  // std::cout << localVar << std::endl;  //
  // 错误！localVar在main函数中，这里不可见

  int localVar = 999; // 这是一个新的局部变量，与main中的localVar不同
  std::cout << "  本函数的局部变量: " << localVar << std::endl;
}
