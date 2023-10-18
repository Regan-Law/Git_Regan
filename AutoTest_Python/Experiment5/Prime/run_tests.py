import os
import shutil
import subprocess

import pytest

def clear_report():
	# 定义测试报告存放路径
	report_path = './reports'
	# 检查测试报告文件夹是否存在
	if os.path.exists(report_path):
		# 清除历史测试报告
		shutil.rmtree(report_path, ignore_errors=True)

def generate_report(report_path):
	# 生成测试报告
	command = f"allure generate {report_path} -o {report_path}/html"
	subprocess.call(command, shell=True)

if __name__ == '__main__':
	# 清除历史测试报告
	clear_report()
	# 定义测试报告存放路径
	report_path = './reports'
	# 执行测试并生成测试报告
	pytest.main(['-s', '-q', '--alluredir', report_path])
	generate_report(report_path)