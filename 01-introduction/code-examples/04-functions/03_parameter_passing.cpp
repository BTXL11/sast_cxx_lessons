#include <iostream>

// 按值传递：复制参数，不影响原始变量
void incrementByValue(int x) {
  x++;
  std::cout << "  函数内部（按值）: x = " << x << std::endl;
}

// 按引用传递：直接操作原始变量
void incrementByReference(int &x) {
  x++;
  std::cout << "  函数内部（按引用）: x = " << x << std::endl;
}

// 按指针传递：通过指针操作原始变量
void incrementByPointer(int *x) {
  (*x)++;
  std::cout << "  函数内部（按指针）: *x = " << *x << std::endl;
}

// 按const引用传递：只读，不能修改，但避免拷贝（效率高）
void printByConstReference(const int &x) {
  std::cout << "  值: " << x << std::endl;
  // x++;  // 错误！不能修改const引用
}

// 交换两个数（使用引用）
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  std::cout << "=== 参数传递方式 ===" << std::endl;

  // 按值传递
  int num1 = 5;
  std::cout << "\n按值传递:" << std::endl;
  std::cout << "调用前: num1 = " << num1 << std::endl;
  incrementByValue(num1);
  std::cout << "调用后: num1 = " << num1 << " (未改变)" << std::endl;

  // 按引用传递
  int num2 = 5;
  std::cout << "\n按引用传递:" << std::endl;
  std::cout << "调用前: num2 = " << num2 << std::endl;
  incrementByReference(num2);
  std::cout << "调用后: num2 = " << num2 << " (已改变)" << std::endl;

  // 按指针传递
  int num3 = 5;
  std::cout << "\n按指针传递:" << std::endl;
  std::cout << "调用前: num3 = " << num3 << std::endl;
  incrementByPointer(&num3);
  std::cout << "调用后: num3 = " << num3 << " (已改变)" << std::endl;

  // const引用
  int num4 = 100;
  std::cout << "\nconst引用传递:" << std::endl;
  printByConstReference(num4);

  // 交换示例
  int x = 10, y = 20;
  std::cout << "\n交换前: x = " << x << ", y = " << y << std::endl;
  swap(x, y);
  std::cout << "交换后: x = " << x << ", y = " << y << std::endl;

  return 0;
}
