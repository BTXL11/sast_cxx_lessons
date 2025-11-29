# Open SWE (LangGraph)

## 概览（Overview）

Open SWE 是由 LangChain 团队推出的开源、基于 LangGraph 的“异步（asynchronous）编码代理（coding agent）”。它将软件开发流程拆分为多个专职智能体（agents），通过图（graph）建模的并发/回退/重试机制编排，从理解代码库到规划方案、实现修改、运行测试到生成 PR，实现端到端的自动化与人机协作。

注：能力与实现不断演进；本文概括其在官方博客、文档与仓库中稳定呈现的设计要点。

## 核心能力（Key Features）

- 多智能体架构：常见包含 Manager / Planner / Coder / Critic（以文档/仓库当期描述为准），各自承担状态管理、任务分解、实现与审阅。
- LangGraph 编排：以图的形式组织步骤，支持分支、回退、超时、重试与人机中断（human-in-the-loop）。
- 端到端闭环：读取需求/issue → 计划 → 生成补丁/说明 → 运行测试/构建 → 评审与PR。
- 可观察性：节点级输入输出、动作轨迹、模型调用与日志追踪，便于调试与治理。
- 可扩展：可替换模型、工具链（检索、执行器、VCS）、质量门禁与组织策略。

## 典型工作流（Workflow）

1. 选择目标仓库与任务（issue/需求）。
2. Manager/Planner 读取上下文并生成计划与子任务。
3. Coder 生成补丁（patch/diff）与变更说明；Critic 审阅或请求修订。
4. 运行测试/构建；根据结果在图上分支或回退重试。
5. 满足质量门禁后创建 PR 并附带说明。

## 优势（Strengths）

- 工程化与可控性：以图建模，显式可视化每一步，便于审计与回溯。
- 并发与鲁棒：支持并行子任务与失败回退，提升吞吐与稳定性。
- 可组合性：模型、检索、执行、评审与门禁均可替换/插拔。

## 局限（Limitations）

- 部署复杂度：需要合理配置模型、工具、权限与资源隔离。
- 依赖代码与测试质量：在覆盖率不足、依赖复杂/脆弱的仓库上效果打折。
- 人机边界：在需求含糊与风险变更上仍需工程师明确约束与验收。

## 定价/获取（Pricing / Access）

- 开源仓库与示例：<https://github.com/langchain-ai/open-swe>
- 博客与文档：
  - 介绍博文：<https://blog.langchain.com/introducing-open-swe-an-open-source-asynchronous-coding-agent/>
  - 文档入口：<https://docs.langchain.com/labs/swe>

## 集成（Integration）

- VCS/CI：GitHub / GitLab / 本地 Git；可在 CI 内以“静默模式”生成补丁与报告。
- 工具链：检索（RAG/符号图）、执行器（shell/pytest/node）、安全与质量扫描（lint/格式化/静态分析）。

## 对比（Comparison）

- vs Devin/企业平台：定位接近，但 Open SWE 强调“开源 + 可编排 + 自主替换组件”，自托管友好。
- vs CLI 代理（Aider/Cline）：后者更交互、人工主导；Open SWE 更偏“多智能体自治 + 图编排”。
- vs IDE Copilot：Open SWE 更像“流水线/车间”，Copilot 偏“行内助手”。

## 资源（Resources）

- GitHub：<https://github.com/langchain-ai/open-swe>
- 文档：<https://docs.langchain.com/labs/swe>
- 博客：<https://blog.langchain.com/introducing-open-swe-an-open-source-asynchronous-coding-agent/>

---

最后更新：2025-11-02
