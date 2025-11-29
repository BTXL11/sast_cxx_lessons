#include <iostream>

int main() {
  std::cout << "=== break和continue示例 ===" << std::endl;

  // break示例
  std::cout << "查找第一个大于50的数:" << std::endl;
  int numbers[] = {10, 25, 35, 60, 75, 90};

  for (int i = 0; i < 6; i++) {
    std::cout << "检查: " << numbers[i];
    if (numbers[i] > 50) {
      std::cout << " - 找到了！" << std::endl;
      break; // 找到后立即退出循环
    }
    std::cout << " - 继续查找" << std::endl;
  }

  // continue示例
  std::cout << "\n只打印奇数 (1-10):" << std::endl;
  for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
      continue; // 跳过偶数
    }
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // 组合使用
  std::cout << "\n打印奇数，遇到15停止:" << std::endl;
  for (int i = 1; i <= 20; i++) {
    if (i == 15) {
      std::cout << "\n遇到15，停止循环" << std::endl;
      break;
    }
    if (i % 2 == 0) {
      continue; // 跳过偶数
    }
    std::cout << i << " ";
  }

  return 0;
}
