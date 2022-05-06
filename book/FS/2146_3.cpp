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

#define ll long long
#define MAX 102
using namespace std;

void init();
void input();
void solve();
void dfs(int, int, int);
int bfs(int);
void check();

int n;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int board[MAX][MAX];
bool visited[MAX][MAX];

void init()
{
    memset(board, 0, sizeof(board));
    memset(visited, false, sizeof(visited));
}

void input()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &board[i][j]);
        }
    }
}

void solve()
{
    int islandnum = 1;
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] != 0 && !visited[i][j]){
                dfs(i, j, islandnum++);
            }
        }
    }

    for(int i=1; i<islandnum; i++){
        memset(visited, false, sizeof(visited));
        ans = min(ans, bfs(i));
    }
    printf("%d", ans);
}

int bfs(int islandnum){
    int ret = 0;
    queue< pair<int, int> > q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] == islandnum){
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()){
        int siz = q.size();
        for(int i=0; i<siz; i++){
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for(int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= 1 && ny >= 1 && nx <= n && ny <= n){
                    if(board[nx][ny] != 0 && board[nx][ny] != islandnum){ // 다른 섬.
                        return ret;
                    }
                    else if(board[nx][ny] == 0 && !visited[nx][ny]){ // 방문한 적이 없는 길.
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        ret++;
    }
    return ret;
}

void dfs(int x, int y, int islandnum){
    visited[x][y] = true;
    board[x][y] = islandnum;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(board[nx][ny] != 0 && !visited[nx][ny]){
            dfs(nx, ny, islandnum);
        }
    }
}

void check(){
    putchar('\n');
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", board[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int main()
{
    init();
    input();
    solve();
    return 0;
}