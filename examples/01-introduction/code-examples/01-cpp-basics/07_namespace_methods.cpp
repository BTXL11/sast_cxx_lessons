#include <iostream>
#include <string>

// 方法1：使用std::前缀（最安全）
void method1() {
  std::cout << "方法1：使用std::前缀" << std::endl;
  std::string name = "Alice";
  std::cout << "姓名: " << name << std::endl;
}

// 方法2：使用using声明
void method2() {
  using std::cout;
  using std::endl;
  using std::string;

  cout << "方法2：使用using声明" << endl;
  string name = "Bob";
  cout << "姓名: " << name << endl;
}

// 方法3：using namespace（仅在小程序中使用）
void method3() {
  using namespace std;

  cout << "方法3：using namespace" << endl;
  string name = "Charlie";
  cout << "姓名: " << name << endl;
}

int main() {
  method1();
  std::cout << std::endl;

  method2();
  std::cout << std::endl;

  method3();

  return 0;
}
