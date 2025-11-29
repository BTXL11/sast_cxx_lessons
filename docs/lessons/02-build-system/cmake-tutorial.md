# CMake 教程

## 目录

- CMake 教程
  - 简介
  - 基础起点（步骤 1）
    - 添加版本号和配置头文件
    - 指定 C++ 标准
    - 构建和测试
  - 添加库（步骤 2）
  - 为库添加使用要求（步骤 3）
  - 安装和测试（步骤 4）
    - 安装规则
    - 测试支持
  - 添加系统自检（步骤 5）
  - 添加自定义命令和生成文件（步骤 6）
  - 构建安装程序（步骤 7）
  - 添加仪表板支持（步骤 8）
  - 混合静态库和共享库（步骤 9）
  - 添加生成器表达式（步骤 10）
  - 添加导出配置（步骤 11）
  - 打包调试版和发布版（步骤 12）

## 简介

CMake 教程提供了一个循序渐进的指南，涵盖了 CMake 帮助解决的常见构建系统问题。在一个示例项目中看到各种主题如何协同工作会非常有帮助。教程文档和示例源代码可以在 CMake 源代码树的 `Help/guide/tutorial` 目录中找到。每个步骤都有自己的子目录，其中包含可用作起点的代码。教程示例是渐进式的，因此每个步骤都提供了前一步骤的完整解决方案。

## 基础起点（步骤 1）

最基础的项目是从源代码文件构建的可执行文件。对于简单的项目，只需要一个三行的 `CMakeLists.txt` 文件。这将是我们教程的起点。在 `Step1` 目录中创建一个 `CMakeLists.txt` 文件，内容如下：

```cmake
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(Tutorial)

# 添加可执行文件
add_executable(Tutorial tutorial.cxx)
```

请注意，此示例在 `CMakeLists.txt` 文件中使用小写命令。CMake 支持大写、小写和混合大小写命令。`tutorial.cxx` 的源代码在 `Step1` 目录中提供，可用于计算数字的平方根。

### 添加版本号和配置头文件

我们将添加的第一个功能是为可执行文件和项目提供版本号。虽然我们可以完全在源代码中执行此操作，但使用 `CMakeLists.txt` 提供了更大的灵活性。

首先，修改 `CMakeLists.txt` 文件以使用 `project` 命令设置项目名称和版本号。

```cmake
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(Tutorial VERSION 1.0)
```

然后，配置一个头文件以将版本号传递给源代码：

```cmake
configure_file(TutorialConfig.h.in TutorialConfig.h)
```

由于配置的文件将被写入二进制树，我们必须将该目录添加到搜索包含文件的路径列表中。在 `CMakeLists.txt` 文件的末尾添加以下行：

```cmake
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
```

使用您喜欢的编辑器，在源目录中创建 `TutorialConfig.h.in`，内容如下：

```cpp
// Tutorial 的配置选项和设置
#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```

当 CMake 配置此头文件时，`@Tutorial_VERSION_MAJOR@` 和 `@Tutorial_VERSION_MINOR@` 的值将被替换。

接下来修改 `tutorial.cxx` 以包含配置的头文件 `TutorialConfig.h`。

最后，让我们通过更新 `tutorial.cxx` 来打印可执行文件名称和版本号，如下所示：

```cpp
  if (argc < 2) {
    // 报告版本
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }
```

### 指定 C++ 标准

接下来，让我们通过将 `atof` 替换为 `std::stod` 来向项目添加一些 C++11 功能到 `tutorial.cxx`。同时，删除 `#include <cstdlib>`。

```cpp
  const double inputValue = std::stod(argv[1]);
```

我们需要在 CMake 代码中明确声明它应该使用正确的标志。在 CMake 中启用对特定 C++ 标准支持的最简单方法是使用 `CMAKE_CXX_STANDARD` 变量。对于本教程，将 `CMakeLists.txt` 文件中的 `CMAKE_CXX_STANDARD` 变量设置为 11，将 `CMAKE_CXX_STANDARD_REQUIRED` 设置为 True。确保在调用 `add_executable` 之前添加 `CMAKE_CXX_STANDARD` 声明。

