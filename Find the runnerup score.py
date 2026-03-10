if __name__ == '__main__':
    n = int(input())
    # Read space-separated integers, convert to a set to remove duplicates
    arr = map(int, input().split())
    
    # Using set() removes the duplicate maximums (like 6, 6)
    unique_scores = set(arr)
    
    # Sort the unique scores in ascending order
    sorted_scores = sorted(unique_scores)
    
    # The runner-up is the second to last element
    print(sorted_scores[-2])
