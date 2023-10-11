def is_leap_year(year):
	"""Return True if year is a leap year."""
	if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
		return True
	else:
		return False

def count_days_in_month(year, month):
	"""Return the number of days in a mouth."""
	if month == 2:
		if is_leap_year(year):
			return 29
		else:
			return 28
	elif month in (4, 6, 9, 11):
		return 30
	else:
		return 31