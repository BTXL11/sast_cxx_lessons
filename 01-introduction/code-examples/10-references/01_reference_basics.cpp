#include <iostream>

int main() {
  std::cout << "=== 引用基础示例 ===" << std::endl;

  int x = 10;
  int &ref = x; // ref是x的引用（别名）

  std::cout << "x = " << x << std::endl;
  std::cout << "ref = " << ref << std::endl;

  // 通过引用修改值
  ref = 20;
  std::cout << "\n修改ref后:" << std::endl;
  std::cout << "x = " << x << std::endl;
  std::cout << "ref = " << ref << std::endl;

  // 引用和原变量的地址相同
  std::cout << "\n地址比较:" << std::endl;
  std::cout << "x的地址: " << &x << std::endl;
  std::cout << "ref的地址: " << &ref << std::endl;

  // 引用必须初始化
  // int& ref2;  // 错误！引用必须初始化

  // 引用不能重新绑定
  int y = 30;
  ref = y; // 这不是重新绑定，而是将y的值赋给x
  std::cout << "\nref = y 后:" << std::endl;
  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;
  std::cout << "ref = " << ref << std::endl;

  return 0;
}
