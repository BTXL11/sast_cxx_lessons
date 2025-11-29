#include <iostream>

int value = 100; // 全局变量

int main() {
  std::cout << "全局变量: " << value << std::endl; // 输出100

  int value = 50;                                  // 局部变量，遮蔽了全局变量
  std::cout << "局部变量: " << value << std::endl; // 输出50

  {
    int value = 25;                                // 块变量，遮蔽了局部变量
    std::cout << "块变量: " << value << std::endl; // 输出25

    // 使用::访问全局变量
    std::cout << "全局变量（使用::）: " << ::value << std::endl; // 输出100
  }

  std::cout << "块外的局部变量: " << value << std::endl; // 输出50

  return 0;
}
