#include <iostream>

int main() {
  std::cout << "=== 指针语法示例 ===" << std::endl;

  int x = 10;
  int y = 20;

  // 声明并初始化指针
  int *ptr1 = &x; // ptr1 指向 x
  int *ptr2 = &y; // ptr2 指向 y

  std::cout << "ptr1 指向的值: " << *ptr1 << std::endl;
  std::cout << "ptr2 指向的值: " << *ptr2 << std::endl;

  // 通过指针修改值
  *ptr1 = 100;
  std::cout << "\n修改后 x = " << x << std::endl;

  // 改变指针指向
  ptr1 = &y; // 现在ptr1指向y
  std::cout << "ptr1 现在指向 y: " << *ptr1 << std::endl;

  // 空指针
  int *ptr3 = nullptr; // C++11推荐使用nullptr
  // int* ptr4 = NULL;   // 旧式写法
  // int* ptr5 = 0;      // 更旧的写法

  if (ptr3 == nullptr) {
    std::cout << "\nptr3 是空指针" << std::endl;
  }

  // 指针的指针
  int **pptr = &ptr2; // pptr 指向 ptr2
  std::cout << "\n指针的指针:" << std::endl;
  std::cout << "**pptr = " << **pptr << std::endl; // 通过pptr访问y的值

  return 0;
}
