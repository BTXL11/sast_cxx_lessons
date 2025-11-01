#include <iostream>
#include <string>

class Rectangle {
private:
  double width;
  double height;
  std::string name;

public:
  // 构造函数 - 使用初始化列表
  Rectangle(double w, double h, std::string n) : width(w), height(h), name(n) {
    std::cout << "矩形 '" << name << "' 已创建 (" << width << "x" << height
              << ")" << std::endl;
  }

  // 析构函数 - 对象销毁时自动调用
  ~Rectangle() { std::cout << "矩形 '" << name << "' 已销毁" << std::endl; }

  double getArea() const { return width * height; }

  void display() const {
    std::cout << "矩形 '" << name << "': " << width << "x" << height
              << ", 面积: " << getArea() << std::endl;
  }
};

int main() {
  std::cout << "=== 构造函数和析构函数示例 ===" << std::endl;
  std::cout << "\n创建对象:" << std::endl;

  Rectangle rect1(5.0, 3.0, "矩形1");
  rect1.display();

  {
    std::cout << "\n进入代码块，创建临时对象:" << std::endl;
    Rectangle rect2(4.0, 4.0, "矩形2");
    rect2.display();
    std::cout << "离开代码块..." << std::endl;
  } // rect2在这里被销毁

  std::cout << "\n继续主程序..." << std::endl;
  rect1.display();

  std::cout << "\nmain函数即将结束..." << std::endl;
  return 0;
} // rect1在这里被销毁
