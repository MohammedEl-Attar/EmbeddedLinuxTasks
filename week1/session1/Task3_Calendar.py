import calendar

year = int(input("Enter the year: "))
month = int(input("Enter the month: "))

# Print the calendar
print("--------------------------")
print(calendar.month(year, month))
