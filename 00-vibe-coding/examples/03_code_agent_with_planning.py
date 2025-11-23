"""
完整的代码 Agent 示例（具有规划能力）

这是一个功能完整的代码助手 Agent，具备以下能力：
1. **任务规划（Planning）**：将复杂任务分解为多个子任务
2. **记忆系统（Memory）**：保存对话历史和重要信息
3. **工具执行（Action）**：调用各种代码相关工具
4. **错误处理**：自动重试和错误恢复
5. **可观测性**：详细的日志记录

## 应用场景
- 代码审查和质量检查
- 自动生成单元测试
- 代码重构建议
- 文档生成

## 前置知识
- Python 面向对象编程
- 装饰器和高阶函数
- 异常处理
- LangChain 框架基础

## 安装依赖
pip install langchain langchain-openai

## 环境变量
export OPENAI_API_KEY=your_key_here

## 运行方式
python 03_code_agent_with_planning.py
"""

import logging
import os
import time
import json
from typing import List, Dict, Any
from dataclasses import dataclass
from enum import Enum

from langchain_openai import ChatOpenAI
from langchain.tools import tool
from langchain.agents import create_agent
from langgraph.checkpoint.memory import InMemorySaver
from rich.console import Console
from rich.markdown import Markdown

# ============================================================================
# 配置日志系统
# ============================================================================

logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


# ============================================================================
# 定义任务和计划的数据结构
# ============================================================================

class TaskStatus(Enum):
    """任务状态枚举"""
    PENDING = "pending"
    IN_PROGRESS = "in_progress"
    COMPLETED = "completed"
    FAILED = "failed"


@dataclass
class Task:
    """任务数据类"""
    id: int
    description: str
    status: TaskStatus
    result: str = ""
    error: str = ""


class TaskPlanner:
    """任务规划器"""

    def __init__(self):
        self.tasks: List[Task] = []
        self.current_task_id = 0

    def add_task(self, description: str) -> int:
        """添加新任务"""
        task = Task(
            id=self.current_task_id,
            description=description,
            status=TaskStatus.PENDING
        )
        self.tasks.append(task)
        task_id = self.current_task_id
        self.current_task_id += 1
        logger.info(f"新任务已添加 [ID: {task_id}]: {description}")
        return task_id

    def get_task(self, task_id: int) -> Task:
        """获取指定任务"""
        for task in self.tasks:
            if task.id == task_id:
                return task
        raise ValueError(f"任务 {task_id} 不存在")

    def update_status(self, task_id: int, status: TaskStatus, result: str = "", error: str = ""):
        """更新任务状态"""
        task = self.get_task(task_id)
        task.status = status
        task.result = result
        task.error = error
        logger.info(f"任务状态已更新 [ID: {task_id}]: {status.value}")

    def get_summary(self) -> str:
        """获取任务摘要"""
        summary = "任务计划概览:\n"
        for task in self.tasks:
            status_icon = {
                TaskStatus.PENDING: "⏳",
                TaskStatus.IN_PROGRESS: "🔄",
                TaskStatus.COMPLETED: "✅",
                TaskStatus.FAILED: "❌"
            }[task.status]
            summary += f"{status_icon} [ID: {task.id}] {task.description} - {task.status.value}\n"
        return summary


# ============================================================================
# 初始化全局状态
# ============================================================================

# 全局任务规划器
planner = TaskPlanner()

# 代码库（模拟）
code_repository = {}

# 代码实际保存的根目录
BASE_OUTPUT_DIR = os.path.join(os.path.dirname(__file__), "generated_code")
os.makedirs(BASE_OUTPUT_DIR, exist_ok=True)

console = Console()


# ============================================================================
# 定义工具集
# ============================================================================

@tool
def create_plan(task_description: str, subtasks: str) -> str:
    """
    创建任务计划

    将复杂任务分解为多个子任务并添加到计划中。

    参数：
        task_description: 主任务描述
        subtasks: 子任务列表，JSON 格式，例如：["子任务1", "子任务2"]

    返回：
        计划创建的结果
    """
    try:
        subtask_list = json.loads(subtasks)
        logger.info(f"开始创建计划：{task_description}")

        for subtask in subtask_list:
            planner.add_task(subtask)

        return f"成功创建计划，包含 {len(subtask_list)} 个子任务\n{planner.get_summary()}"
    except Exception as e:
        error_msg = f"创建计划失败: {str(e)}"
        logger.error(error_msg)
        return error_msg


