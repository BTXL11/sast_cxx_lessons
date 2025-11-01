#include <iostream>

int main() {
  // 好的命名（描述性强）
  int studentAge = 20;
  double accountBalance = 1000.50;
  bool isLoggedIn = true;

  // 不好的命名（难以理解）
  int a = 20;
  double b = 1000.50;
  bool c = true;

  // 使用驼峰命名法或下划线命名法
  int myVariableName = 10;   // 驼峰命名法
  int my_variable_name = 10; // 下划线命名法

  std::cout << "学生年龄: " << studentAge << std::endl;
  std::cout << "账户余额: " << accountBalance << std::endl;
  std::cout << "是否登录: " << (isLoggedIn ? "是" : "否") << std::endl;

  return 0;
}
