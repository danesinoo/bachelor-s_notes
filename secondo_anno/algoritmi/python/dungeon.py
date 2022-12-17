from collections import deque

def print_mat(mat):
    for i in mat:
        print(i)

#take the input
def get_line(line):
    return list(map(int, line.split()))

mat = []
file = open('input.txt', 'r')
for i in file.readlines():
    mat.append(get_line(i))
file.close()
print_mat(mat)

#now we've got mat, the matrix

def div(a, b, n):
    return (a - b) % n == 0

def isempty(a, x, y, mat):
    return not isinstance(mat[x][y], bool) and div(a, mat[x][y], len(mat)-x+y)

#checkes for the solutions
def check_around(x, y, mat):
    tmp = []
    if x+1 < len(mat) and isempty(mat[x+1][y], x, y, mat):
        tmp.append((x+1, y))
        tmp.append((x+1, y))
    if x-1 >= 0 and isempty(mat[x-1][y], x, y, mat):
        tmp.append((x-1, y))
    if y+1 < len(mat[0]) and isempty(mat[x][y+1], x, y, mat):
        tmp.append((x, y+1))
    if y-1 >= 0 and isempty(mat[x][y-1], x, y, mat):
        tmp.append((x, y-1))
    return tmp

q = deque()
q.append((len(mat)-1, 0))
while q:
    x, y = q.popleft()
    q.extend(check_around(x, y, mat))
    mat[x][y] = True

print()
print_mat(mat)
