# 传统Shell的方式（文本处理）
Get-Process | Select-String "edge"

# PowerShell的方式（对象处理）
Get-Process | Where-Object {$_.Name -like "*edge*"} |
    Select-Object Name, CPU, Memory

# 看，我们在处理对象，不是文本！