@tool
def update_task(task_id: int, status: str, result: str = "", error: str = "") -> str:
    """更新指定任务的状态和结果"""
    try:
        status_enum = TaskStatus(status)
    except ValueError:
        valid_status = ", ".join([s.value for s in TaskStatus])
        return f"无效的状态: {status}。可用状态: {valid_status}"

    planner.update_status(task_id, status_enum, result=result, error=error)
    task = planner.get_task(task_id)
    return (
        f"任务 {task.id} 状态: {task.status.value}\n"
        f"描述: {task.description}\n"
        f"结果: {task.result or '无'}\n"
        f"错误: {task.error or '无'}"
    )


@tool
def list_tasks() -> str:
    """列出当前任务计划中的所有任务及详情"""
    if not planner.tasks:
        return "当前没有任何任务"

    lines = ["当前任务详情："]
    for task in planner.tasks:
        lines.append(
            f"[ID: {task.id}] {task.description}\n"
            f"  状态: {task.status.value}\n"
            f"  结果: {task.result or '-'}\n"
            f"  错误: {task.error or '-'}"
        )
    return "\n".join(lines)


@tool
def analyze_code(code: str, language: str = "python") -> str:
    """
    分析代码质量

    检查代码的潜在问题、复杂度、可读性等。

    参数：
        code: 要分析的代码
        language: 编程语言（默认 python）

    返回：
        代码分析报告
    """
    logger.info(f"开始分析 {language} 代码...")

    # 模拟代码分析（实际应该使用 AST 或静态分析工具）
    issues = []

    # 检查代码长度
    lines = code.strip().split('\n')
    if len(lines) > 50:
        issues.append("⚠️ 函数过长，建议拆分为更小的函数")

    # 检查文档字符串
    if '"""' not in code and "'''" not in code:
        issues.append("⚠️ 缺少文档字符串")

    # 检查注释
    comment_lines = [line for line in lines if line.strip().startswith('#')]
    if len(comment_lines) < len(lines) * 0.1:
        issues.append("⚠️ 注释较少，建议增加注释")

    report = f"代码分析报告（{language}）\n"
    report += f"总行数: {len(lines)}\n"
    report += f"注释行: {len(comment_lines)}\n"
    report += f"\n发现的问题:\n"

    if issues:
        for issue in issues:
            report += f"  {issue}\n"
    else:
        report += "  ✅ 未发现明显问题\n"

    return report


@tool
def generate_tests(code: str, function_name: str) -> str:
    """
    为代码生成单元测试

    参数：
        code: 源代码
        function_name: 要测试的函数名

    返回：
        生成的测试代码
    """
    logger.info(f"为函数 '{function_name}' 生成测试...")

    # 模拟测试生成（实际应该使用 AI 分析函数行为）
    test_code = f'''import unittest

class Test{function_name.capitalize()}(unittest.TestCase):
    """测试 {function_name} 函数"""

    def test_basic_case(self):
        """测试基本用例"""
        # TODO: 实现基本测试用例
        pass

    def test_edge_cases(self):
        """测试边界情况"""
        # TODO: 实现边界测试
        pass

    def test_error_handling(self):
        """测试错误处理"""
        # TODO: 实现错误处理测试
        pass


if __name__ == '__main__':
    unittest.main()
'''

    return test_code


@tool
def run_tests(test_code: str) -> str:
    """
    运行单元测试（模拟）

    参数：
        test_code: 测试代码

    返回：
        测试结果
    """
    logger.info("运行单元测试...")

    # 模拟测试运行
    time.sleep(0.5)

    result = """测试运行结果:

运行了 3 个测试
✅ test_basic_case: 通过
⚠️ test_edge_cases: 跳过（未实现）
⚠️ test_error_handling: 跳过（未实现）

总结: 1 passed, 2 skipped, 0 failed
"""

    return result


@tool
def save_code(filename: str, code: str) -> str:
    """
    保存代码到代码库

    参数：
        filename: 文件名
        code: 代码内容

    返回：
        保存结果
    """
    # 先保存到内存代码库，便于在程序中查看
    code_repository[filename] = code

    # 将 filename 视为相对路径，由 Agent 根据内容设计
    # 支持包含子目录，例如 "algorithms/statistics/calculate_average.py"
    safe_relative_path = filename.replace("\\", "/").lstrip("/")
    full_path = os.path.join(BASE_OUTPUT_DIR, safe_relative_path)

    # 确保目标目录存在
    os.makedirs(os.path.dirname(full_path), exist_ok=True)

    # 将代码写入磁盘
    with open(full_path, "w", encoding="utf-8") as f:
        f.write(code)

    logger.info(f"代码已保存到文件系统: {full_path}")
    return f"✅ 代码已成功保存到 {full_path}"


