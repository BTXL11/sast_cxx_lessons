# 加载必要的程序集
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

# 创建主窗体
$form = New-Object System.Windows.Forms.Form
$form.Text = "PowerShell 现代化界面"
$form.Size = New-Object System.Drawing.Size(500, 400)
$form.StartPosition = "CenterScreen"
$form.BackColor = [System.Drawing.Color]::FromArgb(240, 240, 245)
$form.FormBorderStyle = 'FixedDialog'
$form.MaximizeBox = $false

# 创建标题面板
$titlePanel = New-Object System.Windows.Forms.Panel
$titlePanel.Location = New-Object System.Drawing.Point(0, 0)
$titlePanel.Size = New-Object System.Drawing.Size(500, 80)
$titlePanel.BackColor = [System.Drawing.Color]::FromArgb(70, 130, 180)
$form.Controls.Add($titlePanel)

# 创建标题标签
$titleLabel = New-Object System.Windows.Forms.Label
$titleLabel.Location = New-Object System.Drawing.Point(20, 15)
$titleLabel.Size = New-Object System.Drawing.Size(450, 30)
$titleLabel.Text = "欢迎使用 PowerShell GUI"
$titleLabel.Font = New-Object System.Drawing.Font("微软雅黑", 18, [System.Drawing.FontStyle]::Bold)
$titleLabel.ForeColor = [System.Drawing.Color]::White
$titlePanel.Controls.Add($titleLabel)

# 创建副标题
$subtitleLabel = New-Object System.Windows.Forms.Label
$subtitleLabel.Location = New-Object System.Drawing.Point(20, 50)
$subtitleLabel.Size = New-Object System.Drawing.Size(450, 20)
$subtitleLabel.Text = "一个简单而优雅的图形界面示例"
$subtitleLabel.Font = New-Object System.Drawing.Font("微软雅黑", 10)
$subtitleLabel.ForeColor = [System.Drawing.Color]::FromArgb(230, 230, 230)
$titlePanel.Controls.Add($subtitleLabel)

# 创建内容面板
$contentPanel = New-Object System.Windows.Forms.Panel
$contentPanel.Location = New-Object System.Drawing.Point(30, 100)
$contentPanel.Size = New-Object System.Drawing.Size(440, 240)
$contentPanel.BackColor = [System.Drawing.Color]::White
$contentPanel.BorderStyle = 'None'
$form.Controls.Add($contentPanel)

# 添加阴影效果（通过边框模拟）
$shadowPanel = New-Object System.Windows.Forms.Panel
$shadowPanel.Location = New-Object System.Drawing.Point(33, 103)
$shadowPanel.Size = New-Object System.Drawing.Size(440, 240)
$shadowPanel.BackColor = [System.Drawing.Color]::FromArgb(200, 200, 200)
$form.Controls.Add($shadowPanel)
$contentPanel.BringToFront()

# 输入提示标签
$label = New-Object System.Windows.Forms.Label
$label.Location = New-Object System.Drawing.Point(30, 30)
$label.Size = New-Object System.Drawing.Size(380, 25)
$label.Text = "请输入您的姓名"
$label.Font = New-Object System.Drawing.Font("微软雅黑", 11, [System.Drawing.FontStyle]::Bold)
$label.ForeColor = [System.Drawing.Color]::FromArgb(60, 60, 60)
$contentPanel.Controls.Add($label)

# 美化文本框
$textBox = New-Object System.Windows.Forms.TextBox
$textBox.Location = New-Object System.Drawing.Point(30, 60)
$textBox.Size = New-Object System.Drawing.Size(380, 30)
$textBox.Font = New-Object System.Drawing.Font("微软雅黑", 11)
$textBox.BorderStyle = 'FixedSingle'
$textBox.BackColor = [System.Drawing.Color]::FromArgb(250, 250, 250)
$contentPanel.Controls.Add($textBox)

# 创建按钮容器
$buttonPanel = New-Object System.Windows.Forms.Panel
$buttonPanel.Location = New-Object System.Drawing.Point(30, 110)
$buttonPanel.Size = New-Object System.Drawing.Size(380, 50)
$buttonPanel.BackColor = [System.Drawing.Color]::Transparent
$contentPanel.Controls.Add($buttonPanel)

