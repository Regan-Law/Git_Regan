from selenium.webdriver.common.by import By

class LoginPage:
	def __init__(self, driver):
		self.driver = driver

	def enter_username(self, username):
		self.driver.find_element(By.NAME, "username").send_keys(username)

	def enter_password(self, password):
		self.driver.find_element(By.NAME, "password").send_keys(password)

	def click_login_button(self):
		self.driver.find_element(By.NAME, "submit").click()