@tool
def list_saved_code() -> str:
    """列出当前已保存的代码文件"""
    if not code_repository:
        return "当前还没有保存任何代码文件"

    lines = ["当前已保存的代码文件："]
    for filename in code_repository.keys():
        safe_relative_path = filename.replace("\\", "/").lstrip("/")
        full_path = os.path.join(BASE_OUTPUT_DIR, safe_relative_path)
        lines.append(f"- {filename} -> {full_path}")
    return "\n".join(lines)


@tool
def read_saved_code(filename: str) -> str:
    """读取之前保存的代码文件内容"""
    if filename in code_repository:
        return code_repository[filename]

    safe_relative_path = filename.replace("\\", "/").lstrip("/")
    full_path = os.path.join(BASE_OUTPUT_DIR, safe_relative_path)

    if not os.path.exists(full_path):
        return f"未找到文件: {filename}"

    with open(full_path, "r", encoding="utf-8") as f:
        return f.read()


@tool
def get_task_status() -> str:
    """
    获取当前任务计划的状态

    返回：
        任务状态摘要
    """
    return planner.get_summary()


# ============================================================================
# 配置 LLM 与 Agent
# ============================================================================

def create_base_llm(temperature: float = 0.0) -> ChatOpenAI:
    """创建基础 LLM 客户端，用于路由和直接回答"""
    return ChatOpenAI(
        model="gpt-5",
        temperature=temperature,
        base_url="https://ai.megallm.io/v1",
        api_key=os.environ.get("MEGALLM_API_KEY"),
    )


def is_complex_task(task_description: str) -> bool:
    """使用 LLM 判断任务是否为复杂任务"""
    router_llm = create_base_llm(temperature=0)

    prompt = (
        "你是一个任务路由器，负责判断用户任务是否需要使用具备规划和工具调用能力的 Agent。\n"
        "如果任务涉及多步骤、需要规划、代码分析、生成测试、重构或保存多个文件，请回答：complex\n"
        "如果任务只是简单问答、解释概念或对少量代码做轻量说明，请回答：simple\n"
        "只输出一个单词：complex 或 simple。"
    )

    try:
        resp = router_llm.invoke(f"{prompt}\n\n用户任务：\n{task_description}")
        content = getattr(resp, "content", str(resp)).strip().lower()

        if "complex" in content:
            return True
        if "simple" in content:
            return False
    except Exception as e:
        logger.error(f"判断任务复杂度失败: {e}")

    # 回退策略：根据长度和关键词进行简单判断
    if len(task_description) > 400:
        return True

    keywords = ["重构", "架构", "模块", "多文件", "project", "测试用例", "测试套件"]
    if any(k in task_description for k in keywords):
        return True

    return False


def answer_simple(task_description: str) -> str:
    """使用基础 LLM 直接回答简单任务"""
    llm = create_base_llm(temperature=0.2)
    resp = llm.invoke(task_description)
    return getattr(resp, "content", str(resp))


def create_code_agent():
    """创建代码 Agent（使用 LangChain v1.0 API）"""

    # 初始化 LLM
    llm = create_base_llm(temperature=0)

    # 配置记忆（使用 Checkpointer）
    checkpointer = InMemorySaver()

    # 定义系统提示词
    system_prompt = """你是一个专业的代码助手 Agent，具备以下能力：

1. **任务规划**：将复杂任务分解为可执行的子任务
2. **代码分析**：检查代码质量和潜在问题
3. **测试生成**：自动生成单元测试
4. **执行验证**：运行测试并验证结果

## 工作流程

对于复杂任务，请遵循以下步骤：
1. 使用 create_plan 创建详细的任务计划，子任务应覆盖分析、设计、编码、测试、重构、保存和总结等阶段
2. 在每个子任务开始和结束时，使用 update_task 更新任务状态（pending/in_progress/completed/failed），并在 result 和 error 中记录关键信息
3. 在需要时使用 list_tasks 和 get_task_status 查看整体进度
4. 使用 analyze_code 对关键代码片段进行审查
5. 使用 generate_tests 和 run_tests 为核心函数生成并执行测试（即使是简单函数，也要尽量覆盖正常、边界和异常场景）
6. 使用 save_code 保存源码和测试代码；必要时通过 list_saved_code 和 read_saved_code 复用之前生成的文件
7. 在完成所有任务后提供结构化的总结报告

## 代码与文件管理

- 在需要保存源码或测试代码时，必须调用 save_code 工具
- save_code 的 filename 参数应是一个**相对路径**，可以包含子目录，例如：
  - "algorithms/statistics/calculate_average.py"
  - "tests/test_calculate_average.py"
- 请根据代码的功能和内容，合理设计目录结构并填入 filename
- 工具会自动将这些相对路径保存到预先配置的根目录下

## 回答格式

思考（Thought）：分析当前需要做什么
行动（Action）：选择合适的工具
行动输入（Action Input）：工具的输入参数
观察（Observation）：工具返回的结果
... （重复上述循环直到完成任务）
思考：任务已完成
最终答案（Final Answer）：向用户报告结果
"""

    # 准备工具
    tools = [
        create_plan,
        update_task,
        list_tasks,
        analyze_code,
        generate_tests,
        run_tests,
        save_code,
        list_saved_code,
        read_saved_code,
        get_task_status,
    ]

    # 使用新的 create_agent API 创建 Agent
    # create_agent 是 LangChain v1.0 的标准方法
    agent = create_agent(
        model=llm,
        tools=tools,
        system_prompt=system_prompt,
        checkpointer=checkpointer,
    )

    return agent


