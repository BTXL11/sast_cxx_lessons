# Bolt.new (StackBlitz)

概览 / Overview

- 定位：运行在浏览器中的 AI 编程环境与智能体（基于 WebContainers），支持“从提示到项目”的端到端生成、运行与预览。
- 典型场景：免本地安装、快速原型/样例/教程演示、协作分享可运行的工程状态。
- 适用人群：全栈/前端工程师、教学/培训、Hackathon、需要“一键可跑”的云端环境的团队。

Key Features（核心特性）

- Prompt → Project：通过对话生成完整项目结构、依赖、代码与脚本；支持迭代修改与任务分解。
- 浏览器内运行：基于 StackBlitz WebContainers，无需本地 Node/包管理器；可直接启动 dev server 并实时预览。
- 多文件编辑与执行：在同一页面内完成编辑、命令行、预览的闭环；支持包安装、脚本运行、测试等。
- 共享与复现：链接分享项目状态；便于团队演示、教学与复现他人步骤。

Strengths（优势）

- 零环境依赖：无需本地配置 Node/PNPM/NPM，跨平台一致。
- 上手快：单链接进入即可尝试，适合试验技术栈或最小可行样例。
- 与 Web 技术贴合：对前端与 Node 生态的支持自然，开发-预览-调试闭环顺畅。

Limitations（限制）

- 浏览器资源与权限限制：大型依赖/长时编译可能受限；部分系统级工具不可用。
- 隐私与私有依赖：涉及私有仓库/内部包时需要额外配置或迁移到本地环境。
- 复杂后端/数据库：更适合前端与轻后端样例，复杂基础设施通常需云端服务配合。

Use Cases（典型用例）

- 教学/培训/工作坊中演示从 0 到 1 的项目搭建
- 验证某个库/框架的最小可行示例（MVP/PoC）
- 团队讨论方案时快速拼装 UI 与原型

Pricing / Access（获取与定价）

- 在线服务，公开可用；公开预览阶段通常免费或限额。
- 商业/团队功能与配额以官方公示为准。

Integrations（集成）

- 与 GitHub 项目导入/导出、依赖镜像管理、WebContainers 生态集成
- 常见前端框架（React/Vue/Svelte 等）与 Node 工具链

Comparison（对比要点）

- 对比 Vercel v0：v0 更聚焦生成“前端 UI 代码”；Bolt.new 提供“可运行的全栈环境+智能体”，适合端到端演示与试验。
- 对比 Lovable：Lovable 强调从生成到部署的“建站”路径；Bolt 更像“浏览器 IDE + AI 代理”。
- 对比 Replit AI：两者均为在线 IDE + AI；Bolt 依托 WebContainers，启动速度快、无需后端容器。

Examples / Resources（示例与资源）

- 官方入口：<https://bolt.new> ；平台与文档：<https://stackblitz.com>

最后更新：2025-11-02
