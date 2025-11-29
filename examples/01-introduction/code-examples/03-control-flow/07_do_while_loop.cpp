#include <iostream>

int main() {
  std::cout << "=== do-while循环示例 ===" << std::endl;

  // 基本do-while循环
  std::cout << "数字0到4: ";
  int i = 0;
  do {
    std::cout << i << " ";
    i++;
  } while (i < 5);
  std::cout << std::endl;

  // 至少执行一次的特性
  std::cout << "\ndo-while至少执行一次:" << std::endl;
  int x = 10;
  do {
    std::cout << "x = " << x << " (条件为假，但仍执行了一次)" << std::endl;
  } while (x < 5); // 条件为假

  // 对比：while循环不会执行
  std::cout << "\nwhile循环不会执行:" << std::endl;
  int y = 10;
  while (y < 5) { // 条件为假，不执行
    std::cout << "这不会被打印" << std::endl;
  }
  std::cout << "while循环体没有执行" << std::endl;

  // 菜单系统示例
  std::cout << "\n菜单系统示例:" << std::endl;
  int choice;
  int menuCount = 0;

  do {
    std::cout << "\n--- 菜单 ---" << std::endl;
    std::cout << "1. 选项1" << std::endl;
    std::cout << "2. 选项2" << std::endl;
    std::cout << "3. 选项3" << std::endl;
    std::cout << "0. 退出" << std::endl;

    // 模拟用户选择
    int choices[] = {1, 2, 0};
    choice = choices[menuCount++];
    std::cout << "选择: " << choice << std::endl;

    switch (choice) {
    case 1:
      std::cout << "执行选项1" << std::endl;
      break;
    case 2:
      std::cout << "执行选项2" << std::endl;
      break;
    case 3:
      std::cout << "执行选项3" << std::endl;
      break;
    case 0:
      std::cout << "退出程序" << std::endl;
      break;
    default:
      std::cout << "无效选择" << std::endl;
    }
  } while (choice != 0);

  return 0;
}
