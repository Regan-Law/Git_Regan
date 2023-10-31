import unittest

from Experiment7.test.case.login_test import TestLogin
from utils.report_generator import generate_report

if __name__ == "__main__":
	test_suite = unittest.TestSuite()
	test_suite.addTest(unittest.makeSuite(TestLogin))

	generate_report(test_suite)