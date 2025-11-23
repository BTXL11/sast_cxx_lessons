import unittest
from grades.report import generate_report

class TestReport(unittest.TestCase):
    def test_report_basic(self):
        scores = [95, 88, 72, 60, 45]
        report = generate_report(scores)
        self.assertIn("人数: 5", report)
        self.assertIn("最高分: 95.00", report)
        self.assertIn("最低分: 45.00", report)
        self.assertIn("平均分:", report)
        self.assertIn("中位数:", report)
        self.assertIn("标准差:", report)
        # category counts
        self.assertIn("优秀: 1 (20.0%)", report)
        self.assertIn("不及格: 1 (20.0%)", report)

    def test_report_all_excellent(self):
        scores = [99, 95, 100]
        report = generate_report(scores)
        self.assertIn("人数: 3", report)
        self.assertIn("优秀: 3 (100.0%)", report)
        self.assertIn("不及格: 0 (0.0%)", report)

    def test_report_error_empty(self):
        with self.assertRaises(ValueError):
            generate_report([])

    def test_report_error_non_number(self):
        with self.assertRaises(TypeError):
            generate_report([90, 'A'])

if __name__ == '__main__':
    unittest.main()
