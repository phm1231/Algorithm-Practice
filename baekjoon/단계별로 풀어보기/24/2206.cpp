// based problem:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>

#define ll long long
#define MAX 1001

using namespace std;

void init();
void input();
void solve();
void check();
void bfs();

bool map[MAX][MAX];
int path[MAX][MAX];
int n, m;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
queue< pair<int, int> > q;

void init()
{
    memset(map, false, sizeof(map));
    memset(path, 0, sizeof(path));

    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            path[i][j] = INT_MAX;
        }
    }
    path[1][1] = 1;
}

void input()
{
    char ch;
    scanf("%d %d", &n, &m);
    while( (ch = getchar()) != '\n') ;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%c", &ch);
            if(ch == '0') map[i][j] = false;
            if(ch == '1') map[i][j] = true;
        }
        getchar();
    }
}

void solve()
{
    bfs();
    check();
}

void bfs()
{
    q.push(make_pair(1, 1));
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(map[nx][ny] && path[nx][ny] > path[x][y] + 1)
            {
                path[nx][ny] = path[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }

    }
}

void check()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            printf("%d ", path[i][j]);
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