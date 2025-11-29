#include <iostream>
#include <string>

int main() {
  std::cout << "=== 基本输入输出示例 ===" << std::endl;

  // 基本输出
  std::cout << "请输入你的名字: ";

  // 基本输入（读取一个单词）
  std::string name;
  std::cin >> name;

  std::cout << "你好, " << name << "!" << std::endl;

  // 读取整行（包含空格）
  std::cout << "\n请输入一句话: ";
  std::cin.ignore(); // 清除缓冲区中的换行符
  std::string sentence;
  std::getline(std::cin, sentence);

  std::cout << "你说: " << sentence << std::endl;

  // 读取数字
  std::cout << "\n请输入你的年龄: ";
  int age;
  std::cin >> age;

  std::cout << "你 " << age << " 岁了" << std::endl;

  // 读取多个值
  std::cout << "\n请输入两个数字（用空格分隔）: ";
  int a, b;
  std::cin >> a >> b;

  std::cout << "你输入的数字是: " << a << " 和 " << b << std::endl;
  std::cout << "它们的和是: " << (a + b) << std::endl;

  return 0;
}
