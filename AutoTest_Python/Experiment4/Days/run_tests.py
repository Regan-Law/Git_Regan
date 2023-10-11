import unittest

from HtmlTestRunner import HTMLTestRunner

from Experiment4.Days.TestCountDays import TestCountDays

suite = unittest.TestSuite()
suite.addTest(TestCountDays('test_january'))
suite.addTest(TestCountDays('test_february_leap_year'))
suite.addTest(TestCountDays('test_february_non_leap_year'))
suite.addTest(TestCountDays('test_march'))
suite.addTest(TestCountDays('test_april'))
suite.addTest(TestCountDays('test_may'))
suite.addTest(TestCountDays('test_june'))
suite.addTest(TestCountDays('test_july'))
suite.addTest(TestCountDays('test_august'))
suite.addTest(TestCountDays('test_september'))
suite.addTest(TestCountDays('test_october'))
suite.addTest(TestCountDays('test_november'))
suite.addTest(TestCountDays('test_december'))

runner = HTMLTestRunner(output='./test_reports', report_title='Test Report', report_name='Test Report')
runner.run(suite)