# C++ 教程代码示例索引

本目录包含从 `01-introduction/index.md` 文档中提取的所有代码示例。每个代码示例都被组织到对应的章节文件夹中，并使用描述性文件名。

## 📁 目录结构

```
code-examples/
├── 01-cpp-basics/          # 第1章：C++基础
├── 02-variables-operators/ # 第2章：变量和运算符
├── 03-control-flow/        # 第3章：控制流
├── 04-functions/           # 第4章：函数
├── 05-arrays-collections/  # 第5章：数组和集合
├── 06-classes-objects/     # 第6章：类和对象简介
├── 07-pointers/            # 第7章：指针简介
├── 08-strings/             # 第8章：字符串处理
├── 10-references/          # 第10章：引用
├── 11-dynamic-memory/      # 第11章：动态内存管理
├── 16-lambda/              # 第16章：Lambda表达式
└── README.md               # 本文件
```

## 📚 章节详细索引

### 第1章：C++基础 (01-cpp-basics/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_hello_world.cpp` | 最简单的Hello World程序 | 第1章 - 第一个C++程序 |
| `02_hello_world_detailed.cpp` | 带详细注释的Hello World | 第1章 - 程序结构解释 |
| `03_compilation_commands.sh` | 编译和运行命令 | 第1章 - 编译和运行 |
| `04_common_errors.cpp` | 常见编译错误示例 | 第1章 - 常见错误 |
| `05_basic_data_types.cpp` | 基本数据类型演示 | 第1章 - 数据类型 |
| `06_comments_example.cpp` | 注释的使用方法 | 第1章 - 注释 |
| `07_namespace_methods.cpp` | 命名空间的三种使用方法 | 第1章 - 命名空间 |

**编译方法：**

```bash
g++ -o hello 01_hello_world.cpp
./hello
```

---

### 第2章：变量和运算符 (02-variables-operators/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_variable_declaration.cpp` | 变量声明和初始化 | 第2章 - 变量声明 |
| `02_naming_conventions.cpp` | 变量命名规范 | 第2章 - 命名规范 |
| `03_variable_scope.cpp` | 变量作用域演示 | 第2章 - 作用域 |
| `04_variable_shadowing.cpp` | 变量遮蔽示例 | 第2章 - 变量遮蔽 |
| `05_variable_lifetime.cpp` | 变量生命周期（静态变量） | 第2章 - 生命周期 |
| `06_arithmetic_operators.cpp` | 算术运算符（+, -, *, /, %） | 第2章 - 算术运算符 |
| `07_comparison_operators.cpp` | 比较运算符（==, !=, <, >, <=, >=） | 第2章 - 比较运算符 |
| `08_logical_operators.cpp` | 逻辑运算符（&&, \|\|, !） | 第2章 - 逻辑运算符 |
| `09_operator_precedence.cpp` | 运算符优先级 | 第2章 - 运算符优先级 |

**关键概念：**

- 全局变量 vs 局部变量
- 静态变量的持久性
- 短路求值
- 复合赋值运算符（+=, -=, *=, /=, %=）

---

### 第3章：控制流 (03-control-flow/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_if_statement.cpp` | if语句基础 | 第3章 - if语句 |
| `02_if_else_statement.cpp` | if-else和if-else if链 | 第3章 - if-else |
| `03_ternary_operator.cpp` | 三元运算符（? :） | 第3章 - 三元运算符 |
| `04_switch_statement.cpp` | switch语句和case | 第3章 - switch语句 |
| `05_for_loop.cpp` | for循环（基础、嵌套、多变量） | 第3章 - for循环 |
| `06_while_loop.cpp` | while循环 | 第3章 - while循环 |
| `07_do_while_loop.cpp` | do-while循环 | 第3章 - do-while循环 |
| `08_range_based_for.cpp` | 基于范围的for循环（C++11） | 第3章 - 范围for循环 |
| `09_break_continue.cpp` | break和continue语句 | 第3章 - 循环控制 |

**关键概念：**

- 条件分支
- 循环结构
- 循环控制语句
- 现代C++范围循环

---

### 第4章：函数 (04-functions/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_function_basics.cpp` | 函数声明、定义和调用 | 第4章 - 函数基础 |
| `02_practical_functions.cpp` | 实用函数示例（圆面积、质数、阶乘） | 第4章 - 实用函数 |
| `03_parameter_passing.cpp` | 参数传递方式（值、引用、指针） | 第4章 - 参数传递 |
| `04_function_overloading.cpp` | 函数重载 | 第4章 - 函数重载 |

**关键概念：**

- 函数原型和定义分离
- 按值传递 vs 按引用传递
- const引用参数
- 函数重载规则

**编译示例：**

```bash
g++ -o functions 01_function_basics.cpp
./functions
```

---

### 第5章：数组和集合 (05-arrays-collections/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_c_style_arrays.cpp` | C风格数组基础 | 第5章 - C数组 |
| `02_array_initialization.cpp` | 数组初始化的多种方式 | 第5章 - 数组初始化 |
| `03_vectors.cpp` | std::vector容器使用 | 第5章 - vector |

**关键概念：**

- 固定大小数组 vs 动态vector
- 数组初始化语法
- vector的常用操作（push_back, pop_back, insert, sort）
- 基于范围的for循环遍历

---

