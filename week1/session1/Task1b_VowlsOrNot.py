def is_vowel(letter):
    vowels = ['a', 'e', 'i', 'o', 'u']
    if letter.lower() in vowels:
        return True
    else:
        return False

# test
character = input("Enter a letter: ")

if is_vowel(character):
    print(f"The letter '{character}' is a vowel.")
else:
    print(f"The letter '{character}' is not a vowel.")
