import unittest

from HtmlTestRunner import HTMLTestRunner

from TestPrime import TestPrime

# 创建测试套件
suite = unittest.TestSuite()
suite.addTest(TestPrime('test_negative_number'))
suite.addTest(TestPrime('test_zero'))
suite.addTest(TestPrime('test_one'))
suite.addTest(TestPrime('test_prime_number'))
suite.addTest(TestPrime('test_non_prime_number'))

runner = HTMLTestRunner(output='./test_reports', report_title='Test Report', report_name='Test Report')
runner.run(suite)