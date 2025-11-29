# Cursor CLI

概览 / Overview

- 定位：由 Cursor 团队提供的命令行接口（CLI），在终端中与 Cursor 的 AI 代理交互，用于编写、审查与修改代码，以及执行围绕代码的自动化步骤。
- 典型场景：在 terminal 内发起任务、迭代补丁、快速评审与批量修改；结合现有脚本/CI 以脚本化方式驱动 AI 代理完成工程性修改。
- 适用人群：Cursor 用户、偏好在终端工作并希望统一“编辑器与 CLI 代理体验”的开发者。

Key Features（核心特性）

- 交互式 CLI：支持对话式/任务式交互，基于当前目录上下文提出修改建议与补丁。
- 代码修改与评审：生成最小化补丁、支持分块应用与回滚；适合与 Git 流程结合。
- 任务编排：针对常见任务（重构、依赖升级、生成/更新测试、批量替换等）提供更高层的自动化操作。
- 与 Cursor 工作区协同：可与编辑器侧的工作区/项目上下文配合，共享部分会话/历史（以官方文档更新为准）。
- 权限与安全：执行敏感操作前进行确认；可配置“只读/建议优先”模式。

Strengths（优势）

- 体验一致：在终端延续 Cursor 的代理/编辑体验，减少上下文切换。
- 工程闭环：更容易融入脚本与 CI，便于在代码库层面进行规模化改造。
- 上下文友好：对当前项目结构、依赖与脚本的理解更自然，配合 Git 审阅效率高。

Limitations（限制）

- 账号/生态绑定：通常需要 Cursor 账号与其模型/额度支持；与第三方模型/后端的开放度以官方为准。
- 能力边界：对于跨仓库、跨服务的复杂变更仍需分解与人工监督。
- 可移植性：与纯开源 CLI（如 OpenCode/Goose）相比，可定制与自托管空间较小。

Use Cases（典型用例）

- 批量代码升级：如从旧版库迁移到新版 API，自动生成并验证补丁。
- 测试补全：为关键模块生成/更新单元测试并运行用例，失败后自动迭代。
- 规范落地：基于规则对多文件进行重构（命名/风格/结构），并形成 PR。

Pricing / Access（获取与定价）

- 作为 Cursor 生态的一部分，访问与额度依赖 Cursor 订阅与所选模型计划；具体以官方页面与条款为准。

Integrations（集成）

- Shell：bash、zsh、PowerShell 等
- 工具链：Git、包管理器、测试框架、格式化/静态检查工具
- 编辑器：与 Cursor 编辑器侧体验协同（以官方文档为准）

Comparison（对比要点）

- 对比 Gemini CLI/Goose/OpenCode：Cursor CLI 在“与编辑器协同”和“补丁粒度”上更贴近 IDE 使用；Gemini/Goose/OpenCode 在开源与多模型/可自托管方面更有弹性。
- 对比 Aider：Aider 的 Git 驱动补丁与审阅更成熟，Cursor CLI 的优势在于与 Cursor 编辑器深度协同与任务编排。

Examples / Resources（示例与资源）

- 官方介绍：<https://cursor.com/cli>
- 官方文档：<https://cursor.com/docs/cli/overview>
- 博客发布：Cursor Agent CLI（<https://cursor.com/blog/cli）>

最后更新：2025-11-02
