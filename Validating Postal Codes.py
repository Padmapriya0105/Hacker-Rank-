# Matches a string that is exactly 6 digits long and starts with 1-9
# (Ensuring it is between 100000 and 999999 inclusive)
regex_integer_in_range = r"^[1-9][0-9]{5}$"

# Uses a lookahead assertion to find a digit (\d) 
# followed by any character (.), followed by that same digit again (\1)
regex_alternating_repetitive_digit_pair = r"(\d)(?=\d\1)"
