# Sourcegraph Amp

## 概览（Overview）

Sourcegraph Amp 是 Sourcegraph 推出的“代理化编码（agentic coding）”工具家族，面向 IDE（VS Code）与命令行（CLI）。它利用 Sourcegraph 的代码搜索/索引与上下文构建能力，为补全、解释、重构、补丁生成与多仓代码理解提供支撑。

## 核心能力（Key Features）

- 全仓/多仓上下文：依托 Sourcegraph 索引与符号图谱，聚合高相关代码上下文。
- 代理式任务分解：将“修复/实现/重构/测试”等分为可审阅的子步骤与补丁。
- VS Code + CLI：同一能力在 IDE 与终端内可用，便于不同工作流。
- 搜索与导航：结合正则/符号搜索、代码智能与跨仓引用查找。
- 企业治理：审计日志、访问控制、私有部署选项（以官方版本为准）。

## 典型工作流（Workflow）

1. 在 VS Code/CLI 中选定仓库与范围；
2. 通过自然语言描述任务或选择预设“修复/重构/解释/生成测试”动作；
3. Amp 构造上下文、生成补丁与说明；
4. 人工审阅并应用；
5. 运行测试/构建并迭代直至通过，创建 PR。

## 优势（Strengths）

- 强上下文：Sourcegraph 在大仓场景的检索/理解能力成熟。
- 多入口：IDE 与 CLI 统一体验，适配个人与流水线使用。
- 可审计：补丁与解释分离，利于代码评审与回滚。

## 局限（Limitations）

- 部署与集成成本：企业级能力需要配套的索引/权限体系。
- 非 Sourcegraph 环境：若无现成 Sourcegraph，初始门槛较高。

## 定价/获取（Pricing / Access）

- 以 Sourcegraph 官方为准（Cloud/自建/企业授权）。

## 对比（Comparison）

- vs GitHub Copilot：Amp 强在跨仓搜索与上下文组织；Copilot 强在行内补全与生态集成。
- vs Cody：同属 Sourcegraph 体系；Amp 更偏“代理/补丁工作流”，Cody 偏聊天/补全。
- vs Aider/Cline（CLI）：Amp 有成熟的代码检索与企业治理优势。

## 资源（Resources）

- 官方网站/文档：<https://sourcegraph.com/amp> （以最新为准）

---

最后更新：2025-11-02
