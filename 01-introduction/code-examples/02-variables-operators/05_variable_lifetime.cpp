#include <iostream>

int globalCounter = 0; // 程序开始时创建，程序结束时销毁

void incrementCounter() {
  static int staticCounter = 0; // 静态局部变量，只初始化一次
  int localCounter = 0;         // 每次调用都重新创建

  staticCounter++;
  localCounter++;
  globalCounter++;

  std::cout << "静态计数器: " << staticCounter
            << ", 局部计数器: " << localCounter
            << ", 全局计数器: " << globalCounter << std::endl;
}

int main() {
  std::cout << "=== 变量生命周期演示 ===" << std::endl;

  incrementCounter(); // 静态:1, 局部:1, 全局:1
  incrementCounter(); // 静态:2, 局部:1, 全局:2
  incrementCounter(); // 静态:3, 局部:1, 全局:3

  return 0;
}
