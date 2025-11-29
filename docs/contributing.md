# 贡献指南

感谢你对 SAST C++ 教程的关注！我们欢迎任何形式的贡献。

---

## 贡献方式

### 报告问题

如果你发现了错误或有改进建议：

1. 在 [GitHub Issues](https://github.com/AstroAir/sast_cxx_lessons/issues) 搜索是否已有相关问题
2. 如果没有，创建新 Issue，描述问题或建议

### 提交代码

1. **Fork 仓库**

    点击 GitHub 页面右上角的 Fork 按钮

2. **克隆到本地**

    ```bash
    git clone https://github.com/YOUR_USERNAME/sast_cxx_lessons.git
    cd sast_cxx_lessons
    ```

3. **创建分支**

    ```bash
    git checkout -b feature/your-feature-name
    ```

4. **进行修改**

    - 遵循现有的代码风格
    - 添加必要的测试
    - 更新相关文档

5. **提交更改**

    ```bash
    git add .
    git commit -m "feat: 添加新功能描述"
    ```

6. **推送并创建 PR**

    ```bash
    git push origin feature/your-feature-name
    ```

    然后在 GitHub 上创建 Pull Request

---

## 开发环境设置

### 文档开发

```bash
# 安装依赖
pip install -e ".[docs]"

# 启动本地服务器（支持热重载）
mkdocs serve
```

### C++ 示例

```bash
# 构建所有示例
mkdir build && cd build
cmake ..
cmake --build .
```

---

## 代码规范

### C++ 代码

- 使用 C++17 或更高标准
- 遵循 [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- 使用 4 空格缩进
- 文件使用 UTF-8 编码

### Markdown 文档

- 使用中文标点符号
- 代码块标注语言类型
- 图片使用相对路径
- 保持段落简洁

### Commit 消息

遵循 [Conventional Commits](https://www.conventionalcommits.org/) 规范：

```
<type>(<scope>): <description>

[optional body]

[optional footer]
```

类型包括：

- `feat`: 新功能
- `fix`: 修复 bug
- `docs`: 文档更新
- `style`: 代码格式调整
- `refactor`: 代码重构
- `test`: 测试相关
- `chore`: 构建/工具相关

---

## 文档结构

```
docs/
├── index.md                 # 首页
├── getting-started.md       # 快速开始
├── contributing.md          # 贡献指南
└── lessons/                 # 课程内容
    ├── 00-vibe-coding/      # AI 辅助编程
    ├── 01-introduction/     # C++ 基础
    └── 02-build-system/     # 构建系统
```

### 添加新章节

1. 在 `docs/lessons/` 下创建目录
2. 添加 `index.md` 作为章节入口
3. 在 `mkdocs.yml` 的 `nav` 中添加导航

---

## 许可证

提交贡献即表示你同意将代码以 [MIT 许可证](https://github.com/AstroAir/sast_cxx_lessons/blob/main/LICENSE) 发布。

---

## 联系我们

- GitHub Issues: [提交问题](https://github.com/AstroAir/sast_cxx_lessons/issues)
- Email: sast@xjtu.edu.cn

再次感谢你的贡献！
