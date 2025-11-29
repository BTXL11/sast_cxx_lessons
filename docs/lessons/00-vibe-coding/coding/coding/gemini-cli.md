# Gemini CLI

概览 / Overview

- 定位：由 Google 推出的开源终端优先（terminal‑first）AI 代理工具，直接在命令行中与 Gemini 模型交互，支持“思考+行动（ReAct）”循环与本地/远程工具调用。
- 典型场景：命令行内的代码改造、脚手架搭建、运行/测试、日志分析、脚本生成与修复、自然语言→命令/补丁。
- 适用人群：偏好 CLI 工作流的工程师、DevOps/SRE、以“最小窗口切换”方式提升效率的资深开发者。

Key Features（核心特性）

- ReAct 代理循环：结合推理与行动，按步骤读取文件、生成补丁、运行命令并根据结果继续迭代（经用户许可）。
- 工具生态：内置常用工具（文件读写、终端命令、包管理、Git 等），可扩展自定义工具与连接器。
- 项目上下文：对当前目录进行索引/选择性纳入上下文，支持长上下文模型（取决于所选 Gemini 版本）。
- 安全与确认：执行破坏性操作前进行显式确认；支持“只读”/“建议”工作模式。
- 开源与可自托管：Apache 2.0 许可；可与企业内部代理/网关结合，配置私有 API Key、网络与缓存策略。

Strengths（优势）

- 终端原生体验：无需在 IDE 与终端来回切换；对命令行爱好者极其顺手。
- 任务闭环强：从理解需求→修改代码→运行验证→再迭代，天然贴合工程实际流程。
- 与 Gemini 生态协同：与 Gemini Code Assist 共享技术路线，模型/能力升级可快速受益。

Limitations（限制）

- 初期功能边界：对复杂多仓/跨服务场景需额外配置；对特定语言/框架的“专家级工具”需社区扩展。
- 权限与安全：在生产/敏感环境执行命令需审慎治理（最小权限、只读模式、预览补丁再应用）。
- 模型与计费：依赖所选 Gemini 模型与配额，长上下文/长链路任务可能产生更高成本。

Use Cases（典型用例）

- 将需求描述转化为补丁并在本地跑通单测
- 生成脚手架/配置文件（Dockerfile、CI、lint/test 工具链）并校验
- 阅读/总结日志、排查常见错误并提出修复建议

Pricing / Access（获取与定价）

- 开源工具（Apache-2.0）；模型调用按 Google AI Studio/Vertex AI 的计费与配额执行。
- 个人与企业可根据安全与网络策略选择直连或经自建代理网关调用。

Integrations（集成）

- 终端/壳：bash、zsh、PowerShell 等
- 工具：Git、包管理器、测试框架、容器/脚本运行器（取决于本地环境）
- 生态：Gemini Code Assist、Google AI Studio/Vertex AI

Comparison（对比要点）

- 对比 Claude Code（终端）：两者均为“思考+行动”的 CLI 代理；Gemini CLI 在谷歌生态与 ReAct 工具集成上更紧密。
- 对比 Aider（终端对话+Git）：Aider 在 Git 工作流与补丁管理上成熟；Gemini CLI 偏通用代理与工具调用。
- 对比 OpenCode/Goose：Gemini CLI 更聚焦谷歌模型与官方生态；OpenCode/Goose 提供更强的开源可塑性与多模型接入。

Examples / Resources（示例与资源）

- 官方文档：<https://developers.google.com/gemini-code-assist/docs/gemini-cli>
- 官方博客：Introducing Gemini CLI（Google Blog）
- 源码仓库：<https://github.com/google-gemini/gemini-cli>

最后更新：2025-11-02
