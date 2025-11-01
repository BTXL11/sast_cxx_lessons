#include <iostream>
#include <memory>
#include <string>

class Person {
public:
  std::string name;
  int age;

  Person(std::string n, int a) : name(n), age(a) {
    std::cout << "Person " << name << " 创建" << std::endl;
  }

  ~Person() { std::cout << "Person " << name << " 销毁" << std::endl; }

  void greet() {
    std::cout << "你好，我是 " << name << "，" << age << " 岁" << std::endl;
  }
};

int main() {
  std::cout << "=== 智能指针示例 ===" << std::endl;

  // 1. unique_ptr - 独占所有权
  std::cout << "\n1. unique_ptr:" << std::endl;
  {
    std::unique_ptr<Person> p1(new Person("Alice", 25));
    p1->greet();

    // 更好的写法（C++14）
    auto p2 = std::make_unique<Person>("Bob", 30);
    p2->greet();

    // unique_ptr不能拷贝
    // std::unique_ptr<Person> p3 = p1;  // 错误！

    // 但可以移动
    std::unique_ptr<Person> p3 = std::move(p1);
    if (p1 == nullptr) {
      std::cout << "p1 现在是空指针" << std::endl;
    }
    p3->greet();

    std::cout << "离开作用域..." << std::endl;
  } // p2和p3自动销毁，内存自动释放

  // 2. shared_ptr - 共享所有权
  std::cout << "\n2. shared_ptr:" << std::endl;
  {
    std::shared_ptr<Person> sp1 = std::make_shared<Person>("Charlie", 35);
    std::cout << "引用计数: " << sp1.use_count() << std::endl;

    {
      std::shared_ptr<Person> sp2 = sp1; // 可以拷贝
      std::cout << "引用计数: " << sp1.use_count() << std::endl;
      sp2->greet();

      std::shared_ptr<Person> sp3 = sp1;
      std::cout << "引用计数: " << sp1.use_count() << std::endl;

      std::cout << "离开内层作用域..." << std::endl;
    } // sp2和sp3销毁，引用计数减少

    std::cout << "引用计数: " << sp1.use_count() << std::endl;
    std::cout << "离开外层作用域..." << std::endl;
  } // sp1销毁，引用计数为0，对象被删除

  // 3. weak_ptr - 弱引用
  std::cout << "\n3. weak_ptr:" << std::endl;
  {
    std::shared_ptr<Person> sp = std::make_shared<Person>("David", 40);
    std::weak_ptr<Person> wp = sp; // 弱引用，不增加引用计数

    std::cout << "shared_ptr引用计数: " << sp.use_count() << std::endl;
    std::cout << "weak_ptr过期? " << (wp.expired() ? "是" : "否") << std::endl;

    // 使用weak_ptr
    if (auto locked = wp.lock()) { // 转换为shared_ptr
      locked->greet();
    }

    sp.reset(); // 释放shared_ptr
    std::cout << "shared_ptr释放后，weak_ptr过期? "
              << (wp.expired() ? "是" : "否") << std::endl;
  }

  std::cout << "\n智能指针演示完成" << std::endl;

  return 0;
}
