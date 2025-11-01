#include <iostream>
#include <string>

int main() {
  int a = 10, b = 20;
  int age = 25;

  std::cout << "=== 三元运算符示例 ===" << std::endl;

  // 基本用法
  int max = (a > b) ? a : b;
  std::cout << "较大的数: " << max << std::endl;

  // 用于字符串
  std::string status = (age >= 18) ? "成年人" : "未成年人";
  std::cout << "状态: " << status << std::endl;

  // 嵌套三元运算符（不推荐，难以阅读）
  int score = 85;
  std::string grade = (score >= 90)   ? "A"
                      : (score >= 80) ? "B"
                      : (score >= 70) ? "C"
                                      : "F";
  std::cout << "等级: " << grade << std::endl;

  // 在输出中直接使用
  std::cout << "数字 " << a << " 是" << ((a % 2 == 0) ? "偶数" : "奇数")
            << std::endl;

  return 0;
}
