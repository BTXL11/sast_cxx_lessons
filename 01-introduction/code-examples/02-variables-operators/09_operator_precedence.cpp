#include <iostream>

int main() {
  int result;

  // 没有括号
  result = 5 + 3 * 2; // 先乘后加：5 + 6 = 11
  std::cout << "5 + 3 * 2 = " << result << std::endl;

  // 使用括号改变优先级
  result = (5 + 3) * 2; // 先加后乘：8 * 2 = 16
  std::cout << "(5 + 3) * 2 = " << result << std::endl;

  // 复杂表达式
  bool condition = 10 > 5 && 20 < 30 || false;
  // 等价于：((10 > 5) && (20 < 30)) || false
  std::cout << std::boolalpha;
  std::cout << "10 > 5 && 20 < 30 || false = " << condition
            << std::endl; // true

  return 0;
}