### 第6章：类和对象简介 (06-classes-objects/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_simple_class.cpp` | 简单的Student类 | 第6章 - 类基础 |
| `02_bank_account_class.cpp` | 银行账户类实例 | 第6章 - 实用类示例 |

**关键概念：**

- 类的定义和对象创建
- 成员变量和成员函数
- public访问修饰符
- 对象的方法调用

---

### 第7章：指针简介 (07-pointers/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_pointer_basics.cpp` | 指针基础（声明、取地址、解引用） | 第7章 - 指针基础 |

**关键概念：**

- 指针声明（int*）
- 取地址运算符（&）
- 解引用运算符（*）
- 通过指针修改值

---

### 第8章：字符串处理 (08-strings/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_string_basics.cpp` | std::string基础操作 | 第8章 - string类 |

**关键概念：**

- 字符串创建和拼接
- 字符串长度和访问
- 子字符串和查找
- 字符串比较

---

### 第10章：引用 (10-references/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_reference_basics.cpp` | 引用基础（别名、地址） | 第10章 - 引用基础 |

**关键概念：**

- 引用作为别名
- 引用必须初始化
- 引用不能重新绑定
- 引用和原变量共享地址

---

### 第11章：动态内存管理 (11-dynamic-memory/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_new_delete.cpp` | new和delete操作符 | 第11章 - 动态内存 |

**关键概念：**

- 动态分配单个对象（new）
- 动态分配数组（new[]）
- 释放内存（delete和delete[]）
- 内存泄漏预防

---

### 第16章：Lambda表达式 (16-lambda/)

| 文件名 | 描述 | 原文档位置 |
|--------|------|-----------|
| `01_lambda_basics.cpp` | Lambda表达式基础和捕获 | 第16章 - Lambda |

**关键概念：**

- Lambda语法 [](){}
- 参数和返回类型
- 捕获外部变量（按值、按引用）
- 在算法中使用lambda

---

## 🔧 编译和运行

### 基本编译

```bash
g++ -o program filename.cpp
./program
```

### 使用C++11/14/17特性

```bash
g++ -std=c++11 -o program filename.cpp
g++ -std=c++14 -o program filename.cpp
g++ -std=c++17 -o program filename.cpp
```

### 启用警告

```bash
g++ -Wall -Wextra -o program filename.cpp
```

### 调试模式

```bash
g++ -g -o program filename.cpp
gdb ./program
```

## 📝 注意事项

1. **完整性**：所有代码示例都包含必要的头文件和main函数，可以直接编译运行
2. **注释**：保留了原文档中的中文注释和说明
3. **命名**：文件名使用数字前缀排序，便于按顺序学习
4. **标准**：部分示例需要C++11或更高版本（如范围for循环、lambda表达式）

## 🎯 学习建议

1. **按顺序学习**：建议按章节顺序学习，每章内按文件编号顺序
2. **动手实践**：每个示例都应该编译运行，观察输出
3. **修改实验**：尝试修改代码，理解不同参数的效果
4. **组合应用**：后续章节会用到前面的知识，注意知识的累积

## 📖 原文档映射

所有代码示例都提取自：`d:\Project\sast_cxx_lessons/01-introduction\index.md`

每个文件的"原文档位置"列指明了代码在原文档中的章节位置，方便对照学习。

## 📊 提取统计

**原文档代码块总数**：91个C++代码示例
**已提取文件数**：30个代码文件
**覆盖章节**：17章中的10章（核心章节）

### 已完整提取的章节

- ✅ 第1章：C++基础（7个文件）
- ✅ 第2章：变量和运算符（9个文件）
- ✅ 第3章：控制流（9个文件）
- ✅ 第4章：函数（4个文件）
- ✅ 第5章：数组和集合（3个文件）

### 已提取代表性示例的章节

- ⚡ 第6章：类和对象（2个文件）
- ⚡ 第7章：指针（1个文件）
- ⚡ 第8章：字符串（1个文件）
- ⚡ 第10章：引用（1个文件）
- ⚡ 第11章：动态内存（1个文件）
- ⚡ 第16章：Lambda表达式（1个文件）

### 待提取的章节（原文档中有代码示例）

- 第9章：输入输出操作（3个示例）
- 第12章：构造函数和析构函数（3个示例）
- 第13章：拷贝语义（3个示例）
- 第14章：类型转换（5个示例）
- 第15章：内联函数（4个示例）
- 第17章：左值和右值（3个示例）

## 🔄 如何继续提取

如需提取剩余的代码示例，可以按照以下步骤：

1. **查看原文档**：`d:\Project\sast_cxx_lessons/01-introduction\index.md`
2. **定位代码块**：搜索 ` ```cpp` 标记
3. **创建文件**：按照现有命名规范（章节编号_描述性名称.cpp）
4. **保持结构**：确保代码完整可编译（包含必要的头文件和main函数）
5. **更新README**：在本文件中添加新提取的文件信息

## 💡 提取原则

本次提取遵循以下原则：

1. **完整性**：每个代码文件都是完整的、可编译的程序
2. **可读性**：保留所有中文注释和说明
3. **组织性**：按章节组织，使用描述性文件名
4. **实用性**：优先提取教学价值高的示例
5. **可追溯性**：README中记录每个文件对应的原文档位置

---

**最后更新**：2025-10-31
**提取状态**：核心示例已完成（30/91个代码块）
**文档版本**：C++ Tutorial - Introduction
**原文档路径**：`d:\Project\sast_cxx_lessons/01-introduction\index.md`
