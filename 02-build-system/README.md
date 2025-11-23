# 02-build-system 示例说明

本目录包含本课程 CMake 部分的配套示例代码和构建脚本。

## 目录结构

- `cmake.md` / `cmake-tutorial.md`：课程讲义
- `example/Step1` ~ `example/Step11`：
  每一步都是一个 **完整的可构建工程**，对应讲义中的 Step1~Step11
- `env/`：跨平台环境配置与一键构建脚本
  - `setup_env.sh`：Linux / macOS 使用
  - `setup_env.ps1`：Windows PowerShell 使用

## Windows 下构建示例（推荐）

在 PowerShell 中进入本目录：

```powershell
cd d:\Project\sast_cxx_lessons\02-build-system

# 构建 Step1，Debug
.\env\setup_env.ps1 -Step 1 -Config Debug

# 构建 Step6，Release
.\env\setup_env.ps1 -Step 6 -Config Release
```

脚本会自动：

1. 检查 `cmake` 是否可用；
2. 在 `example/StepN_build` 下生成构建目录；
3. 运行 `cmake ..\StepN` 和 `cmake --build .` 完成构建。

如果该步骤包含测试，可以在对应的 `StepN_build` 目录中运行：

```powershell
ctest -N
ctest -C Debug -VV
```

> 提示：使用 Visual Studio 生成器时，`ctest` 需要加 `-C Debug` 或 `-C Release`。

## Linux / macOS 下构建示例

```bash
cd /path/to/sast_cxx_lessons/02-build-system

# 构建 Step1，Debug
./env/setup_env.sh 1

# 构建 Step6，Release
./env/setup_env.sh 6 Release
```

脚本会在 `example/StepN_build` 下创建构建目录并调用：

```bash
cmake ../StepN -DCMAKE_BUILD_TYPE=Debug
cmake --build .
```

同样，可以在 `StepN_build` 目录中使用：

```bash
ctest -N
ctest -VV
```

## 说明

- 每个 Step 目录都包含独立的 `CMakeLists.txt` 和源代码，不依赖前一步的构建结果。
- IDE 中直接打开源码时，可能会看到 `TutorialConfig.h`、`Table.h` 等文件缺失的报错，这些文件会在 **CMake 配置/构建阶段自动生成**，不影响正常使用。
