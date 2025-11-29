<#
.SYNOPSIS
    MkDocs 文档辅助脚本

.DESCRIPTION
    用于本地预览和构建 MkDocs 文档

.PARAMETER Action
    操作类型: serve (本地预览) 或 build (构建静态文件)

.EXAMPLE
    .\scripts\docs.ps1 serve
    .\scripts\docs.ps1 build
#>

param(
    [Parameter(Position = 0)]
    [ValidateSet("serve", "build", "install")]
    [string]$Action = "serve"
)

$ErrorActionPreference = "Stop"
$ProjectRoot = Split-Path -Parent $PSScriptRoot

Push-Location $ProjectRoot

try {
    switch ($Action) {
        "install" {
            Write-Host "Installing documentation dependencies..." -ForegroundColor Cyan
            pip install -e ".[docs]"
            Write-Host "Done!" -ForegroundColor Green
        }
        "serve" {
            Write-Host "Starting local documentation server..." -ForegroundColor Cyan
            Write-Host "Visit http://127.0.0.1:8000 to preview" -ForegroundColor Yellow
            mkdocs serve
        }
        "build" {
            Write-Host "Building documentation..." -ForegroundColor Cyan
            mkdocs build --strict
            Write-Host "Documentation built to ./site/" -ForegroundColor Green
        }
    }
}
finally {
    Pop-Location
}
