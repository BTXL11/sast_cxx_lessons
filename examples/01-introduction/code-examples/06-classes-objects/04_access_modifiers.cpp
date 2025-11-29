#include <iostream>
#include <string>

class BankAccount {
private: // 私有成员：只能在类内部访问
  double balance;
  std::string password;

  // 私有辅助函数
  bool verifyPassword(std::string pwd) const { return pwd == password; }

public: // 公有成员：可以从任何地方访问
  std::string accountNumber;
  std::string ownerName;

  // 构造函数
  BankAccount(std::string accNum, std::string owner, std::string pwd,
              double initialBalance = 0.0) {
    accountNumber = accNum;
    ownerName = owner;
    password = pwd;
    balance = initialBalance;
  }

  // 公有方法：存款
  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      std::cout << "存入 " << amount << " 元成功" << std::endl;
    } else {
      std::cout << "存款金额必须大于0" << std::endl;
    }
  }

  // 公有方法：取款（需要密码）
  bool withdraw(std::string pwd, double amount) {
    if (!verifyPassword(pwd)) {
      std::cout << "密码错误！" << std::endl;
      return false;
    }

    if (amount > balance) {
      std::cout << "余额不足！" << std::endl;
      return false;
    }

    if (amount <= 0) {
      std::cout << "取款金额必须大于0" << std::endl;
      return false;
    }

    balance -= amount;
    std::cout << "取出 " << amount << " 元成功" << std::endl;
    return true;
  }

  // 公有方法：查询余额（需要密码）
  void checkBalance(std::string pwd) const {
    if (verifyPassword(pwd)) {
      std::cout << "当前余额: " << balance << " 元" << std::endl;
    } else {
      std::cout << "密码错误！" << std::endl;
    }
  }

  // 公有方法：显示账户信息（不显示敏感信息）
  void displayInfo() const {
    std::cout << "账户号: " << accountNumber << std::endl;
    std::cout << "户主: " << ownerName << std::endl;
    // 不显示余额和密码
  }
};

int main() {
  std::cout << "=== 访问修饰符示例 ===" << std::endl;

  BankAccount account("123456", "张三", "1234", 1000.0);

  account.displayInfo();
  std::cout << std::endl;

  // 可以直接访问公有成员
  std::cout << "账户号（公有）: " << account.accountNumber << std::endl;

  // 不能直接访问私有成员
  // std::cout << account.balance << std::endl;  // 错误！balance是私有的
  // std::cout << account.password << std::endl;  // 错误！password是私有的

  std::cout << std::endl;

  // 通过公有方法访问
  account.checkBalance("1234"); // 正确密码
  account.checkBalance("0000"); // 错误密码

  std::cout << std::endl;

  account.deposit(500);
  account.checkBalance("1234");

  std::cout << std::endl;

  account.withdraw("1234", 300);
  account.checkBalance("1234");

  return 0;
}
