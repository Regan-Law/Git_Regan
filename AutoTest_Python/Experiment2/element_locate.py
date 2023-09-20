import time

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.select import Select

driver = webdriver.Edge()
driver.get("http://localhost:8081/ecshop/")
driver.implicitly_wait(3)

def register():
	driver.find_element(By.CSS_SELECTOR, "#ECS_MEMBERZONE > a:nth-child(3)").click()
	driver.find_element(By.CSS_SELECTOR, "#username").send_keys("reganlaw777")
	driver.find_element(By.CSS_SELECTOR, "#email").send_keys("reganlaw@qq.com")
	driver.find_element(By.CSS_SELECTOR, "#password1").send_keys("yan111111")
	driver.find_element(By.CSS_SELECTOR, "#conform_password").send_keys("yan111111")
	driver.find_element(By.NAME, "extend_field1").send_keys("reganlaw@msn.com")
	driver.find_element(By.NAME, "extend_field2").send_keys("12345678901")
	driver.find_element(By.NAME, "extend_field3").send_keys("12345678901")
	driver.find_element(By.NAME, "extend_field4").send_keys("12345678901")
	driver.find_element(By.NAME, "extend_field5").send_keys("12345678901")
	Select(driver.find_element(By.NAME, "sel_question")).select_by_index(2)
	driver.find_element(By.NAME, "passwd_answer").send_keys("12345678901")
	driver.find_element(By.NAME, "Submit").click()
	time.sleep(3)
	driver.back()
	print("注册成功")

def login():
	driver.find_element(By.CSS_SELECTOR, "#ECS_MEMBERZONE > a:nth-child(2) > img").click()
	driver.find_element(By.NAME, "username").send_keys("reganlaw777")
	driver.find_element(By.NAME, "password").send_keys("yan111111")
	driver.find_element(By.NAME, "submit").click()
	time.sleep(3)
	print("登录成功")

register()
login()

driver.quit()