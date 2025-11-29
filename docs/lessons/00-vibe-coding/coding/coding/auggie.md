# Auggie (Augment Code CLI)

## 概览（Overview）

Auggie 是 Augment Code 推出的命令行/终端内 AI 编程代理与工具箱，将 Augment 的上下文引擎和专用代理带到任何代码目录与 CI 流水线中。它遵循“Unix 风格工具”的设计，可通过标准输入/输出与其他命令组合，适用于本地开发与自动化脚本。

## 核心能力（Key Features）

- 上下文引擎：自动收集与裁剪仓库上下文（文件、符号、变更、依赖），向模型提供高相关信息。
- 专用代理（Specialized agents）：围绕代码审查、安全、重构、测试生成、文档补全等任务的可选 agent 预设。
- Patch/Diff 输出：以补丁形式返回修改，便于审阅、应用与回滚。
- 可编排：支持在脚本/CI 中串联，如 `git diff | auggie review`、`auggie apply` 等（以官方命令为准）。
- 多模型支持：可按需配置 LLM/路由策略，平衡质量、时延与成本（以官方当前支持为准）。

## 典型工作流（Workflow）

1. 在仓库根目录配置认证与模型；
2. 选择代理/命令（如 review/refactor/test/doc）；
3. Auggie 读取上下文并生成 patch/diff 与说明；
4. 人工审阅与部分/整体应用；
5. 运行测试/构建，循环迭代直至通过，最终提交 PR。

## 优势（Strengths）

- 融入现有 CLI 与 CI：适合脚本化/自动化，覆盖 IDE 之外的工作流。
- 可审计：以补丁为中心，利于代码评审与合规记录。
- 上下文质量高：结合 Augment 的上下文引擎，在大仓下仍具相关性。

## 局限（Limitations）

- 需命令行经验：相对 IDE 插件，CLI 更依赖脚本化与操作习惯。
- 首次配置成本：模型/权限/忽略名单/上下文策略需调优。
- 模型依赖与费用：按模型调用计费，需结合组织策略与预算。

## 定价/获取（Pricing / Access）

- 参考官方站点与文档：
  - 产品页：<https://www.augmentcode.com/product/CLI>
  - 文档：<https://docs.augmentcode.com/cli/overview>
  - VS Code 扩展见下文链接。

## 集成（Integration）

- Git 工作流：分支/提交信息/PR 模板生成与审查支持（以官方能力为准）。
- CI/CD：在 CI 中进行自动审查、生成修复补丁与报告；支持与现有质量门禁配合。

## 对比（Comparison）

- vs IDE Copilot：CLI 更透明/可编排，适合自动化；IDE 插件更即用/交互性强。
- vs Aider/Cline（CLI）：Auggie 在“跨大仓上下文”和“专用代理/审计输出”上有优势；Aider/Cline 社区覆盖广、生态成熟。
- vs Gemini/Claude CLI：后者为厂商一方/通用 CLI，Auggie 更偏工程化与代码上下文质量。

## 资源（Resources）

- Augment Code 主页：<https://www.augmentcode.com/>
- VS Code 扩展安装：<https://www.augmentcode.com/install/vscode>
- 扩展市场页：<https://marketplace.visualstudio.com/items?itemName=augment.vscode-augment>

---

最后更新：2025-11-02
