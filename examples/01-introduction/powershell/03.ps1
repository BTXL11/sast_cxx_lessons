# 🎭 自定义提示符
function prompt {
    $time = Get-Date -Format "HH:mm:ss"
    "[$time] PS> "
}

# 🎲 做个决定帮手
function Should-I {
    $answer = Get-Random -InputObject @("做！", "不做！", "再想想", "明天再说")
    Write-Host $answer -ForegroundColor Yellow
}
# 使用：Should-I

# 🔊 让电脑说话（Windows）
Add-Type -AssemblyName System.Speech
$speak = New-Object System.Speech.Synthesis.SpeechSynthesizer
$speak.Speak("你好，我是你的电脑")

# 📊 快速统计文件
Get-ChildItem -Recurse |
    Group-Object Extension |
    Sort-Object Count -Descending |
    Select-Object Name, Count

# 🌡️ 系统温度检测（需要管理员权限）
Get-WmiObject MSAcpi_ThermalZoneTemperature -Namespace root/wmi |
    Select-Object -Property CurrentTemperature