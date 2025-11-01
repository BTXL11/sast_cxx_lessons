#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << "=== 基于范围的for循环 ===" << std::endl;

  // 遍历数组
  int numbers[] = {1, 2, 3, 4, 5};
  std::cout << "数组元素: ";
  for (int num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // 遍历vector
  std::vector<std::string> fruits = {"苹果", "香蕉", "橙子"};
  std::cout << "\n水果列表:" << std::endl;
  for (std::string fruit : fruits) {
    std::cout << "- " << fruit << std::endl;
  }

  // 使用引用修改元素
  int scores[] = {85, 90, 78, 92, 88};
  std::cout << "\n原始分数: ";
  for (int score : scores) {
    std::cout << score << " ";
  }
  std::cout << std::endl;

  // 给每个分数加5分
  for (int &score : scores) { // 注意：使用引用&
    score += 5;
  }

  std::cout << "加分后: ";
  for (int score : scores) {
    std::cout << score << " ";
  }
  std::cout << std::endl;

  // 使用const引用（只读，效率高）
  std::vector<std::string> cities = {"北京", "上海", "广州", "深圳"};
  std::cout << "\n城市列表:" << std::endl;
  for (const std::string &city : cities) { // const引用，避免拷贝
    std::cout << "城市: " << city << std::endl;
  }

  // 使用auto自动推导类型
  std::cout << "\n使用auto:" << std::endl;
  for (auto num : numbers) { // auto自动推导为int
    std::cout << num * 2 << " ";
  }
  std::cout << std::endl;

  return 0;
}
