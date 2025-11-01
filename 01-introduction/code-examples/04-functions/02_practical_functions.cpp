#include <cmath>
#include <iostream>

// 计算圆的面积
double calculateCircleArea(double radius) {
  const double PI = 3.14159265359;
  return PI * radius * radius;
}

// 计算圆的周长
double calculateCircleCircumference(double radius) {
  const double PI = 3.14159265359;
  return 2 * PI * radius;
}

// 判断是否为质数
bool isPrime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

// 计算阶乘
int factorial(int n) {
  if (n <= 1)
    return 1;
  int result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main() {
  std::cout << "=== 实用函数示例 ===" << std::endl;

  // 圆的计算
  double radius = 5.0;
  std::cout << "半径为 " << radius << " 的圆：" << std::endl;
  std::cout << "  面积: " << calculateCircleArea(radius) << std::endl;
  std::cout << "  周长: " << calculateCircleCircumference(radius) << std::endl;

  // 质数判断
  std::cout << "\n质数判断：" << std::endl;
  for (int i = 1; i <= 10; i++) {
    std::cout << i << (isPrime(i) ? " 是质数" : " 不是质数") << std::endl;
  }

  // 阶乘计算
  std::cout << "\n阶乘计算：" << std::endl;
  for (int i = 1; i <= 5; i++) {
    std::cout << i << "! = " << factorial(i) << std::endl;
  }

  return 0;
}
