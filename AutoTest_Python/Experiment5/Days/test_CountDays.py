import allure
import pytest

from CountDays import days_from_new_year

@pytest.fixture(scope="function")
def setup_teardown():
	print("test start")
	yield
	print("test end")

@allure.feature("Days from New Year")
class TestDaysFromNewYear:
	@allure.title("Test Days from New Year")
	@pytest.mark.parametrize("year, month, day, expected", [
		(2023, 1, 1, 1),
		(2023, 2, 15, 46),
		(2023, 12, 31, 365),
		(2024, 1, 1, 1),
		(2024, 2, 15, 46),
		(2024, 12, 31, 366)
	])
	def test_days_from_new_year(self, year, month, day, expected, setup_teardown):
		assert days_from_new_year(year, month, day) == expected