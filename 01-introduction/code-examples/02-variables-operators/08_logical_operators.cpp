#include <iostream>

int main() {
  bool a = true, b = false;
  int age = 25;
  double salary = 50000;

  std::cout << std::boolalpha; // 显示true/false而不是1/0
  std::cout << "=== 逻辑运算符 ===" << std::endl;

  // 基本逻辑运算
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "a && b (与): " << (a && b)
            << std::endl; // false（两者都为true才是true）
  std::cout << "a || b (或): " << (a || b)
            << std::endl; // true（至少一个为true就是true）
  std::cout << "!a (非): " << (!a) << std::endl; // false（取反）
  std::cout << "!b (非): " << (!b) << std::endl; // true（取反）

  // 实际应用示例
  std::cout << "\n实际应用：" << std::endl;
  std::cout << "年龄: " << age << ", 薪水: " << salary << std::endl;

  // 检查是否符合贷款条件（年龄>=18且薪水>=30000）
  bool canGetLoan = (age >= 18) && (salary >= 30000);
  std::cout << "可以获得贷款: " << canGetLoan << std::endl; // true

  // 检查是否需要缴税（薪水>40000或有其他收入）
  bool hasOtherIncome = false;
  bool needPayTax = (salary > 40000) || hasOtherIncome;
  std::cout << "需要缴税: " << needPayTax << std::endl; // true

  // 短路求值演示
  std::cout << "\n短路求值：" << std::endl;
  int x = 5;
  // 在&&中，如果第一个条件为false，第二个条件不会被评估
  if (false && (++x > 0)) {
    std::cout << "这不会执行" << std::endl;
  }
  std::cout << "x的值: " << x << " (没有增加)" << std::endl; // 5

  // 在||中，如果第一个条件为true，第二个条件不会被评估
  if (true || (++x > 0)) {
    std::cout << "这会执行" << std::endl;
  }
  std::cout << "x的值: " << x << " (仍然没有增加)" << std::endl; // 5

  return 0;
}
