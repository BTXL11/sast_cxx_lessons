"""Core statistical functions for grade analysis.

Functions:
    average(scores): Return the arithmetic mean.
    median(scores): Return the median value.
    stddev(scores, sample=False): Return standard deviation (population by default, sample if sample=True)

Raises:
    ValueError: if scores list is empty
    TypeError: if any element is not int/float
"""
from math import sqrt
from typing import List, Sequence

Number = float

def _validate_scores(scores: Sequence[float]) -> List[float]:
    if not isinstance(scores, (list, tuple)):
        raise TypeError("scores must be a list or tuple of numbers")
    if len(scores) == 0:
        raise ValueError("scores list is empty")
    validated: List[float] = []
    for i, s in enumerate(scores):
        if not isinstance(s, (int, float)):
            raise TypeError(f"score at index {i} is not a number: {s!r}")
        validated.append(float(s))
    return validated


def average(scores: Sequence[float]) -> float:
    """Compute arithmetic mean of scores.

    >>> average([90, 100])
    95.0
    """
    vals = _validate_scores(scores)
    return sum(vals) / len(vals)


def median(scores: Sequence[float]) -> float:
    """Compute median value.

    For even count, returns the average of the two middle values.
    """
    vals = _validate_scores(scores)
    sorted_vals = sorted(vals)
    n = len(sorted_vals)
    mid = n // 2
    if n % 2 == 1:
        return sorted_vals[mid]
    else:
        return (sorted_vals[mid - 1] + sorted_vals[mid]) / 2.0


def stddev(scores: Sequence[float], sample: bool = False) -> float:
    """Compute standard deviation.

    By default computes population standard deviation. If sample=True,
    uses sample standard deviation (denominator n-1). Requires n>1 when sample=True.
    """
    vals = _validate_scores(scores)
    n = len(vals)
    if sample and n < 2:
        raise ValueError("sample standard deviation requires at least two scores")
    mean = sum(vals) / n
    var_sum = sum((v - mean) ** 2 for v in vals)
    if sample:
        variance = var_sum / (n - 1)
    else:
        variance = var_sum / n
    return sqrt(variance)

__all__ = ["average", "median", "stddev"]
