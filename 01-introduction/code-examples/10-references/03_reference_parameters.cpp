#include <iostream>

// 按引用传递 - 可以修改原始变量
void increment(int &x) {
  x++;
  std::cout << "  函数内: x = " << x << std::endl;
}

// 按值传递 - 不能修改原始变量
void incrementByValue(int x) {
  x++;
  std::cout << "  函数内: x = " << x << std::endl;
}

// 按const引用传递 - 不能修改，但避免拷贝
void printValue(const int &x) {
  std::cout << "  值: " << x << std::endl;
  // x++;  // 错误！不能修改const引用
}

// 交换两个数
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// 返回引用
int &getElement(int arr[], int index) { return arr[index]; }

int main() {
  std::cout << "=== 引用参数示例 ===" << std::endl;

  // 按引用传递
  int num1 = 5;
  std::cout << "按引用传递:" << std::endl;
  std::cout << "调用前: " << num1 << std::endl;
  increment(num1);
  std::cout << "调用后: " << num1 << " (已改变)" << std::endl;

  // 按值传递
  int num2 = 5;
  std::cout << "\n按值传递:" << std::endl;
  std::cout << "调用前: " << num2 << std::endl;
  incrementByValue(num2);
  std::cout << "调用后: " << num2 << " (未改变)" << std::endl;

  // const引用
  int num3 = 100;
  std::cout << "\nconst引用传递:" << std::endl;
  printValue(num3);

  // 交换
  int x = 10, y = 20;
  std::cout << "\n交换前: x = " << x << ", y = " << y << std::endl;
  swap(x, y);
  std::cout << "交换后: x = " << x << ", y = " << y << std::endl;

  // 返回引用
  int numbers[5] = {10, 20, 30, 40, 50};
  std::cout << "\n返回引用:" << std::endl;
  std::cout << "numbers[2] = " << numbers[2] << std::endl;

  getElement(numbers, 2) = 300; // 通过引用修改数组元素
  std::cout << "修改后 numbers[2] = " << numbers[2] << std::endl;

  return 0;
}
