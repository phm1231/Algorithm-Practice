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
#define MAX 1001
using namespace std;

typedef struct pos{
    int y;
    int x;
    int broken;
}pos;

void init();
void input();
void solve();
void print();

int n, m;
char maps[MAX][MAX];
int visited[MAX][MAX][2];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(maps, 0, sizeof(maps));
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            visited[i][j][0] = visited[i][j][1] = 987654321;
        }
    }
}

void input()
{
    scanf("%d %d", &n, &m);
    getchar();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%c", &maps[i][j]);
        }
        getchar();
    }
}

void solve()
{
    bfs();
//    print();
}

void bfs(){
    queue<pos> q;
    q.push({1, 1, 0});
    visited[1][1][0] = 0;

    while(!q.empty()){
        pos p = q.front();
        q.pop();

        int y = p.y;
        int x = p.x;
        int broken = p.broken;

        for(int i=0; i<4; i++){
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            if(next_y < 1 || next_y > n || next_x < 1 || next_x > m) continue;

            if(maps[next_y][next_x] == '0'){
                if(visited[next_y][next_x][broken] > visited[y][x][broken] + 1){
                    visited[next_y][next_x][0] = visited[y][x][0] + 1;
                    q.push({next_y, next_x, broken});
                }

            }
            if(maps[next_y][next_x] == '1' && broken == 0){
                if(visited[next_y][next_x][1] > visited[y][x][0] + 1){
                    visited[next_y][next_x][1] = visited[y][x][0] + 1;
                    q.push({next_y, next_x, 1});
                }
            }
            if(next_y == n && next_x == m){
                cout << visited[next_y][next_x];
                return;
            }
        }
    }
}

void print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            putchar(maps[i][j]);
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