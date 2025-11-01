#include <iostream>
#include <string>

class Resource {
private:
  std::string name;
  int *data;

public:
  // 构造函数
  Resource(std::string n, int size) : name(n) {
    data = new int[size];
    std::cout << "Resource '" << name << "' 创建，分配了 " << size << " 个整数"
              << std::endl;
  }

  // 析构函数 - 释放动态分配的内存
  ~Resource() {
    delete[] data;
    std::cout << "Resource '" << name << "' 销毁，内存已释放" << std::endl;
  }

  void setData(int index, int value) { data[index] = value; }

  int getData(int index) const { return data[index]; }
};

void demonstrateLifetime() {
  std::cout << "\n进入函数..." << std::endl;
  Resource r("临时资源", 5);
  r.setData(0, 100);
  std::cout << "数据: " << r.getData(0) << std::endl;
  std::cout << "离开函数..." << std::endl;
} // r在这里被销毁，析构函数自动调用

int main() {
  std::cout << "=== 析构函数示例 ===" << std::endl;

  std::cout << "\n创建全局资源:" << std::endl;
  Resource r1("全局资源", 10);

  demonstrateLifetime();

  std::cout << "\n创建代码块资源:" << std::endl;
  {
    Resource r2("块资源", 3);
    std::cout << "在代码块内..." << std::endl;
  } // r2在这里被销毁

  std::cout << "\n动态分配资源:" << std::endl;
  Resource *r3 = new Resource("动态资源", 7);
  delete r3; // 手动删除，调用析构函数

  std::cout << "\nmain函数即将结束..." << std::endl;
  return 0;
} // r1在这里被销毁
