# -*-coding:utf-8-*-

import openpyxl

class ExcelUtil:
	def __init__(self, file_path, sheet_name):
		self.file_path = file_path
		self.sheet_name = sheet_name

	def read_data(self):
		workbook = openpyxl.load_workbook(self.file_path)
		sheet = workbook[self.sheet_name]
		data = []
		for row in sheet.iter_rows(min_row=2, values_only=True):
			data.append(row)
		workbook.close()
		return data