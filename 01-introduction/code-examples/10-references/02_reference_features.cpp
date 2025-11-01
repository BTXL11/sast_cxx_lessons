#include <iostream>

int main() {
  std::cout << "=== 引用特性示例 ===" << std::endl;

  // 1. 必须初始化
  int value = 10;
  int &goodRef = value; // 正确
  // int& badRef;  // 错误！引用必须初始化

  std::cout << "goodRef = " << goodRef << std::endl;

  // 2. 不可重绑定
  int alice = 25;
  int bob = 30;
  int &ref = alice;

  std::cout << "\n初始: ref = " << ref << " (绑定到alice)" << std::endl;

  ref = bob; // 这不是重新绑定，而是将bob的值赋给alice
  std::cout << "ref = bob 后:" << std::endl;
  std::cout << "  alice = " << alice << std::endl;
  std::cout << "  bob = " << bob << std::endl;
  std::cout << "  ref = " << ref << std::endl;

  // 3. 引用和原变量共享地址
  int x = 100;
  int &refX = x;

  std::cout << "\n地址比较:" << std::endl;
  std::cout << "x的地址: " << &x << std::endl;
  std::cout << "refX的地址: " << &refX << std::endl;
  std::cout << "地址相同: " << (&x == &refX ? "是" : "否") << std::endl;

  // 4. const引用
  const int &constRef = x;
  std::cout << "\nconst引用: " << constRef << std::endl;
  // constRef = 200;  // 错误！不能通过const引用修改值

  // 5. 引用数组
  int arr[3] = {1, 2, 3};
  int &ref0 = arr[0];
  int &ref1 = arr[1];
  int &ref2 = arr[2];

  std::cout << "\n引用数组元素:" << std::endl;
  std::cout << "ref0 = " << ref0 << std::endl;
  std::cout << "ref1 = " << ref1 << std::endl;
  std::cout << "ref2 = " << ref2 << std::endl;

  ref0 = 10;
  ref1 = 20;
  ref2 = 30;

  std::cout << "修改后数组: ";
  for (int i = 0; i < 3; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
