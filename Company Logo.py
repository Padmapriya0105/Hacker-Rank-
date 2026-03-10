import collections

if __name__ == '__main__':
    s = input().strip()
    counts = collections.Counter(s)
    sorted_chars = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
    for i in range(3):
        print(f"{sorted_chars[i][0]} {sorted_chars[i][1]}")
