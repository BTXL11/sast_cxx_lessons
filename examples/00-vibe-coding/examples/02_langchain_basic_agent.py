"""
LangChain 基础 Agent 示例

这个示例展示了如何使用 LangChain 创建一个简单的 Agent，
该 Agent 可以调用工具来完成日程管理任务。

## 前置知识
- Python 基础
- 异步编程基础（可选）
- LLM（大语言模型）的基本概念

## 安装依赖
pip install langchain langchain-openai

## 环境变量
需要设置 OPENAI_API_KEY 环境变量：
- Windows: set OPENAI_API_KEY=your_key_here
- Linux/Mac: export OPENAI_API_KEY=your_key_here

## 运行方式
python 02_langchain_basic_agent.py

## 核心概念
1. **Tool（工具）**：Agent 可以调用的函数
2. **LLM（大语言模型）**：负责推理和决策
3. **Checkpointer（检查点）**：保存对话历史和状态（替代旧的 Memory）
4. **Agent（智能体）**：整合以上组件的系统
5. **ReAct 模式**：Reasoning（推理）+ Acting（行动）的循环

## API 版本说明
本示例使用 LangChain v1.0 的新 API：
- 使用 `create_agent` 替代旧的 `create_react_agent` + `AgentExecutor`
- 使用 `checkpointer` 替代旧的 `ConversationBufferMemory`
- 使用 `system_prompt` 参数替代 `PromptTemplate`
"""

from langchain_openai import ChatOpenAI
from langchain.tools import tool
from langchain.agents import create_agent
from langgraph.checkpoint.memory import InMemorySaver

# ============================================================================
# 第一步：定义工具（Tools）
# ============================================================================

# 模拟的日程数据存储
EVENTS = []


@tool
def add_event(date: str, title: str) -> str:
    """
    添加新日程到日历

    参数：
        date: 日期，格式如 "2025-11-12"
        title: 日程标题

    返回：
        操作结果的描述
    """
    EVENTS.append({"date": date, "title": title})
    return f"已成功添加日程：{date} - {title}"


@tool
def list_all_events() -> str:
    """
    列出所有日程

    返回：
        所有日程的格式化字符串
    """
    if not EVENTS:
        return "当前没有任何日程"

    result = "当前所有日程：\n"
    for i, event in enumerate(EVENTS, 1):
        result += f"{i}. {event['date']} - {event['title']}\n"
    return result


# ============================================================================
# 第二步：初始化 LLM
# ============================================================================

# 使用 OpenAI 的 GPT-4o-mini 模型（成本较低，适合开发测试）
llm = ChatOpenAI(
    model="gpt-4o-mini",
    temperature=0,  # 降低随机性，使输出更确定
)

# ============================================================================
# 第三步：配置记忆系统（使用 Checkpointer）
# ============================================================================

# InMemorySaver 提供短期记忆功能，适合开发和测试
# 生产环境建议使用 PostgresSaver
checkpointer = InMemorySaver()

# ============================================================================
# 第四步：定义系统提示词
# ============================================================================

# 系统提示词定义了 Agent 的行为方式
system_prompt = """你是一个专业的日程助理，可以帮助用户管理日程。

请使用以下格式回答：

思考（Thought）：我需要做什么？
行动（Action）：使用的工具名称
行动输入（Action Input）：工具的输入参数
观察（Observation）：工具返回的结果
... （这个 思考/行动/行动输入/观察 的循环可以重复多次）
思考：我现在知道最终答案了
最终答案（Final Answer）：对用户的最终回答
"""

# ============================================================================
# 第五步：创建 Agent
# ============================================================================

# 准备工具列表
tools = [add_event, list_all_events]

# 使用新的 create_agent API 创建 Agent
# create_agent 是 LangChain v1.0 的标准方法，替代了旧的 create_react_agent + AgentExecutor
agent = create_agent(
    model=llm,
    tools=tools,
    system_prompt=system_prompt,
    checkpointer=checkpointer,  # 提供记忆功能
)

# ============================================================================
# 第六步：运行示例
# ============================================================================

if __name__ == "__main__":
    print("=" * 60)
    print("LangChain 基础 Agent 示例")
    print("=" * 60)
    print()

    # 配置：使用 thread_id 来维护会话状态
    config = {"configurable": {"thread_id": "1"}}

    # 示例 1：添加日程
    print("\n【示例 1】添加日程")
    print("-" * 60)
    response = agent.invoke({
        "messages": [{"role": "user", "content": "帮我在11月15日添加一个标题为'团队会议'的日程"}]
    }, config)
    print(f"\n最终回答：{response['messages'][-1].content}")

    # 示例 2：再添加一个日程
    print("\n【示例 2】再添加一个日程")
    print("-" * 60)
    response = agent.invoke({
        "messages": [{"role": "user", "content": "再帮我添加11月16日的'项目评审'"}]
    }, config)
    print(f"\n最终回答：{response['messages'][-1].content}")

    # 示例 3：查看所有日程
    print("\n【示例 3】查看所有日程")
    print("-" * 60)
    response = agent.invoke({
        "messages": [{"role": "user", "content": "列出我所有的日程"}]
    }, config)
    print(f"\n最终回答：{response['messages'][-1].content}")

    # 示例 4：测试记忆功能
    print("\n【示例 4】测试记忆功能")
    print("-" * 60)
    response = agent.invoke({
        "messages": [{"role": "user", "content": "我第一个添加的日程是什么？"}]
    }, config)
    print(f"\n最终回答：{response['messages'][-1].content}")

    print("\n" + "=" * 60)
    print("示例运行完成")
    print("=" * 60)
