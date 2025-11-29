#include <iostream>

int main() {
  std::cout << "=== while循环示例 ===" << std::endl;

  // 基本while循环
  std::cout << "数字0到4: ";
  int i = 0;
  while (i < 5) {
    std::cout << i << " ";
    i++;
  }
  std::cout << std::endl;

  // 用户输入验证（模拟）
  int password = 0;
  int attempts = 0;
  const int correctPassword = 1234;

  std::cout << "\n密码验证示例（正确密码是1234）:" << std::endl;
  // 在实际程序中，这里会从用户输入读取
  // 这里我们模拟几次错误尝试
  int testPasswords[] = {1111, 2222, 1234};
  int testIndex = 0;

  while (password != correctPassword && attempts < 3) {
    password = testPasswords[testIndex++];
    attempts++;
    std::cout << "尝试 " << attempts << ": 输入密码 " << password;

    if (password == correctPassword) {
      std::cout << " - 正确！" << std::endl;
    } else {
      std::cout << " - 错误！" << std::endl;
    }
  }

  if (password == correctPassword) {
    std::cout << "登录成功！" << std::endl;
  } else {
    std::cout << "登录失败，尝试次数过多。" << std::endl;
  }

  // 计算阶乘
  int n = 5;
  int factorial = 1;
  int counter = n;

  while (counter > 0) {
    factorial *= counter;
    counter--;
  }
  std::cout << "\n" << n << "的阶乘是: " << factorial << std::endl;

  return 0;
}
