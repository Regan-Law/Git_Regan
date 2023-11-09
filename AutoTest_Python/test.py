import unittest

from ddt import ddt, data, unpack

class is_prime:
	def prime(self, number):
		if number < 2:
			return False
		for element in range(2, number):
			if number % element == 0:
				return False
		return True

@ddt
class Test_is_prime(unittest.TestCase):
	def setUp(self):
		print("start test")

	def tearDown(self):
		print("end test")

	@data([1, False], [2, True], [4, False])
	@unpack
	def test_prime(self, number, result):
		p = is_prime()
		self.assertEqual(p.prime(number), result)

if __name__ == "__main__":
	unittest.main()