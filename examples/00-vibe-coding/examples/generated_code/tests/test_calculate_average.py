import unittest

def calculate_average(numbers):
    total = sum(numbers)
    count = len(numbers)
    return total / count

class TestCalculate_average(unittest.TestCase):
    """测试 calculate_average 函数"""

    def test_basic_case(self):
        """测试基本用例"""
        self.assertEqual(calculate_average([1, 2, 3]), 2)
        self.assertEqual(calculate_average([10, 20, 30]), 20)

    def test_edge_cases(self):
        """测试边界情况"""
        self.assertEqual(calculate_average([5]), 5)
        self.assertEqual(calculate_average([0, 0, 0]), 0)

    def test_error_handling(self):
        """测试错误处理"""
        with self.assertRaises(ZeroDivisionError):
            calculate_average([])


if __name__ == '__main__':
    unittest.main()