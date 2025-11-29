#include <iostream>

int main() {
  std::cout << "=== new和delete示例 ===" << std::endl;

  // 动态分配单个整数
  int *ptr = new int;
  *ptr = 42;
  std::cout << "动态分配的整数: " << *ptr << std::endl;
  delete ptr; // 释放内存

  // 动态分配并初始化
  int *ptr2 = new int(100);
  std::cout << "初始化的整数: " << *ptr2 << std::endl;
  delete ptr2;

  // 动态分配数组
  int size = 5;
  int *arr = new int[size];

  // 填充数组
  for (int i = 0; i < size; i++) {
    arr[i] = i * 10;
  }

  // 打印数组
  std::cout << "动态数组: ";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  delete[] arr; // 释放数组内存（注意使用delete[]）

  // 动态分配对象
  struct Point {
    int x, y;
    void display() { std::cout << "(" << x << ", " << y << ")" << std::endl; }
  };

  Point *p = new Point{10, 20};
  std::cout << "动态分配的Point: ";
  p->display();
  delete p;

  std::cout << "内存已释放" << std::endl;

  return 0;
}
