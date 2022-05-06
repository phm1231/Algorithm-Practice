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
/*
 #define CPP_INOUT true
    #ifdef CPP_INOUT
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif
*/
using namespace std;

void init();
void input();
void solve();
void dfs(int, int, int);
int bfs(int);
void check();

int board[MAX][MAX];
bool visited[MAX][MAX];
int n;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

void init()
{
    memset(visited, false, sizeof(visited));
    memset(board, 0, sizeof(board));
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
    int islandNum = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] && !visited[i][j]){
                board[i][j] = islandNum;
                visited[i][j] = true;
                dfs(i, j, islandNum++);
            }
        }
    }

    int ans = INT_MAX;
    for(int i=1; i<islandNum; i++){
        memset(visited, false, sizeof(visited));
        ans = min(ans, bfs(i));
    }
    printf("%d\n", ans);
}

int bfs(int num){
    queue< pair<int, int> > q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] == num){
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }

    int ret = 0;
    while(!q.empty()){
        int cursize = q.size();
        for(int i=0; i<cursize; i++){
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(board[nx][ny] == 0 && !visited[nx][ny]){ // 바닷길
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }  
                else if(board[nx][ny] != num && !visited[nx][ny]){ // 다른 섬에 도착
                    return ret;
                }
            }
        }
        ret++;
    }
    return ret;
}

void dfs(int a, int b, int num){
    stack< pair<int, int> > stk;
    stk.push(make_pair(a, b));
    while(!stk.empty()){
        pair<int, int> p = stk.top();
        int x = p.first;
        int y = p.second;
        stk.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(board[nx][ny] == 1 && !visited[nx][ny]){
                visited[nx][ny] = true;
                board[nx][ny] = num;
                stk.push(make_pair(nx, ny));
            }
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
}

int main()
{
    init();
    input();
    solve();
    return 0;
}