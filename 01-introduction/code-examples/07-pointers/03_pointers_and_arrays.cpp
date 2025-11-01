#include <iostream>

int main() {
  std::cout << "=== 指针与数组示例 ===" << std::endl;

  int numbers[5] = {10, 20, 30, 40, 50};

  // 数组名是指向第一个元素的指针
  int *ptr = numbers; // 等价于 int* ptr = &numbers[0];

  std::cout << "使用指针访问数组元素:" << std::endl;
  std::cout << "*ptr = " << *ptr << std::endl;           // 10
  std::cout << "*(ptr+1) = " << *(ptr + 1) << std::endl; // 20
  std::cout << "*(ptr+2) = " << *(ptr + 2) << std::endl; // 30
  std::cout << "*(ptr+3) = " << *(ptr + 3) << std::endl; // 40
  std::cout << "*(ptr+4) = " << *(ptr + 4) << std::endl; // 50

  // 指针算术
  std::cout << "\n指针算术:" << std::endl;
  std::cout << "ptr[0] = " << ptr[0] << std::endl; // 等价于 *ptr
  std::cout << "ptr[1] = " << ptr[1] << std::endl; // 等价于 *(ptr+1)
  std::cout << "ptr[2] = " << ptr[2] << std::endl; // 等价于 *(ptr+2)

  // 使用指针遍历数组
  std::cout << "\n使用指针遍历数组: ";
  for (int i = 0; i < 5; i++) {
    std::cout << *(ptr + i) << " ";
  }
  std::cout << std::endl;

  // 指针递增
  std::cout << "\n指针递增遍历: ";
  int *p = numbers;
  for (int i = 0; i < 5; i++) {
    std::cout << *p << " ";
    p++; // 指针移动到下一个元素
  }
  std::cout << std::endl;

  return 0;
}
