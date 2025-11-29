#include <iostream>

int main() {
  int x = 10, y = 20, z = 10;

  std::cout << "=== 比较运算符 ===" << std::endl;
  std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
  std::cout << std::endl;

  // 在C++中，true显示为1，false显示为0
  std::cout << "x == y: " << (x == y) << " (相等)" << std::endl; // 0 (false)
  std::cout << "x == z: " << (x == z) << " (相等)" << std::endl; // 1 (true)
  std::cout << "x != y: " << (x != y) << " (不等)" << std::endl; // 1 (true)
  std::cout << "x < y: " << (x < y) << " (小于)" << std::endl;   // 1 (true)
  std::cout << "x > y: " << (x > y) << " (大于)" << std::endl;   // 0 (false)
  std::cout << "x <= z: " << (x <= z) << " (小于等于)" << std::endl; // 1 (true)
  std::cout << "y >= x: " << (y >= x) << " (大于等于)" << std::endl; // 1 (true)

  // 使用boolalpha让布尔值显示为true/false
  std::cout << std::boolalpha; // 设置布尔值输出格式
  std::cout << "\n使用boolalpha后：" << std::endl;
  std::cout << "x == y: " << (x == y) << std::endl; // false
  std::cout << "x < y: " << (x < y) << std::endl;   // true

  return 0;
}
