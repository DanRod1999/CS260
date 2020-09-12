n =7 
A = [[0 for i in range(n+1)] for j in range(n+1)]
C = [[0 for i in range(n+1)] for j in range(n+1)] 
P = A

C[1][2]=3
C[1][3]=1
C[1][4]=5
C[1][5]=7
C[1][6]=9
C[3][2]=1
C[4][5]=1
C[5][6]=1
A = C
print(C)

for i in range(1, n+1):
    for j in range(1, n+1): 
        P[i][j] = 0
print(A)

for i in range(1,n+1):
    for j in range(n):
        if A[i][j] == 0:
            A[i][j] = -1


for i in range(1,n+1):
    A[i][i] = 0
for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if A[i][k] + A[k][j] < A[i][j] and A[i][j] != -1 and A[i][k] != -1 and A[k][j] != -1:
                print(A[i][k], A[k][j], A[i][j])
                print(k,i,j)
                A[i][j] = A[i][k] + A[k][j]
                P[i][j] = k
		
for i in range(1,n+1):
    print(P[i][1:-1])


for i in range(1,n+1):
    for j in range(1,n+1):
        if A[i][j] == -1:
            A[i][j] = 0
print(P)