```cmake
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(Tutorial VERSION 1.0)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

### 构建和测试

运行 `cmake` 可执行文件或 `cmake-gui` 来配置项目，然后使用您选择的构建工具进行构建。

例如，从命令行我们可以导航到 CMake 源代码树的 `Help/guide/tutorial` 目录并创建一个构建目录：

```bash
mkdir Step1_build
```

接下来，导航到构建目录并运行 CMake 来配置项目并生成本机构建系统：

```bash
cd Step1_build
cmake ../Step1
```

然后调用该构建系统来实际编译/链接项目：

```bash
cmake --build .
```

最后，尝试使用这些命令来使用新构建的 Tutorial：

```bash
Tutorial 4294967296
Tutorial 10
Tutorial
```

## 添加库（步骤 2）

现在我们将向项目添加一个库。此库将包含我们自己的计算数字平方根的实现。然后可执行文件可以使用此库而不是编译器提供的标准平方根函数。

对于本教程，我们将把库放入名为 `MathFunctions` 的子目录中。此目录已包含头文件 `MathFunctions.h` 和源文件 `mysqrt.cxx`。源文件有一个名为 `mysqrt` 的函数，它提供与编译器的 `sqrt` 函数类似的功能。

将以下一行 `CMakeLists.txt` 文件添加到 `MathFunctions` 目录：

```cmake
add_library(MathFunctions mysqrt.cxx)
```

要使用新库，我们将在顶级 `CMakeLists.txt` 文件中添加一个 `add_subdirectory` 调用，以便构建该库。我们将新库添加到可执行文件，并将 `MathFunctions` 添加为包含目录，以便可以找到 `mysqrt.h` 头文件。顶级 `CMakeLists.txt` 文件的最后几行现在应该如下所示：

```cmake
# 添加 MathFunctions 库
add_subdirectory(MathFunctions)

# 添加可执行文件
add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC MathFunctions)

# 将二进制树添加到包含文件的搜索路径中
# 以便我们能找到 TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          )
```

现在让我们使 `MathFunctions` 库成为可选的。虽然对于本教程来说确实没有必要这样做，但对于大型项目来说这是常见的情况。第一步是向顶级 `CMakeLists.txt` 文件添加一个选项。

```cmake
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 配置头文件以将一些 CMake 设置
# 传递给源代码
configure_file(TutorialConfig.h.in TutorialConfig.h)
```

此选项将在 `cmake-gui` 和 `ccmake` 中显示，默认值为 ON，用户可以更改。此设置将存储在缓存中，这样用户就不需要在每次运行 CMake 时都设置该值。

下一个更改是使构建和链接 `MathFunctions` 库成为条件的。为此，我们将顶级 `CMakeLists.txt` 文件的末尾更改为如下所示：

```cmake
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# 添加可执行文件
add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# 将二进制树添加到包含文件的搜索路径中
# 以便我们能找到 TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )
```

请注意使用变量 `EXTRA_LIBS` 来收集任何可选库，以便稍后链接到可执行文件中。变量 `EXTRA_INCLUDES` 用于类似的可选头文件。这是处理许多可选组件时的经典方法，我们将在下一步中介绍现代方法。

对源代码的相应更改非常简单。首先，在 `tutorial.cxx` 中，如果我们需要，包含 `MathFunctions.h` 头文件：

```cpp
#ifdef USE_MYMATH
#  include "MathFunctions.h"
#endif
```

然后，在同一文件中，使 `USE_MYMATH` 控制使用哪个平方根函数：

```cpp
#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  const double outputValue = sqrt(inputValue);
#endif
```

由于源代码现在需要 `USE_MYMATH`，我们可以使用以下行将其添加到 `TutorialConfig.h.in`：

```cpp
#cmakedefine USE_MYMATH
```

**练习**：为什么在 `USE_MYMATH` 选项之后配置 `TutorialConfig.h.in` 很重要？如果我们颠倒这两者会发生什么？

运行 `cmake` 可执行文件或 `cmake-gui` 来配置项目，然后使用您选择的构建工具进行构建。然后运行构建的 Tutorial 可执行文件。

现在让我们更新 `USE_MYMATH` 的值。最简单的方法是使用 `cmake-gui`，或者如果您在终端中使用 `ccmake`。或者，如果您想从命令行更改选项，请尝试：

```bash
cmake ../Step2 -DUSE_MYMATH=OFF
```

重新构建并再次运行教程。

哪个函数给出更好的结果，`sqrt` 还是 `mysqrt`？

## 为库添加使用要求（步骤 3）

使用要求允许对库或可执行文件的链接和包含行进行更好的控制，同时还可以更好地控制 CMake 内部目标的传递属性。利用使用要求的主要命令是：

- `target_compile_definitions`
- `target_compile_options`
- `target_include_directories`
- `target_link_libraries`

让我们重构我们在添加库（步骤 2）中的代码，以使用现代 CMake 的使用要求方法。我们首先声明任何链接到 `MathFunctions` 的人都需要包含当前源目录，而 `MathFunctions` 本身不需要。因此，这可以成为 `INTERFACE` 使用要求。

请记住，`INTERFACE` 意味着消费者需要但生产者不需要的东西。将以下行添加到 `MathFunctions/CMakeLists.txt` 的末尾：

```cmake
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
```

现在我们已经为 `MathFunctions` 指定了使用要求，我们可以安全地从顶级 `CMakeLists.txt` 中删除对 `EXTRA_INCLUDES` 变量的使用，这里：

```cmake
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif()
```

和这里：

```cmake
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
```

完成此操作后，运行 `cmake` 可执行文件或 `cmake-gui` 来配置项目，然后使用您选择的构建工具或从构建目录使用 `cmake --build .` 进行构建。

## 安装和测试（步骤 4）

现在我们可以开始向项目添加安装规则和测试支持。

### 安装规则

安装规则相当简单：对于 `MathFunctions`，我们想要安装库和头文件；对于应用程序，我们想要安装可执行文件和配置的头文件。

因此在 `MathFunctions/CMakeLists.txt` 的末尾我们添加：

```cmake
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
```

在顶级 `CMakeLists.txt` 的末尾我们添加：

```cmake
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  DESTINATION include
  )