# 美化问候按钮
$button = New-Object System.Windows.Forms.Button
$button.Location = New-Object System.Drawing.Point(0, 0)
$button.Size = New-Object System.Drawing.Size(120, 40)
$button.Text = "问候"
$button.Font = New-Object System.Drawing.Font("微软雅黑", 10, [System.Drawing.FontStyle]::Bold)
$button.FlatStyle = 'Flat'
$button.FlatAppearance.BorderSize = 0
$button.BackColor = [System.Drawing.Color]::FromArgb(70, 130, 180)
$button.ForeColor = [System.Drawing.Color]::White
$button.Cursor = [System.Windows.Forms.Cursors]::Hand
$button.Add_MouseEnter({
        $button.BackColor = [System.Drawing.Color]::FromArgb(90, 150, 200)
    })
$button.Add_MouseLeave({
        $button.BackColor = [System.Drawing.Color]::FromArgb(70, 130, 180)
    })
$button.Add_Click({
        if ($textBox.Text -ne "") {
            $resultLabel.Text = "你好，$($textBox.Text)！"
            $resultLabel.Text += "`n欢迎使用 PowerShell 现代化界面 ✨"
            $resultLabel.ForeColor = [System.Drawing.Color]::FromArgb(70, 130, 180)
        }
        else {
            $resultLabel.Text = "⚠ 请先输入姓名"
            $resultLabel.ForeColor = [System.Drawing.Color]::FromArgb(220, 90, 90)
        }
    })
$buttonPanel.Controls.Add($button)

# 美化清除按钮
$clearButton = New-Object System.Windows.Forms.Button
$clearButton.Location = New-Object System.Drawing.Point(130, 0)
$clearButton.Size = New-Object System.Drawing.Size(120, 40)
$clearButton.Text = "清除"
$clearButton.Font = New-Object System.Drawing.Font("微软雅黑", 10, [System.Drawing.FontStyle]::Bold)
$clearButton.FlatStyle = 'Flat'
$clearButton.FlatAppearance.BorderSize = 0
$clearButton.BackColor = [System.Drawing.Color]::FromArgb(150, 150, 150)
$clearButton.ForeColor = [System.Drawing.Color]::White
$clearButton.Cursor = [System.Windows.Forms.Cursors]::Hand
$clearButton.Add_MouseEnter({
        $clearButton.BackColor = [System.Drawing.Color]::FromArgb(170, 170, 170)
    })
$clearButton.Add_MouseLeave({
        $clearButton.BackColor = [System.Drawing.Color]::FromArgb(150, 150, 150)
    })
$clearButton.Add_Click({
        $textBox.Text = ""
        $resultLabel.Text = ""
    })
$buttonPanel.Controls.Add($clearButton)

# 美化退出按钮
$exitButton = New-Object System.Windows.Forms.Button
$exitButton.Location = New-Object System.Drawing.Point(260, 0)
$exitButton.Size = New-Object System.Drawing.Size(120, 40)
$exitButton.Text = "退出"
$exitButton.Font = New-Object System.Drawing.Font("微软雅黑", 10, [System.Drawing.FontStyle]::Bold)
$exitButton.FlatStyle = 'Flat'
$exitButton.FlatAppearance.BorderSize = 0
$exitButton.BackColor = [System.Drawing.Color]::FromArgb(220, 90, 90)
$exitButton.ForeColor = [System.Drawing.Color]::White
$exitButton.Cursor = [System.Windows.Forms.Cursors]::Hand
$exitButton.Add_MouseEnter({
        $exitButton.BackColor = [System.Drawing.Color]::FromArgb(240, 110, 110)
    })
$exitButton.Add_MouseLeave({
        $exitButton.BackColor = [System.Drawing.Color]::FromArgb(220, 90, 90)
    })
$exitButton.Add_Click({
        $form.Close()
    })
$buttonPanel.Controls.Add($exitButton)

# 美化结果显示区域
$resultLabel = New-Object System.Windows.Forms.Label
$resultLabel.Location = New-Object System.Drawing.Point(30, 170)
$resultLabel.Size = New-Object System.Drawing.Size(380, 60)
$resultLabel.Font = New-Object System.Drawing.Font("微软雅黑", 12, [System.Drawing.FontStyle]::Bold)
$resultLabel.TextAlign = 'MiddleCenter'
$resultLabel.BackColor = [System.Drawing.Color]::FromArgb(245, 245, 250)
$contentPanel.Controls.Add($resultLabel)

# 显示窗体
$form.Add_Shown({ $form.Activate() })
[void]$form.ShowDialog()