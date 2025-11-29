# 快速开始

本指南将帮助你快速搭建 C++ 开发环境并运行第一个程序。

---

## 环境要求

- **操作系统**：Windows 10+、macOS 10.15+、Linux（Ubuntu 20.04+）
- **编译器**：支持 C++17 或更高版本
- **构建工具**：CMake 3.10+

---

## 安装开发环境

### Windows

#### 方式一：Visual Studio（推荐）

1. 下载 [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/)
2. 安装时选择 **"使用 C++ 的桌面开发"** 工作负载
3. 确保勾选 CMake 工具

#### 方式二：MinGW-w64 + VS Code

1. 下载 [MSYS2](https://www.msys2.org/)
2. 安装后打开 MSYS2 终端，运行：

    ```bash
    pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake
    ```

3. 将 `C:\msys64\ucrt64\bin` 添加到系统 PATH
4. 安装 [VS Code](https://code.visualstudio.com/) 和 C/C++ 扩展

### macOS

```bash
# 安装 Xcode 命令行工具
xcode-select --install

# 使用 Homebrew 安装 CMake
brew install cmake
```

### Linux

=== "Ubuntu/Debian"

    ```bash
    sudo apt update
    sudo apt install build-essential cmake git
    ```

=== "Fedora"

    ```bash
    sudo dnf install gcc-c++ cmake git
    ```

=== "Arch Linux"

    ```bash
    sudo pacman -S base-devel cmake git
    ```

---

## 验证安装

打开终端，运行以下命令验证安装：

```bash
# 检查编译器
g++ --version
# 或
clang++ --version

# 检查 CMake
cmake --version
```

---

## 第一个程序

### 创建源文件

创建 `hello.cpp`：

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, SAST C++!" << std::endl;
    return 0;
}
```

### 编译运行

=== "直接编译"

    ```bash
    # 编译
    g++ -std=c++17 -o hello hello.cpp
    
    # 运行
    ./hello  # Linux/macOS
    .\hello.exe  # Windows
    ```

=== "使用 CMake"

    创建 `CMakeLists.txt`：

    ```cmake
    cmake_minimum_required(VERSION 3.10)
    project(Hello LANGUAGES CXX)
    
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    
    add_executable(hello hello.cpp)
    ```

    构建：

    ```bash
    mkdir build && cd build
    cmake ..
    cmake --build .
    ./hello
    ```

---

## 克隆课程仓库

```bash
git clone https://github.com/AstroAir/sast_cxx_lessons.git
cd sast_cxx_lessons
```

### 构建示例

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

---

## 本地预览文档

如果你想在本地预览或编辑文档：

```bash
# 安装 Python 依赖
pip install -e ".[docs]"

# 启动开发服务器
mkdocs serve
```

访问 [http://127.0.0.1:8000](http://127.0.0.1:8000) 查看文档。

---

## 下一步

- [C++ 基础教程](lessons/01-introduction/index.md) - 从零开始学习 C++
- [构建系统](lessons/02-build-system/index.md) - 学习 CMake
- [Vibe Coding](lessons/00-vibe-coding/index.md) - AI 辅助编程
