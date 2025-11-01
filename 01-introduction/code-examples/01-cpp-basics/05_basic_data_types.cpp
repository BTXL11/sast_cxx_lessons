#include <iostream>
#include <string>

int main() {
  // 整数类型
  int age = 25;                          // 标准整数
  short year = 2024;                     // 短整数
  long population = 8000000000L;         // 长整数（注意L后缀）
  long long bigNumber = 9999999999999LL; // 超长整数（注意LL后缀）

  // 浮点类型
  float height = 5.9f;       // 单精度（注意f后缀）
  double pi = 3.14159265359; // 双精度

  // 字符和布尔类型
  char grade = 'A';      // 单个字符（用单引号）
  bool isStudent = true; // 布尔值

  // 字符串类型（需要#include <string>）
  std::string name = "Alice"; // 字符串（用双引号）

  // 输出所有变量
  std::cout << "=== 基本数据类型示例 ===" << std::endl;
  std::cout << "姓名: " << name << std::endl;
  std::cout << "年龄: " << age << std::endl;
  std::cout << "年份: " << year << std::endl;
  std::cout << "人口: " << population << std::endl;
  std::cout << "大数字: " << bigNumber << std::endl;
  std::cout << "身高: " << height << " 英尺" << std::endl;
  std::cout << "圆周率: " << pi << std::endl;
  std::cout << "成绩等级: " << grade << std::endl;
  std::cout << "是学生: " << (isStudent ? "是" : "否") << std::endl;

  // 显示数据类型的大小
  std::cout << "\n=== 数据类型大小（字节） ===" << std::endl;
  std::cout << "int: " << sizeof(int) << " 字节" << std::endl;
  std::cout << "short: " << sizeof(short) << " 字节" << std::endl;
  std::cout << "long: " << sizeof(long) << " 字节" << std::endl;
  std::cout << "long long: " << sizeof(long long) << " 字节" << std::endl;
  std::cout << "float: " << sizeof(float) << " 字节" << std::endl;
  std::cout << "double: " << sizeof(double) << " 字节" << std::endl;
  std::cout << "char: " << sizeof(char) << " 字节" << std::endl;
  std::cout << "bool: " << sizeof(bool) << " 字节" << std::endl;

  return 0;
}
