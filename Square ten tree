import sys

def solve():
    # Read L and R as strings to handle massive digit counts
    L_str = sys.stdin.readline().strip()
    R_str = sys.stdin.readline().strip()
    
    # L-1 for 0-indexing logic
    L = int(L_str) - 1
    R = int(R_str)
    
    res = []
    k = 0
    
    # 1. Climbing up from L-1
    while L < R:
        p = 2**k
        mod = 10**p
        
        # If R is within the current level's range
        if L // mod == R // mod:
            break
            
        if L % mod != 0:
            # How many blocks of size 10^(2^(k-1)) to reach next 10^(2^k) boundary
            # Level k in this problem corresponds to blocks of size 10^(2^(k-1))
            prev_p = 2**(k-1) if k > 0 else 0
            block_size = 10**prev_p
            
            diff = (mod - (L % mod))
            count = diff // block_size
            res.append((k, count))
            L += diff
        k += 1
        
    # 2. Descending from R down to the meeting point
    right_part = []
    while k >= 0:
        p = 2**k
        mod = 10**p
        
        prev_p = 2**(k-1) if k > 0 else 0
        block_size = 10**prev_p
        
        count = (R - L) // block_size
        if count > 0:
            right_part.append((k, count))
            L += count * block_size
        k -= 1
        
    # Merge consecutive identical levels (Compression)
    ans = []
    combined = res + right_part
    if not combined: return
    
    curr_level, curr_count = combined[0]
    for i in range(1, len(combined)):
        level, count = combined[i]
        if level == curr_level:
            curr_count += count
        else:
            ans.append((curr_level, curr_count))
            curr_level, curr_count = level, count
    ans.append((curr_level, curr_count))
    
    # Output Format
    print(len(ans))
    for level, count in ans:
        print(f"{level} {count}")

if __name__ == "__main__":
    solve()
