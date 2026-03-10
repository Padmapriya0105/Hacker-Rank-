if __name__ == '__main__':
    # Read the number of elements (though not strictly needed for the tuple creation)
    n = int(input())
    
    # Read the space-separated integers, map them to int, and convert to a tuple
    integer_list = map(int, input().split())
    t = tuple(integer_list)
    
    # Print the hash of the tuple
    print(hash(t))
