#include <iostream>

int main() {
  std::cout << "=== C风格数组示例 ===" << std::endl;

  // 声明并初始化数组
  int scores[5]; // 声明5个整数的数组

  // 逐个赋值
  scores[0] = 85;
  scores[1] = 90;
  scores[2] = 78;
  scores[3] = 92;
  scores[4] = 88;

  // 访问数组元素
  std::cout << "第一个分数: " << scores[0] << std::endl;
  std::cout << "第三个分数: " << scores[2] << std::endl;
  std::cout << "最后一个分数: " << scores[4] << std::endl;

  // 修改数组元素
  scores[2] = 95;
  std::cout << "修改后的第三个分数: " << scores[2] << std::endl;

  // 遍历数组
  std::cout << "\n所有分数: ";
  for (int i = 0; i < 5; i++) {
    std::cout << scores[i] << " ";
  }
  std::cout << std::endl;

  // 计算总分和平均分
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += scores[i];
  }
  double average = static_cast<double>(sum) / 5;
  std::cout << "总分: " << sum << std::endl;
  std::cout << "平均分: " << average << std::endl;

  return 0;
}
