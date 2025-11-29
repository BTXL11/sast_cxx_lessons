#include <iostream>
#include <string>
#include <vector>

// 接受左值引用
void processLvalue(int &x) {
  std::cout << "处理左值: " << x << std::endl;
  x *= 2;
}

// 接受右值引用（C++11）
void processRvalue(int &&x) {
  std::cout << "处理右值: " << x << std::endl;
  x *= 2;
}

// 函数重载：左值和右值
void process(int &x) { std::cout << "左值版本: " << x << std::endl; }

void process(int &&x) { std::cout << "右值版本: " << x << std::endl; }

int main() {
  std::cout << "=== 右值引用（C++11）===" << std::endl;

  // 1. 左值引用 vs 右值引用
  std::cout << "\n1. 左值引用 vs 右值引用:" << std::endl;
  int x = 10;

  int &lref = x;   // 左值引用，绑定到左值
  int &&rref = 20; // 右值引用，绑定到右值

  std::cout << "左值引用: " << lref << std::endl;
  std::cout << "右值引用: " << rref << std::endl;

  // 右值引用本身是左值！
  rref = 30;
  std::cout << "修改右值引用: " << rref << std::endl;

  // 2. 函数重载
  std::cout << "\n2. 函数重载:" << std::endl;
  int a = 100;
  process(a);   // 调用左值版本
  process(200); // 调用右值版本

  // 3. std::move - 将左值转换为右值
  std::cout << "\n3. std::move:" << std::endl;
  int b = 50;
  std::cout << "b = " << b << std::endl;

  process(b);            // 左值版本
  process(std::move(b)); // 右值版本（强制转换为右值）

  std::cout << "移动后 b = " << b << " (值仍然存在)" << std::endl;

  // 4. 移动语义示例
  std::cout << "\n4. 移动语义:" << std::endl;
  std::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::cout << "vec1 大小: " << vec1.size() << std::endl;

  // 移动而不是拷贝
  std::vector<int> vec2 = std::move(vec1);
  std::cout << "移动后 vec1 大小: " << vec1.size() << std::endl;
  std::cout << "vec2 大小: " << vec2.size() << std::endl;

  // 5. 字符串移动
  std::cout << "\n5. 字符串移动:" << std::endl;
  std::string str1 = "Hello, World!";
  std::cout << "str1: " << str1 << std::endl;

  std::string str2 = std::move(str1);
  std::cout << "移动后 str1: \"" << str1 << "\"" << std::endl;
  std::cout << "str2: " << str2 << std::endl;

  // 6. 完美转发
  std::cout << "\n6. 万能引用（转发引用）:" << std::endl;
  int c = 42;

  // T&& 在模板中是万能引用
  auto &&uref1 = c;   // 左值，推导为 int&
  auto &&uref2 = 100; // 右值，推导为 int&&

  std::cout << "uref1: " << uref1 << std::endl;
  std::cout << "uref2: " << uref2 << std::endl;

  // 7. 右值引用的优势
  std::cout << "\n7. 右值引用优势:" << std::endl;
  std::cout << "- 避免不必要的拷贝" << std::endl;
  std::cout << "- 实现移动语义" << std::endl;
  std::cout << "- 提高性能" << std::endl;
  std::cout << "- 完美转发" << std::endl;

  return 0;
}