```

这就是创建教程的基本本地安装所需的全部内容。

现在运行 `cmake` 可执行文件或 `cmake-gui` 来配置项目，然后使用您选择的构建工具进行构建。

然后通过从命令行使用 `cmake` 命令的安装选项运行安装步骤（在 3.15 中引入，旧版本的 CMake 必须使用 `make install`）。对于多配置工具，不要忘记使用 `--config` 参数指定配置。如果使用 IDE，只需构建 INSTALL 目标。此步骤将安装适当的头文件、库和可执行文件。例如：

```bash
cmake --install .
```

CMake 变量 `CMAKE_INSTALL_PREFIX` 用于确定文件将安装的根目录。如果使用 `cmake --install` 命令，可以通过 `--prefix` 参数覆盖安装前缀。例如：

```bash
cmake --install . --prefix "/home/myuser/installdir"
```

导航到安装目录并验证已安装的 Tutorial 是否运行。

### 测试支持

接下来让我们测试我们的应用程序。在顶级 `CMakeLists.txt` 文件的末尾，我们可以启用测试，然后添加一些基本测试来验证应用程序是否正常工作。

```cmake
enable_testing()

# 应用程序是否运行
add_test(NAME Runs COMMAND Tutorial 25)

# 使用消息是否有效？
add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )

# 定义一个函数以简化添加测试
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# 做一堆基于结果的测试
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is [-nan|nan|0]")
do_test(Tutorial 0.0001 "0.0001 is 0.01")
```

第一个测试只是验证应用程序运行，不会发生段错误或以其他方式崩溃，并且返回值为零。这是 CTest 测试的基本形式。

下一个测试使用 `PASS_REGULAR_EXPRESSION` 测试属性来验证测试的输出包含某些字符串。在这种情况下，验证在提供不正确数量的参数时是否打印使用消息。

最后，我们有一个名为 `do_test` 的函数，它运行应用程序并验证计算的平方根对于给定输入是否正确。对于 `do_test` 的每次调用，都会根据传递的参数向项目添加另一个具有名称、输入和预期结果的测试。

重新构建应用程序，然后 cd 到二进制目录并运行 `ctest` 可执行文件：`ctest -N` 和 `ctest -VV`。对于多配置生成器（例如 Visual Studio），必须指定配置类型。要在调试模式下运行测试，例如，从构建目录（而不是 Debug 子目录！）使用 `ctest -C Debug -VV`。或者，从 IDE 构建 RUN_TESTS 目标。

## 添加系统自检（步骤 5）

让我们考虑向项目添加一些代码，这些代码取决于目标平台可能没有的功能。对于此示例，我们将添加一些代码，这些代码取决于目标平台是否具有 `log` 和 `exp` 函数。当然，几乎每个平台都有这些函数，但在本教程中假设它们不常见。

如果平台具有 `log` 和 `exp`，那么我们将在 `mysqrt` 函数中使用它们来计算平方根。我们首先使用 `MathFunctions/CMakeLists.txt` 中的 `CheckSymbolExists` 模块测试这些函数的可用性。在某些平台上，我们需要链接到 m 库。如果最初未找到 `log` 和 `exp`，则需要 m 库并重试。

```cmake
include(CheckSymbolExists)
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)
if(NOT (HAVE_LOG AND HAVE_EXP))
  unset(HAVE_LOG CACHE)
  unset(HAVE_EXP CACHE)
  set(CMAKE_REQUIRED_LIBRARIES "m")
  check_symbol_exists(log "math.h" HAVE_LOG)
  check_symbol_exists(exp "math.h" HAVE_EXP)
  if(HAVE_LOG AND HAVE_EXP)
    target_link_libraries(MathFunctions PRIVATE m)
  endif()
