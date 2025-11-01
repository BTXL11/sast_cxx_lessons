#include <iomanip>
#include <iostream>
#include <string>

int main() {
  std::cout << "=== 格式化输出示例 ===" << std::endl;

  double pi = 3.14159265359;

  // 设置小数精度
  std::cout << "默认: " << pi << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "2位小数: " << pi
            << std::endl;
  std::cout << std::setprecision(4) << "4位小数: " << pi << std::endl;

  // 设置宽度和对齐
  std::cout << "\n设置宽度:" << std::endl;
  std::cout << std::setw(10) << "Name" << std::setw(10) << "Age" << std::endl;
  std::cout << std::setw(10) << "Alice" << std::setw(10) << 25 << std::endl;
  std::cout << std::setw(10) << "Bob" << std::setw(10) << 30 << std::endl;

  // 左对齐和右对齐
  std::cout << "\n对齐方式:" << std::endl;
  std::cout << std::left << std::setw(15) << "左对齐" << std::right
            << std::setw(15) << "右对齐" << std::endl;

  // 填充字符
  std::cout << "\n填充字符:" << std::endl;
  std::cout << std::setfill('*') << std::setw(20) << "Hello" << std::endl;
  std::cout << std::setfill(' '); // 恢复默认

  // 布尔值格式
  bool flag = true;
  std::cout << "\n布尔值:" << std::endl;
  std::cout << "默认: " << flag << std::endl;
  std::cout << std::boolalpha << "boolalpha: " << flag << std::endl;
  std::cout << std::noboolalpha; // 恢复默认

  // 进制
  int num = 255;
  std::cout << "\n进制:" << std::endl;
  std::cout << "十进制: " << std::dec << num << std::endl;
  std::cout << "十六进制: " << std::hex << num << std::endl;
  std::cout << "八进制: " << std::oct << num << std::endl;
  std::cout << std::dec; // 恢复十进制

  // 科学计数法
  double large = 123456.789;
  std::cout << "\n科学计数法:" << std::endl;
  std::cout << std::scientific << large << std::endl;
  std::cout << std::fixed; // 恢复固定小数

  return 0;
}
