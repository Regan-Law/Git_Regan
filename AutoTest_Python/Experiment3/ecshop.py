import time

from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Edge()
driver.get("http://localhost:8081/ecshop/")
driver.implicitly_wait(3)
driver.maximize_window()
origin_handle = driver.current_window_handle
driver.find_element(By.CSS_SELECTOR, "#ECS_MEMBERZONE > a:nth-child(2) > img").click()

driver.find_element(By.CSS_SELECTOR,
                    "body > div.usBox.clearfix > div.usBox_1.f_l > form > table > tbody > tr:nth-child(1) > td:nth-child(2) > input").send_keys(
	"reganlaw777")

driver.find_element(By.CSS_SELECTOR,
                    "body > div.usBox.clearfix > div.usBox_1.f_l > form > table > tbody > tr:nth-child(2) > td:nth-child(2) > input").send_keys(
	"yan111111")

driver.find_element(By.CSS_SELECTOR,
                    "body > div.usBox.clearfix > div.usBox_1.f_l > form > table > tbody > tr:nth-child(2) > td:nth-child(2) > input").submit()
time.sleep(3)

driver.find_element(By.CSS_SELECTOR, "#ECS_MEMBERZONE > font > a:nth-child(2)").click()

driver.find_element(By.CSS_SELECTOR,
                    "body > div:nth-child(8) > div.AreaL > div > div > div > div > a:nth-child(6)").click()

driver.find_element(By.CSS_SELECTOR,
                    "body > div:nth-child(8) > div.AreaR > div > div > div > form > table > tbody > tr:nth-child(1) > td:nth-child(2) > input[type=radio]:nth-child(1)").click()

driver.find_element(By.CSS_SELECTOR,
                    "body > div:nth-child(8) > div.AreaR > div > div > div > form > table > tbody > tr:nth-child(2) > td:nth-child(2) > input").send_keys(
	"投诉")

driver.find_element(By.CSS_SELECTOR,
                    "body > div:nth-child(8) > div.AreaR > div > div > div > form > table > tbody > tr:nth-child(3) > td:nth-child(2) > textarea").send_keys(
	"123")

file_input = driver.find_element(By.CSS_SELECTOR,
                                 "body > div:nth-child(8) > div.AreaR > div > div > div > form > table > tbody > tr:nth-child(4) > td:nth-child(2) > input")

file_input.send_keys("D:\\Regan\Photo\\dogg zipped.jpg")

driver.find_element(By.CSS_SELECTOR,
                    "body > div:nth-child(8) > div.AreaR > div > div > div > form > table > tbody > tr:nth-child(5) > td:nth-child(2) > input.bnt_bonus").click()
time.sleep(3)

driver.find_element(By.CSS_SELECTOR,
                    "body > div:nth-child(8) > div.AreaR > div > div > div > div.msgBottomBorder > div > a").click()

handles = driver.window_handles
driver.switch_to.window(handles[1])

driver.save_screenshot("screenshot.png")

driver.switch_to.window(origin_handle)

driver.find_element(By.CSS_SELECTOR, "#mainNav > a").click()
driver.find_element(By.CSS_SELECTOR, "#category_tree > dl > dt > a").click()
driver.find_element(By.CSS_SELECTOR,
                    "body > div:nth-child(8) > div.AreaR > div:nth-child(5) > div > form > div > div > div > a:nth-child(8)").click()

driver.switch_to.alert.accept()
driver.quit()