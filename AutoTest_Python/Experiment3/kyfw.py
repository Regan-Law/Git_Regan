from selenium import webdriver
from selenium.webdriver import Keys
from selenium.webdriver.common.by import By

driver = webdriver.Edge()
driver.get("https://kyfw.12306.cn/otn/leftTicket/init?linktypeid")
driver.implicitly_wait(3)
driver.maximize_window()

driver.find_element(By.CSS_SELECTOR, "#fromStationText").click()

driver.find_element(By.CSS_SELECTOR, "#ul_list1 > li:nth-child(21)").click()

driver.find_element(By.CSS_SELECTOR, "#toStationText").click()

driver.find_element(By.CSS_SELECTOR, "#ul_list1 > li:nth-child(2)").click()

date = driver.find_element(By.CSS_SELECTOR, "#train_date")
date.send_keys(Keys.BACK_SPACE * 2)
date.send_keys("28")

driver.find_element(By.CSS_SELECTOR, "#query_ticket").click()

driver.close()

driver.quit()