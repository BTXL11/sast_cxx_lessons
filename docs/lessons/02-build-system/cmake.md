# CMake 教程

## 目录

- [简介](#简介)
- [第1步：基础起点](#第1步基础起点)
  - [创建基本项目](#创建基本项目)
  - [添加版本号和配置头文件](#添加版本号和配置头文件)
  - [指定 C++ 标准](#指定-c-标准)
  - [构建和测试](#构建和测试)
- [第2步：添加库](#第2步添加库)
- [第3步：为库添加使用要求](#第3步为库添加使用要求)
- [第4步：安装和测试](#第4步安装和测试)
  - [配置安装规则](#配置安装规则)
  - [添加测试支持](#添加测试支持)
- [第5步：添加系统自检](#第5步添加系统自检)
- [第6步：添加自定义命令和生成文件](#第6步添加自定义命令和生成文件)
- [第7步：构建安装程序](#第7步构建安装程序)
- [第8步：添加仪表板支持](#第8步添加仪表板支持)
- [第9步：混合静态库和共享库](#第9步混合静态库和共享库)
- [第10步：添加生成器表达式](#第10步添加生成器表达式)
- [第11步：添加导出配置](#第11步添加导出配置)
- [第12步：打包调试版和发布版](#第12步打包调试版和发布版)

---

## 简介

本教程通过一个实际项目示例，循序渐进地介绍 CMake 如何解决常见的构建系统问题。您将学习到各种 CMake 功能如何协同工作，构建一个完整的项目。

**教程资源位置**：CMake 源代码树的 `Help/guide/tutorial` 目录

**教程结构**：

- 每个步骤都有独立的子目录，包含该步骤的起始代码
- 每个步骤都提供了前一步骤的完整解决方案，可作为参考
- 教程采用渐进式设计，每步都在前一步的基础上增加新功能

---

## 第1步：基础起点

### 创建基本项目

最简单的 CMake 项目只需要一个包含三行代码的 `CMakeLists.txt` 文件。这个文件定义了如何从源代码构建可执行程序。

在 `Step1` 目录中创建 `CMakeLists.txt` 文件：

```cmake
# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(Tutorial)

# 添加可执行文件(从 tutorial.cxx 源文件构建 Tutorial 可执行程序)
add_executable(Tutorial tutorial.cxx)
```

**代码说明**：

- `cmake_minimum_required`： 确保使用足够新的 CMake 版本
- `project`： 定义项目名称，CMake 会自动设置相关变量
- `add_executable`： 指定要生成的可执行文件名称和源文件

**注意**： CMake 命令不区分大小写，支持大写、小写和混合大小写。本教程统一使用小写以保持一致性。

教程的源文件 `tutorial.cxx` 实现了一个计算数字平方根的程序。

### 添加版本号和配置头文件

为项目添加版本号可以更灵活地管理版本信息。虽然可以直接在源代码中硬编码版本号，但使用 CMake 管理版本更加便捷。

**步骤 1**： 在 `CMakeLists.txt` 中设置版本号

修改 `project` 命令,添加版本信息：

```cmake
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本号(主版本号1,次版本号0)
project(Tutorial VERSION 1.0)
```

**步骤 2**： 配置头文件模板

添加以下命令生成配置头文件：

```cmake
# 根据模板文件生成配置头文件，将版本号传递给源代码
configure_file(TutorialConfig.h.in TutorialConfig.h)
```

**步骤 3**： 添加头文件搜索路径

由于生成的配置文件位于构建目录(二进制树），需要将该目录添加到头文件搜索路径:

```cmake
# PUBLIC 表示 Tutorial 及其依赖项都可以访问这个目录
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
```

**步骤 4**： 创建头文件模板

在源目录中创建 `TutorialConfig.h.in` 文件：

```cpp
// Tutorial 的配置选项和设置
// @...@ 包围的内容会在配置时被 CMake 替换为实际值
#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```

**步骤 5**： 在源代码中使用版本信息

修改 `tutorial.cxx`,包含配置头文件并显示版本号:

```cpp
#include "TutorialConfig.h"

// 在错误信息中显示程序名称和版本号
if (argc < 2) {
    std::cout << argv[0] << " Version "
              << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
}
```

### 指定 C++ 标准

现代 C++ 项目通常需要指定使用的 C++ 标准版本。我们将使用 C++11 特性来改进代码。

**步骤 1**： 更新源代码使用 C++11 特性

将 `tutorial.cxx` 中的字符串转换函数替换为 C++11 的版本:

```cpp
// 替换 atof 为 std::stod (C++11 标准库函数)
const double inputValue = std::stod(argv[1]);

// 可以删除 #include <cstdlib>,因为不再需要 atof
```

**步骤 2**： 在 CMake 中启用 C++11 支持

在 `CMakeLists.txt` 中添加 C++ 标准设置(**必须在 `add_executable` 之前**):

```cmake
cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

# 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD 11)
# 要求必须支持指定的标准(如果编译器不支持将报错)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

### 构建和测试

**构建步骤**:

1. 创建独立的构建目录(推荐做法,保持源代码目录整洁):

```bash
mkdir Step1_build
cd Step1_build
```

2. 运行 CMake 配置项目:

```bash
# ../ Step1 指向包含 CMakeLists.txt 的源目录
cmake ../Step1
```

这一步 CMake 会:

- 检测编译器和构建工具
- 生成构建系统文件(如 Makefile 或 Visual Studio 项目文件)
- 根据模板生成配置头文件

3. 构建项目:

```bash
# --build . 表示在当前目录构建
cmake --build .
```

4. 测试程序:

```bash
# 测试各种输入
Tutorial 4294967296
Tutorial 10
Tutorial  # 不带参数,应该显示使用说明和版本号
```

---

## 第2步：添加库

现在我们将创建一个自定义的数学函数库，用于计算平方根，而不是直接使用编译器提供的标准函数。这演示了如何组织更大的项目。

**项目结构**：

```
Step2/
  ├── CMakeLists.txt          # 主构建文件
  ├── tutorial.cxx            # 主程序源文件
  └── MathFunctions/          # 库的子目录
      ├── CMakeLists.txt      # 库的构建文件
      ├── MathFunctions.h     # 库的头文件
      └── mysqrt.cxx          # 库的实现文件
```

### 创建库

**步骤 1**： 为库创建 CMakeLists.txt

在 `MathFunctions` 目录中创建 `CMakeLists.txt`:

```cmake
# 创建名为 MathFunctions 的库,从 mysqrt.cxx 编译
add_library(MathFunctions mysqrt.cxx)
```

**步骤 2**： 在主项目中使用库

修改顶级 `CMakeLists.txt`,添加子目录和链接库:

```cmake
# 添加 MathFunctions 子目录,CMake 会处理其中的 CMakeLists.txt
add_subdirectory(MathFunctions)

# 添加可执行文件
add_executable(Tutorial tutorial.cxx)

# 将 MathFunctions 库链接到 Tutorial 可执行文件
# PUBLIC 表示链接关系会传递给依赖 Tutorial 的其他目标
target_link_libraries(Tutorial PUBLIC MathFunctions)

# 添加 MathFunctions 目录到头文件搜索路径
target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          )
```

### 使库成为可选项

在大型项目中,某些功能是可选的。我们将让用户选择是否使用自定义的数学库。

**步骤 1**： 添加选项

在顶级 `CMakeLists.txt` 中添加:

```cmake
# 创建一个用户可配置的选项
# ON 表示默认启用
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 必须在选项之后配置头文件，这样配置文件才能获取到选项的值
configure_file(TutorialConfig.h.in TutorialConfig.h)
```

**步骤 2**： 条件编译库

修改顶级 `CMakeLists.txt` 的末尾:

```cmake
# 使用 if 语句控制是否构建和链接 MathFunctions
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  # 使用 list(APPEND ...) 将库添加到列表变量
  list(APPEND EXTRA_LIBS MathFunctions)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

add_executable(Tutorial tutorial.cxx)

# 使用变量来链接库(如果 USE_MYMATH 为 OFF,EXTRA_LIBS 为空)
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )
```

**说明**: 使用 `EXTRA_LIBS` 和 `EXTRA_INCLUDES` 变量是处理可选组件的经典方法。步骤 3 将介绍更现代的方法。

**步骤 3**： 在源代码中条件编译

修改 `tutorial.cxx`:

```cpp
// 只在需要时包含自定义库的头文件
#ifdef USE_MYMATH
#  include "MathFunctions.h"
#endif

// ...

// 根据编译选项选择使用哪个函数
#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  const double outputValue = sqrt(inputValue);  // 标准库函数
#endif
```

**步骤 4**： 在配置头文件中定义宏

在 `TutorialConfig.h.in` 中添加:

```cpp
// #cmakedefine 会根据 CMake 变量的值决定是否定义这个宏
#cmakedefine USE_MYMATH
```

### 测试可选功能

**方法 1**： 使用 GUI 工具

- 运行 `cmake-gui` 或 `ccmake`,可以交互式地切换 `USE_MYMATH` 选项

**方法 2**： 使用命令行

```bash
# 配置时禁用自定义数学库
cmake ../Step2 -DUSE_MYMATH=OFF
cmake --build .
```

**练习思考**：

- 为什么 `configure_file` 必须在 `option(USE_MYMATH ...)` 之后?
- 如果颠倒顺序会发生什么?(提示:配置头文件时 USE_MYMATH 变量还未定义)
- 比较使用 `sqrt` 和 `mysqrt` 的结果,哪个更准确?

---

## 第3步：为库添加使用要求

使用要求(Usage Requirements)是 CMake 的现代特性,可以更精确地控制库的编译和链接属性,并自动传递给使用该库的目标。

### 理解使用要求

**关键概念**：

- **PRIVATE**： 仅库自身需要
- **INTERFACE**： 仅使用库的目标需要
- **PUBLIC**： 库自身和使用者都需要

**主要命令**：

- `target_compile_definitions`: 添加预处理器定义
- `target_compile_options`: 添加编译选项
- `target_include_directories`: 添加头文件目录
- `target_link_libraries`: 链接其他库

### 重构代码使用现代方法

**步骤 1**： 在库中指定使用要求

修改 `MathFunctions/CMakeLists.txt`:

```cmake
add_library(MathFunctions mysqrt.cxx)

# INTERFACE 表示:使用 MathFunctions 的目标需要包含这个目录,
# 但 MathFunctions 本身编译时不需要
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
```

**解释**:

- `CMAKE_CURRENT_SOURCE_DIR`: 当前 CMakeLists.txt 所在目录
- 使用 `INTERFACE` 因为头文件是给库的使用者用的,不是库自身编译需要的

**步骤 2**： 简化主项目配置

修改顶级 `CMakeLists.txt`,移除手动管理的包含目录:

```cmake
# 简化:不再需要 EXTRA_INCLUDES
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
  # 删除: list(APPEND EXTRA_INCLUDES ...)
endif()
```

```cmake
# 简化:不再需要手动添加 MathFunctions 的包含目录
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           # 删除: ${EXTRA_INCLUDES}
                           )
```

**优势**：

- 头文件路径与库定义在一起，更易维护
- 链接库时自动获得所需的包含目录
- 减少重复配置，降低出错可能

### 验证构建

```bash
cmake ../Step3
cmake --build .
./Tutorial 25
```

程序应该正常工作，但构建配置更加简洁和模块化。

---

## 第4步：安装和测试

### 配置安装规则

安装规则定义了如何将构建好的文件复制到系统目录，便于分发和使用。

**步骤 1**： 安装库文件

在 `MathFunctions/CMakeLists.txt` 末尾添加:

```cmake
# 安装库文件到 lib 目录
install(TARGETS MathFunctions DESTINATION lib)
# 安装头文件到 include 目录
install(FILES MathFunctions.h DESTINATION include)
```

**步骤 2**： 安装可执行文件

在顶级 `CMakeLists.txt` 末尾添加:

```cmake
# 安装可执行文件到 bin 目录
install(TARGETS Tutorial DESTINATION bin)
# 安装配置头文件到 include 目录
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  DESTINATION include
  )
```

**执行安装**：

```bash
# 构建项目
cmake --build .

# 安装到默认位置(通常需要管理员权限)
cmake --install .

# 或安装到自定义位置(推荐用于测试)
cmake --install . --prefix "/home/myuser/installdir"
```

**验证安装**：

```bash
cd /home/myuser/installdir/bin
./Tutorial 16
```

### 添加测试支持

测试确保代码按预期工作。CMake 集成了 CTest 测试框架。

在顶级 `CMakeLists.txt` 末尾添加:

```cmake
# 启用测试功能
enable_testing()

# 测试1: 程序能否正常运行
add_test(NAME Runs COMMAND Tutorial 25)

# 测试2: 检查使用说明是否正确显示
add_test(NAME Usage COMMAND Tutorial)
# 验证输出是否匹配正则表达式
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )

# 定义辅助函数简化测试添加
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# 添加多个数值测试
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is ([-nan|nan|0])")  # 处理负数
do_test(Tutorial 0.0001 "0.0001 is 0.01")
```

**运行测试**：

```bash
# 列出所有测试
ctest -N

# 运行测试并显示详细输出
ctest -VV

# 多配置生成器需指定配置类型
ctest -C Debug -VV
```

**理解测试**：

- 第一个测试检查程序是否能运行而不崩溃
- `PASS_REGULAR_EXPRESSION` 验证输出是否包含特定文本
- `do_test` 函数通过循环创建多个类似的测试,避免重复代码

---

## 第5步：添加系统自检

有时代码需要适应不同平台的差异。本步骤演示如何检测平台功能并相应调整代码。

### 检测系统功能

我们将检测平台是否提供 `log` 和 `exp` 函数,如果有就用它们优化平方根计算。

在 `MathFunctions/CMakeLists.txt` 开头添加:

```cmake
# 引入符号检测模块
include(CheckSymbolExists)

# 检查 math.h 中是否定义了 log 函数
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)

# 某些平台需要链接数学库 m
if(NOT (HAVE_LOG AND HAVE_EXP))
  # 清除缓存的检测结果
  unset(HAVE_LOG CACHE)
  unset(HAVE_EXP CACHE)
  # 尝试链接 m 库后重新检测
  set(CMAKE_REQUIRED_LIBRARIES "m")
  check_symbol_exists(log "math.h" HAVE_LOG)
  check_symbol_exists(exp "math.h" HAVE_EXP)
  # 如果需要 m 库,则链接它
  if(HAVE_LOG AND HAVE_EXP)
    target_link_libraries(MathFunctions PRIVATE m)
  endif()
endif()
```

### 将检测结果传递给代码

```cmake
# 如果找到这些函数,定义宏供代码使用
if(HAVE_LOG AND HAVE_EXP)
  # PRIVATE 表示这些定义只在编译 MathFunctions 时有效
  target_compile_definitions(MathFunctions
                             PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()
```

### 在代码中使用检测结果

修改 `MathFunctions/mysqrt.cxx`:

```cpp
#include <cmath>  // 需要数学函数

double mysqrt(double x)
{
  if (x <= 0) {
    return 0;
  }

  // 如果平台支持,使用 log 和 exp 来计算
  #if defined(HAVE_LOG) && defined(HAVE_EXP)
    double result = exp(log(x) * 0.5);
    std::cout << "Computing sqrt of " << x << " to be " << result
              << " using log and exp" << std::endl;
  #else
    // 回退到基本算法
    double result = x;
    // ... 原有的迭代算法 ...
  #endif

  return result;
}
```

**测试**：

```bash
cmake ../Step5
cmake --build .
./Tutorial 9
# 观察输出,看是否显示 "using log and exp"
```

---

## 第6步：添加自定义命令和生成文件

本步骤演示如何在构建过程中生成源代码文件。我们将生成一个预计算的平方根表。

### 理解构建流程

```
编译时间            运行 MakeTable 程序
    ↓                     ↓
源文件 → 生成 Table.h → 编译 mysqrt.cxx → 生成库
```

### 步骤 1：创建表生成程序

`MathFunctions/MakeTable.cxx` 已提供,它生成包含平方根表的 C++ 头文件。

### 步骤 2：将生成程序添加到构建

修改 `MathFunctions/CMakeLists.txt`:

```cmake
# 首先移除 log/exp 检测代码(我们用预计算表代替)

# 创建生成表的程序
add_executable(MakeTable MakeTable.cxx)

# 添加自定义命令生成头文件
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h  # 输出文件
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h  # 运行的命令
  DEPENDS MakeTable  # 依赖关系,MakeTable 变化时重新生成
  )
```

### 步骤 3：使用生成的文件

```cmake
# 将生成的头文件添加到库的源文件列表
add_library(MathFunctions
            mysqrt.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/Table.h  # 生成的文件
            )

# 添加二进制目录到包含路径,以便找到生成的头文件
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PRIVATE ${CMAKE_CURRENT_BINARY_DIR}  # PRIVATE:只在编译库时需要
          )
```

### 步骤 4：在代码中使用表

修改 `MathFunctions/mysqrt.cxx`:

```cpp
#include "Table.h"  // 包含生成的表

double mysqrt(double x)
{
  if (x <= 0) {
    return 0;
  }

  // 使用预计算表获取初始值
  double result = x;
  if (x >= 1 && x < 10) {
    std::cout << "Use the table to help find an initial value" << std::endl;
    result = sqrtTable[static_cast<int>(x)];
  }

  // 用牛顿法迭代改进结果
  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    double delta = x - (result * result);
    result = result + 0.5 * delta / result;
    std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
  }

  return result;
}
```

### 观察构建过程

```bash
cmake ../Step6
cmake --build .
```

您会看到:

1. 首先编译并链接 MakeTable
2. 运行 MakeTable 生成 Table.h
3. 编译包含 Table.h 的 mysqrt.cxx
4. 最后链接所有组件

---

## 第7步：构建安装程序

CPack 可以创建可分发的安装包,支持多种格式(ZIP、TGZ、DEB、RPM、NSIS 等)。

### 配置 CPack

在顶级 `CMakeLists.txt` 末尾添加:

```cmake
# 包含必要的系统运行时库(如 Visual C++ 运行时)
include(InstallRequiredSystemLibraries)

# 设置许可证文件
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")

# 设置版本号(CPack 会在包名中使用)
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")

# 包含 CPack 模块,启用打包功能
include(CPack)
```

### 生成安装包

**生成二进制包**：

```bash
# 使用默认生成器(取决于平台)
cpack

# 指定生成器和配置
cpack -G ZIP -C Debug        # Windows ZIP 包
cpack -G TGZ -C Release      # Linux tar.gz 包
cpack -G DEB                 # Debian 包
cpack -G NSIS                # Windows 安装程序
```

**生成源代码包**：

```bash
# 使用源代码配置文件
cpack --config CPackSourceConfig.cmake
```

**或使用 Make**：

```bash
make package
```

### 测试安装包

1. 解压或运行生成的安装包
2. 找到安装的可执行文件
3. 运行并验证功能正常

---

## 第8步：添加仪表板支持

CTest 可以将测试结果上传到 CDash 仪表板,用于持续集成和监控。

### 配置 CTest

修改顶级 `CMakeLists.txt`,替换:

```cmake
enable_testing()
```

为:

```cmake
# CTest 模块会自动调用 enable_testing()
include(CTest)
```

### 配置仪表板

创建 `CTestConfig.cmake` 文件：

```cmake
# 项目名称
set(CTEST_PROJECT_NAME "CMakeTutorial")
# 每日构建开始时间
set(CTEST_NIGHTLY_START_TIME "00:00:00 EST")

# CDash 服务器配置
set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "my.cdash.org")
set(CTEST_DROP_LOCATION "/submit.php?project=CMakeTutorial")
set(CTEST_DROP_SITE_CDASH TRUE)
```

### 提交测试结果

```bash
# 配置项目(不构建)
cmake ../Step8

# 运行实验性构建和测试,并提交结果
ctest [-VV] -D Experimental

# 多配置生成器需指定配置
ctest [-VV] -C Debug -D Experimental
```

**或在 IDE 中**：

- 构建 `Experimental` 目标

**查看结果**：
访问 <https://my.cdash.org/index.php?project=CMakeTutorial>

**其他仪表板类型**：

- `Nightly`： 每日构建
- `Continuous`： 持续集成构建

---

## 第9步：混合静态库和共享库

演示如何让用户选择构建静态库还是共享库,以及如何处理两者的差异。

### 添加库类型选项

修改顶级 `CMakeLists.txt`:

```cmake
# 控制是否构建共享库(默认开启)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# Windows 需要特殊处理:设置输出目录,避免 DLL 路径问题
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")  # .lib/.a
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")  # .so
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")  # .exe/.dll
```

### 重构库结构

现在 MathFunctions 将封装实现细节,调用者不需要知道是否使用自定义实现。

**MathFunctions/CMakeLists.cmake** 完整版本：

```cmake
# 主接口库
add_library(MathFunctions MathFunctions.cxx)

target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

# 控制实现方式的选项
option(USE_MYMATH "Use tutorial provided math implementation" ON)

if(USE_MYMATH)
  # 定义宏,让 MathFunctions.cxx 知道使用哪个实现
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  # 表生成工具
  add_executable(MakeTable MakeTable.cxx)

  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
    )

  # 实现库(强制静态)
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              ${CMAKE_CURRENT_BINARY_DIR}/Table.h
              )

  target_include_directories(SqrtLibrary PRIVATE
                             ${CMAKE_CURRENT_BINARY_DIR}
                             )

  # 关键:即使构建共享库,静态库也需要位置无关代码
  set_target_properties(SqrtLibrary PROPERTIES
                        POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                        )

  # 私有链接:外部不需要知道 SqrtLibrary
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

# Windows DLL 导出声明
target_compile_definitions(MathFunctions PRIVATE "EXPORTING_MYMATH")

# 安装规则
set(installable_libs MathFunctions)
if(TARGET SqrtLibrary)
  list(APPEND installable_libs SqrtLibrary)
endif()
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
```

### 处理 Windows DLL 导出

修改 `MathFunctions/MathFunctions.h`:

```cpp
// Windows DLL 导出/导入宏
#if defined(_WIN32)
  #if defined(EXPORTING_MYMATH)
    #define DECLSPEC __declspec(dllexport)  // 构建 DLL 时
  #else
    #define DECLSPEC __declspec(dllimport)  // 使用 DLL 时
  #endif
#else
  #define DECLSPEC  // 非 Windows 平台不需要
#endif

namespace mathfunctions {
  // 导出函数声明
  double DECLSPEC sqrt(double x);
}
```

### 简化主程序

修改 `tutorial.cxx`,移除条件编译:

```cpp
// 始终包含和使用 MathFunctions
#include "MathFunctions.h"

// ...

const double outputValue = mathfunctions::sqrt(inputValue);
```

### 测试不同配置

```bash
# 测试共享库(默认)
cmake ../Step9
cmake --build .

# 测试静态库
cmake ../Step9 -DBUILD_SHARED_LIBS=OFF
cmake --build .

# 切换自定义实现
cmake ../Step9 -DUSE_MYMATH=OFF
cmake --build .
```

**练习**: 查找并使用 `GenerateExportHeader` 模块简化 DLL 导出处理。

---

## 第10步：添加生成器表达式

生成器表达式允许根据构建配置动态生成内容,提供更灵活的配置。

### 理解生成器表达式

**语法**： `$<...>`

**类型**：

- **逻辑**： `$<0:...>`(空), `$<1:...>`(内容)
- **信息**： `$<CONFIG>`, `$<PLATFORM_ID>`, `$<COMPILE_LANGUAGE>`
- **条件**： `$<IF:condition,true_value,false_value>`

### 使用接口库传递编译选项

替换全局 C++ 标准设置:

```cmake
# 移除这些
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# 创建接口库来管理编译要求
add_library(tutorial_compiler_flags INTERFACE)

# 设置 C++ 标准
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)
```

### 添加编译器警告

不同编译器有不同的警告选项，使用生成器表达式处理：

```cmake
# 定义编译器类型变量
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# 根据编译器添加不同的警告选项
target_compile_options(tutorial_compiler_flags INTERFACE
  # GCC 风格编译器的警告
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  # MSVC 编译器的警告
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
```

**解析**：

- `$<COMPILE_LANG_AND_ID:CXX,GNU>`: 如果是 C++ 且编译器是 GCC
- `$<BUILD_INTERFACE:...>`: 只在构建时应用，安装后不影响使用者
- `$<${gcc_like_cxx}:...>`: 如果变量为真，展开为内容

### 应用到目标

```cmake
# 在需要的目标上链接接口库
target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)
target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)
```

### 更多生成器表达式示例

```cmake
# 根据配置类型添加定义
target_compile_definitions(MyTarget PRIVATE
  $<$<CONFIG:Debug>:DEBUG_MODE>
  $<$<CONFIG:Release>:NDEBUG>
)

# 根据平台添加链接库
target_link_libraries(MyTarget PRIVATE
  $<$<PLATFORM_ID:Windows>:ws2_32>
  $<$<PLATFORM_ID:Linux>:pthread>
)
```

---

## 第11步：添加导出配置

让其他 CMake 项目能够轻松使用我们的库,就像使用 `find_package(Tutorial)` 一样。

### 导出构建树目标

**步骤 1**： 导出安装的目标

修改 `MathFunctions/CMakeLists.txt`:

```cmake
set(installable_libs MathFunctions tutorial_compiler_flags)
if(TARGET SqrtLibrary)
  list(APPEND installable_libs SqrtLibrary)
endif()

# 添加 EXPORT,生成目标导出信息
install(TARGETS ${installable_libs}
        DESTINATION lib
        EXPORT MathFunctionsTargets)  # 导出名称
install(FILES MathFunctions.h DESTINATION include)
```

**步骤 2**： 安装导出文件

在顶级 `CMakeLists.txt` 添加:

```cmake
# 安装导出的目标信息
install(EXPORT MathFunctionsTargets
  FILE MathFunctionsTargets.cmake
  DESTINATION lib/cmake/MathFunctions
)
```

**步骤 3**： 修正包含目录

为了支持构建树和安装树，使用生成器表达式：

```cmake
target_include_directories(MathFunctions
                           INTERFACE
                            # 构建时使用源目录
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            # 安装后使用 include 目录
                            $<INSTALL_INTERFACE:include>
                           )
```

### 生成配置文件

**步骤 1**： 创建配置文件模板

创建 `Config.cmake.in`:

```cmake
# @PACKAGE_INIT@ 会被替换为必要的初始化代码
@PACKAGE_INIT@

# 包含目标定义
include("${CMAKE_CURRENT_LIST_DIR}/MathFunctionsTargets.cmake")
```

**步骤 2**： 配置并安装配置文件

在顶级 `CMakeLists.txt` 添加:

```cmake
include(CMakePackageConfigHelpers)

# 生成配置文件
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/MathFunctions"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# 生成版本文件(用于版本兼容性检查)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake"
  VERSION "${Tutorial_VERSION_MAJOR}.${Tutorial_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion  # 接受任何更新的版本
)

# 安装配置文件
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake
  DESTINATION lib/cmake/MathFunctions
)
```

### 支持从构建树使用

在顶级 `CMakeLists.txt` 添加:

```cmake
# 导出到构建树,无需安装即可使用
export(EXPORT MathFunctionsTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsTargets.cmake"
)
```

### 使用导出的包

其他项目现在可以这样使用:

```cmake
find_package(MathFunctions 1.0 REQUIRED)
target_link_libraries(MyApp PRIVATE MathFunctions)
```

CMake 会自动:

- 找到包含目录
- 链接必要的库
- 应用编译选项

---

## 第12步：打包调试版和发布版

**注意**： 此方法仅适用于单配置生成器(Make, Ninja),不适用于多配置生成器(Visual Studio, Xcode)。

### 设置调试后缀

在顶级 `CMakeLists.txt` 开头:

```cmake
# 调试版本的可执行文件和库添加 'd' 后缀
set(CMAKE_DEBUG_POSTFIX d)

add_library(tutorial_compiler_flags INTERFACE)
```

为可执行文件设置:

```cmake
add_executable(Tutorial tutorial.cxx)
set_target_properties(Tutorial PROPERTIES
                      DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
```

### 添加库版本号

在 `MathFunctions/CMakeLists.txt`:

```cmake
# 设置库的版本号
set_property(TARGET MathFunctions PROPERTY VERSION "1.0.0")
# 设置 soname 版本(Linux 共享库)
set_property(TARGET MathFunctions PROPERTY SOVERSION "1")
```

### 创建多配置目录

```bash
mkdir -p debug release

# 配置调试版本
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

# 配置发布版本
cd ../release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

### 创建多配置打包脚本

创建 `MultiCPackConfig.cmake`:

```cmake
# 包含默认的 CPack 配置
include("release/CPackConfig.cmake")

# 指定要打包的多个构建
set(CPACK_INSTALL_CMAKE_PROJECTS
    "debug;Tutorial;ALL;/"      # 调试版本
    "release;Tutorial;ALL;/"    # 发布版本
    )
```

### 生成包

```bash
# 使用自定义配置文件打包
cpack --config MultiCPackConfig.cmake
```

生成的包将包含:

- `Tutorial`(发布版可执行文件)
- `Tutoriald`(调试版可执行文件)
- `libMathFunctions.so.1.0.0`(发布版库)
- `libMathFunctionsd.so.1.0.0`(调试版库)

---

## 总结

通过这 12 个步骤，您学习了：

1. **基础概念**： 项目配置、版本管理、C++ 标准
2. **项目组织**： 库、子目录、模块化设计
3. **现代 CMake**： 使用要求、生成器表达式、接口库
4. **质量保证**： 测试、系统自检、持续集成
5. **分发**： 安装规则、打包、导出配置
6. **高级特性**： 自定义命令、混合库类型、多配置打包

**最佳实践**：

- 使用 `target_*` 命令而非全局变量
- 正确使用 PUBLIC/PRIVATE/INTERFACE
- 利用生成器表达式提高灵活性
- 为库提供配置文件以便其他项目使用
- 保持构建和源目录分离

继续探索 [CMake 官方文档](https://cmake.org/documentation/) 了解更多功能!
