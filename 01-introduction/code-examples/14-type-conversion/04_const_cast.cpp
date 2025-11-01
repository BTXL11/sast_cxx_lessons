#include <iostream>

void printValue(const int *ptr) { std::cout << "值: " << *ptr << std::endl; }

void modifyValue(int *ptr) {
  *ptr = 100;
  std::cout << "值已修改为: " << *ptr << std::endl;
}

class Data {
private:
  mutable int cache;
  int value;

public:
  Data(int v) : value(v), cache(-1) {}

  // const成员函数，但需要修改mutable成员
  int getValue() const {
    if (cache == -1) {
      cache = value * 2; // 计算并缓存
      std::cout << "计算缓存..." << std::endl;
    }
    return cache;
  }

  void setValue(int v) {
    value = v;
    cache = -1; // 清除缓存
  }
};

int main() {
  std::cout << "=== const_cast 示例 ===" << std::endl;

  // 1. 移除const限定符
  std::cout << "\n1. 移除const限定符:" << std::endl;
  const int value = 42;
  const int *const_ptr = &value;

  std::cout << "const指针: ";
  printValue(const_ptr);

  // 使用const_cast移除const
  int *non_const_ptr = const_cast<int *>(const_ptr);
  // 注意：修改原本是const的变量是未定义行为！
  // *non_const_ptr = 100;  // 危险！不要这样做

  // 2. 安全的使用场景
  std::cout << "\n2. 安全的使用场景:" << std::endl;
  int normal_value = 50;
  const int *const_ptr2 = &normal_value;

  std::cout << "原始值: " << normal_value << std::endl;

  // 移除const并修改（安全，因为原始变量不是const）
  int *modifiable_ptr = const_cast<int *>(const_ptr2);
  modifyValue(modifiable_ptr);

  std::cout << "修改后: " << normal_value << std::endl;

  // 3. 添加const限定符
  std::cout << "\n3. 添加const限定符:" << std::endl;
  int x = 10;
  int *ptr = &x;
  const int *const_ptr3 = const_cast<const int *>(ptr);
  std::cout << "添加const后: " << *const_ptr3 << std::endl;

  // 4. const成员函数中的应用
  std::cout << "\n4. const对象:" << std::endl;
  const Data data(20);
  std::cout << "第一次调用: " << data.getValue() << std::endl;
  std::cout << "第二次调用: " << data.getValue() << std::endl;

  // 5. 函数重载中的const_cast
  std::cout << "\n5. 避免代码重复:" << std::endl;
  int arr[] = {1, 2, 3, 4, 5};
  const int *const_arr = arr;

  // 非const版本
  int *result1 = arr;
  std::cout << "非const数组: " << result1[0] << std::endl;

  // const版本
  const int *result2 = const_arr;
  std::cout << "const数组: " << result2[0] << std::endl;

  // 6. 警告示例
  std::cout << "\n6. 危险操作警告:" << std::endl;
  const char *literal = "Hello"; // 字符串字面量
  // char* bad_ptr = const_cast<char*>(literal);
  // bad_ptr[0] = 'h';  // 危险！可能导致程序崩溃

  std::cout << "字符串字面量: " << literal << std::endl;
  std::cout << "不要尝试修改字符串字面量！" << std::endl;

  return 0;
}
