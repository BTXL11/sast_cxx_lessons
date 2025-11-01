#!/bin/bash

# 基本编译命令
g++ -o hello hello.cpp

# 运行程序
./hello          # Linux/Mac
# hello.exe      # Windows

# 带优化和警告的编译（推荐）
g++ -Wall -Wextra -std=c++17 -o hello hello.cpp

# 编译多个源文件
g++ -o program main.cpp utils.cpp helper.cpp

# 使用clang++编译器（跨平台）
clang++ -o hello hello.cpp
./hello

