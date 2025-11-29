param(
    [int]$Step = 1,
    [string]$Config = "Debug"
)

$ErrorActionPreference = "Stop"

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$rootDir   = Join-Path $scriptDir ".."
$exampleDir = Join-Path $rootDir "example"
$stepSrc   = Join-Path $exampleDir ("Step{0}" -f $Step)
$stepBuild = Join-Path $exampleDir ("Step{0}_build" -f $Step)

if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    Write-Error "cmake 未找到，请先在系统中安装 CMake (例如：choco install cmake 或从官网安装)。"
}

if (-not (Test-Path $stepSrc)) {
    Write-Error "源目录不存在: $stepSrc"
}

if (-not (Test-Path $stepBuild)) {
    New-Item -ItemType Directory -Path $stepBuild | Out-Null
}

Push-Location $stepBuild

Write-Host "[INFO] 配置 Step$Step (Config=$Config)" -ForegroundColor Cyan

# 不指定生成器，让 CMake 根据环境选择（VS / Ninja 等）
cmake "..\Step$Step" -DCMAKE_BUILD_TYPE=$Config

Write-Host "[INFO] 构建 Step$Step" -ForegroundColor Cyan
cmake --build . --config $Config

Write-Host "[INFO] 如该步骤包含测试，可在此目录运行: ctest -N 或 ctest -C $Config -VV" -ForegroundColor Green

Pop-Location
