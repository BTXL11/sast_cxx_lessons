# 加载 Windows Forms 程序集
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

# 创建主窗体
$form = New-Object System.Windows.Forms.Form
$form.Text = "PowerShell 图形界面示例"
$form.Size = New-Object System.Drawing.Size(400, 300)
$form.StartPosition = "CenterScreen"

# 创建标签
$label = New-Object System.Windows.Forms.Label
$label.Location = New-Object System.Drawing.Point(20, 20)
$label.Size = New-Object System.Drawing.Size(350, 20)
$label.Text = "请输入您的姓名："
$form.Controls.Add($label)

# 创建文本框
$textBox = New-Object System.Windows.Forms.TextBox
$textBox.Location = New-Object System.Drawing.Point(20, 50)
$textBox.Size = New-Object System.Drawing.Size(340, 20)
$form.Controls.Add($textBox)

# 创建按钮
$button = New-Object System.Windows.Forms.Button
$button.Location = New-Object System.Drawing.Point(20, 90)
$button.Size = New-Object System.Drawing.Size(100, 30)
$button.Text = "问候"
$button.Add_Click({
    if ($textBox.Text -ne "") {
        $resultLabel.Text = "你好，$($textBox.Text)！欢迎使用 PowerShell GUI"
    } else {
        $resultLabel.Text = "请先输入姓名"
    }
})
$form.Controls.Add($button)

# 创建清除按钮
$clearButton = New-Object System.Windows.Forms.Button
$clearButton.Location = New-Object System.Drawing.Point(130, 90)
$clearButton.Size = New-Object System.Drawing.Size(100, 30)
$clearButton.Text = "清除"
$clearButton.Add_Click({
    $textBox.Text = ""
    $resultLabel.Text = ""
})
$form.Controls.Add($clearButton)

# 创建结果显示标签
$resultLabel = New-Object System.Windows.Forms.Label
$resultLabel.Location = New-Object System.Drawing.Point(20, 140)
$resultLabel.Size = New-Object System.Drawing.Size(350, 60)
$resultLabel.Font = New-Object System.Drawing.Font("微软雅黑", 12)
$resultLabel.ForeColor = [System.Drawing.Color]::Blue
$form.Controls.Add($resultLabel)

# 创建退出按钮
$exitButton = New-Object System.Windows.Forms.Button
$exitButton.Location = New-Object System.Drawing.Point(20, 210)
$exitButton.Size = New-Object System.Drawing.Size(100, 30)
$exitButton.Text = "退出"
$exitButton.Add_Click({
    $form.Close()
})
$form.Controls.Add($exitButton)

# 显示窗体
$form.ShowDialog()