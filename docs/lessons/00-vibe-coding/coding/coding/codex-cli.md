# Codex CLI

## 概览（Overview）

“Codex CLI” 在社区语境中常被用来指代“OpenAI 官方/生态中的命令行编码助手”。历史上 OpenAI 曾推出过 Codex 代码模型，但如今主推的新一代模型（如 GPT-4.1 / o3 系列 / Omni）与更通用的 OpenAI CLI/SDK 配合即可实现“读-改-测-提交”的终端工作流。本条目将“Codex CLI”泛指：以 OpenAI 模型为核心、通过命令行驱动的 AI 编码代理工作流。

重要提示：OpenAI 已不再以“Codex”作为产品品牌，建议使用最新的 OpenAI CLI/SDK 与模型，并参考第三方开源工具（如 Aider、Cline、Roo Code 的 CLI 模式）构建终端工作流。

## 核心能力（Key Features）

- 代码读写与上下文注入：通过 CLI 扫描/选取文件，整理上下文发送给模型，生成修复/实现建议。
- Patch/Diff 输出：以补丁形式返回改动，便于审阅与 git 应用。
- 任务化执行：将“实现/重构/修复/测试”分解为可追踪的步骤。
- 本地工具调用：集成单元测试、格式化、lint、构建等命令（以脚本/插件实现）。

## 典型工作流（Workflow）

1. 选择模型与策略（如 o3-mini-high、GPT-4.1、gpt-4o 等）。
2. 采集上下文（git diff、文件片段、Issue/PR 描述）。
3. 生成补丁与说明，审阅并应用到工作树。
4. 运行测试/构建并循环修复，最终提交 PR。

## 优势（Strengths）

- 灵活：可与既有 CLI 工具链拼装，无厂商锁定。
- 可审计：Patch/Diff 驱动，便于代码评审与回滚。
- 可扩展：结合 OpenAI Assistants / ReAct 工程化模式，易于迭代。

## 局限（Limitations）

- 需自行编排：与“成品型”CLI 相比，需要更多脚本化与配置。
- 权限与安全：应限制文件读写范围，谨慎执行命令。

## 获取与配置（Pricing / Access）

- 使用 OpenAI 账号与 API Key，按调用计费。
- 开发入口：OpenAI CLI/SDK 文档与 Assistants API。

## 对比（Comparison）

- vs Aider/Cline：后者是“拿来即用”的终端代理；“Codex CLI”更像是你基于 OpenAI CLI/SDK 自建的工作流。
- vs IDE 集成（Copilot/Cody）：终端更透明、可脚本化；IDE 集成更顺手与上下文感知丰富。

## 资源（Resources）

- OpenAI CLI 与 SDK 文档（以官网为准）
- 社区方案：Aider、Cline、Roo Code（CLI 模式）等

---

最后更新：2025-11-02
