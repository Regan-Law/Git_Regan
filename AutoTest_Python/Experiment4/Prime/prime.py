class IsPrime:
	def __init__(self):
		pass

	def prime(self, number):
		if number < 0 or number in (0, 1):
			return False
		for element in range(2, number):
			if number % element == 0:
				return False
		return True