# ============================================================================
# 主程序
# ============================================================================


def read_task_from_console(default_task: str) -> str:
    console.print("\n[bold cyan]【输入】你可以输入自己的任务描述，支持多行；直接回车使用内置示例任务。[/bold cyan]")
    console.print("[dim]第一行输入后按回车继续输入，空行结束输入。[/dim]")

    try:
        first_line = input()
    except EOFError:
        return default_task

    if not first_line.strip():
        console.print("\n[输入] 使用内置示例任务", style="green")
        return default_task

    lines = [first_line]
    while True:
        try:
            line = input()
        except EOFError:
            break
        if not line.strip():
            break
        lines.append(line)

    console.print("\n[输入] 已接收自定义任务", style="green")
    return "\n".join(lines).strip()


if __name__ == "__main__":
    console.rule("[bold cyan]代码助手 Agent（具有规划能力）[/bold cyan]")
    console.print()

    # 创建 Agent
    agent = create_code_agent()

    # 配置：使用 thread_id 来维护会话状态
    config = {"configurable": {"thread_id": "1"}}

    # 示例代码（用于默认任务）
    sample_code = '''
def calculate_average(numbers):
    total = sum(numbers)
    count = len(numbers)
    return total / count
'''

    # 默认示例任务：完整的代码审查与测试流程
    default_task = f"""
    请对以下代码进行完整的审查和测试流程：

    ```python
    {sample_code}
    ```

    具体要求：
    1. 创建一个详细的任务计划
    2. 分析代码质量
    3. 生成单元测试
    4. 运行测试
    5. 为源码和测试代码设计合理的相对路径（如 algorithms/statistics/calculate_average.py 和 tests/test_calculate_average.py），并调用 save_code 保存
    6. 提供完整的总结报告（包括保存的文件路径）
    7. 如果你认为有必要，可以将任务拆分为多个模块和文件，并在任务计划和总结中清晰说明
    """

    # 读取用户输入的任务描述
    task = read_task_from_console(default_task)

    try:
        console.print("\n[bold yellow][路由][/bold yellow] 正在判断任务是否为复杂任务...")
        complex_task = is_complex_task(task)

        if complex_task:
            console.print("[bold yellow][路由][/bold yellow] 检测为复杂任务，使用 Agent 模式执行")
            response = agent.invoke({
                "messages": [{"role": "user", "content": task}]
            }, config)
            final_answer = response['messages'][-1].content
        else:
            console.print("[bold yellow][路由][/bold yellow] 检测为简单任务，直接用 LLM 回答")
            final_answer = answer_simple(task)

        console.rule("[bold magenta]最终答案[/bold magenta]")
        try:
            console.print(Markdown(final_answer))
        except Exception:
            console.print(final_answer)
    except Exception as e:
        logger.error(f"执行失败: {str(e)}")
        console.print(f"\n❌ 执行失败: {str(e)}", style="bold red")

    console.rule("[bold blue]代码库内容[/bold blue]")
    if not code_repository:
        console.print("（当前运行未保存任何代码文件）", style="dim")
    else:
        for filename, code in code_repository.items():
            console.print(f"\n[bold]文件:[/bold] {filename}")
            console.print("-" * 80, style="dim")
            preview = code[:200] + "..." if len(code) > 200 else code
            console.print(preview, style="dim")
