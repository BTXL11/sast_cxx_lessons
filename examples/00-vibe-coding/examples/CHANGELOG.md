# 文档更新日志

## 2025-11-12 - LangChain v1.0 API 迁移

### 主要更新

本次更新将所有示例代码和文档从 LangChain 旧版 API 迁移到 **LangChain v1.0** 的新 API。

### 具体变更

#### 1. API 变化

**旧 API（已弃用）：**
```python
from langchain.agents import create_react_agent, AgentExecutor
from langchain.memory import ConversationBufferMemory
from langchain.prompts import PromptTemplate

memory = ConversationBufferMemory(return_messages=True)
prompt = PromptTemplate.from_template("...")
agent = create_react_agent(llm=llm, tools=tools, prompt=prompt)
executor = AgentExecutor(agent=agent, tools=tools, memory=memory, verbose=True)
response = executor.invoke({"input": "用户请求"})
```

**新 API（推荐使用）：**
```python
from langchain.agents import create_agent
from langgraph.checkpoint.memory import InMemorySaver

checkpointer = InMemorySaver()
system_prompt = "..."
agent = create_agent(
    model=llm,
    tools=tools,
    system_prompt=system_prompt,
    checkpointer=checkpointer,
)
config = {"configurable": {"thread_id": "1"}}
response = agent.invoke({
    "messages": [{"role": "user", "content": "用户请求"}]
}, config)
```

#### 2. 依赖包更新

**旧依赖：**
```bash
pip install langchain langchain-openai
```

**新依赖：**
```bash
pip install langchain langchain-openai langgraph
```

**说明：** 需要安装 `langgraph` 包以使用 `InMemorySaver` 等新的状态管理功能。

#### 3. 文档更新内容

##### README.md 更新：

1. **添加重要说明部分**
   - 在文档开头添加了 LangChain v1.0 API 的重要说明
   - 列出了主要 API 变化

2. **更新目录结构**
   - 添加了缺失的 `04_integrated_mcp_langchain.py` 文件

3. **更新依赖安装说明**
   - 添加了 `langgraph` 包到安装命令
   - 添加了关于新 API 的注意事项

4. **示例 2 文档更新**
   - 更新核心概念：Memory → Checkpointer
   - 更新代码示例以使用新 API
   - 添加 API 版本说明部分
   - 更新预期输出示例

5. **示例 3 文档更新**
   - 更新 Agent 配置代码示例
   - 添加 API 版本说明部分
   - 更新预期输出格式

6. **示例 4 文档更新**
   - 更新 LangChain Agent 配置示例
   - 添加 API 版本说明部分

7. **更新学习路径**
   - 添加了关于掌握 LangChain v1.0 新 API 的学习目标
   - 添加了关于 checkpointer 状态管理的学习内容

8. **更新 FAQ 部分**
   - 更新依赖安装命令
   - 添加关于 `InMemorySaver` 找不到的解决方案
   - 新增 Q6：处理旧 API 相关错误
   - 更新调试技巧

#### 4. 代码文件状态

所有代码文件已经使用新 API 实现：

- ✅ `01_calendar_server.py` - 无需更新（仅使用 FastMCP）
- ✅ `02_langchain_basic_agent.py` - 已使用新 API
- ✅ `03_code_agent_with_planning.py` - 已使用新 API
- ✅ `04_integrated_mcp_langchain.py` - 已使用新 API

### 关键改进

1. **更简洁的 API**
   - `create_agent` 统一了 Agent 创建流程
   - 不再需要分别创建 Agent 和 Executor

2. **更好的状态管理**
   - `checkpointer` 提供了更灵活的状态持久化
   - 支持 `InMemorySaver`（开发）和 `PostgresSaver`（生产）

3. **更清晰的配置**
   - 使用 `system_prompt` 直接传递提示词
   - 使用 `thread_id` 管理会话状态

4. **更好的可扩展性**
   - 新 API 为未来功能扩展提供了更好的基础
   - 更容易集成到复杂的应用中

### 迁移指南

如果您有基于旧 API 的代码，请按以下步骤迁移：

1. **安装新依赖**
   ```bash
   pip install --upgrade langchain langchain-openai langgraph
   ```

2. **更新导入语句**
   ```python
   # 删除
   from langchain.agents import create_react_agent, AgentExecutor
   from langchain.memory import ConversationBufferMemory
   from langchain.prompts import PromptTemplate
   
   # 添加
   from langchain.agents import create_agent
   from langgraph.checkpoint.memory import InMemorySaver
   ```

3. **更新 Agent 创建代码**
   - 将 `ConversationBufferMemory` 替换为 `InMemorySaver`
   - 将 `PromptTemplate` 替换为 `system_prompt` 字符串
   - 使用 `create_agent` 替代 `create_react_agent` + `AgentExecutor`

4. **更新调用方式**
   - 使用 `messages` 格式传递输入
   - 添加 `config` 参数指定 `thread_id`

5. **测试功能**
   - 验证所有功能正常工作
   - 检查状态管理是否符合预期

### 参考资源

- [LangChain 官方文档](https://docs.langchain.com/)
- [LangGraph 文档](https://langchain-ai.github.io/langgraph/)
- [迁移指南](https://docs.langchain.com/docs/migration)

### 反馈

如有问题或建议，请通过以下方式反馈：
- 提交 Issue
- 发起 Pull Request
- 参与讨论

