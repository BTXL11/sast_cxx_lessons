#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::cout << "=== 文件操作示例 ===" << std::endl;

  // 写入文件
  std::ofstream outfile("example.txt");
  if (outfile.is_open()) {
    outfile << "Hello, File!" << std::endl;
    outfile << "这是第二行" << std::endl;
    outfile << "数字: " << 42 << std::endl;
    outfile.close();
    std::cout << "文件写入成功" << std::endl;
  } else {
    std::cout << "无法打开文件进行写入" << std::endl;
    return 1;
  }

  // 读取文件
  std::ifstream infile("example.txt");
  if (infile.is_open()) {
    std::cout << "\n文件内容:" << std::endl;
    std::string line;
    while (std::getline(infile, line)) {
      std::cout << line << std::endl;
    }
    infile.close();
  } else {
    std::cout << "无法打开文件进行读取" << std::endl;
    return 1;
  }

  // 追加到文件
  std::ofstream appendfile("example.txt", std::ios::app);
  if (appendfile.is_open()) {
    appendfile << "这是追加的内容" << std::endl;
    appendfile.close();
    std::cout << "\n内容已追加" << std::endl;
  }

  // 再次读取文件
  infile.open("example.txt");
  if (infile.is_open()) {
    std::cout << "\n更新后的文件内容:" << std::endl;
    std::string line;
    while (std::getline(infile, line)) {
      std::cout << line << std::endl;
    }
    infile.close();
  }

  // 读取数字
  std::ofstream numfile("numbers.txt");
  numfile << "10 20 30 40 50" << std::endl;
  numfile.close();

  std::ifstream numread("numbers.txt");
  if (numread.is_open()) {
    std::cout << "\n从文件读取数字:" << std::endl;
    int num;
    while (numread >> num) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
    numread.close();
  }

  std::cout << "\n文件操作完成" << std::endl;

  return 0;
}
