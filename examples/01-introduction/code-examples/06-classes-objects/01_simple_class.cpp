#include <iostream>
#include <string>

// 类定义
class Student {
public: // 公有成员，可以从类外部访问
  // 成员变量（属性）
  std::string name;
  int age;
  double gpa;

  // 成员函数（方法）
  void displayInfo() {
    std::cout << "=== 学生信息 ===" << std::endl;
    std::cout << "姓名: " << name << std::endl;
    std::cout << "年龄: " << age << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
  }

  // 另一个成员函数
  void study(std::string subject) {
    std::cout << name << " 正在学习 " << subject << std::endl;
  }

  // 判断是否优秀
  bool isExcellent() { return gpa >= 3.5; }
};

int main() {
  std::cout << "=== 类和对象示例 ===" << std::endl;

  // 创建对象（实例化）
  Student student1;

  // 设置对象的属性
  student1.name = "Alice";
  student1.age = 20;
  student1.gpa = 3.8;

  // 调用对象的方法
  student1.displayInfo();
  student1.study("C++编程");

  if (student1.isExcellent()) {
    std::cout << student1.name << " 是优秀学生！" << std::endl;
  }

  std::cout << std::endl;

  // 创建第二个对象
  Student student2;
  student2.name = "Bob";
  student2.age = 21;
  student2.gpa = 3.2;

  student2.displayInfo();
  student2.study("数据结构");

  if (!student2.isExcellent()) {
    std::cout << student2.name << " 需要继续努力！" << std::endl;
  }

  return 0;
}
