from collections import deque

N = int(input())
totem = [[[-1,-1] for j in range(N*2)] for i in range(N)]
chk_val = [[True for j in range(N*2)] for i in range(N)]
num = 1

for i in range(N):
    for j in range(N-(i%2)):
        A, B = map(int,input().split())
        totem[i][j*2+(i%2)] = [A,num]
        totem[i][j*2+1+(i%2)] = [B,num]
        num += 1

q = deque()
q.append((0,0))
dx = [1,0,-1,0]
dy = [0,1,0,-1]

route = [_ for _ in range(num)]
chk_idx = [True for _ in range(num)]
ans = -1

chk_idx[0] = False
chk_val[0][0] = False

while q:
    y,x = q.popleft()
    ans = max(ans,totem[y][x][1])
    if totem[y][x][1] == num-1:
        break

    for i in range(4):
        if x+dx[i] >= 0 and x+dx[i] < 2*N and y+dy[i] >= 0 and y+dy[i] < N:
            idx = totem[y+dy[i]][x+dx[i]][1]
            if totem[y+dy[i]][x+dx[i]][0] == -1:
                continue
            elif totem[y][x][1] == totem[y+dy[i]][x+dx[i]][1] and chk_val[y+dy[i]][x+dx[i]]:
                q.append((y+dy[i],x+dx[i]))
                chk_val[y+dy[i]][x+dx[i]] = False
                chk_idx[idx] = False
            elif totem[y+dy[i]][x+dx[i]][0] == totem[y][x][0] and chk_idx[idx]:
                q.append((y+dy[i],x+dx[i]))
                route[idx] = totem[y][x][1]
                chk_val[y+dy[i]][x+dx[i]] = False
                chk_idx[idx] = False

answers = []

while ans != route[ans]:
    answers += [ans]
    ans = route[ans]

answers += [ans]
print(len(answers))
for i in range(len(answers)-1,-1,-1):
    print(answers[i],end=' ')