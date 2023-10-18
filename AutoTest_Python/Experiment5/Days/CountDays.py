def days_from_new_year(year, month, day):
	days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
	if year % 4 == 0 and (year % 100 != 0 or year % 400 == 0):
		days_in_month[1] = 29

	days = day
	for i in range(month - 1):
		days += days_in_month[i]

	return days