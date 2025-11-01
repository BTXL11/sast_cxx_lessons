#include <iostream>

// 宏定义
#define SQUARE_MACRO(x) ((x) * (x))
#define MAX_MACRO(a, b) ((a) > (b) ? (a) : (b))

// 内联函数
inline int square(int x) { return x * x; }

inline int max(int a, int b) { return (a > b) ? a : b; }

int main() {
  std::cout << "=== 内联函数 vs 宏 ===" << std::endl;

  // 1. 基本使用
  std::cout << "\n1. 基本使用:" << std::endl;
  int num = 5;
  std::cout << "宏 SQUARE_MACRO(5) = " << SQUARE_MACRO(num) << std::endl;
  std::cout << "内联 square(5) = " << square(num) << std::endl;

  // 2. 类型安全
  std::cout << "\n2. 类型安全:" << std::endl;
  double d = 3.5;
  // 宏没有类型检查
  std::cout << "宏 SQUARE_MACRO(3.5) = " << SQUARE_MACRO(d) << std::endl;
  // 内联函数有类型检查（这里会隐式转换）
  std::cout << "内联 square(3.5) = " << square(static_cast<int>(d))
            << std::endl;

  // 3. 副作用问题
  std::cout << "\n3. 副作用问题:" << std::endl;
  int x = 5;

  // 宏：表达式会被计算两次！
  std::cout << "宏 SQUARE_MACRO(x++) = " << SQUARE_MACRO(x++) << std::endl;
  std::cout << "x的值: " << x << " (x被递增了两次！)" << std::endl;

  x = 5; // 重置
  int temp = x++;
  std::cout << "内联 square(x++) = " << square(temp) << std::endl;
  std::cout << "x的值: " << x << " (x只递增一次)" << std::endl;

  // 4. 调试
  std::cout << "\n4. 调试优势:" << std::endl;
  std::cout << "- 内联函数可以设置断点" << std::endl;
  std::cout << "- 内联函数有作用域" << std::endl;
  std::cout << "- 内联函数有类型检查" << std::endl;

  // 5. 宏的问题示例
  std::cout << "\n5. 宏的常见陷阱:" << std::endl;
  int a = 3, b = 4;

  // 如果宏定义不当：#define MAX_BAD(a,b) a > b ? a : b
  // 使用时可能出错：int result = MAX_BAD(a, b) + 1;
  // 展开为：int result = a > b ? a : b + 1;  // 错误！

  std::cout << "MAX_MACRO(3, 4) = " << MAX_MACRO(a, b) << std::endl;
  std::cout << "max(3, 4) = " << max(a, b) << std::endl;

  // 6. 内联函数的优势总结
  std::cout << "\n6. 内联函数优势:" << std::endl;
  std::cout << "✓ 类型安全" << std::endl;
  std::cout << "✓ 无副作用问题" << std::endl;
  std::cout << "✓ 可调试" << std::endl;
  std::cout << "✓ 有作用域" << std::endl;
  std::cout << "✓ 可以是类成员" << std::endl;

  std::cout << "\n7. 宏的优势:" << std::endl;
  std::cout << "✓ 可以用于任何类型（模板出现前）" << std::endl;
  std::cout << "✓ 可以进行文本替换" << std::endl;
  std::cout << "✓ 条件编译" << std::endl;

  return 0;
}
