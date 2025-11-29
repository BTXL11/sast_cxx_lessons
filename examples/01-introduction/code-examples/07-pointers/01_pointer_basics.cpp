#include <iostream>

int main() {
  std::cout << "=== 指针基础示例 ===" << std::endl;

  int x = 42;

  std::cout << "变量 x 的值: " << x << std::endl;
  std::cout << "变量 x 的地址: " << &x << std::endl;

  // 创建指向x的指针
  int *ptr = &x; // & 是取地址运算符

  std::cout << "\n指针 ptr 存储的地址: " << ptr << std::endl;
  std::cout << "指针 ptr 指向的值: " << *ptr << std::endl; // * 是解引用运算符

  // 通过指针修改值
  *ptr = 100;
  std::cout << "\n通过指针修改后:" << std::endl;
  std::cout << "x 的值: " << x << std::endl;
  std::cout << "*ptr 的值: " << *ptr << std::endl;

  // 指针本身也有地址
  std::cout << "\n指针 ptr 本身的地址: " << &ptr << std::endl;

  return 0;
}
