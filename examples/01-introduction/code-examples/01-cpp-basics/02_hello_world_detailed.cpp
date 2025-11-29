#include <iostream> // 包含输入输出流库

// 这是程序的主函数，程序从这里开始执行
int main() {
  // 输出欢迎信息
  std::cout << "欢迎来到C++世界！" << std::endl;

  // 可以连续输出多行
  std::cout << "这是第二行" << std::endl;
  std::cout << "这是第三行" << std::endl;

  // 也可以在一行中输出多个内容
  std::cout << "数字: " << 42 << ", 文本: " << "C++" << std::endl;

  // 返回0表示程序成功执行
  return 0;
}