endif()
```

如果可用，使用 `target_compile_definitions` 将 `HAVE_LOG` 和 `HAVE_EXP` 指定为 `PRIVATE` 编译定义。

```cmake
if(HAVE_LOG AND HAVE_EXP)
  target_compile_definitions(MathFunctions
                             PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()
```

如果系统上有 `log` 和 `exp`，那么我们将在 `mysqrt` 函数中使用它们来计算平方根。将以下代码添加到 `MathFunctions/mysqrt.cxx` 中的 `mysqrt` 函数（不要忘记在返回结果之前的 `#endif`！）：

```cpp
#if defined(HAVE_LOG) && defined(HAVE_EXP)
  double result = exp(log(x) * 0.5);
  std::cout << "Computing sqrt of " << x << " to be " << result
            << " using log and exp" << std::endl;
#else
  double result = x;
```

我们还需要修改 `mysqrt.cxx` 以包含 `cmath`。

```cpp
#include <cmath>
```

运行 `cmake` 可执行文件或 `cmake-gui` 来配置项目，然后使用您选择的构建工具进行构建并运行 Tutorial 可执行文件。

现在哪个函数给出更好的结果，`sqrt` 还是 `mysqrt`？

## 添加自定义命令和生成文件（步骤 6）

假设，出于本教程的目的，我们决定永远不想使用平台的 `log` 和 `exp` 函数，而是想生成一个预计算值表以在 `mysqrt` 函数中使用。在本节中，我们将在构建过程中创建表，然后将该表编译到我们的应用程序中。

首先，让我们删除 `MathFunctions/CMakeLists.txt` 中对 `log` 和 `exp` 函数的检查。然后从 `mysqrt.cxx` 中删除对 `HAVE_LOG` 和 `HAVE_EXP` 的检查。同时，我们可以删除 `#include <cmath>`。

在 `MathFunctions` 子目录中，提供了一个名为 `MakeTable.cxx` 的新源文件来生成表。

查看文件后，我们可以看到该表是作为有效的 C++ 代码生成的，并且输出文件名作为参数传入。

下一步是将适当的命令添加到 `MathFunctions/CMakeLists.txt` 文件以构建 MakeTable 可执行文件，然后将其作为构建过程的一部分运行。需要几个命令来完成此操作。

首先，在 `MathFunctions/CMakeLists.txt` 的顶部，添加 MakeTable 的可执行文件，就像添加任何其他可执行文件一样。

```cmake
add_executable(MakeTable MakeTable.cxx)
```

然后我们添加一个自定义命令，指定如何通过运行 MakeTable 来生成 `Table.h`。

```cmake
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
  )
```

接下来，我们必须让 CMake 知道 `mysqrt.cxx` 依赖于生成的文件 `Table.h`。这是通过将生成的 `Table.h` 添加到库 MathFunctions 的源列表来完成的。

```cmake
add_library(MathFunctions
            mysqrt.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/Table.h
            )
```

我们还必须将当前二进制目录添加到包含目录列表中，以便 `mysqrt.cxx` 可以找到并包含 `Table.h`。

```cmake
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
          )
```

现在让我们使用生成的表。首先，修改 `mysqrt.cxx` 以包含 `Table.h`。接下来，我们可以重写 mysqrt 函数以使用该表：

```cpp
double mysqrt(double x)
{
  if (x <= 0) {
    return 0;
  }

  // 使用表来帮助找到初始值
  double result = x;
  if (x >= 1 && x < 10) {
    std::cout << "Use the table to help find an initial value " << std::endl;
    result = sqrtTable[static_cast<int>(x)];
  }

  // 进行十次迭代
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

运行 `cmake` 可执行文件或 `cmake-gui` 来配置项目，然后使用您选择的构建工具进行构建。

当构建此项目时，它将首先构建 MakeTable 可执行文件。然后它将运行 MakeTable 来生成 `Table.h`。最后，它将编译包含 `Table.h` 的 `mysqrt.cxx` 以生成 MathFunctions 库。

运行 Tutorial 可执行文件并验证它是否正在使用该表。

## 构建安装程序（步骤 7）

接下来假设我们想要将我们的项目分发给其他人，以便他们可以使用它。我们希望在各种平台上提供二进制和源代码分发。这与我们之前在安装和测试（步骤 4）中所做的安装有点不同，在那里我们是从源代码构建的二进制文件进行安装。在此示例中，我们将构建支持二进制安装和包管理功能的安装包。为此，我们将使用 CPack 来创建特定于平台的安装程序。具体来说，我们需要在顶级 `CMakeLists.txt` 文件的底部添加几行。

```cmake
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)
```

这就是全部内容。我们首先包含 `InstallRequiredSystemLibraries`。此模块将包含当前平台项目所需的任何运行时库。接下来，我们设置一些 CPack 变量，用于存储此项目的许可证和版本信息。版本信息是在本教程前面设置的，`license.txt` 已包含在此步骤的顶级源目录中。

最后，我们包含 CPack 模块，该模块将使用这些变量和当前系统的一些其他属性来设置安装程序。

下一步是以通常的方式构建项目，然后运行 `cpack` 可执行文件。要构建二进制分发，从二进制目录运行：

```bash
cpack
```

要指定生成器，请使用 `-G` 选项。对于多配置构建，使用 `-C` 指定配置。例如：

```bash
cpack -G ZIP -C Debug
```

要创建源代码分发，您可以输入：

```bash
cpack --config CPackSourceConfig.cmake
```

或者，运行 `make package` 或从 IDE 右键单击 Package 目标并构建项目。

运行在二进制目录中找到的安装程序。然后运行已安装的可执行文件并验证它是否有效。

## 添加仪表板支持（步骤 8）

添加对将我们的测试结果提交到仪表板的支持很简单。我们已经在测试支持中为项目定义了许多测试。现在我们只需要运行这些测试并将它们提交到仪表板。为了包括对仪表板的支持，我们在顶级 `CMakeLists.txt` 中包含 CTest 模块。

替换：

```cmake
# 启用测试
enable_testing()
```

为：

```cmake
# 启用仪表板脚本
include(CTest)
```

CTest 模块将自动调用 `enable_testing()`，因此我们可以将其从 CMake 文件中删除。

我们还需要在顶级目录中创建一个 `CTestConfig.cmake` 文件，我们可以在其中指定项目的名称以及提交仪表板的位置。

```cmake
set(CTEST_PROJECT_NAME "CMakeTutorial")
set(CTEST_NIGHTLY_START_TIME "00:00:00 EST")

