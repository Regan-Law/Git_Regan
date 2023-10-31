from HtmlTestRunner import HTMLTestRunner

def generate_report(test_suite):
	runner = HTMLTestRunner(output='./report', report_title='Test Report', report_name='Test Report')
	runner.run(test_suite)