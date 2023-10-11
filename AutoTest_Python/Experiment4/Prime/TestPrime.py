import unittest

from prime import IsPrime

class TestPrime(unittest.TestCase):
	def setUp(self):
		self.prime_checker = IsPrime()

	def test_negative_number(self):
		result = self.prime_checker.prime(-1)
		self.assertFalse(result)

	def test_zero(self):
		result = self.prime_checker.prime(0)
		self.assertFalse(result)

	def test_one(self):
		result = self.prime_checker.prime(1)
		self.assertFalse(result)

	def test_prime_number(self):
		result = self.prime_checker.prime(7)
		self.assertTrue(result)

	def test_non_prime_number(self):
		result = self.prime_checker.prime(10)
		self.assertFalse(result)

if __name__ == '__main__':
	unittest.main()