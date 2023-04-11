// based problem:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

int hy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hx[] = {1, -1, 2, -2, 2, -2, 1, -1};

int k, n, m;
int board[201][201];
int visited[201][201][31];

void init()
{
    FAST
    for(int i=0; i<201; i++){
        for(int j=0; j<201; j++){
            for(int k=0; k<31; k++){
                visited[i][j][k] = 987654321;
            }
        }
    }
}

void input()
{
    cin >> k >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    for(int i=0; i<k; i++) visited[0][0][i] = 0;
    queue<pair<int, int> > q;
    queue<int> usedQ;

    q.push(make_pair(0, 0));
    usedQ.push(0);

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        int used = usedQ.front(); // 여태껏 사용한 횟수
        q.pop();
        usedQ.pop();

        // 원숭이식 이동
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(board[ny][nx] == 1) continue;
                if(visited[ny][nx][used] > visited[y][x][used] + 1){
                    visited[ny][nx][used] = visited[y][x][used] + 1;
                    q.push(make_pair(ny, nx));
                    usedQ.push(used);
                }
            }
        }
        // 말 식 이동
        for(int i=0; i<8; i++){
            int ny = y + hy[i];
            int nx = x + hx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m && used < k){
                if(board[ny][nx] == 1) continue;
                if(visited[ny][nx][used+1] > visited[y][x][used] + 1){
                    visited[ny][nx][used+1] = visited[y][x][used] + 1;
                    q.push(make_pair(ny, nx));
                    usedQ.push(used+1);
                }
            }
        }
    }

    int answer = 987654321;
    for(int i=0; i<=k; i++) answer = min(answer, visited[n-1][m-1][i]);
    if(answer == 987654321) answer = -1;
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}