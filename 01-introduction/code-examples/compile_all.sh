#!/bin/bash

# 编译所有C++代码示例的脚本
# 用法: ./compile_all.sh

echo "========================================="
echo "编译所有C++代码示例"
echo "========================================="
echo ""

# 计数器
total=0
success=0
failed=0

# 创建输出目录
mkdir -p compiled_output

# 编译函数
compile_file() {
    local file=$1
    local output_name=$(basename "$file" .cpp)
    local output_path="compiled_output/$output_name"
    
    echo -n "编译 $file ... "
    
    # 尝试编译（使用C++11标准）
    if g++ -std=c++11 -Wall -o "$output_path" "$file" 2>/dev/null; then
        echo "✓ 成功"
        ((success++))
        return 0
    else
        echo "✗ 失败"
        ((failed++))
        return 1
    fi
}

# 遍历所有.cpp文件
echo "开始编译..."
echo ""

for file in $(find . -name "*.cpp" | sort); do
    ((total++))
    compile_file "$file"
done

echo ""
echo "========================================="
echo "编译统计"
echo "========================================="
echo "总文件数: $total"
echo "成功: $success"
echo "失败: $failed"
echo ""

if [ $failed -eq 0 ]; then
    echo "✓ 所有文件编译成功！"
    echo ""
    echo "编译后的可执行文件位于: compiled_output/"
    echo "运行示例: ./compiled_output/01_hello_world"
else
    echo "⚠ 有 $failed 个文件编译失败"
    echo "请检查这些文件的语法错误"
fi

echo ""
echo "========================================="

