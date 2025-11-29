# RepoPrompt

## 概览（Overview）

RepoPrompt 是一款原生 macOS 的“上下文工程（Context Engineering）”工具箱与 MCP 服务器，可将本地仓库（或选中文件/片段）转换为结构化、可复用的 Prompt 片段，并让 AI 代理（如 Claude Desktop/Claude Code、支持 MCP 的 IDE 扩展）以安全、可控的方式读取/应用到代码修改流程中。

核心理念：把“如何给模型讲清楚你的代码/意图”的工作模块化、可视化，既可手工编排，也可开放给代理在边界内自动执行。

## 核心能力与特性（Key Features）

- 本地仓库上下文提取：按文件/目录/选区构建结构化上下文，避免“一股脑贴整仓”的低效与风险。
- Prompt 组件与图（Prompt Graph）：将上下文、约束、风格、准则等拆分为可复用组件，并以图式串联为任务模板。
- MCP（Model Context Protocol）支持：作为 MCP Server 暴露能力，供 Claude、其他 MCP 客户端/代理调用（读取上下文、生成补丁、应用/回滚等）。
- 最小化与确定性：通过模板与差异化（diff/patch）输出，尽量减少无关改动，便于审阅与回滚。
- 可视化审阅：在应用前展示修改摘要与风险点，支持逐步确认（human‑in‑the‑loop）。
- 与 Git 工作流契合：配合分支/提交/PR 过程，生成更小更审查友好的变更。

## 典型工作流（Workflows）

1. 选中文件/目录/代码片段，生成结构化上下文（含文件路径、片段位置、依赖说明）。
2. 选择/编辑 Prompt 模板（风格、约束、验收标准），触发模型推理。
3. 生成 patch/diff；在 RepoPrompt 内预览、逐条确认；应用到工作副本。
4. 运行测试/静态检查；根据反馈调整 Prompt 组件或上下文。
5. 提交分支并创建 PR，进入团队审查流。

## 优势（Strengths）

- 上下文工程一等公民：相较“一次性贴上下文”，组件化更可维护、可迁移。
- 安全可控：人机协作、逐步确认，降低大改动风险。
- 与 MCP 生态互通：可被多种 AI 代理复用，无需重复造轮子。
- 面向审查：输出更贴近“最小可审查单元”，帮助代码评审与知识沉淀。

## 局限与注意（Limitations）

- 平台：当前面向 macOS。Windows/Linux 需关注官方路线图。
- 学习曲线：需要一定上下文工程/模板化思维，首次搭建成本略高。
- 非模型提供方：需要配合外部 LLM/代理使用（BYO API Key 或使用现有客户端）。

## 集成与平台支持（Integrations）

- MCP 客户端：Claude Desktop/Claude Code 等支持 MCP 的客户端。
- VCS/开发工具：与 Git 分支/PR 流程契合；与 IDE 并行使用（通过 MCP）。

## 定价与获取（Pricing / Access）

- 商业软件（提供试用/授权，具体以官网为准）。
- 官网下载与文档见下文链接。

## 与其他工具对比（Comparison）

- 对比 Aider/Goose/OpenCode（终端代理）：它们更偏“执行代理”；RepoPrompt更偏“上下文与变更模板的生产与复用”，常作为代理的能力提供者/MCP 服务端。
- 对比 IDE Copilot：IDE 插件偏“即时补全/对话”；RepoPrompt 强调“结构化上下文 + 可审查变更”。

## 快速上手（Quickstart）

- 安装应用 → 打开本地仓库 → 选区/选文件生成上下文 → 组合 Prompt 组件 → 通过 MCP 或手动触发推理 → 预览并应用补丁。

## 参考与资源（Resources）

- 官网与下载：<https://repoprompt.com/>
- 文档：<https://repoprompt.com/docs>
- 生态与讨论：X/Twitter @RepoPrompt

---

最后更新：2025-11-02
