# Aider: Terminal Pair Programming (2025)

## Overview

Aider is an open-source, terminal-based AI pair programmer that integrates tightly with git. It can read and edit files, propose patches, and automatically commit changes with descriptive messages. It supports multiple model providers and is widely used for CLI-first workflows.

- GitHub: <https://github.com/Aider-AI/aider>
- Docs: <https://aider.chat/>

## Key Features

- Chat-driven editing of files with precise diffs
- Automatic git commits on each change
- Works well with test-driven workflows
- Model support: OpenAI, Anthropic, Google, OpenRouter, local (via adapters)
- Repo-aware context; can include/exclude files

## Strengths

- Excellent git hygiene (commits, diffs, revert)
- Lightweight and fast for iterative tasks
- Works anywhere a terminal is available

## Limitations

- No GUI/IDE panel (terminal-first)
- Autonomy is user-driven (not a fully autonomous agent)

## Use Cases

- Apply small-to-medium patches safely
- Generate tests and make them pass
- Refactor and run linters from CLI

## Pricing/Access

- Open-source; BYO API keys

## Installation

```bash
pip install aider-chat
# or: uvx aider / pipx install aider-chat
```

## Basic Usage

```bash
aider --model anthropic/claude-3-5-sonnet
# add specific files:
aider --file app.py --file tests/test_app.py
```

## Comparison Points

- vs Cline: Aider is simpler and git-centric; Cline is agentic with browser/commands
- vs Copilot/Cursor: Aider is terminal-only; complements IDE assistants

## Resources

- GitHub: <https://github.com/Aider-AI/aider>
- Docs: <https://aider.chat/docs/>

---
Last Updated: Nov 2025
