# Crush

## 概览（Overview）

Crush 是 Charm（Charmbracelet）生态的一款命令行/终端内 AI 编程助手与 TUI（终端 UI）应用尝试，强调“在你最熟悉的终端里与 AI 结对编程”。它通常与 Charm 的其他终端工具（如 gum、glow、bubbletea、wish 等）一起被提及，目标是把补全、重构、解释、运行/测试等开发活动维持在终端内的流畅体验。

注：Crush 仍在快速迭代中，具体命令与插件形态以官方仓库为准；曾有“OpenCode AI”等相关尝试/品牌演进的社区讨论。

## 核心能力（Key Features）

- 终端优先：无需离开 Shell，即可聊天、生成/应用补丁、查看 diff。
- TUI 交互：基于 Bubble Tea 等栈实现的交互界面，键盘友好。
- 模型可配置：可接入多家 LLM 提供商，按需切换（以实际实现为准）。
- Git 集成：读取工作区变更、生成补丁、方便分支/PR 工作流。
- 命令整合：与 lint、fmt、test、build 等命令联动，回路式迭代。

## 典型工作流（Workflow）

1. 在仓库根目录启动 Crush，选择/配置模型与权限范围。
2. 通过自然语言描述任务，或让 Crush 读取 diff/报错/测试输出。
3. 查看建议的 patch/diff，按需部分/整体应用到工作树。
4. 运行测试与构建，如失败则继续迭代修复。
5. 生成提交信息，创建 PR 并附带变更说明。

## 优势（Strengths）

- 贴合终端：脚本化、可组合，面向工程师的“键盘效率”。
- 审计友好：以补丁为中心，易于代码评审与回滚。
- 生态互补：与 Charm 生态工具（glow、gum 等）天然契合。

## 局限（Limitations）

- 生态/成熟度：与 IDE 级产品相比，功能完备度与稳定性需评估。
- 可视化能力有限：复杂重构与 UI 场景更适合 IDE。
- 权限与安全：需谨慎赋权“读写/执行”范围。

## 获取与配置（Pricing / Access）

- 以官方仓库为准（Charmbracelet 组织/网站发布）。

## 对比（Comparison）

- vs Aider：二者均为“补丁中心”的 CLI 代理；Aider 文档/社群成熟度更高。
- vs Cline/Roo Code（CLI 模式）：Crush 更强调 TUI 与终端生态一致性。
- vs IDE Copilot：终端工作流优势明显，但 IDE 上下文/导航更强。

## 资源（Resources）

- Charm 官方与 GitHub 组织（以最新为准）

---

最后更新：2025-11-02