set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "my.cdash.org")
set(CTEST_DROP_LOCATION "/submit.php?project=CMakeTutorial")
set(CTEST_DROP_SITE_CDASH TRUE)
```

`ctest` 可执行文件在运行时将读取此文件。要创建一个简单的仪表板，您可以运行 `cmake` 可执行文件或 `cmake-gui` 来配置项目，但不要构建它。相反，切换目录到二进制树，然后运行：

```bash
ctest [-VV] -D Experimental
```

请记住，对于多配置生成器（例如 Visual Studio），必须指定配置类型：

```bash
ctest [-VV] -C Debug -D Experimental
```

或者，从 IDE 构建 Experimental 目标。

`ctest` 可执行文件将构建和测试项目，并将结果提交到 Kitware 的公共仪表板：<https://my.cdash.org/index.php?project=CMakeTutorial>

## 混合静态库和共享库（步骤 9）

在本节中，我们将展示如何使用 `BUILD_SHARED_LIBS` 变量来控制 `add_library` 的默认行为，并允许控制如何构建没有显式类型（`STATIC`、`SHARED`、`MODULE` 或 `OBJECT`）的库。

为此，我们需要将 `BUILD_SHARED_LIBS` 添加到顶级 `CMakeLists.txt`。我们使用 `option` 命令，因为它允许用户可选择地选择该值应为 ON 还是 OFF。

接下来，我们将重构 MathFunctions 成为一个真正的库，它封装了使用 `mysqrt` 或 `sqrt`，而不是要求调用代码执行此逻辑。这也意味着 `USE_MYMATH` 将不控制构建 MathFunctions，而是控制此库的行为。

第一步是更新顶级 `CMakeLists.txt` 的起始部分，使其看起来像：

```cmake
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(Tutorial VERSION 1.0)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 控制静态和共享库的构建位置，以便在 Windows 上
# 我们不需要修改路径来运行可执行文件
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# 配置头文件以仅传递版本号
configure_file(TutorialConfig.h.in TutorialConfig.h)

