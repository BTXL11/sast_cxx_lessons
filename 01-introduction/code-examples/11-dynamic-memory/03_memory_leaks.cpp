#include <iostream>

// 错误：内存泄漏
void badFunction() {
  int *ptr = new int(42);
  std::cout << "分配了内存，但忘记释放！" << std::endl;
  // 忘记delete，内存永远不会被释放
  // 这是内存泄漏！
}

// 正确：释放内存
void goodFunction() {
  int *ptr = new int(42);
  std::cout << "分配了内存: " << *ptr << std::endl;
  delete ptr; // 正确释放
  std::cout << "内存已释放" << std::endl;
}

// 错误：重复释放
void doubleFreeError() {
  int *ptr = new int(100);
  delete ptr;
  // delete ptr;  // 错误！重复释放，会导致程序崩溃
}

// 正确：释放后设为nullptr
void safeDelete() {
  int *ptr = new int(100);
  delete ptr;
  ptr = nullptr; // 安全做法

  // 可以安全地再次delete（delete nullptr是安全的）
  delete ptr;
  std::cout << "安全删除完成" << std::endl;
}

// 错误：使用已释放的内存
void useAfterFree() {
  int *ptr = new int(50);
  delete ptr;
  // std::cout << *ptr << std::endl;  // 错误！使用已释放的内存（悬空指针）
}

// 正确：使用智能指针避免内存泄漏
#include <memory>
void smartPointerExample() {
  std::unique_ptr<int> ptr(new int(42));
  std::cout << "智能指针值: " << *ptr << std::endl;
  // 不需要手动delete，智能指针会自动释放
}

int main() {
  std::cout << "=== 内存泄漏和正确做法 ===" << std::endl;

  std::cout << "\n1. 错误示例（内存泄漏）:" << std::endl;
  badFunction();
  // 内存泄漏了！

  std::cout << "\n2. 正确示例:" << std::endl;
  goodFunction();

  std::cout << "\n3. 安全删除:" << std::endl;
  safeDelete();

  std::cout << "\n4. 智能指针（推荐）:" << std::endl;
  smartPointerExample();

  std::cout << "\n5. 数组内存泄漏示例:" << std::endl;
  int *arr = new int[10];
  // delete arr;  // 错误！应该使用delete[]
  delete[] arr; // 正确
  std::cout << "数组内存正确释放" << std::endl;

  std::cout << "\n内存管理演示完成" << std::endl;

  return 0;
}
