import time

from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Edge()
driver.implicitly_wait(3)
driver.get("https://www.baidu.com")

driver.maximize_window()
print(driver.title)
origin_handle = driver.current_window_handle

driver.find_element(By.LINK_TEXT, "新闻").click()
handles = driver.window_handles
driver.switch_to.window(handles[1])
print(driver.title)

driver.switch_to.window(origin_handle)
print(driver.title)

driver.switch_to.window(handles[1])
print(driver.title)
time.sleep(1)

driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
time.sleep(3)

driver.execute_script("window.scrollTo(document.body.scrollHeight, 0);")
time.sleep(3)

driver.quit()