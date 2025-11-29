#include <cstring> // C字符串函数
#include <iostream>

int main() {
  std::cout << "=== C风格字符串示例 ===" << std::endl;

  // 创建C风格字符串的几种方式
  char str1[] = "Hello"; // 编译器自动添加'\0'
  char str2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
  const char *str3 = "World"; // 字符串字面量

  std::cout << "str1: " << str1 << std::endl;
  std::cout << "str2: " << str2 << std::endl;
  std::cout << "str3: " << str3 << std::endl;

  // 字符串长度
  std::cout << "\nstrlen(str1) = " << strlen(str1) << std::endl;
  std::cout << "sizeof(str1) = " << sizeof(str1) << " (包含\\0)" << std::endl;

  // 字符串拷贝
  char dest[20];
  strcpy(dest, str1);
  std::cout << "\n拷贝后 dest: " << dest << std::endl;

  // 字符串连接
  strcat(dest, " ");
  strcat(dest, str3);
  std::cout << "连接后 dest: " << dest << std::endl;

  // 字符串比较
  if (strcmp(str1, str2) == 0) {
    std::cout << "\nstr1 和 str2 相等" << std::endl;
  }

  // 查找字符
  char *pos = strchr(dest, 'W');
  if (pos != nullptr) {
    std::cout << "找到 'W' 在位置: " << (pos - dest) << std::endl;
  }

  // 遍历字符串
  std::cout << "\n逐字符输出: ";
  for (int i = 0; str1[i] != '\0'; i++) {
    std::cout << str1[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
