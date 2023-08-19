def count_digit(lst):
    return sum(str(num).count('4') for num in lst)

# test
numbers = [4, 24, 42, 14, 54, 94]

result = count_digit(numbers)
print(f"The number of 4's in the list is: {result}")
