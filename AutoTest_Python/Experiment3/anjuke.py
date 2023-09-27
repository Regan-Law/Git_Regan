from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Edge()
driver.get("https://nj.zu.anjuke.com/")
driver.implicitly_wait(3)
driver.maximize_window()

driver.find_element(By.CSS_SELECTOR, "body > div.topbar > div > ul > li:nth-child(4) > a").click()

driver.find_element(By.CSS_SELECTOR, "#switch_apf_id_5 > i").click()

driver.find_element(By.CSS_SELECTOR, "#city_list > dl:nth-child(2) > dd > a:nth-child(4)").click()

driver.find_element(By.CSS_SELECTOR, "body > div.nav.header-center.clearfix > ul > li:nth-child(2) > a").click()

driver.find_element(By.CSS_SELECTOR,
                    "body > div.w1180 > div.div-border.items-list > div:nth-child(1) > span.elems-l > div > a:nth-child(4)").click()

driver.find_element(By.CSS_SELECTOR,
                    "body > div.w1180 > div.div-border.items-list > div:nth-child(1) > span.elems-l > div > div > a:nth-child(24)").click()

driver.find_element(By.CSS_SELECTOR, "#from-price").send_keys("5000")

driver.find_element(By.CSS_SELECTOR, "#to-price").send_keys("8000")

driver.find_element(By.CSS_SELECTOR, "#pricerange_search").click()

driver.find_element(By.CSS_SELECTOR,
                    "body > div.w1180 > div.div-border.items-list > div:nth-child(4) > span.elems-l > a:nth-child(2)").click()

driver.find_element(By.CSS_SELECTOR, "#condmenu > ul > li:nth-child(2) > a").click()

driver.find_element(By.CSS_SELECTOR, "#condmenu > ul > li:nth-child(2) > ul > li:nth-child(2) > a").click()

driver.find_element(By.CSS_SELECTOR, "#search-rent").send_keys("经天路")

driver.find_element(By.CSS_SELECTOR, "#search-button").click()

driver.find_element(By.CSS_SELECTOR, "#list-content > div.zu-tab > a:nth-child(2)").click()

driver.find_element(By.CSS_SELECTOR, "#list-content > div:nth-child(3)").click()

driver.quit()