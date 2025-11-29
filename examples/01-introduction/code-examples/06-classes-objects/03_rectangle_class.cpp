#include <iostream>
#include <string>

// 矩形类
class Rectangle {
public:
  double width;
  double height;

  // 计算面积
  double getArea() { return width * height; }

  // 计算周长
  double getPerimeter() { return 2 * (width + height); }

  // 判断是否为正方形
  bool isSquare() { return width == height; }

  // 显示信息
  void display() {
    std::cout << "矩形: " << width << " x " << height << std::endl;
    std::cout << "  面积: " << getArea() << std::endl;
    std::cout << "  周长: " << getPerimeter() << std::endl;
    std::cout << "  是否为正方形: " << (isSquare() ? "是" : "否") << std::endl;
  }
};

int main() {
  std::cout << "=== 矩形类示例 ===" << std::endl;

  Rectangle rect1;
  rect1.width = 5.0;
  rect1.height = 3.0;

  std::cout << "\n矩形1:" << std::endl;
  rect1.display();

  Rectangle rect2;
  rect2.width = 4.0;
  rect2.height = 4.0;

  std::cout << "\n矩形2:" << std::endl;
  rect2.display();

  return 0;
}
