#include <iostream>

/*
 * 程序功能：演示注释的使用
 * 作者：学习者
 * 日期：2024-10-31
 */

int main() {
  // 声明并初始化变量
  int score = 95; // 学生分数

  /*
   * 根据分数判断等级
   * 90-100: A
   * 80-89: B
   * 其他: C
   */
  if (score >= 90) {
    std::cout << "等级: A" << std::endl; // 优秀
  } else if (score >= 80) {
    std::cout << "等级: B" << std::endl; // 良好
  } else {
    std::cout << "等级: C" << std::endl; // 及格
  }

  // 程序结束
  return 0;
}
