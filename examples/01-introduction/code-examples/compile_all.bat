@echo off
REM 编译所有C++代码示例的批处理脚本
REM 用法: compile_all.bat

echo =========================================
echo 编译所有C++代码示例
echo =========================================
echo.

REM 创建输出目录
if not exist compiled_output mkdir compiled_output

REM 计数器
set total=0
set success=0
set failed=0

echo 开始编译...
echo.

REM 编译第1章
echo [第1章：C++基础]
for %%f in (01-cpp-basics\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第2章
echo [第2章：变量和运算符]
for %%f in (02-variables-operators\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第3章
echo [第3章：控制流]
for %%f in (03-control-flow\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第4章
echo [第4章：函数]
for %%f in (04-functions\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第5章
echo [第5章：数组和集合]
for %%f in (05-arrays-collections\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第6章
echo [第6章：类和对象]
for %%f in (06-classes-objects\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第7章
echo [第7章：指针]
for %%f in (07-pointers\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第8章
echo [第8章：字符串]
for %%f in (08-strings\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第10章
echo [第10章：引用]
for %%f in (10-references\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第11章
echo [第11章：动态内存]
for %%f in (11-dynamic-memory\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第9章
echo [第9章：输入输出]
for %%f in (09-input-output\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第12章
echo [第12章：构造函数和析构函数]
for %%f in (12-constructors\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第13章
echo [第13章：拷贝语义]
for %%f in (13-copy-semantics\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第14章
echo [第14章：类型转换]
for %%f in (14-type-conversion\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第15章
echo [第15章：内联函数]
for %%f in (15-inline-functions\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第16章
echo [第16章：Lambda表达式]
for %%f in (16-lambda\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

REM 编译第17章
echo [第17章：左值和右值]
for %%f in (17-lvalues-rvalues\*.cpp) do (
    set /a total+=1
    echo 编译 %%f ...
    g++ -std=c++11 -Wall -o compiled_output\%%~nf.exe %%f 2>nul
    if errorlevel 1 (
        echo   X 失败
        set /a failed+=1
    ) else (
        echo   √ 成功
        set /a success+=1
    )
)
echo.

echo =========================================
echo 编译统计
echo =========================================
echo 总文件数: %total%
echo 成功: %success%
echo 失败: %failed%
echo.

if %failed%==0 (
    echo √ 所有文件编译成功！
    echo.
    echo 编译后的可执行文件位于: compiled_output\
    echo 运行示例: compiled_output\01_hello_world.exe
) else (
    echo 警告: 有 %failed% 个文件编译失败
    echo 请检查这些文件的语法错误
)

echo.
echo =========================================
pause

