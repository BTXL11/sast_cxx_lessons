import unittest
from calculator.calculator import Calculator, CalculatorError

class TestCalculatorOperations(unittest.TestCase):
    def setUp(self):
        self.calc = Calculator()

    def test_add(self):
        self.assertEqual(self.calc.add(1,2),3)
        self.assertAlmostEqual(self.calc.add(1.5,2.3),3.8)
        with self.assertRaises(CalculatorError):
            self.calc.add("a",1)

    def test_sub(self):
        self.assertEqual(self.calc.sub(5,2),3)
        self.assertEqual(self.calc.sub(-1,-1),0)

    def test_mul(self):
        self.assertEqual(self.calc.mul(3,4),12)
        self.assertEqual(self.calc.mul(3,-2),-6)

    def test_div(self):
        self.assertEqual(self.calc.div(6,3),2)
        self.assertAlmostEqual(self.calc.div(7,2),3.5)
        with self.assertRaises(CalculatorError):
            self.calc.div(5,0)

    def test_mod(self):
        self.assertEqual(self.calc.mod(7,3),1)
        with self.assertRaises(CalculatorError):
            self.calc.mod(5,0)

    def test_pow(self):
        self.assertEqual(self.calc.pow(2,3),8)
        self.assertEqual(self.calc.pow(5,0),1)

class TestCalculatorEvaluate(unittest.TestCase):
    def setUp(self):
        self.calc = Calculator()

    def test_basic_expressions(self):
        self.assertEqual(self.calc.evaluate("1+2"),3)
        self.assertEqual(self.calc.evaluate("2*3+4"),10)
        self.assertEqual(self.calc.evaluate("2*(3+4)"),14)
        self.assertEqual(self.calc.evaluate("2**3"),8)
        self.assertEqual(self.calc.evaluate("10%3"),1)

    def test_unary(self):
        self.assertEqual(self.calc.evaluate("-5"), -5)
        self.assertEqual(self.calc.evaluate("+5"), 5)
        self.assertEqual(self.calc.evaluate("-(2+3)"), -5)

    def test_division_and_mod_zero(self):
        with self.assertRaises(CalculatorError):
            self.calc.evaluate("1/0")
        with self.assertRaises(CalculatorError):
            self.calc.evaluate("1%0")

    def test_invalid_syntax(self):
        with self.assertRaises(CalculatorError):
            self.calc.evaluate("1+*")

    def test_invalid_type_expression(self):
        with self.assertRaises(CalculatorError):
            self.calc.evaluate(123)  # not str

    def test_unsupported_node(self):
        # Attempt to access name (should fail)
        with self.assertRaises(CalculatorError):
            self.calc.evaluate("a+1")

    def test_complex_expression(self):
        expr = "(2+3)*4 - 5%2 + 2**3"  # (5)*4 -1 +8 = 20 -1 +8 =27
        self.assertEqual(self.calc.evaluate(expr),27)

    def test_overflow_pow(self):
        # Python big int handles large pow; test a large exponent to ensure no exception
        self.assertTrue(isinstance(self.calc.evaluate("2**10"), int))

if __name__ == '__main__':
    unittest.main()
