"""
MCP Calendar Server 基础示例

这是一个使用 FastMCP 框架实现的日历管理服务器。
该服务器暴露了一组工具（tools），让 AI 模型可以通过 MCP 协议调用来管理日程。

## 前置知识
- Python 基础语法
- 装饰器的概念
- 基本的 JSON 数据结构

## 安装依赖
pip install fastmcp

## 运行方式
python 01_calendar_server.py

## 配置客户端（以 Claude Desktop 为例）
在配置文件中添加：
{
  "mcpServers": {
    "calendar": {
      "command": "python",
      "args": ["<绝对路径>/01_calendar_server.py"],
      "env": {}
    }
  }
}

配置文件位置：
- Windows: %APPDATA%\\Claude\\claude_desktop_config.json
- macOS: ~/Library/Application Support/Claude/claude_desktop_config.json
- Linux: ~/.config/Claude/claude_desktop_config.json
"""

from fastmcp import FastMCP
from typing import List, Dict

# 创建 FastMCP 应用实例
# 第一个参数是服务器名称，version 指定版本号
app = FastMCP("calendar", version="0.1.0")

# 使用内存中的列表存储日程数据（生产环境应使用数据库）
EVENTS: List[Dict] = []


@app.tool
def add_event(date: str, title: str) -> dict:
    """
    在指定日期新增日程

    参数：
        date: 日期字符串，格式如 "2025-11-12"
        title: 日程标题

    返回：
        包含状态和数据的字典
    """
    event = {"date": date, "title": title}
    EVENTS.append(event)
    return {"status": "ok", "data": event}


@app.tool
def list_events() -> list:
    """
    列出所有日程

    返回：
        所有日程的列表
    """
    return EVENTS


@app.tool
def delete_event(date: str, title: str) -> dict:
    """
    删除指定日期与标题的日程

    参数：
        date: 日期字符串
        title: 日程标题

    返回：
        删除结果，包含被删除的日程或错误信息
    """
    for i, e in enumerate(EVENTS):
        if e.get("date") == date and e.get("title") == title:
            removed = EVENTS.pop(i)
            return {"ok": True, "removed": removed}
    raise ValueError(f"未找到日程：{date} - {title}")


@app.tool
def update_event(date: str, title: str, new_title: str) -> dict:
    """
    更新指定日程的标题

    参数：
        date: 日期字符串
        title: 原标题
        new_title: 新标题

    返回：
        更新结果
    """
    for e in EVENTS:
        if e.get("date") == date and e.get("title") == title:
            e["title"] = new_title
            return {"ok": True, "item": e}
    raise ValueError(f"未找到日程：{date} - {title}")


@app.tool
def search_events(keyword: str) -> list[dict]:
    """
    按关键词模糊搜索标题

    参数：
        keyword: 搜索关键词

    返回：
        匹配的日程列表
    """
    kw = keyword.lower()
    return [e for e in EVENTS if kw in e.get("title", "").lower()]


# 运行服务器
if __name__ == "__main__":
    app.run()
