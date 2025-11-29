#include <iostream>

class Base {
public:
  virtual void show() { std::cout << "Base class" << std::endl; }
  virtual ~Base() {}
};

class Derived : public Base {
public:
  void show() override { std::cout << "Derived class" << std::endl; }
};

int main() {
  std::cout << "=== static_cast 示例 ===" << std::endl;

  // 1. 基本类型转换
  std::cout << "\n1. 基本类型转换:" << std::endl;
  double pi = 3.14159;
  int ipi = static_cast<int>(pi);
  std::cout << "double " << pi << " -> int " << ipi << std::endl;

  int num = 65;
  char ch = static_cast<char>(num);
  std::cout << "int " << num << " -> char '" << ch << "'" << std::endl;

  // 2. 指针类型转换
  std::cout << "\n2. 指针类型转换:" << std::endl;
  int value = 42;
  void *void_ptr = &value;
  int *int_ptr = static_cast<int *>(void_ptr);
  std::cout << "void* -> int*: " << *int_ptr << std::endl;

  // 3. 类层次结构中的转换
  std::cout << "\n3. 向上转换（安全）:" << std::endl;
  Derived derived;
  Base *base_ptr = static_cast<Base *>(&derived);
  base_ptr->show();

  std::cout << "\n4. 向下转换（需谨慎）:" << std::endl;
  Base base;
  Base *base_ptr2 = &base;
  // Derived* derived_ptr = static_cast<Derived*>(base_ptr2);  // 不安全！
  // derived_ptr->show();  // 可能导致未定义行为

  // 5. 枚举转换
  std::cout << "\n5. 枚举转换:" << std::endl;
  enum Color { RED, GREEN, BLUE };
  int color_value = static_cast<int>(GREEN);
  std::cout << "GREEN -> int: " << color_value << std::endl;

  Color color = static_cast<Color>(2);
  std::cout << "int 2 -> Color: " << color << " (BLUE)" << std::endl;

  // 6. 显式转换避免警告
  std::cout << "\n6. 避免隐式转换警告:" << std::endl;
  double d = 10.5;
  int i = static_cast<int>(d); // 明确表示有意截断
  std::cout << "显式转换: " << d << " -> " << i << std::endl;

  // 7. 算术运算中的转换
  std::cout << "\n7. 算术运算:" << std::endl;
  int a = 7;
  int b = 2;
  double result = static_cast<double>(a) / b; // 避免整数除法
  std::cout << a << " / " << b << " = " << result << std::endl;

  return 0;
}
