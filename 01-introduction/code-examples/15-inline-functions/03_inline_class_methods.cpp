#include <iostream>
#include <string>

class Point {
private:
  int x, y;

public:
  // 方法1：类内定义（隐式内联）
  Point(int xVal, int yVal) : x(xVal), y(yVal) {}

  // 类内定义的成员函数自动是内联的
  int getX() const { return x; }
  int getY() const { return y; }

  void setX(int xVal) { x = xVal; }
  void setY(int yVal) { y = yVal; }

  // 类内声明，类外定义（需要显式inline）
  void display() const;

  // 内联成员函数：计算距离原点的距离
  double distanceFromOrigin() const { return std::sqrt(x * x + y * y); }
};

// 类外定义，使用inline关键字
inline void Point::display() const {
  std::cout << "(" << x << ", " << y << ")" << std::endl;
}

class Rectangle {
private:
  int width, height;

public:
  Rectangle(int w, int h) : width(w), height(h) {}

  // 简单的getter/setter通常定义为内联
  int getWidth() const { return width; }
  int getHeight() const { return height; }

  void setWidth(int w) { width = w; }
  void setHeight(int h) { height = h; }

  // 计算面积（内联）
  int area() const { return width * height; }

  // 计算周长（内联）
  int perimeter() const { return 2 * (width + height); }

  // 判断是否为正方形（内联）
  bool isSquare() const { return width == height; }

  void display() const {
    std::cout << "矩形: " << width << "x" << height << ", 面积: " << area()
              << ", 周长: " << perimeter() << std::endl;
  }
};

int main() {
  std::cout << "=== 类成员内联函数 ===" << std::endl;

  // 1. Point类示例
  std::cout << "\n1. Point类:" << std::endl;
  Point p1(3, 4);
  std::cout << "点: ";
  p1.display();
  std::cout << "x = " << p1.getX() << ", y = " << p1.getY() << std::endl;
  std::cout << "距离原点: " << p1.distanceFromOrigin() << std::endl;

  p1.setX(5);
  p1.setY(12);
  std::cout << "\n修改后: ";
  p1.display();
  std::cout << "距离原点: " << p1.distanceFromOrigin() << std::endl;

  // 2. Rectangle类示例
  std::cout << "\n2. Rectangle类:" << std::endl;
  Rectangle rect1(10, 5);
  rect1.display();
  std::cout << "是正方形? " << (rect1.isSquare() ? "是" : "否") << std::endl;

  Rectangle rect2(8, 8);
  rect2.display();
  std::cout << "是正方形? " << (rect2.isSquare() ? "是" : "否") << std::endl;

  // 3. 性能优势
  std::cout << "\n3. 内联成员函数优势:" << std::endl;
  std::cout << "- getter/setter函数非常适合内联" << std::endl;
  std::cout << "- 避免函数调用开销" << std::endl;
  std::cout << "- 类内定义自动内联" << std::endl;

  // 4. 频繁调用
  std::cout << "\n4. 频繁调用内联函数:" << std::endl;
  int totalArea = 0;
  for (int i = 1; i <= 5; i++) {
    Rectangle r(i, i);
    totalArea += r.area(); // 内联函数，无调用开销
  }
  std::cout << "总面积: " << totalArea << std::endl;

  return 0;
}
