#include <iostream>
#include <string>

class Widget {
private:
  std::string name;

public:
  Widget(std::string n) : name(n) {
    std::cout << "Widget '" << name << "' 构造" << std::endl;
  }

  Widget(const Widget &other) : name(other.name) {
    std::cout << "Widget '" << name << "' 拷贝构造" << std::endl;
  }

  Widget &operator=(const Widget &other) {
    name = other.name;
    std::cout << "Widget '" << name << "' 拷贝赋值" << std::endl;
    return *this;
  }

  ~Widget() { std::cout << "Widget '" << name << "' 析构" << std::endl; }

  void display() const { std::cout << "Widget: " << name << std::endl; }
};

// 按值返回
Widget createWidget(std::string name) {
  Widget w(name);
  return w; // 可能触发拷贝消除（RVO - Return Value Optimization）
}

// 按值传递
void processWidget(Widget w) {
  std::cout << "处理中: ";
  w.display();
}

int main() {
  std::cout << "=== 拷贝消除示例 ===" << std::endl;

  std::cout << "\n1. 返回值优化（RVO）:" << std::endl;
  Widget w1 = createWidget("Widget1");
  // 编译器可能优化掉拷贝，直接在w1的位置构造对象

  std::cout << "\n2. 按值传递:" << std::endl;
  Widget w2("Widget2");
  processWidget(w2); // 会触发拷贝构造

  std::cout << "\n3. 临时对象:" << std::endl;
  processWidget(Widget("Temp")); // 临时对象

  std::cout << "\n4. 直接初始化 vs 拷贝初始化:" << std::endl;
  Widget w3("Widget3");          // 直接初始化
  Widget w4 = Widget("Widget4"); // 拷贝初始化（可能被优化）

  std::cout << "\n程序结束:" << std::endl;
  return 0;
}
