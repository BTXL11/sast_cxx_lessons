#include <iostream>
#include <string>

// 重载add函数 - 不同参数类型
int add(int a, int b) {
  std::cout << "调用 int add(int, int)" << std::endl;
  return a + b;
}

double add(double a, double b) {
  std::cout << "调用 double add(double, double)" << std::endl;
  return a + b;
}

// 重载add函数 - 不同参数数量
int add(int a, int b, int c) {
  std::cout << "调用 int add(int, int, int)" << std::endl;
  return a + b + c;
}

// 重载print函数
void print(int value) { std::cout << "整数: " << value << std::endl; }

void print(double value) { std::cout << "浮点数: " << value << std::endl; }

void print(std::string value) { std::cout << "字符串: " << value << std::endl; }

void print(int arr[], int size) {
  std::cout << "数组: [";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i];
    if (i < size - 1)
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

int main() {
  std::cout << "=== 函数重载示例 ===" << std::endl;

  // 调用不同版本的add
  std::cout << "\nadd函数重载:" << std::endl;
  std::cout << "结果: " << add(5, 3) << std::endl;
  std::cout << "结果: " << add(5.5, 3.2) << std::endl;
  std::cout << "结果: " << add(1, 2, 3) << std::endl;

  // 调用不同版本的print
  std::cout << "\nprint函数重载:" << std::endl;
  print(42);
  print(3.14);
  print("Hello, World!");

  int numbers[] = {1, 2, 3, 4, 5};
  print(numbers, 5);

  return 0;
}
