import unittest

from CountDays import count_days_in_month

class TestCountDays(unittest.TestCase):
	def test_january(self):
		self.assertEqual(count_days_in_month(2023, 1), 31)

	def test_february_leap_year(self):
		self.assertEqual(count_days_in_month(2024, 2), 29)

	def test_february_non_leap_year(self):
		self.assertEqual(count_days_in_month(2023, 2), 28)

	def test_march(self):
		self.assertEqual(count_days_in_month(2023, 3), 31)

	def test_april(self):
		self.assertEqual(count_days_in_month(2023, 4), 30)

	def test_may(self):
		self.assertEqual(count_days_in_month(2023, 5), 31)

	def test_june(self):
		self.assertEqual(count_days_in_month(2023, 6), 30)

	def test_july(self):
		self.assertEqual(count_days_in_month(2023, 7), 31)

	def test_august(self):
		self.assertEqual(count_days_in_month(2023, 8), 31)

	def test_september(self):
		self.assertEqual(count_days_in_month(2023, 9), 30)

	def test_october(self):
		self.assertEqual(count_days_in_month(2023, 10), 31)

	def test_november(self):
		self.assertEqual(count_days_in_month(2023, 11), 30)

	def test_december(self):
		self.assertEqual(count_days_in_month(2023, 12), 31)

if __name__ == '__main__':
	unittest.main()