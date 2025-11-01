#include <iostream>
#include <string>

class Animal {
public:
  virtual void makeSound() { std::cout << "动物发出声音" << std::endl; }
  virtual ~Animal() {}
};

class Dog : public Animal {
public:
  void makeSound() override { std::cout << "汪汪汪！" << std::endl; }

  void fetch() { std::cout << "狗在捡球" << std::endl; }
};

class Cat : public Animal {
public:
  void makeSound() override { std::cout << "喵喵喵！" << std::endl; }

  void climb() { std::cout << "猫在爬树" << std::endl; }
};

int main() {
  std::cout << "=== dynamic_cast 示例 ===" << std::endl;

  // 1. 向上转换（总是安全的）
  std::cout << "\n1. 向上转换:" << std::endl;
  Dog dog;
  Animal *animal_ptr = &dog;
  animal_ptr->makeSound();

  // 2. 向下转换（需要运行时检查）
  std::cout << "\n2. 安全的向下转换:" << std::endl;
  Animal *animal1 = new Dog();
  Dog *dog_ptr = dynamic_cast<Dog *>(animal1);

  if (dog_ptr != nullptr) {
    std::cout << "转换成功！" << std::endl;
    dog_ptr->makeSound();
    dog_ptr->fetch();
  } else {
    std::cout << "转换失败！" << std::endl;
  }

  // 3. 失败的向下转换
  std::cout << "\n3. 失败的向下转换:" << std::endl;
  Animal *animal2 = new Cat();
  Dog *dog_ptr2 = dynamic_cast<Dog *>(animal2);

  if (dog_ptr2 != nullptr) {
    std::cout << "转换成功！" << std::endl;
    dog_ptr2->fetch();
  } else {
    std::cout << "转换失败！animal2 不是 Dog 类型" << std::endl;
  }

  // 正确的转换
  Cat *cat_ptr = dynamic_cast<Cat *>(animal2);
  if (cat_ptr != nullptr) {
    std::cout << "正确转换为 Cat！" << std::endl;
    cat_ptr->makeSound();
    cat_ptr->climb();
  }

  // 4. 引用的 dynamic_cast
  std::cout << "\n4. 引用的 dynamic_cast:" << std::endl;
  Dog dog2;
  Animal &animal_ref = dog2;

  try {
    Dog &dog_ref = dynamic_cast<Dog &>(animal_ref);
    std::cout << "引用转换成功！" << std::endl;
    dog_ref.fetch();
  } catch (std::bad_cast &e) {
    std::cout << "引用转换失败: " << e.what() << std::endl;
  }

  // 5. 类型识别
  std::cout << "\n5. 运行时类型识别:" << std::endl;
  Animal *animals[] = {new Dog(), new Cat(), new Dog()};

  for (int i = 0; i < 3; i++) {
    std::cout << "动物 " << i << ": ";

    if (dynamic_cast<Dog *>(animals[i])) {
      std::cout << "是狗" << std::endl;
    } else if (dynamic_cast<Cat *>(animals[i])) {
      std::cout << "是猫" << std::endl;
    } else {
      std::cout << "未知类型" << std::endl;
    }
  }

  // 清理
  delete animal1;
  delete animal2;
  for (int i = 0; i < 3; i++) {
    delete animals[i];
  }

  return 0;
}
