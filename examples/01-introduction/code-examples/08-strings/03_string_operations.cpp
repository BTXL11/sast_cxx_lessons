#include <iostream>
#include <string>

int main() {
  std::cout << "=== std::string操作示例 ===" << std::endl;

  // 创建字符串
  std::string str1 = "Hello";
  std::string str2("World");
  std::string str3(5, '*'); // "*****"

  std::cout << "str1: " << str1 << std::endl;
  std::cout << "str2: " << str2 << std::endl;
  std::cout << "str3: " << str3 << std::endl;

  // 字符串拼接
  std::string greeting = str1 + " " + str2 + "!";
  std::cout << "\n拼接: " << greeting << std::endl;

  // 字符串长度
  std::cout << "长度: " << greeting.length() << std::endl;
  std::cout << "大小: " << greeting.size() << std::endl;
  std::cout << "容量: " << greeting.capacity() << std::endl;

  // 访问字符
  std::cout << "\n第一个字符: " << greeting[0] << std::endl;
  std::cout << "最后一个字符: " << greeting[greeting.length() - 1] << std::endl;
  std::cout << "使用at(): " << greeting.at(6) << std::endl;

  // 修改字符串
  greeting[0] = 'h';
  std::cout << "修改后: " << greeting << std::endl;

  // 子字符串
  std::string sub = greeting.substr(0, 5); // 从位置0开始，长度5
  std::cout << "\n子字符串(0,5): " << sub << std::endl;
  std::string sub2 = greeting.substr(6); // 从位置6到结尾
  std::cout << "子字符串(6): " << sub2 << std::endl;

  // 查找
  size_t pos = greeting.find("World");
  if (pos != std::string::npos) {
    std::cout << "\n找到 'World' 在位置: " << pos << std::endl;
  }

  // 替换
  std::string text = "I like cats";
  text.replace(7, 4, "dogs"); // 从位置7开始，替换4个字符
  std::cout << "替换后: " << text << std::endl;

  // 插入
  text.insert(7, "big ");
  std::cout << "插入后: " << text << std::endl;

  // 删除
  text.erase(7, 4); // 从位置7删除4个字符
  std::cout << "删除后: " << text << std::endl;

  // 比较
  std::string s1 = "apple";
  std::string s2 = "banana";
  if (s1 < s2) {
    std::cout << "\n" << s1 << " < " << s2 << " (字典序)" << std::endl;
  }

  // 转换为C风格字符串
  const char *cstr = greeting.c_str();
  std::cout << "C风格字符串: " << cstr << std::endl;

  return 0;
}