# 添加 MathFunctions 库
add_subdirectory(MathFunctions)

# 添加可执行文件
add_executable(Tutorial tutorial.cxx)
target_link_libraries(Tutorial PUBLIC MathFunctions)
```

现在我们已经使 MathFunctions 始终被使用，我们需要更新该库的逻辑。因此，在 `MathFunctions/CMakeLists.txt` 中，我们需要创建一个 SqrtLibrary，当 `USE_MYMATH` 启用时将有条件地构建和安装。现在，由于这是一个教程，我们将明确要求 SqrtLibrary 以静态方式构建。

最终结果是 `MathFunctions/CMakeLists.txt` 应该看起来像：

```cmake
# 添加运行的库
add_library(MathFunctions MathFunctions.cxx)

# 声明任何链接到我们的人都需要包含当前源目录
# 来找到 MathFunctions.h，而我们不需要。
target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

# 我们应该使用我们自己的数学函数吗
option(USE_MYMATH "Use tutorial provided math implementation" ON)
if(USE_MYMATH)

  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  # 首先我们添加生成表的可执行文件
  add_executable(MakeTable MakeTable.cxx)

  # 添加生成源代码的命令
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
    )

  # 只做 sqrt 的库
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              ${CMAKE_CURRENT_BINARY_DIR}/Table.h
              )

  # 声明我们依赖于我们的二进制目录来找到 Table.h
  target_include_directories(SqrtLibrary PRIVATE
                             ${CMAKE_CURRENT_BINARY_DIR}
                             )

  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

# 定义符号，声明我们在 Windows 上构建时使用 declspec(dllexport)
target_compile_definitions(MathFunctions PRIVATE "EXPORTING_MYMATH")

# 安装规则
set(installable_libs MathFunctions)
if(TARGET SqrtLibrary)
  list(APPEND installable_libs SqrtLibrary)
endif()
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
```

接下来，更新 `MathFunctions/mysqrt.cxx` 以使用 `mathfunctions` 和 `detail` 命名空间：

```cpp
#include <iostream>

#include "MathFunctions.h"

// 包含生成的表
#include "Table.h"

