#include <iostream>

int getValue() { return 42; }

int &getReference() {
  static int value = 100;
  return value;
}

int main() {
  std::cout << "=== 左值和右值基础 ===" << std::endl;

  // 1. 左值（lvalue）- 有名字，有地址
  std::cout << "\n1. 左值示例:" << std::endl;
  int x = 10; // x 是左值
  int y = 20; // y 是左值

  std::cout << "x = " << x << ", 地址: " << &x << std::endl;
  std::cout << "y = " << y << ", 地址: " << &y << std::endl;

  // 左值可以出现在赋值语句左边
  x = 30;
  std::cout << "修改后 x = " << x << std::endl;

  // 2. 右值（rvalue）- 临时值，没有地址
  std::cout << "\n2. 右值示例:" << std::endl;
  int z = 5 + 3; // 5 + 3 是右值（临时值）
  std::cout << "z = " << z << std::endl;

  // 右值不能取地址
  // &(5 + 3);  // 错误！
  // &42;       // 错误！

  // 右值不能出现在赋值语句左边
  // 42 = x;    // 错误！
  // (x + y) = 10;  // 错误！

  // 3. 函数返回值
  std::cout << "\n3. 函数返回值:" << std::endl;

  // 返回值是右值
  int result = getValue();
  std::cout << "getValue() = " << result << std::endl;
  // getValue() = 10;  // 错误！右值不能赋值

  // 返回引用是左值
  getReference() = 200; // 正确！返回引用是左值
  std::cout << "getReference() = " << getReference() << std::endl;

  // 4. 数组元素和指针解引用
  std::cout << "\n4. 数组和指针:" << std::endl;
  int arr[3] = {1, 2, 3};

  arr[0] = 10; // arr[0] 是左值
  std::cout << "arr[0] = " << arr[0] << std::endl;

  int *ptr = &x;
  *ptr = 50; // *ptr 是左值
  std::cout << "*ptr = " << *ptr << std::endl;

  // 5. 字符串字面量
  std::cout << "\n5. 字符串字面量:" << std::endl;
  const char *str = "Hello"; // "Hello" 是左值（特殊情况）
  std::cout << "字符串: " << str << std::endl;
  std::cout << "地址: " << static_cast<const void *>(str) << std::endl;

  // 6. 左值引用
  std::cout << "\n6. 左值引用:" << std::endl;
  int a = 100;
  int &ref = a; // 左值引用，必须绑定到左值

  ref = 150;
  std::cout << "a = " << a << " (通过引用修改)" << std::endl;

  // int& bad_ref = 42;  // 错误！不能将左值引用绑定到右值
  const int &const_ref = 42; // 正确！const左值引用可以绑定到右值
  std::cout << "const引用绑定到右值: " << const_ref << std::endl;

  // 7. 总结
  std::cout << "\n7. 左值 vs 右值:" << std::endl;
  std::cout << "左值（lvalue）:" << std::endl;
  std::cout << "  - 有名字，有地址" << std::endl;
  std::cout << "  - 可以出现在赋值语句左边" << std::endl;
  std::cout << "  - 持久存在" << std::endl;
  std::cout << "  - 例如：变量、数组元素、返回引用的函数" << std::endl;

  std::cout << "\n右值（rvalue）:" << std::endl;
  std::cout << "  - 临时值，没有地址" << std::endl;
  std::cout << "  - 不能出现在赋值语句左边" << std::endl;
  std::cout << "  - 临时存在" << std::endl;
  std::cout << "  - 例如：字面量、表达式结果、返回值的函数" << std::endl;

  return 0;
}
