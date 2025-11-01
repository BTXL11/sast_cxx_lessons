#include <iostream>
#include <string>

class Person {
public:
  std::string name;
  int age;

  void greet() {
    std::cout << "你好，我是 " << name << "，今年 " << age << " 岁"
              << std::endl;
  }

  void celebrateBirthday() {
    age++;
    std::cout << name << " 过生日了！现在 " << age << " 岁" << std::endl;
  }
};

int main() {
  std::cout << "=== 指向对象的指针 ===" << std::endl;

  // 创建对象
  Person person1;
  person1.name = "Alice";
  person1.age = 25;

  // 创建指向对象的指针
  Person *ptr = &person1;

  // 使用指针访问成员（使用->运算符）
  std::cout << "通过指针访问:" << std::endl;
  std::cout << "姓名: " << ptr->name << std::endl;
  std::cout << "年龄: " << ptr->age << std::endl;

  // 通过指针调用方法
  ptr->greet();
  ptr->celebrateBirthday();

  // 等价的写法（使用*解引用）
  std::cout << "\n使用解引用访问:" << std::endl;
  std::cout << "姓名: " << (*ptr).name << std::endl;
  std::cout << "年龄: " << (*ptr).age << std::endl;

  // 动态分配对象
  std::cout << "\n动态分配对象:" << std::endl;
  Person *ptr2 = new Person;
  ptr2->name = "Bob";
  ptr2->age = 30;
  ptr2->greet();

  // 释放内存
  delete ptr2;
  std::cout << "对象已删除" << std::endl;

  return 0;
}
