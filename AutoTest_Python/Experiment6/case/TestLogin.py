import unittest

import ddt
from selenium import webdriver
from selenium.common import NoSuchElementException
from selenium.webdriver.common.by import By

from Experiment6.common.ExcelUtil import ExcelUtil

@ddt.ddt
class TestLogin(unittest.TestCase):
	driver = None

	@classmethod
	def setUpClass(cls):
		cls.driver = webdriver.Edge()
		cls.driver.implicitly_wait(3)
		cls.driver.maximize_window()

	@classmethod
	def tearDownClass(cls):
		cls.driver.quit()

	def setUp(self):
		self.driver.get("http://localhost:8081/ecshop/user.php")
		if self.is_logged_in():
			self.driver.find_element(By.LINK_TEXT, "退出").click()
			self.driver.find_element(By.CSS_SELECTOR, "#ECS_MEMBERZONE > a:nth-child(2) > img").click()
		else:
			self.driver.find_element(By.CSS_SELECTOR, "#ECS_MEMBERZONE > a:nth-child(2) > img").click()

	def is_logged_in(self):
		try:
			self.driver.find_element(By.LINK_TEXT, "退出")
			return True
		except NoSuchElementException:
			return False

	@ddt.data(*ExcelUtil('data/test_cases.xlsx', 'Login').read_data())
	@ddt.unpack
	def test_login(self, case_id, title, username, password, expected_result):
		self.driver.find_element(By.NAME, "username").send_keys(username)
		self.driver.find_element(By.NAME, "password").send_keys(password)
		self.driver.find_element(By.NAME, "submit").click()
		# if expected_result == '登录成功':
		# 	self.assertIn('用户中心', self.driver.title)
		# 	self.driver.find_element(By.PARTIAL_LINK_TEXT, "退出").click()
		# else:
		# 	self.assertIn(expected_result, self.driver.page_source)

		actual_result = self.driver.find_element(By.CSS_SELECTOR,
		                                         "body > div:nth-child(7) > div > div > div > div > p:nth-child(1)").text
		self.assertEqual(actual_result, expected_result)

if __name__ == '__main__':
	unittest.main()