namespace mathfunctions {
namespace detail {
// 使用简单操作的 hack 平方根计算
double mysqrt(double x)
{
  if (x <= 0) {
    return 0;
  }

  // 使用表来帮助找到初始值
  double result = x;
  if (x >= 1 && x < 10) {
    std::cout << "Use the table to help find an initial value " << std::endl;
    result = sqrtTable[static_cast<int>(x)];
  }

  // 进行十次迭代
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
}
}
```

我们还需要在 `tutorial.cxx` 中进行一些更改，使其不再使用 `USE_MYMATH`：

1. 始终包含 `MathFunctions.h`
2. 始终使用 `mathfunctions::sqrt`
3. 不包含 cmath

最后，更新 `MathFunctions/MathFunctions.h` 以使用 dll 导出定义：

```cpp
#if defined(_WIN32)
#  if defined(EXPORTING_MYMATH)
#    define DECLSPEC __declspec(dllexport)
#  else
#    define DECLSPEC __declspec(dllimport)
#  endif
#else // 非 Windows
#  define DECLSPEC
#endif

namespace mathfunctions {
double DECLSPEC sqrt(double x);
}
```

此时，如果您构建所有内容，您可能会注意到链接失败，因为我们将没有位置无关代码的静态库与具有位置无关代码的库组合在一起。解决方案是明确将 SqrtLibrary 的 `POSITION_INDEPENDENT_CODE` 目标属性设置为 True，无论构建类型如何。

```cmake
  # 声明当默认是共享库时 SqrtLibrary 需要 PIC
  set_target_properties(SqrtLibrary PROPERTIES
                        POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                        )

  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
```

**练习**：我们修改了 `MathFunctions.h` 以使用 dll 导出定义。使用 CMake 文档，您能找到一个辅助模块来简化这一过程吗？

## 添加生成器表达式（步骤 10）

生成器表达式在构建系统生成期间进行评估，以生成特定于每个构建配置的信息。

生成器表达式允许在许多目标属性的上下文中使用，例如 `LINK_LIBRARIES`、`INCLUDE_DIRECTORIES`、`COMPILE_DEFINITIONS` 等。在使用命令填充这些属性时也可以使用它们，例如 `target_link_libraries`、`target_include_directories`、`target_compile_definitions` 等。

生成器表达式可用于启用条件链接、编译时使用的条件定义、条件包含目录等。条件可以基于构建配置、目标属性、平台信息或任何其他可查询的信息。

有不同类型的生成器表达式，包括逻辑表达式、信息表达式和输出表达式。

逻辑表达式用于创建条件输出。基本表达式是 0 和 1 表达式。`$<0:...>` 结果为空字符串，`<1:...>` 结果为 "…" 的内容。它们也可以嵌套。

生成器表达式的常见用法是有条件地添加编译器标志，例如用于语言级别或警告的标志。一个很好的模式是将此信息与 `INTERFACE` 目标关联，允许此信息传播。让我们首先构造一个 `INTERFACE` 目标并指定所需的 C++ 标准级别 11，而不是使用 `CMAKE_CXX_STANDARD`。

因此以下代码：

```cmake
# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

将被替换为：

```cmake
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)
```

接下来，我们添加我们想要用于项目的所需编译器警告标志。由于警告标志因编译器而异，我们使用 `COMPILE_LANG_AND_ID` 生成器表达式来控制根据语言和编译器 ID 集应用哪些标志，如下所示：

```cmake
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
```

看到这一点，我们看到警告标志被封装在 `BUILD_INTERFACE` 条件内。这样做是为了使我们安装的项目的消费者不会继承我们的警告标志。

**练习**：修改 `MathFunctions/CMakeLists.txt`，以便所有目标都有对 `tutorial_compiler_flags` 的 `target_link_libraries` 调用。

## 添加导出配置（步骤 11）

在教程的安装和测试（步骤 4）期间，我们添加了 CMake 安装项目的库和头文件的功能。在构建安装程序（步骤 7）期间，我们添加了打包此信息的功能，以便将其分发给其他人。

下一步是添加必要的信息，以便其他 CMake 项目可以使用我们的项目，无论是从构建目录、本地安装还是打包时。

第一步是更新我们的 `install(TARGETS)` 命令，不仅指定 `DESTINATION`，还指定 `EXPORT`。`EXPORT` 关键字生成并安装一个 CMake 文件，其中包含从安装树导入安装命令中列出的所有目标的代码。所以让我们通过更新 `MathFunctions/CMakeLists.txt` 中的安装命令来明确导出 MathFunctions 库，使其看起来像：

```cmake
set(installable_libs MathFunctions tutorial_compiler_flags)
if(TARGET SqrtLibrary)
  list(APPEND installable_libs SqrtLibrary)
endif()
install(TARGETS ${installable_libs}
        DESTINATION lib
        EXPORT MathFunctionsTargets)
install(FILES MathFunctions.h DESTINATION include)
```

现在我们已经导出了 MathFunctions，我们还需要明确安装生成的 `MathFunctionsTargets.cmake` 文件。这是通过将以下内容添加到顶级 `CMakeLists.txt` 的底部来完成的：

```cmake
install(EXPORT MathFunctionsTargets
  FILE MathFunctionsTargets.cmake
  DESTINATION lib/cmake/MathFunctions
)
```

此时，您应该尝试运行 CMake。如果一切设置正确，您将看到 CMake 将生成一个如下所示的错误：

```
Target "MathFunctions" INTERFACE_INCLUDE_DIRECTORIES property contains
path:

  "/Users/robert/Documents/CMakeClass/Tutorial/Step11/MathFunctions"

which is prefixed in the source directory.
```

CMake 试图说的是，在生成导出信息期间，它将导出一个本质上与当前机器相关的路径，并且在其他机器上无效。解决方案是更新 MathFunctions `target_include_directories`，以了解在从构建目录内使用以及从安装/包使用时需要不同的 `INTERFACE` 位置。这意味着将 MathFunctions 的 `target_include_directories` 调用转换为如下所示：

```cmake
target_include_directories(MathFunctions
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
                           )
```

更新后，我们可以重新运行 CMake 并验证它不再发出警告。

此时，我们已经让 CMake 正确打包了所需的目标信息，但我们仍然需要生成一个 `MathFunctionsConfig.cmake`，以便 CMake `find_package` 命令可以找到我们的项目。所以让我们继续在项目的顶层添加一个名为 `Config.cmake.in` 的新文件，内容如下：

```cmake
@PACKAGE_INIT@

include ( "${CMAKE_CURRENT_LIST_DIR}/MathFunctionsTargets.cmake" )
```

然后，要正确配置和安装该文件，请将以下内容添加到顶级 `CMakeLists.txt` 的底部：

```cmake
install(EXPORT MathFunctionsTargets
  FILE MathFunctionsTargets.cmake
  DESTINATION lib/cmake/MathFunctions
)

include(CMakePackageConfigHelpers)
# 生成包含导出的配置文件
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/example"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )
# 为配置文件生成版本文件
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake"
  VERSION "${Tutorial_VERSION_MAJOR}.${Tutorial_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

# 安装配置文件
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake
  DESTINATION lib/cmake/MathFunctions
  )
```

此时，我们已经为项目生成了一个可重定位的 CMake 配置，可以在项目安装或打包后使用。如果我们希望我们的项目也可以从构建目录中使用，我们只需要将以下内容添加到顶级 `CMakeLists.txt` 的底部：

```cmake
export(EXPORT MathFunctionsTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsTargets.cmake"
)
```

通过此导出调用，我们现在生成一个 `Targets.cmake`，允许在构建目录中配置的 `MathFunctionsConfig.cmake` 被其他项目使用，而无需安装它。

## 打包调试版和发布版（步骤 12）

**注意**：此示例对单配置生成器有效，不适用于多配置生成器（例如 Visual Studio）。

默认情况下，CMake 的模型是构建目录仅包含单个配置，无论是 Debug、Release、MinSizeRel 还是 RelWithDebInfo。但是，可以设置 CPack 来捆绑多个构建目录并构建包含同一项目的多个配置的包。

首先，我们希望确保调试和发布构建对将要安装的可执行文件和库使用不同的名称。让我们使用 d 作为调试可执行文件和库的后缀。

在顶级 `CMakeLists.txt` 文件开头附近设置 `CMAKE_DEBUG_POSTFIX`：

```cmake
set(CMAKE_DEBUG_POSTFIX d)

add_library(tutorial_compiler_flags INTERFACE)
```

以及 tutorial 可执行文件的 `DEBUG_POSTFIX` 属性：

```cmake
add_executable(Tutorial tutorial.cxx)
set_target_properties(Tutorial PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_link_libraries(Tutorial PUBLIC MathFunctions)
```

让我们还为 MathFunctions 库添加版本编号。在 `MathFunctions/CMakeLists.txt` 中，设置 `VERSION` 和 `SOVERSION` 属性：

```cmake
set_property(TARGET MathFunctions PROPERTY VERSION "1.0.0")
set_property(TARGET MathFunctions PROPERTY SOVERSION "1")
```

从 `Step12` 目录，创建 `debug` 和 `release` 子目录。布局将如下所示：

```
- Step12
   - debug
   - release
```

现在我们需要设置调试和发布构建。我们可以使用 `CMAKE_BUILD_TYPE` 来设置配置类型：

```bash
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
cd ../release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

现在调试和发布构建都已完成，我们可以使用自定义配置文件将两个构建打包到单个版本中。在 `Step12` 目录中，创建一个名为 `MultiCPackConfig.cmake` 的文件。在此文件中，首先包含 `cmake` 可执行文件创建的默认配置文件。

接下来，使用 `CPACK_INSTALL_CMAKE_PROJECTS` 变量指定要安装的项目。在这种情况下，我们想要安装调试和发布。

```cmake
include("release/CPackConfig.cmake")

set(CPACK_INSTALL_CMAKE_PROJECTS
    "debug;Tutorial;ALL;/"
    "release;Tutorial;ALL;/"
    )
```

从 `Step12` 目录，使用 config 选项运行 `cpack`，指定我们的自定义配置文件：

```bash
cpack --config MultiCPackConfig.cmake
```
