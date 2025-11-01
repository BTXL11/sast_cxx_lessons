#include <iostream>

int main() {
  int day = 3;
  char grade = 'B';
  int choice = 2;

  std::cout << "=== switch语句示例 ===" << std::endl;

  // 基本switch语句
  std::cout << "今天是: ";
  switch (day) {
  case 1:
    std::cout << "星期一" << std::endl;
    break;
  case 2:
    std::cout << "星期二" << std::endl;
    break;
  case 3:
    std::cout << "星期三" << std::endl;
    break;
  case 4:
    std::cout << "星期四" << std::endl;
    break;
  case 5:
    std::cout << "星期五" << std::endl;
    break;
  case 6:
  case 7:
    std::cout << "周末" << std::endl;
    break;
  default:
    std::cout << "无效的日期" << std::endl;
  }

  // 字符switch
  std::cout << "\n成绩等级: ";
  switch (grade) {
  case 'A':
    std::cout << "优秀 (90-100)" << std::endl;
    break;
  case 'B':
    std::cout << "良好 (80-89)" << std::endl;
    break;
  case 'C':
    std::cout << "中等 (70-79)" << std::endl;
    break;
  case 'D':
    std::cout << "及格 (60-69)" << std::endl;
    break;
  case 'F':
    std::cout << "不及格 (<60)" << std::endl;
    break;
  default:
    std::cout << "无效等级" << std::endl;
  }

  // 菜单系统
  std::cout << "\n菜单选择: ";
  switch (choice) {
  case 1:
    std::cout << "新建文件" << std::endl;
    break;
  case 2:
    std::cout << "打开文件" << std::endl;
    break;
  case 3:
    std::cout << "保存文件" << std::endl;
    break;
  case 4:
    std::cout << "退出" << std::endl;
    break;
  default:
    std::cout << "无效选择" << std::endl;
  }

  return 0;
}
