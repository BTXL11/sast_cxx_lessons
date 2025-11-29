#include <cstring>
#include <iostream>

// 浅拷贝示例（有问题）
class ShallowArray {
private:
  int *data;
  int size;

public:
  ShallowArray(int s) : size(s) {
    data = new int[size];
    std::cout << "ShallowArray 创建，大小: " << size << std::endl;
  }

  // 默认拷贝构造函数（浅拷贝）
  // ShallowArray(const ShallowArray& other) : data(other.data),
  // size(other.size) {}

  ~ShallowArray() {
    delete[] data;
    std::cout << "ShallowArray 销毁" << std::endl;
  }

  void set(int index, int value) { data[index] = value; }

  int get(int index) const { return data[index]; }
};

// 深拷贝示例（正确）
class DeepArray {
private:
  int *data;
  int size;

public:
  DeepArray(int s) : size(s) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = 0;
    }
    std::cout << "DeepArray 创建，大小: " << size << std::endl;
  }

  // 深拷贝构造函数
  DeepArray(const DeepArray &other) : size(other.size) {
    data = new int[size]; // 分配新内存
    for (int i = 0; i < size; i++) {
      data[i] = other.data[i]; // 拷贝数据
    }
    std::cout << "DeepArray 拷贝构造" << std::endl;
  }

  // 深拷贝赋值运算符
  DeepArray &operator=(const DeepArray &other) {
    if (this != &other) { // 防止自我赋值
      delete[] data;      // 释放旧内存
      size = other.size;
      data = new int[size]; // 分配新内存
      for (int i = 0; i < size; i++) {
        data[i] = other.data[i]; // 拷贝数据
      }
      std::cout << "DeepArray 拷贝赋值" << std::endl;
    }
    return *this;
  }

  ~DeepArray() {
    delete[] data;
    std::cout << "DeepArray 销毁" << std::endl;
  }

  void set(int index, int value) { data[index] = value; }

  int get(int index) const { return data[index]; }

  void display() const {
    std::cout << "数组: ";
    for (int i = 0; i < size; i++) {
      std::cout << data[i] << " ";
    }
    std::cout << std::endl;
  }
};

int main() {
  std::cout << "=== 浅拷贝 vs 深拷贝 ===" << std::endl;

  std::cout << "\n深拷贝示例:" << std::endl;
  {
    DeepArray arr1(5);
    arr1.set(0, 10);
    arr1.set(1, 20);
    arr1.set(2, 30);

    std::cout << "arr1: ";
    arr1.display();

    // 拷贝构造
    DeepArray arr2 = arr1;
    std::cout << "arr2 (拷贝自arr1): ";
    arr2.display();

    // 修改arr2不影响arr1
    arr2.set(0, 999);
    std::cout << "\n修改arr2后:" << std::endl;
    std::cout << "arr1: ";
    arr1.display();
    std::cout << "arr2: ";
    arr2.display();

    // 拷贝赋值
    DeepArray arr3(3);
    arr3 = arr1;
    std::cout << "\narr3 (赋值自arr1): ";
    arr3.display();

    std::cout << "\n离开作用域..." << std::endl;
  }

  std::cout << "\n程序结束" << std::endl;

  return 0;
}
