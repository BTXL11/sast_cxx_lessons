# Snyk Code（DeepCode）

概览 / Overview

- 定位：面向开发者的即时/增量静态代码分析（SAST）与 AI 修复建议工具，前身为 DeepCode 引擎并入 Snyk 后的产品化形态。
- 目标：在 IDE/PR 阶段尽早发现安全缺陷/代码异味，并给出可执行的修复建议与学习示例。

Key Features（核心特性）

- 快速、上下文感知的 SAST：在编辑时与 PR 检查中发现问题，结果包含路径、影响与示例。
- AI 辅助修复建议：结合模式库与模型生成给出修复 patch，开发者可一键应用/调优。
- IDE 与 PR 集成：VS Code/JetBrains 插件、GitHub/GitLab/Azure DevOps PR 注释与阻断策略。
- 多语言支持：覆盖主流后端/前端语言与框架；持续扩展规则集与模型能力。
- 与 Snyk 平台联动：与 Snyk Open Source/Container/Infrastructure 等安全产品协同治理。

Strengths（优势）

- 开发者体验好：反馈快、提示清晰、修复建议直达代码。
- 企业治理：与组织策略、质量门禁与报表体系结合，支持合规审计。
- 持续更新的规则+模型混合引擎，减少纯规则或纯 ML 的单点短板。

Limitations（限制）

- 误报/漏报：静态分析常见权衡；需结合单元测试/动态扫描/代码评审共同保障。
- 私有/遗留代码库：初次扫描与基线建立可能需要时间与资源。
- 付费为主：免费层功能有限，完整治理能力通常在商业计划中。

Use Cases（典型用例）

- 在 IDE 中即时发现并修复常见漏洞/异味
- 在 PR 阶段作为质量门禁，阻断高风险修改合入
- 与安全团队协作，出具风险报表与跟踪修复 SLA

Pricing / Access（获取与定价）

- 提供免费与付费层；团队/企业计划解锁更完整的策略、审计与报表能力。详见官方站点。

Integrations（集成）

- IDE：VS Code、JetBrains 系列
- 源码平台：GitHub、GitLab、Azure DevOps、Bitbucket 等
- 与 Snyk 其他产品线联动：依赖、容器、基础设施扫描

Comparison（对比要点）

- 对比 GitHub CodeQL/Advanced Security：CodeQL 侧重语义查询与规则编写能力；Snyk Code 更强调开发体验与 AI 修复建议。
- 对比 SonarQube/SonarCloud：Sonar 代码质量覆盖面广；Snyk Code 在“安全缺陷+修复建议直达”上更聚焦。
- 对比 DeepSource/Semgrep：侧重轻量规则与 CI 扫描；Snyk Code 提供 IDE 即时反馈与平台化治理。

Examples / Resources（示例与资源）

- 官方站点与文档：<https://snyk.io/product/snyk-code/>
- DeepCode 历史背景与并入公告：Snyk 官方博客

最后更新：2025-11-02
