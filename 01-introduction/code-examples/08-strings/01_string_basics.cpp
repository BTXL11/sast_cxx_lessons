#include <iostream>
#include <string>

int main() {
  std::cout << "=== std::string基础示例 ===" << std::endl;

  // 创建字符串
  std::string str1 = "Hello";
  std::string str2 = "World";
  std::string str3; // 空字符串

  std::cout << "str1: " << str1 << std::endl;
  std::cout << "str2: " << str2 << std::endl;

  // 字符串拼接
  std::string greeting = str1 + " " + str2;
  std::cout << "拼接: " << greeting << std::endl;

  // 字符串长度
  std::cout << "长度: " << greeting.length() << std::endl;
  std::cout << "大小: " << greeting.size() << std::endl;

  // 访问字符
  std::cout << "第一个字符: " << greeting[0] << std::endl;
  std::cout << "最后一个字符: " << greeting[greeting.length() - 1] << std::endl;

  // 修改字符
  greeting[0] = 'h';
  std::cout << "修改后: " << greeting << std::endl;

  // 追加字符串
  greeting += "!";
  std::cout << "追加后: " << greeting << std::endl;

  // 子字符串
  std::string sub = greeting.substr(0, 5); // 从位置0开始，长度5
  std::cout << "子字符串: " << sub << std::endl;

  // 查找
  size_t pos = greeting.find("World");
  if (pos != std::string::npos) {
    std::cout << "找到 'World' 在位置: " << pos << std::endl;
  }

  // 比较
  std::string s1 = "apple";
  std::string s2 = "banana";
  if (s1 < s2) {
    std::cout << s1 << " 在字典序中小于 " << s2 << std::endl;
  }

  // 清空和检查
  std::cout << "是否为空: " << (str3.empty() ? "是" : "否") << std::endl;
  greeting.clear();
  std::cout << "清空后是否为空: " << (greeting.empty() ? "是" : "否")
            << std::endl;

  return 0;
}
