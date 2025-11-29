#include <cstring>
#include <iostream>
#include <string>

class String {
private:
  char *data;
  size_t length;

public:
  // 构造函数
  String(const char *str = "") {
    length = strlen(str);
    data = new char[length + 1];
    strcpy(data, str);
    std::cout << "构造: \"" << data << "\"" << std::endl;
  }

  // 拷贝构造函数
  String(const String &other) {
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);
    std::cout << "拷贝构造: \"" << data << "\"" << std::endl;
  }

  // 移动构造函数（C++11）
  String(String &&other) noexcept {
    data = other.data; // 窃取资源
    length = other.length;

    other.data = nullptr; // 清空源对象
    other.length = 0;

    std::cout << "移动构造: \"" << data << "\"" << std::endl;
  }

  // 拷贝赋值运算符
  String &operator=(const String &other) {
    std::cout << "拷贝赋值: \"" << other.data << "\"" << std::endl;

    if (this != &other) {
      delete[] data;

      length = other.length;
      data = new char[length + 1];
      strcpy(data, other.data);
    }

    return *this;
  }

  // 移动赋值运算符（C++11）
  String &operator=(String &&other) noexcept {
    std::cout << "移动赋值: \"" << other.data << "\"" << std::endl;

    if (this != &other) {
      delete[] data;

      data = other.data; // 窃取资源
      length = other.length;

      other.data = nullptr; // 清空源对象
      other.length = 0;
    }

    return *this;
  }

  // 析构函数
  ~String() {
    if (data) {
      std::cout << "析构: \"" << data << "\"" << std::endl;
      delete[] data;
    } else {
      std::cout << "析构: (空)" << std::endl;
    }
  }

  const char *c_str() const { return data ? data : ""; }

  void display() const { std::cout << "\"" << c_str() << "\"" << std::endl; }
};

String createString() {
  String temp("临时字符串");
  return temp; // 返回时触发移动
}

int main() {
  std::cout << "=== 移动语义示例 ===" << std::endl;

  // 1. 拷贝 vs 移动
  std::cout << "\n1. 拷贝构造:" << std::endl;
  String s1("Hello");
  String s2 = s1; // 拷贝构造

  std::cout << "\n2. 移动构造:" << std::endl;
  String s3 = std::move(s1); // 移动构造
  std::cout << "s1: ";
  s1.display();
  std::cout << "s3: ";
  s3.display();

  // 3. 拷贝赋值 vs 移动赋值
  std::cout << "\n3. 拷贝赋值:" << std::endl;
  String s4("World");
  String s5;
  s5 = s4; // 拷贝赋值

  std::cout << "\n4. 移动赋值:" << std::endl;
  String s6;
  s6 = std::move(s4); // 移动赋值
  std::cout << "s4: ";
  s4.display();
  std::cout << "s6: ";
  s6.display();

  // 5. 函数返回值优化
  std::cout << "\n5. 函数返回值:" << std::endl;
  String s7 = createString(); // 可能触发移动或RVO
  s7.display();

  // 6. 容器中的移动
  std::cout << "\n6. 移动的性能优势:" << std::endl;
  std::cout << "拷贝：分配新内存 + 复制数据（慢）" << std::endl;
  std::cout << "移动：转移指针（快）" << std::endl;

  // 7. 五法则（Rule of Five）
  std::cout << "\n7. 五法则（C++11）:" << std::endl;
  std::cout << "1. 析构函数" << std::endl;
  std::cout << "2. 拷贝构造函数" << std::endl;
  std::cout << "3. 拷贝赋值运算符" << std::endl;
  std::cout << "4. 移动构造函数" << std::endl;
  std::cout << "5. 移动赋值运算符" << std::endl;

  std::cout << "\n程序结束，对象将被销毁:" << std::endl;
  return 0;
}
