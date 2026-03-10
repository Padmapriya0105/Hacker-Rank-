import re

n, m = map(int, input().split())


matrix = [input() for _ in range(n)]


decoded_string = "".join(["".join(column) for column in zip(*matrix)])


final_output = re.sub(r'(?<=\w)[^\w]+(?=\w)', ' ', decoded_string)

print(final_output)

