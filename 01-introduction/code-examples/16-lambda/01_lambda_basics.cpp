#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cout << "=== Lambda表达式基础 ===" << std::endl;

  // 最简单的lambda
  auto hello = []() { std::cout << "Hello from lambda!" << std::endl; };
  hello();

  // 带参数的lambda
  auto add = [](int a, int b) { return a + b; };
  std::cout << "5 + 3 = " << add(5, 3) << std::endl;

  // 带返回类型的lambda
  auto multiply = [](int a, int b) -> int { return a * b; };
  std::cout << "5 * 3 = " << multiply(5, 3) << std::endl;

  // 捕获外部变量
  int x = 10;
  int y = 20;

  // 按值捕获
  auto lambda1 = [x, y]() {
    std::cout << "按值捕获: x=" << x << ", y=" << y << std::endl;
  };
  lambda1();

  // 按引用捕获
  auto lambda2 = [&x, &y]() {
    x += 5;
    y += 5;
    std::cout << "按引用捕获并修改: x=" << x << ", y=" << y << std::endl;
  };
  lambda2();
  std::cout << "外部变量: x=" << x << ", y=" << y << std::endl;

  // 捕获所有外部变量
  auto lambda3 = [=]() { // 按值捕获所有
    std::cout << "捕获所有(值): x=" << x << ", y=" << y << std::endl;
  };
  lambda3();

  // 在算法中使用lambda
  std::vector<int> numbers = {5, 2, 8, 1, 9, 3};

  std::cout << "\n原始数组: ";
  for (int n : numbers)
    std::cout << n << " ";
  std::cout << std::endl;

  // 使用lambda排序
  std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
    return a > b; // 降序排序
  });

  std::cout << "降序排序: ";
  for (int n : numbers)
    std::cout << n << " ";
  std::cout << std::endl;

  return 0;
}
