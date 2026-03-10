def merge_the_tools(string, k):
    for i in range(0, len(string), k):
        substring = string[i : i + k]
        seen = {}
        for char in substring:
            seen[char] = True
        print("".join(seen.keys()))
if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
