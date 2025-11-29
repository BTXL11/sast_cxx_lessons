#include <iostream>
#include <string>

class Student {
private:
  std::string name;
  int age;
  double gpa;

public:
  // 1. 默认构造函数
  Student() : name("Unknown"), age(0), gpa(0.0) {
    std::cout << "默认构造函数调用" << std::endl;
  }

  // 2. 带参数的构造函数
  Student(std::string n, int a, double g) : name(n), age(a), gpa(g) {
    std::cout << "带参数构造函数调用: " << name << std::endl;
  }

  // 3. 拷贝构造函数
  Student(const Student &other)
      : name(other.name), age(other.age), gpa(other.gpa) {
    std::cout << "拷贝构造函数调用: " << name << std::endl;
  }

  // 4. 委托构造函数（C++11）
  Student(std::string n) : Student(n, 18, 0.0) {
    std::cout << "委托构造函数调用" << std::endl;
  }

  void display() const {
    std::cout << "学生: " << name << ", 年龄: " << age << ", GPA: " << gpa
              << std::endl;
  }

  ~Student() { std::cout << "析构函数调用: " << name << std::endl; }
};

int main() {
  std::cout << "=== 构造函数类型示例 ===" << std::endl;

  std::cout << "\n1. 默认构造函数:" << std::endl;
  Student s1;
  s1.display();

  std::cout << "\n2. 带参数构造函数:" << std::endl;
  Student s2("Alice", 20, 3.8);
  s2.display();

  std::cout << "\n3. 拷贝构造函数:" << std::endl;
  Student s3 = s2; // 或 Student s3(s2);
  s3.display();

  std::cout << "\n4. 委托构造函数:" << std::endl;
  Student s4("Bob");
  s4.display();

  std::cout << "\n程序结束，对象将被销毁:" << std::endl;
  return 0;
}
