#include <iostream>

int main() {
  std::cout << "=== 数组遍历方法 ===" << std::endl;

  int numbers[] = {10, 20, 30, 40, 50};
  int size = sizeof(numbers) / sizeof(numbers[0]); // 计算数组大小

  // 方法1：使用索引的for循环
  std::cout << "方法1 - 索引for循环: ";
  for (int i = 0; i < size; i++) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  // 方法2：使用指针
  std::cout << "方法2 - 指针遍历: ";
  for (int *ptr = numbers; ptr < numbers + size; ptr++) {
    std::cout << *ptr << " ";
  }
  std::cout << std::endl;

  // 方法3：基于范围的for循环（C++11）
  std::cout << "方法3 - 范围for循环: ";
  for (int num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // 方法4：使用auto（C++11）
  std::cout << "方法4 - auto范围循环: ";
  for (auto num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
