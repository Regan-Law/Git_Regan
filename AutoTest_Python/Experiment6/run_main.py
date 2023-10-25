import unittest

from HtmlTestRunner import HTMLTestRunner

def get_all_cases():
	suite = unittest.TestLoader().discover('case', pattern='Test*.py')
	return suite

if __name__ == '__main__':
	suite = unittest.TestLoader().discover('case', pattern='Test*.py')
	runner = HTMLTestRunner(output='./report', report_title='Test Report', report_name='Test Report')
	runner.run(suite)