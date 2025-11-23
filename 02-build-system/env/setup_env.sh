#!/usr/bin/env bash

# 简单跨平台环境配置与构建脚本（Linux/macOS）
# 用法示例：
#   ./env/setup_env.sh 1         # 构建 Step1，Debug
#   ./env/setup_env.sh 6 Release # 构建 Step6，Release

set -e

STEP=${1:-1}
CONFIG=${2:-Debug}

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
EXAMPLE_DIR="${ROOT_DIR}/example"
STEP_SRC="${EXAMPLE_DIR}/Step${STEP}"
STEP_BUILD="${EXAMPLE_DIR}/Step${STEP}_build"

if ! command -v cmake >/dev/null 2>&1; then
  echo "[ERROR] cmake 未找到，请先安装 CMake。"
  echo "  例如：Ubuntu: sudo apt install cmake   /   macOS: brew install cmake"
  exit 1
fi

if ! command -v c++ >/dev/null 2>&1 && ! command -v g++ >/dev/null 2>&1 && ! command -v clang++ >/dev/null 2>&1; then
  echo "[ERROR] 未找到 C++ 编译器，请先安装 g++ 或 clang++。"
  exit 1
fi

if [ ! -d "${STEP_SRC}" ]; then
  echo "[ERROR] 源目录不存在: ${STEP_SRC}"
  exit 1
fi

mkdir -p "${STEP_BUILD}"
cd "${STEP_BUILD}"

echo "[INFO] 配置 Step${STEP} (CMAKE_BUILD_TYPE=${CONFIG})"
cmake "${STEP_SRC}" -DCMAKE_BUILD_TYPE="${CONFIG}"

echo "[INFO] 构建 Step${STEP}"
cmake --build .

echo "[INFO] 如果该步骤包含测试，可以在此目录运行: ctest -N 或 ctest -VV"
