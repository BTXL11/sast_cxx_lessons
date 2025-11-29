# Vibe Coding：AI 辅助编程

欢迎来到 **Vibe Coding** 章节！在这里，我们将学习如何利用现代 AI 工具提升编程效率。

---

## 什么是 Vibe Coding？

Vibe Coding 是一种新兴的编程范式，强调与 AI 协作完成开发任务。不同于传统的"人写代码"模式，Vibe Coding 让开发者专注于：

- **描述意图**：用自然语言表达你想要实现的功能
- **审查代码**：检查 AI 生成的代码是否符合预期
- **迭代优化**：通过对话不断改进代码质量

---

## 本章内容

### AI Agent 与 MCP

了解 AI Agent 的核心概念和 Model Context Protocol (MCP) 标准：

- Agent 是什么？
- MCP 如何连接 AI 与外部工具
- 实践：构建你的第一个 Agent

[:octicons-arrow-right-24: AI Agent 与 MCP 入门](mcp-starter.md)

### AI 平台指南

全面了解主流 AI API 平台：

- 国际平台：OpenAI、Anthropic、Google 等
- 国内平台：通义千问、文心一言、智谱等
- 注册流程、免费额度、选型建议

[:octicons-arrow-right-24: AI 平台全景指南](api-platform.md)

### 编程工具

深入了解各类 AI 编程工具：

| 工具 | 特点 | 适用场景 |
|------|------|---------|
| [GitHub Copilot](coding/github-copilot.md) | 代码补全、Chat | 日常开发 |
| [Cursor](coding/cursor.md) | AI-first IDE | 全栈开发 |
| [Claude](coding/claude.md) | 长上下文、代码分析 | 复杂项目 |
| [Windsurf](coding/windsurf.md) | Agentic IDE | 自动化任务 |

[:octicons-arrow-right-24: 查看所有工具](coding/index.md)

### 博客文章

深入学习 AI 编程技巧：

- [Prompt 工程最佳实践](blog/best-practices-for-prompt-engineering-zh.md)
- [如何创建 Skills](blog/how-to-create-skills-key-steps-limitations-and-examples-zh.md)
- [MCP 应用实践](blog/mcp-apps.md)

---

## 快速开始

### 1. 选择一个 AI 工具

推荐初学者从以下工具开始：

=== "VS Code + Copilot"

    最成熟的方案，适合已有 VS Code 使用经验的开发者。

    ```bash
    # 安装 GitHub Copilot 扩展
    code --install-extension GitHub.copilot
    ```

=== "Cursor"

    开箱即用的 AI IDE，内置多种模型支持。

    1. 下载 [Cursor](https://cursor.sh/)
    2. 登录并选择模型
    3. 开始编码

=== "Claude"

    适合需要处理大型代码库的场景。

    1. 访问 [claude.ai](https://claude.ai/)
    2. 上传代码文件或粘贴代码
    3. 开始对话

### 2. 学习 Prompt 技巧

有效的 Prompt 是 Vibe Coding 的关键：

!!! tip "好的 Prompt 示例"

    ```
    请帮我实现一个 C++ 函数，功能如下：
    - 输入：一个整数数组
    - 输出：数组中所有偶数的和
    - 要求：使用 C++17 标准，包含边界检查
    ```

!!! warning "避免的 Prompt"

    ```
    写个函数算偶数和
    ```

### 3. 实践项目

尝试用 AI 辅助完成以下任务：

- [ ] 实现一个简单的计算器
- [ ] 编写单元测试
- [ ] 重构一段遗留代码
- [ ] 添加代码注释和文档

---

## 下一步

- [AI Agent 与 MCP 入门](mcp-starter.md) - 深入理解 AI Agent
- [C++ 基础教程](../01-introduction/index.md) - 学习 C++ 语言
- [构建系统](../02-build-system/index.md) - 学习 CMake
