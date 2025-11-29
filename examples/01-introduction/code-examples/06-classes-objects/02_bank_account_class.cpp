#include <iostream>
#include <string>

// 银行账户类
class BankAccount {
public:
  std::string accountNumber;
  std::string ownerName;
  double balance;

  // 存款
  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      std::cout << "存入 " << amount << " 元，当前余额: " << balance << " 元"
                << std::endl;
    }
  }

  // 取款
  void withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
      balance -= amount;
      std::cout << "取出 " << amount << " 元，当前余额: " << balance << " 元"
                << std::endl;
    } else {
      std::cout << "余额不足或金额无效！" << std::endl;
    }
  }

  // 显示账户信息
  void displayAccount() {
    std::cout << "账户: " << accountNumber << std::endl;
    std::cout << "户主: " << ownerName << std::endl;
    std::cout << "余额: " << balance << " 元" << std::endl;
  }
};

int main() {
  std::cout << "=== 银行账户类示例 ===" << std::endl;
  BankAccount account;
  account.accountNumber = "123456789";
  account.ownerName = "张三";
  account.balance = 1000.0;

  account.displayAccount();
  std::cout << std::endl;

  account.deposit(500);
  account.withdraw(300);
  account.withdraw(2000); // 余额不足

  std::cout << std::endl;
  account.displayAccount();

  return 0;
}
