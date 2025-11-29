#include <iostream>

int main() {
  std::cout << "=== 动态数组示例 ===" << std::endl;

  // 动态分配数组
  int size = 5;
  int *arr = new int[size];

  // 填充数组
  std::cout << "填充数组:" << std::endl;
  for (int i = 0; i < size; i++) {
    arr[i] = (i + 1) * 10;
    std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
  }

  // 打印数组
  std::cout << "\n数组内容: ";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  // 修改数组
  arr[2] = 999;
  std::cout << "修改 arr[2] 后: ";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  // 释放数组内存（注意使用delete[]）
  delete[] arr;
  std::cout << "\n数组内存已释放" << std::endl;

  // 动态分配并初始化
  int *arr2 = new int[3]{10, 20, 30}; // C++11
  std::cout << "\n初始化的动态数组: ";
  for (int i = 0; i < 3; i++) {
    std::cout << arr2[i] << " ";
  }
  std::cout << std::endl;
  delete[] arr2;

  // 二维动态数组
  std::cout << "\n二维动态数组:" << std::endl;
  int rows = 3, cols = 4;
  int **matrix = new int *[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
  }

  // 填充二维数组
  int value = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = value++;
    }
  }

  // 打印二维数组
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << matrix[i][j] << "\t";
    }
    std::cout << std::endl;
  }

  // 释放二维数组
  for (int i = 0; i < rows; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
  std::cout << "\n二维数组内存已释放" << std::endl;

  return 0;
}
