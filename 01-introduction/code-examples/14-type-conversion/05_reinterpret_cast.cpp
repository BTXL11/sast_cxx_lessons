#include <cstdint>
#include <iostream>

struct Data {
  int x;
  int y;
};

int main() {
  std::cout << "=== reinterpret_cast 示例 ===" << std::endl;

  // 1. 指针类型的重新解释
  std::cout << "\n1. 指针类型重新解释:" << std::endl;
  int value = 0x12345678;
  int *int_ptr = &value;

  // 将int*重新解释为char*
  char *char_ptr = reinterpret_cast<char *>(int_ptr);

  std::cout << "int值: 0x" << std::hex << value << std::dec << std::endl;
  std::cout << "按字节读取: ";
  for (size_t i = 0; i < sizeof(int); i++) {
    std::cout << "0x" << std::hex << (int)(unsigned char)char_ptr[i] << " ";
  }
  std::cout << std::dec << std::endl;

  // 2. 指针与整数之间的转换
  std::cout << "\n2. 指针与整数转换:" << std::endl;
  int x = 42;
  int *ptr = &x;

  // 指针转换为整数
  uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
  std::cout << "指针地址: 0x" << std::hex << addr << std::dec << std::endl;

  // 整数转换回指针
  int *ptr2 = reinterpret_cast<int *>(addr);
  std::cout << "恢复的指针值: " << *ptr2 << std::endl;

  // 3. 不同类型指针之间的转换
  std::cout << "\n3. 不同类型指针转换:" << std::endl;
  Data data = {10, 20};
  Data *data_ptr = &data;

  // 将Data*重新解释为int*
  int *int_array = reinterpret_cast<int *>(data_ptr);
  std::cout << "data.x = " << int_array[0] << std::endl;
  std::cout << "data.y = " << int_array[1] << std::endl;

  // 4. 函数指针转换
  std::cout << "\n4. 函数指针转换:" << std::endl;
  void (*func_ptr)() = nullptr;
  uintptr_t func_addr = reinterpret_cast<uintptr_t>(func_ptr);
  std::cout << "函数指针地址: 0x" << std::hex << func_addr << std::dec
            << std::endl;

  // 5. 引用的重新解释
  std::cout << "\n5. 引用重新解释:" << std::endl;
  int num = 65;
  int &int_ref = num;

  // 将int&重新解释为char&
  char &char_ref = reinterpret_cast<char &>(int_ref);
  std::cout << "int值: " << num << std::endl;
  std::cout << "作为char: '" << char_ref << "'" << std::endl;

  // 6. 警告：危险的使用
  std::cout << "\n6. 危险操作示例:" << std::endl;
  double d = 3.14159;
  double *d_ptr = &d;

  // 危险：将double*重新解释为int*
  int *dangerous_ptr = reinterpret_cast<int *>(d_ptr);
  std::cout << "double值: " << d << std::endl;
  std::cout << "重新解释为int: " << *dangerous_ptr << " (无意义的值)"
            << std::endl;

  // 7. 实际应用：底层内存操作
  std::cout << "\n7. 底层内存操作:" << std::endl;
  unsigned char buffer[4] = {0x12, 0x34, 0x56, 0x78};
  uint32_t *value_ptr = reinterpret_cast<uint32_t *>(buffer);

  std::cout << "字节数组: ";
  for (int i = 0; i < 4; i++) {
    std::cout << "0x" << std::hex << (int)buffer[i] << " ";
  }
  std::cout << std::dec << std::endl;
  std::cout << "作为uint32_t: 0x" << std::hex << *value_ptr << std::dec
            << std::endl;

  std::cout << "\n注意：reinterpret_cast 非常危险，只在必要时使用！"
            << std::endl;

  return 0;
}
