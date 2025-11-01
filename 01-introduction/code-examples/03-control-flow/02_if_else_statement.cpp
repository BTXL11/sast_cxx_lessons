#include <iostream>

int main() {
  int score = 75;
  int age = 16;

  std::cout << "=== if-else语句示例 ===" << std::endl;

  // 简单if-else
  std::cout << "分数: " << score << std::endl;
  if (score >= 60) {
    std::cout << "及格" << std::endl;
  } else {
    std::cout << "不及格" << std::endl;
  }

  // if-else if-else链
  std::cout << "\n成绩等级: ";
  if (score >= 90) {
    std::cout << "A (优秀)" << std::endl;
  } else if (score >= 80) {
    std::cout << "B (良好)" << std::endl;
  } else if (score >= 70) {
    std::cout << "C (中等)" << std::endl;
  } else if (score >= 60) {
    std::cout << "D (及格)" << std::endl;
  } else {
    std::cout << "F (不及格)" << std::endl;
  }

  // 嵌套if-else
  std::cout << "\n年龄: " << age << std::endl;
  if (age >= 18) {
    if (age >= 65) {
      std::cout << "老年人" << std::endl;
    } else {
      std::cout << "成年人" << std::endl;
    }
  } else {
    if (age >= 13) {
      std::cout << "青少年" << std::endl;
    } else {
      std::cout << "儿童" << std::endl;
    }
  }

  return 0;
}
