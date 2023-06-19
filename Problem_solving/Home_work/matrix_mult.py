import random

row = 3
col = 3
a = [[0]*col]*row
b = [[0]*col]*row
c = [[0]*col]*row
for i in range(0, row):
    for j in range(0, row):
        a[i][j] = random.randint(0,9)
        b[i][j] = random.randint(0,9)


for i in range(0, row):
    for j in range(0, col):
        c[i][j] = 0
        for k in range (0, row):
            c[i][j] += a[k][i] * b[j][k]

print(c)