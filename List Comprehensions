if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    
    # List comprehension to generate coordinates
    # range(x + 1) ensures we include the value of x itself
    result = [
        [i, j, k] 
        for i in range(x + 1) 
        for j in range(y + 1) 
        for k in range(z + 1) 
        if (i + j + k) != n
    ]
    
    print(result)
