from collections import deque


def print_mat(mat):
    for i in mat:
        print(i)


# take the input
def get_line(line):
    return list(map(int, line.split()))


file = open("input.txt", "r")
mat = list(map(get_line, file.readlines()))
print_mat(mat)


# controlliamo se possiamo muoverci nella suddetta casella
def isempty(a, x, y, mat, turno):
    tmp = (abs(a - mat[x][y])) % turno
    return tmp == 0


# checkes for the solutions
def check_around(x, y, mat, turno):
    tmp = []
    if x + 1 < len(mat) and isempty(mat[x + 1][y], x, y, mat, turno):
        tmp.append((x + 1, y))
    if x > 0 and isempty(mat[x - 1][y], x, y, mat, turno):
        tmp.append((x - 1, y))
    if y + 1 < len(mat[0]) and isempty(mat[x][y + 1], x, y, mat, turno):
        tmp.append((x, y + 1))
    if y > 0 and isempty(mat[x][y - 1], x, y, mat, turno):
        tmp.append((x, y - 1))
    return tmp


q = deque([(len(mat) - 1, 0)])
tmp = deque()
turno = 1

movimenti = deque([[(len(mat) - 1, 0)]])

while len(q) > 0:
    while len(q) > 0:
        x, y = q.popleft()
        tmp2 = check_around(x, y, mat, turno)
        aux = movimenti.popleft()
        for i in tmp2:
            movimenti.append(aux + [i])
            tmp.append(i)
            if mat[i[0]][i[1]] == 732:
                print()
                print(movimenti[-1])
                exit()
    q = tmp
    tmp = deque()
    turno += 1
