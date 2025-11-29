# Cline: Comprehensive Guide (2025)

## Overview

Cline is an open-source, autonomous coding agent for your IDE. It started as the "Claude Dev" VS Code extension and evolved into a general agent that can plan tasks, edit files, run shell commands, browse the web, and iterate toward goals with human-in-the-loop checkpoints. Cline supports model freedom (Claude, GPT, Gemini, local via Ollama) and works across CLI, VS Code, and JetBrains.

- Website: <https://cline.bot/>
- VS Code: <https://marketplace.visualstudio.com/items?itemName=saoudrizwan.claude-dev>
- Docs: <https://docs.cline.bot/>

## Key Features

- Autonomous multi-step agent: plan → edit → run → verify → iterate
- First-class CLI + IDE flow: start in terminal, continue in VS Code/JetBrains, finish in CI
- Tools: file system read/write, shell commands, browser, tests, git
- Model flexibility: Anthropic Claude, OpenAI GPT, Google Gemini, OpenRouter, local (Ollama)
- Checkpoints: user approval gates and diff review before applying changes
- MCP support: extend functionality via Model Context Protocol servers
- Project context: .clinerules and system prompts for style/constraints
- Reproducible history: identical timeline across CLI/IDE/CI runs
- Open source, vendor-neutral; BYO API keys

## Strengths

- Excellent autonomy with safe checkpoints and diffs
- Works the same across CLI and IDEs; reproducible state
- Broad model support; easy to swap providers
- Strong web browsing and command execution for real tasks
- Active community and rapid iteration

## Limitations

- Requires careful prompting and scoping for large repos
- Long running tasks can be slow/expensive depending on model
- Quality depends on chosen model and available context
- Still needs developer oversight for critical changes

## Use Cases

- Implement a feature across multiple files with tests
- Refactor module structure and update imports
- Run linters/formatters/tests and fix failures
- Investigate a bug end-to-end (read logs → reproduce → patch)
- Scaffold a new project and CI workflow

## Pricing/Access

- Extension and CLI are free/open-source
- BYO model/API keys (OpenAI, Anthropic, Google, OpenRouter, etc.)
- No data used to train Cline itself; model provider policies apply

## IDE and Workflow Integration

- VS Code extension (id: saoudrizwan.claude-dev)
- JetBrains plugin support (see docs)
- CLI entrypoint that shares history/state with IDE
- MCP servers for tools (filesystem, web, issue trackers, etc.)

## Setup

1. Install the VS Code extension "Cline" from Marketplace
2. Provide your API key(s) in the extension settings
3. (Optional) Create `.clinerules` to set project constraints and style
4. Start a task: describe the objective and let Cline propose a plan
5. Approve diffs/commands; iterate until done

## Comparison Points

- vs Roo Code: Cline focuses on transparent, checkpointed autonomy; Roo emphasizes multi-agent team workflows
- vs Cursor/Windsurf: Cline is an agent-first layer you add to your existing editor, not a full IDE fork (Cursor/Windsurf are IDEs)
- vs Aider: Cline is more agentic with browser/command tools; Aider is a focused terminal pair programmer tightly coupled with git

## Example Commands

- CLI: `cline start` then paste your task; or invoke via npx (see docs)
- VS Code: Open Cline panel → describe objective → run plan

## Resources

- Docs: <https://docs.cline.bot/getting-started/installing-cline>
- Marketplace: <https://marketplace.visualstudio.com/items?itemName=saoudrizwan.claude-dev>
- Website: <https://cline.bot/>

---
Last Updated: Nov 2025
