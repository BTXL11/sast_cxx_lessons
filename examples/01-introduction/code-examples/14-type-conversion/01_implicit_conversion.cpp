#include <iostream>

int main() {
  std::cout << "=== 隐式类型转换示例 ===" << std::endl;

  // 1. 整数提升
  std::cout << "\n1. 整数提升:" << std::endl;
  char c = 'A';
  int i = c; // char -> int
  std::cout << "char 'A' -> int: " << i << std::endl;

  short s = 100;
  int i2 = s; // short -> int
  std::cout << "short 100 -> int: " << i2 << std::endl;

  // 2. 整数转换
  std::cout << "\n2. 整数转换:" << std::endl;
  int x = 1000;
  long l = x; // int -> long
  std::cout << "int 1000 -> long: " << l << std::endl;

  // 3. 浮点转换
  std::cout << "\n3. 浮点转换:" << std::endl;
  float f = 3.14f;
  double d = f; // float -> double
  std::cout << "float 3.14 -> double: " << d << std::endl;

  // 4. 整数到浮点
  std::cout << "\n4. 整数到浮点:" << std::endl;
  int num = 42;
  double dnum = num; // int -> double
  std::cout << "int 42 -> double: " << dnum << std::endl;

  // 5. 浮点到整数（截断）
  std::cout << "\n5. 浮点到整数（会截断）:" << std::endl;
  double pi = 3.14159;
  int ipi = pi; // double -> int（小数部分丢失）
  std::cout << "double 3.14159 -> int: " << ipi << std::endl;

  // 6. 布尔转换
  std::cout << "\n6. 布尔转换:" << std::endl;
  bool b1 = 42; // 非零 -> true
  bool b2 = 0;  // 零 -> false
  std::cout << std::boolalpha;
  std::cout << "int 42 -> bool: " << b1 << std::endl;
  std::cout << "int 0 -> bool: " << b2 << std::endl;

  int from_bool = true; // true -> 1
  std::cout << "bool true -> int: " << from_bool << std::endl;

  // 7. 指针转换
  std::cout << "\n7. 指针转换:" << std::endl;
  int *ptr = nullptr;
  bool is_null = (ptr == nullptr);
  std::cout << "nullptr -> bool: " << is_null << std::endl;

  // 8. 混合运算中的转换
  std::cout << "\n8. 混合运算:" << std::endl;
  int a = 5;
  double b = 2.5;
  double result = a + b; // int -> double，然后相加
  std::cout << "int 5 + double 2.5 = " << result << std::endl;

  // 9. 有符号和无符号转换
  std::cout << "\n9. 有符号和无符号:" << std::endl;
  int signed_num = -1;
  unsigned int unsigned_num = signed_num; // 可能产生意外结果
  std::cout << "int -1 -> unsigned int: " << unsigned_num << std::endl;

  return 0;
}
