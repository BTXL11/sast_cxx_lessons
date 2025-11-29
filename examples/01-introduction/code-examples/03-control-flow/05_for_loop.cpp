#include <iostream>

int main() {
  std::cout << "=== for循环示例 ===" << std::endl;

  // 基本for循环
  std::cout << "数字0到4: ";
  for (int i = 0; i < 5; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // 倒序循环
  std::cout << "倒数: ";
  for (int i = 5; i > 0; i--) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // 步长为2
  std::cout << "偶数0到10: ";
  for (int i = 0; i <= 10; i += 2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // 嵌套for循环（打印乘法表）
  std::cout << "\n3x3乘法表:" << std::endl;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      std::cout << i << "x" << j << "=" << (i * j) << "\t";
    }
    std::cout << std::endl;
  }

  // 计算总和
  int sum = 0;
  for (int i = 1; i <= 10; i++) {
    sum += i;
  }
  std::cout << "\n1到10的和: " << sum << std::endl;

  // 多个变量
  std::cout << "多变量循环: ";
  for (int i = 0, j = 10; i < 5; i++, j--) {
    std::cout << "(" << i << "," << j << ") ";
  }
  std::cout << std::endl;

  return 0;
}
