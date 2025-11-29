# AI Agent 与 MCP 快速参考指南

## 📊 文档统计

- 📄 文档总行数：**1,322 行**
- 📊 Mermaid 图表：**9 个**
- 💻 代码块：**106 个**（全部带语言标识符）
- 📚 示例数量：**4 个**

## 🗺️ 文档导航

### 核心章节

| 章节 | 行号范围 | 内容 |
|------|---------|------|
| API 版本说明 | 16-59 | LangChain v1.0 API 迁移说明和对比图 |
| 示例 1 | 140-257 | MCP Calendar Server 基础 |
| 示例 2 | 259-457 | LangChain Agent 基础 |
| 示例 3 | 459-705 | Code Agent 任务规划 |
| 示例 4 | 707-1093 | FastMCP + LangChain 集成 |
| 学习路径 | 1095-1206 | 分阶段学习计划和时间线 |
| FAQ | 1208-1275 | 常见问题解答 |

## 🎨 Mermaid 图表索引

### 1. API 迁移对比图
- **位置**：第 23-47 行
- **类型**：流程图 (graph LR)
- **用途**：对比旧 API vs 新 API

### 2. 示例 1 - MCP Server 架构
- **位置**：第 152-176 行
- **类型**：流程图 (graph TB)
- **用途**：展示 MCP Server 架构和通信流程

### 3. 示例 2 - Agent 架构
- **位置**：第 270-293 行
- **类型**：流程图 (graph TB)
- **用途**：展示 LangChain Agent 核心组件

### 4. 示例 2 - ReAct 执行流程
- **位置**：第 297-325 行
- **类型**：序列图 (sequenceDiagram)
- **用途**：展示 ReAct 循环的详细执行流程

### 5. 示例 3 - 系统架构
- **位置**：第 470-500 行
- **类型**：流程图 (graph TB)
- **用途**：展示 Code Agent 系统架构

### 6. 示例 3 - 任务执行流程
- **位置**：第 504-539 行
- **类型**：序列图 (sequenceDiagram)
- **用途**：展示任务规划和执行流程

### 7. 示例 4 - 双层架构
- **位置**：第 806-841 行
- **类型**：流程图 (graph TB)
- **用途**：展示 MCP + LangChain 双层架构

### 8. 示例 4 - 交互序列
- **位置**：第 845-882 行
- **类型**：序列图 (sequenceDiagram)
- **用途**：展示完整的请求处理流程

### 9. 学习路径时间线
- **位置**：第 1099-1143 行
- **类型**：时间线 (timeline)
- **用途**：展示分阶段学习路径

## 🚀 快速开始

### 环境准备

```bash
# 安装所有依赖
pip install fastmcp langchain langchain-openai langgraph

# 设置 API 密钥（Windows）
set OPENAI_API_KEY=sk-your-key-here

# 设置 API 密钥（Linux/macOS）
export OPENAI_API_KEY=sk-your-key-here
```

### 运行示例

```bash
# 示例 1：MCP Server
python 01_calendar_server.py

# 示例 2：LangChain Agent
python 02_langchain_basic_agent.py

# 示例 3：Code Agent
python 03_code_agent_with_planning.py

# 示例 4：集成示例
python 04_integrated_mcp_langchain.py
```

## 📖 API 速查

### LangChain v1.0 新 API

#### 创建 Agent

```python
from langchain.agents import create_agent
from langgraph.checkpoint.memory import InMemorySaver

# 配置
llm = ChatOpenAI(model="gpt-4o-mini", temperature=0)
checkpointer = InMemorySaver()
system_prompt = "你是一个专业的助手..."

# 创建 Agent
agent = create_agent(
    model=llm,
    tools=tools,
    system_prompt=system_prompt,
    checkpointer=checkpointer,
)
```

#### 调用 Agent

```python
# 配置会话
config = {"configurable": {"thread_id": "1"}}

# 发送请求
response = agent.invoke({
    "messages": [{"role": "user", "content": "用户请求"}]
}, config)
```

### 旧 API（已弃用）

```python
# ❌ 不要使用
from langchain.agents import create_react_agent, AgentExecutor
from langchain.memory import ConversationBufferMemory

memory = ConversationBufferMemory(return_messages=True)
agent = create_react_agent(llm=llm, tools=tools, prompt=prompt)
executor = AgentExecutor(agent=agent, tools=tools, memory=memory)
```

## 🛠️ 工具定义速查

### FastMCP 工具

```python
from fastmcp import FastMCP

mcp = FastMCP("server-name")

@mcp.tool()
def my_tool(param: str) -> dict:
    """工具描述"""
    return {"result": "success"}
```

### LangChain 工具

```python
from langchain.tools import tool as lc_tool

@lc_tool
def my_tool(param: str) -> str:
    """工具描述"""
    return "result"
```

## 🎯 核心概念速查

### Agent 组件

| 组件 | 旧 API | 新 API | 说明 |
|------|--------|--------|------|
| 记忆 | ConversationBufferMemory | InMemorySaver | 状态管理 |
| 提示词 | PromptTemplate | system_prompt | 系统提示 |
| 创建 | create_react_agent | create_agent | Agent 创建 |
| 执行 | AgentExecutor | Agent.invoke | 调用方式 |
| 会话 | - | thread_id | 会话标识 |

### ReAct 模式

```text
1. Reasoning（推理）：思考需要做什么
2. Acting（行动）：调用工具执行
3. Observing（观察）：查看执行结果
4. 循环往复直到完成任务
```

## 📚 学习路径速查

### 第 1-2 周：基础入门
- ✅ 理解基本概念
- ✅ 运行示例 1 和 2
- ✅ 掌握 LangChain v1.0 API

### 第 3-4 周：进阶学习
- ✅ 学习任务规划（示例 3）
- ✅ 理解双层架构（示例 4）
- ✅ 自定义开发

### 第 5 周+：高级实践
- ✅ 架构优化
- ✅ 生产部署
- ✅ 持续改进

## 🔍 常见问题速查

### Q1: ModuleNotFoundError
```bash
pip install fastmcp langchain langchain-openai langgraph
```

### Q2: 找不到 InMemorySaver
```bash
pip install langgraph
```

### Q3: API 密钥错误
```bash
# 检查环境变量
echo %OPENAI_API_KEY%  # Windows
echo $OPENAI_API_KEY   # Linux/macOS
```

### Q4: 旧 API 错误
- 升级到最新版本
- 使用新 API（create_agent）
- 参考文档中的 API 版本说明

## 📊 图表查看建议

### 支持 Mermaid 的工具
- ✅ GitHub
- ✅ VS Code（需要插件）
- ✅ Typora
- ✅ Obsidian
- ✅ GitLab

### VS Code 插件推荐
```text
- Markdown Preview Mermaid Support
- Mermaid Markdown Syntax Highlighting
```

## 🔗 相关资源

- [LangChain 官方文档](https://docs.langchain.com/)
- [LangGraph 文档](https://langchain-ai.github.io/langgraph/)
- [FastMCP 文档](https://github.com/jlowin/fastmcp)
- [Mermaid 文档](https://mermaid.js.org/)

## 📝 文档更新日志

查看 `CHANGELOG.md` 了解详细的更新历史。

查看 `README_IMPROVEMENTS.md` 了解本次改进的详细说明。

---

**提示**：本快速参考指南提供了文档的概览和常用信息的快速访问。详细内容请参考 `README.md` 主文档。

