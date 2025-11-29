#include <iostream>

int main() {
  std::cout << "=== 数组初始化方式 ===" << std::endl;

  // 方式1：声明时完全初始化
  int numbers1[5] = {10, 20, 30, 40, 50};

  // 方式2：部分初始化（其余元素自动初始化为0）
  int numbers2[5] = {1, 2, 3}; // {1, 2, 3, 0, 0}

  // 方式3：让编译器推导大小
  int numbers3[] = {5, 10, 15, 20}; // 大小自动为4

  // 方式4：现代C++统一初始化（C++11）
  int numbers4[5]{1, 2, 3, 4, 5};

  // 方式5：全部初始化为0
  int numbers5[5] = {0}; // 或 int numbers5[5]{};

  // 打印各个数组
  std::cout << "numbers1: ";
  for (int i = 0; i < 5; i++)
    std::cout << numbers1[i] << " ";
  std::cout << std::endl;

  std::cout << "numbers2: ";
  for (int i = 0; i < 5; i++)
    std::cout << numbers2[i] << " ";
  std::cout << std::endl;

  std::cout << "numbers3: ";
  for (int i = 0; i < 4; i++)
    std::cout << numbers3[i] << " ";
  std::cout << std::endl;

  std::cout << "numbers4: ";
  for (int i = 0; i < 5; i++)
    std::cout << numbers4[i] << " ";
  std::cout << std::endl;

  std::cout << "numbers5: ";
  for (int i = 0; i < 5; i++)
    std::cout << numbers5[i] << " ";
  std::cout << std::endl;

  // 字符数组（字符串）
  char greeting[] = "Hello"; // 自动添加'\0'
  std::cout << "\n字符数组: " << greeting << std::endl;
  std::cout << "数组大小: " << sizeof(greeting) << " 字节" << std::endl;

  return 0;
}
