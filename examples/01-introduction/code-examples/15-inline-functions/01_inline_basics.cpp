#include <iostream>

// 普通函数
int square(int x) { return x * x; }

// 内联函数
inline int inlineSquare(int x) { return x * x; }

// 内联函数：最大值
inline int max(int a, int b) { return (a > b) ? a : b; }

// 内联函数：最小值
inline int min(int a, int b) { return (a < b) ? a : b; }

// 复杂的内联函数（编译器可能不内联）
inline int complexFunction(int x) {
  int result = 0;
  for (int i = 0; i < x; i++) {
    result += i * i;
  }
  return result;
}

int main() {
  std::cout << "=== 内联函数基础 ===" << std::endl;

  // 1. 基本使用
  std::cout << "\n1. 基本内联函数:" << std::endl;
  int num = 5;
  std::cout << "square(" << num << ") = " << square(num) << std::endl;
  std::cout << "inlineSquare(" << num << ") = " << inlineSquare(num)
            << std::endl;

  // 2. 多次调用
  std::cout << "\n2. 多次调用内联函数:" << std::endl;
  for (int i = 1; i <= 5; i++) {
    std::cout << "inlineSquare(" << i << ") = " << inlineSquare(i) << std::endl;
  }

  // 3. 内联函数组合
  std::cout << "\n3. 内联函数组合:" << std::endl;
  int a = 10, b = 20, c = 15;
  int maximum = max(max(a, b), c);
  int minimum = min(min(a, b), c);
  std::cout << "最大值: " << maximum << std::endl;
  std::cout << "最小值: " << minimum << std::endl;

  // 4. 复杂内联函数
  std::cout << "\n4. 复杂内联函数:" << std::endl;
  std::cout << "complexFunction(10) = " << complexFunction(10) << std::endl;

  // 5. 性能比较（概念演示）
  std::cout << "\n5. 内联函数优势:" << std::endl;
  std::cout << "- 避免函数调用开销" << std::endl;
  std::cout << "- 适合小型、频繁调用的函数" << std::endl;
  std::cout << "- 编译器可能自动内联或拒绝内联" << std::endl;

  return 0;
}
