#include <iostream>
#include <string>

int main() {
  // 未初始化的变量（危险！）
  int uninitializedVar; // 包含垃圾值

  // 正确的初始化方式
  int age = 25;               // 传统初始化
  double salary{50000.50};    // 统一初始化
  std::string name = "Alice"; // 字符串初始化
  bool isEmployed{true};      // 布尔值初始化

  // 多个变量声明
  int x = 10, y = 20, z = 30; // 同时声明多个变量

  // 常量（不可修改）
  const double PI = 3.14159; // 常量必须初始化
  const int MAX_SCORE{100};  // 使用花括号初始化常量

  // 输出变量值
  std::cout << "=== 变量值 ===" << std::endl;
  std::cout << "年龄: " << age << std::endl;
  std::cout << "薪水: " << salary << std::endl;
  std::cout << "姓名: " << name << std::endl;
  std::cout << "是否在职: " << (isEmployed ? "是" : "否") << std::endl;
  std::cout << "x, y, z: " << x << ", " << y << ", " << z << std::endl;
  std::cout << "圆周率: " << PI << std::endl;
  std::cout << "最高分: " << MAX_SCORE << std::endl;

  // 变量可以被重新赋值（常量除外）
  age = 26;
  std::cout << "\n更新后的年龄: " << age << std::endl;

  // PI = 3.14;  // 错误！常量不能被修改

  return 0;
}
