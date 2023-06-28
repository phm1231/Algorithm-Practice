#include <bits/stdc++.h>
 
using namespace std;
 
#define Max 1001
#define INF 2e9
 
int R, C, K, sy, sx, ey, ex;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
char m[Max][Max];
queue<pair<int, int> > q;
int T[Max][Max];
 
int bfs()
{
    q.push({ sy, sx });
    T[sy][sx] = 0;
 
    while (!q.empty())
    {
        int qs = q.size();
 
        while (qs--)
        {
            int r = q.front().first;
            int c = q.front().second;
 
            q.pop();
 
            for (int i = 0; i < 4; i++) {
                for (int k = 1; k <= K; k++) {
                    int y = r + dy[i] * k;
                    int x = c + dx[i] * k;
 
                    // T[y][x] == T[r][c] + 1; 일 때도 탐색을 해야 한다.
                    // 즉, <=가 아니라 <이다.
                    if (y < 0 || y >= R || x < 0 || x >= C || m[y][x] == '#' || T[y][x] < T[r][c] + 1) {
                        break;
                    }
            
                    // if 문 없으면, 시간 초과 발생(q에 많이 push 되는 듯)
                    // if 문의 의도는 방문하지 않은 곳만을 최우선적으로 탐색
                    if (T[y][x] == INF) {
                        T[y][x] = T[r][c] + 1;
                        q.push({ y, x });
                    }
                }
            }
        }
    }
 
    return T[ey][ex] == INF ? -1 : T[ey][ex];
}
 
int main()
{
    cin.tie(0);
    cin >> R >> C >> K;
 
    for (int i = 0; i < R; i++) {
        scanf("%s", &m[i][0]);
        for (int j = 0; j < C; j++) {
            T[i][j] = INF;
        }
    }
 
    cin >> sy >> sx >> ey >> ex;
 
    --sy; --sx; --ey; --ex;
 
    int g = bfs();
 
    if (g == -1) {
        printf("-1\n");
        return 0;
    }
 
    printf("%d\n", g);
 
    return 0;
}
