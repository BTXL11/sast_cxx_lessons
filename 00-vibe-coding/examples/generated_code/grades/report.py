"""Report generation module for grade statistics."""
from typing import Sequence, List
from grades.core import average, median, stddev

CATEGORIES = [
    ("优秀", 90),
    ("良好", 80),
    ("中等", 70),
    ("及格", 60),
    ("不及格", 0),
]

def _validate(scores: Sequence[float]) -> List[float]:
    if not isinstance(scores, (list, tuple)):
        raise TypeError("scores must be a list or tuple of numbers")
    if len(scores) == 0:
        raise ValueError("scores list is empty")
    out: List[float] = []
    for i, s in enumerate(scores):
        if not isinstance(s, (int, float)):
            raise TypeError(f"score at index {i} is not a number: {s!r}")
        out.append(float(s))
    return out

def _categorize(scores: List[float]):
    counts = {name: 0 for name, _ in CATEGORIES}
    for s in scores:
        for name, threshold in CATEGORIES:
            if s >= threshold:
                counts[name] += 1
                break
    return counts

def generate_report(scores: Sequence[float]) -> str:
    """Generate a textual report of grade statistics.

    Sections:
    - Basic stats: count, min, max, average, median, stddev (population)
    - Category distribution counts and percentages
    """
    vals = _validate(scores)
    count = len(vals)
    avg = average(vals)
    med = median(vals)
    sd = stddev(vals)
    mn = min(vals)
    mx = max(vals)
    cat_counts = _categorize(vals)
    lines = []
    lines.append("成绩统计报告")
    lines.append("----------------")
    lines.append(f"人数: {count}")
    lines.append(f"最高分: {mx:.2f}")
    lines.append(f"最低分: {mn:.2f}")
    lines.append(f"平均分: {avg:.2f}")
    lines.append(f"中位数: {med:.2f}")
    lines.append(f"标准差: {sd:.4f}")
    lines.append("")
    lines.append("分档分布：")
    for name, _ in CATEGORIES:
        c = cat_counts[name]
        pct = c / count * 100
        lines.append(f"  {name}: {c} ({pct:.1f}%)")
    return "\n".join(lines)

__all__ = ["generate_report"]
