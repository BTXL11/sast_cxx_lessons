#include <iostream>
#include <string>

class Point {
private:
  const int x; // const成员必须在初始化列表中初始化
  const int y;

public:
  // 使用初始化列表
  Point(int xVal, int yVal) : x(xVal), y(yVal) {
    std::cout << "Point(" << x << ", " << y << ") 创建" << std::endl;
  }

  void display() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
  }
};

class Rectangle {
private:
  int width;
  int height;
  Point topLeft; // 成员对象

public:
  // 初始化列表：初始化成员对象
  Rectangle(int w, int h, int x, int y) : width(w), height(h), topLeft(x, y) {
    std::cout << "Rectangle 创建" << std::endl;
  }

  void display() const {
    std::cout << "矩形: " << width << "x" << height << ", 左上角: ";
    topLeft.display();
  }
};

class Counter {
private:
  int &count; // 引用成员必须在初始化列表中初始化

public:
  Counter(int &c) : count(c) {
    std::cout << "Counter 创建，绑定到计数器" << std::endl;
  }

  void increment() { count++; }

  int getValue() const { return count; }
};

int main() {
  std::cout << "=== 初始化列表示例 ===" << std::endl;

  std::cout << "\n1. const成员初始化:" << std::endl;
  Point p(10, 20);
  p.display();

  std::cout << "\n2. 成员对象初始化:" << std::endl;
  Rectangle rect(100, 50, 5, 5);
  rect.display();

  std::cout << "\n3. 引用成员初始化:" << std::endl;
  int value = 0;
  Counter counter(value);
  std::cout << "初始值: " << counter.getValue() << std::endl;
  counter.increment();
  counter.increment();
  std::cout << "递增后: " << counter.getValue() << std::endl;
  std::cout << "原始变量: " << value << std::endl;

  return 0;
}
