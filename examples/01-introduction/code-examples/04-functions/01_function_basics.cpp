#include <iostream>

// 函数声明（原型）- 告诉编译器函数的存在
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);

int main() {
  std::cout << "=== 函数基础示例 ===" << std::endl;

  // 调用函数
  int sum = add(10, 5);
  int difference = subtract(10, 5);
  int product = multiply(10, 5);
  double quotient = divide(10.0, 5.0);

  std::cout << "10 + 5 = " << sum << std::endl;
  std::cout << "10 - 5 = " << difference << std::endl;
  std::cout << "10 * 5 = " << product << std::endl;
  std::cout << "10 / 5 = " << quotient << std::endl;

  // 直接在表达式中使用函数
  int result = add(multiply(3, 4), subtract(20, 5));
  std::cout << "\n(3 * 4) + (20 - 5) = " << result << std::endl;

  return 0;
}

// 函数定义 - 实现函数的功能
int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

double divide(double a, double b) {
  if (b != 0) {
    return a / b;
  } else {
    std::cout << "错误：除数不能为0" << std::endl;
    return 0.0;
  }
}
