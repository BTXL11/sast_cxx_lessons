"""Calculator module providing safe arithmetic operations and expression evaluation."""
from __future__ import annotations
import ast
from typing import Union, Any

Number = Union[int, float]

__all__ = ["Calculator", "CalculatorError"]

class CalculatorError(Exception):
    """Custom exception for calculator errors."""
    pass

class Calculator:
    """A simple calculator supporting basic operations and safe expression evaluation."""

    def _validate_number(self, x: Any) -> Number:
        if not isinstance(x, (int, float)):
            raise CalculatorError(f"Unsupported operand type: {type(x)}")
        return x

    def add(self, a: Any, b: Any) -> Number:
        a = self._validate_number(a)
        b = self._validate_number(b)
        return a + b

    def sub(self, a: Any, b: Any) -> Number:
        a = self._validate_number(a)
        b = self._validate_number(b)
        return a - b

    def mul(self, a: Any, b: Any) -> Number:
        a = self._validate_number(a)
        b = self._validate_number(b)
        return a * b

    def div(self, a: Any, b: Any) -> float:
        a = self._validate_number(a)
        b = self._validate_number(b)
        if b == 0:
            raise CalculatorError("Division by zero")
        return a / b

    def mod(self, a: Any, b: Any) -> Number:
        a = self._validate_number(a)
        b = self._validate_number(b)
        if b == 0:
            raise CalculatorError("Modulo by zero")
        return a % b

    def pow(self, a: Any, b: Any) -> Number:
        a = self._validate_number(a)
        b = self._validate_number(b)
        try:
            return pow(a, b)
        except OverflowError as e:
            raise CalculatorError(str(e))

    def evaluate(self, expression: str) -> Number:
        """Safely evaluate an arithmetic expression string."""
        if not isinstance(expression, str):
            raise CalculatorError("Expression must be a string")
        try:
            tree = ast.parse(expression, mode='eval')
        except SyntaxError as e:
            raise CalculatorError(f"Syntax error: {e}")

        def _eval(node: ast.AST) -> Number:
            if isinstance(node, ast.Expression):
                return _eval(node.body)
            if isinstance(node, ast.BinOp):
                left = _eval(node.left)
                right = _eval(node.right)
                op = node.op
                if isinstance(op, ast.Add):
                    return left + right
                if isinstance(op, ast.Sub):
                    return left - right
                if isinstance(op, ast.Mult):
                    return left * right
                if isinstance(op, ast.Div):
                    if right == 0:
                        raise CalculatorError("Division by zero")
                    return left / right
                if isinstance(op, ast.Mod):
                    if right == 0:
                        raise CalculatorError("Modulo by zero")
                    return left % right
                if isinstance(op, ast.Pow):
                    try:
                        return pow(left, right)
                    except OverflowError as e:
                        raise CalculatorError(str(e))
                raise CalculatorError(f"Unsupported operator: {op}")
            if isinstance(node, ast.UnaryOp):
                operand = _eval(node.operand)
                if isinstance(node.op, ast.UAdd):
                    return +operand
                if isinstance(node.op, ast.USub):
                    return -operand
                raise CalculatorError(f"Unsupported unary operator: {node.op}")
            if isinstance(node, ast.Num):  # Python <3.8
                return node.n
            if isinstance(node, ast.Constant):  # Python 3.8+
                if isinstance(node.value, (int, float)):
                    return node.value
                else:
                    raise CalculatorError("Unsupported constant type")
            raise CalculatorError(f"Unsupported expression element: {ast.dump(node)}")

        return _eval(tree)
