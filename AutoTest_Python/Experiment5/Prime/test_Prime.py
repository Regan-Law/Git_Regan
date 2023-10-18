import allure
import pytest

from prime import IsPrime

# 定义固件fixture，实现测试用例执行前输出"test start"，测试执行结束输出"test end"
@pytest.fixture(scope="function")
def setup_teardown():
	print("test start")
	yield
	print("test end")

# 定义测试类
@allure.feature("Prime Numbers")
class TestPrime:
	# 定义测试用例
	@allure.title("Test Prime Numbers")
	@pytest.mark.parametrize("number, expected", [
		(2, True),
		(3, True),
		(4, False),
		(5, True),
		(6, False)
	])
	def test_prime(self, number, expected, setup_teardown):
		prime_obj = IsPrime()
		assert prime_obj.prime(number) == expected