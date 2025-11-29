# 📁 文件操作（跟Linux很像）
ls              # 列出文件（其实是Get-ChildItem的别名）
cd Desktop      # 切换目录
mkdir 新文件夹   # 创建目录
rm 文件.txt     # 删除文件

# 🔍 查找东西
Get-ChildItem -Recurse -Filter "*.txt"  # 找所有txt文件
Get-Process | Where Name -like "*chrome*"  # 找Chrome进程

# 💾 数据处理
Get-Process | Export-Csv ./processes.csv  # 导出到CSV
Import-Csv data.csv | Where Age -gt 18  # 从CSV筛选数据

# 🎨 好玩的命令
Write-Host "彩虹文字" -ForegroundColor Cyan
Get-Random -Minimum 1 -Maximum 100  # 随机数
Get-Date  # 当前时间
(Get-Date).AddDays(100)  # 100天后是几号？