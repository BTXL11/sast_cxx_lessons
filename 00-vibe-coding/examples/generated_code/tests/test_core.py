import unittest
from math import sqrt
from grades.core import average, median, stddev

class TestAverage(unittest.TestCase):
    def test_average_basic(self):
        self.assertAlmostEqual(average([90, 100]), 95.0)
        self.assertAlmostEqual(average([70]), 70.0)
        self.assertAlmostEqual(average([0, 0, 0]), 0.0)

    def test_average_float_and_int(self):
        self.assertAlmostEqual(average([89.5, 90, 90.5]), 90.0)

    def test_average_error_empty(self):
        with self.assertRaises(ValueError):
            average([])

    def test_average_error_non_number(self):
        with self.assertRaises(TypeError):
            average([90, 'A'])

class TestMedian(unittest.TestCase):
    def test_median_odd(self):
        self.assertEqual(median([1, 3, 2]), 2.0)
        self.assertEqual(median([100]), 100.0)

    def test_median_even(self):
        self.assertEqual(median([1, 2, 3, 4]), (2+3)/2)
        self.assertEqual(median([90, 100]), 95.0)

    def test_median_sorted_unsorted(self):
        self.assertEqual(median([4, 1, 3, 2]), 2.5)

    def test_median_error_empty(self):
        with self.assertRaises(ValueError):
            median([])

    def test_median_error_non_number(self):
        with self.assertRaises(TypeError):
            median([1, None])

class TestStdDev(unittest.TestCase):
    def test_stddev_population(self):
        self.assertAlmostEqual(stddev([100]), 0.0)
        # population stddev of [2,4,4,4,5,5,7,9] = sqrt(32/8)=2.0
        self.assertAlmostEqual(stddev([2,4,4,4,5,5,7,9]), 2.0)

    def test_stddev_sample(self):
        # sample stddev of [2,4,4,4,5,5,7,9] = sqrt(32/7)=~2.13809
        self.assertAlmostEqual(stddev([2,4,4,4,5,5,7,9], sample=True), sqrt(32/7), places=6)

    def test_stddev_error_empty(self):
        with self.assertRaises(ValueError):
            stddev([])

    def test_stddev_error_non_number(self):
        with self.assertRaises(TypeError):
            stddev(['bad'])

    def test_stddev_error_sample_single(self):
        with self.assertRaises(ValueError):
            stddev([100], sample=True)

if __name__ == '__main__':
    unittest.main()
