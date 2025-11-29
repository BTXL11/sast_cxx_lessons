#include <cstring>
#include <iostream>

// 三法则（Rule of Three）：
// 如果一个类需要自定义以下三者之一，通常需要自定义全部三个：
// 1. 析构函数
// 2. 拷贝构造函数
// 3. 拷贝赋值运算符

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
    std::cout << "String 创建: \"" << data << "\"" << std::endl;
  }

  // 1. 析构函数
  ~String() {
    std::cout << "String 销毁: \"" << data << "\"" << std::endl;
    delete[] data;
  }

  // 2. 拷贝构造函数
  String(const String &other) {
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);
    std::cout << "String 拷贝构造: \"" << data << "\"" << std::endl;
  }

  // 3. 拷贝赋值运算符
  String &operator=(const String &other) {
    std::cout << "String 拷贝赋值: \"" << other.data << "\"" << std::endl;

    if (this != &other) { // 防止自我赋值
      // 释放旧资源
      delete[] data;

      // 拷贝新资源
      length = other.length;
      data = new char[length + 1];
      strcpy(data, other.data);
    }

    return *this;
  }

  // 辅助函数
  const char *c_str() const { return data; }

  size_t size() const { return length; }

  void display() const {
    std::cout << "\"" << data << "\" (长度: " << length << ")" << std::endl;
  }
};

int main() {
  std::cout << "=== 三法则示例 ===" << std::endl;

  std::cout << "\n1. 创建对象:" << std::endl;
  String s1("Hello");
  s1.display();

  std::cout << "\n2. 拷贝构造:" << std::endl;
  String s2 = s1;
  s2.display();

  std::cout << "\n3. 拷贝赋值:" << std::endl;
  String s3("World");
  s3.display();
  s3 = s1;
  s3.display();

  std::cout << "\n4. 自我赋值测试:" << std::endl;
  s1 = s1;
  s1.display();

  std::cout << "\n5. 链式赋值:" << std::endl;
  String s4, s5;
  s5 = s4 = s1;
  s4.display();
  s5.display();

  std::cout << "\n程序结束，对象将被销毁:" << std::endl;
  return 0;
}
