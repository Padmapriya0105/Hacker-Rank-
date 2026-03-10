if __name__ == '__main__':
    students = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        students.append([name, score])
    
    # 1. Get all unique scores and sort them
    unique_scores = sorted(set(student[1] for student in students))
    
    # 2. Identify the second lowest score
    second_lowest_score = unique_scores[1]
    
    # 3. Collect names of students with that score
    names = [student[0] for student in students if student[1] == second_lowest_score]
    
    # 4. Sort names alphabetically and print
    for name in sorted(names):
        print(name)
