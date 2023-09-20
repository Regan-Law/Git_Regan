from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Edge()
driver.implicitly_wait(3)
driver.get("https://www.baidu.com")
hot_searches = driver.find_element(By.ID, "hotsearch-content-wrapper")
news_titles = hot_searches.find_elements(By.CSS_SELECTOR, "li > a > span.title-content-title")
for title in news_titles:
	print(title.text)
driver.quit()