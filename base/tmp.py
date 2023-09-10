def isPosInRect(rect,pos):
    if pos[0] >= rect[0][0] and pos[1] >= rect[0][1] and pos[0] <= rect[1][0] and pos[1] <= rect[1][1]:
        return True
    return False

def isAttachInside(rect1, rect2):
    if rect1[0][0] == rect2[0][0]:
        return True
    elif rect1[0][1] == rect2[0][1]:
        return True
    elif rect1[1][0] == rect2[1][0]:
        return True
    elif rect1[1][1] == rect2[1][1]:
        return True
    
    return False

def findRoot(x):
    if x == chk[x]:
        return x
    chk[x] = findRoot(chk[x])
    return chk[x]

N = int(input())
chk = [i for i in range(N)]
rects = []
zeroChk = False
ans = 0

for i in range(N):
    x1, y1, x2, y2 = map(int,input().split())
    rects += [[[x1,y1],[x2,y2],[x1,y2],[x2,y1]]] # [x1,y1], [x2,y2] 는 대각선을 이루고 [x1,y2], [x2,y1]도 대각선을 이룬다
    
    if (x1==0 and y1*y2<=0) or (x2==0 and y1*y2<=0) or (y1==0 and x1*x2<=0) or (y2==0 and x1*x2<=0):
        zeroChk = True
    
rects = sorted(rects,key=lambda x: x[0][0])
for i in range(N):
    for j in range(i+1,N):
        rect1 = rects[i]
        rect2 = rects[j]
        root_i = findRoot(i)
        root_j = findRoot(j)
        if root_i > root_j:
            root_i, root_j = root_j, root_i
        elif root_i == root_j:
            continue

        if isPosInRect(rect1,rect2[0]) ^ isPosInRect(rect1,rect2[1]):
            chk[root_j] = root_i
        elif isPosInRect(rect1,rect2[2]) ^ isPosInRect(rect1,rect2[3]):
            chk[root_j] = root_i
        elif isPosInRect(rect1,rect2[0]) == True and isPosInRect(rect1,rect2[1]) == True and isAttachInside(rect1,rect2):
            chk[root_j] = root_i
        elif rect1 == rect2:
            chk[root_j] = root_i
        elif isPosInRect(rect2,rect1[0]) ^ isPosInRect(rect2,rect1[1]):
            chk[root_j] = root_i
        elif isPosInRect(rect2,rect1[2]) ^ isPosInRect(rect2,rect1[3]):
            chk[root_j] = root_i
        elif isPosInRect(rect2,rect1[0]) == True and isPosInRect(rect2,rect1[1]) == True and isAttachInside(rect1,rect2):
            chk[root_j] = root_i

for i in range(N):
    if chk[i] == i:
        ans += 1

if zeroChk:
    ans -= 1

print(ans)