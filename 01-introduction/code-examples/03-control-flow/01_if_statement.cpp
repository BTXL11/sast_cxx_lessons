#include <iostream>

int main() {
  int age = 18;
  double temperature = 25.5;
  bool hasLicense = true;

  std::cout << "=== if语句示例 ===" << std::endl;

  // 简单if语句
  if (age >= 18) {
    std::cout << "你是成年人" << std::endl;
  }

  // 多个独立的if语句
  if (temperature > 30) {
    std::cout << "天气很热" << std::endl;
  }

  if (temperature >= 20 && temperature <= 30) {
    std::cout << "天气适宜" << std::endl;
  }

  if (temperature < 20) {
    std::cout << "天气有点冷" << std::endl;
  }

  // 组合条件
  if (age >= 18 && hasLicense) {
    std::cout << "你可以开车" << std::endl;
  }

  // 单行if语句（不推荐，但合法）
  if (age >= 18)
    std::cout << "成年人（单行）" << std::endl;

  return 0;
}
