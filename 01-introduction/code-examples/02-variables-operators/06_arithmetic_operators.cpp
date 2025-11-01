#include <iostream>

int main() {
  int a = 10, b = 3;
  double x = 10.0, y = 3.0;

  std::cout << "=== 算术运算符 ===" << std::endl;
  std::cout << "整数运算：" << std::endl;
  std::cout << "a + b = " << (a + b) << std::endl; // 13（加法）
  std::cout << "a - b = " << (a - b) << std::endl; // 7（减法）
  std::cout << "a * b = " << (a * b) << std::endl; // 30（乘法）
  std::cout << "a / b = " << (a / b) << std::endl; // 3（整数除法，舍弃小数）
  std::cout << "a % b = " << (a % b) << std::endl; // 1（取模，余数）

  std::cout << "\n浮点数运算：" << std::endl;
  std::cout << "x / y = " << (x / y) << std::endl; // 3.33333（浮点除法）
  // std::cout << (x % y) << std::endl;  // 错误！%不能用于浮点数

  // 自增和自减运算符
  int count = 5;
  std::cout << "\n自增自减运算符：" << std::endl;
  std::cout << "count初始值: " << count << std::endl;
  std::cout << "count++（后缀）: " << count++
            << std::endl;                             // 输出5，然后count变为6
  std::cout << "count现在是: " << count << std::endl; // 6
  std::cout << "++count（前缀）: " << ++count
            << std::endl;                             // count先变为7，然后输出7
  std::cout << "count现在是: " << count << std::endl; // 7

  // 复合赋值运算符
  int num = 10;
  std::cout << "\n复合赋值运算符：" << std::endl;
  std::cout << "num初始值: " << num << std::endl;
  num += 5;                                      // 等价于 num = num + 5
  std::cout << "num += 5: " << num << std::endl; // 15
  num -= 3;                                      // 等价于 num = num - 3
  std::cout << "num -= 3: " << num << std::endl; // 12
  num *= 2;                                      // 等价于 num = num * 2
  std::cout << "num *= 2: " << num << std::endl; // 24
  num /= 4;                                      // 等价于 num = num / 4
  std::cout << "num /= 4: " << num << std::endl; // 6
  num %= 4;                                      // 等价于 num = num % 4
  std::cout << "num %= 4: " << num << std::endl; // 2

  return 0;
}
