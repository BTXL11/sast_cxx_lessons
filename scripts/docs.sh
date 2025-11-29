#!/bin/bash
#
# MkDocs 文档辅助脚本
# 用法: ./scripts/docs.sh [serve|build|install]
#

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

cd "$PROJECT_ROOT"

ACTION="${1:-serve}"

case "$ACTION" in
    install)
        echo -e "\033[36mInstalling documentation dependencies...\033[0m"
        pip install -e ".[docs]"
        echo -e "\033[32mDone!\033[0m"
        ;;
    serve)
        echo -e "\033[36mStarting local documentation server...\033[0m"
        echo -e "\033[33mVisit http://127.0.0.1:8000 to preview\033[0m"
        mkdocs serve
        ;;
    build)
        echo -e "\033[36mBuilding documentation...\033[0m"
        mkdocs build --strict
        echo -e "\033[32mDocumentation built to ./site/\033[0m"
        ;;
    *)
        echo "Usage: $0 [serve|build|install]"
        echo "  serve   - Start local preview server (default)"
        echo "  build   - Build static documentation"
        echo "  install - Install documentation dependencies"
        exit 1
        ;;
esac
