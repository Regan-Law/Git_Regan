import unittest

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.edge.service import Service

from Experiment7.test.pages.login_page import LoginPage
from Experiment7.utils.json_reader import read_json

class TestLogin(unittest.TestCase):
	def setUp(self):
		edge_service = Service(executable_path="drivers/msedgedriver.exe")
		self.driver = webdriver.Edge(service=edge_service)
		self.driver.get("http://localhost:8081/ecshop/user.php")

	def tearDown(self):
		self.driver.quit()

	def test_login(self):
		login_page = LoginPage(self.driver)
		login_data = read_json("config/base_data.json")
		username = login_data["username"]
		password = login_data["password"]

		login_page.enter_username(username)
		login_page.enter_password(password)
		login_page.click_login_button()
		actual_result = self.driver.find_element(By.CSS_SELECTOR,
		                                         "body > div:nth-child(7) > div > div > div > div > p:nth-child(1)").text
		self.assertEqual(actual_result, "登录成功")

if __name__ == "__main__":
	unittest.main()