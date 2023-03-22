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
#define MAX 1002

using namespace std;

void init();
void input();
void solve();
void bfs();
void check();

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;
int tomato[MAX][MAX];
queue< pair<int, int> > q;

void init()
{
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            tomato[i][j] = INT_MIN;
        }
    }
}

void input()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &tomato[i][j]);
            if(tomato[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }
}

void bfs()
{
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(tomato[nx][ny] == -1)
            {

            }
            else if(tomato[nx][ny] == 0)
            {
                tomato[nx][ny] = tomato[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
            else if(tomato[nx][ny] > tomato[x][y] + 1)
            {
                tomato[nx][ny] = tomato[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    check();
}

void check()
{
    int maximum = INT_MIN;
    bool flag = false;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(maximum < tomato[i][j])
            {
                maximum = tomato[i][j];
            }
            if(tomato[i][j] == 0)
            {
                flag = true;
            }
        }
    }
    if (flag)
    {
        printf("-1");
    }
    else
    {
        printf("%d\n", maximum - 1);
    }
}

void solve()
{
    bfs();
}

int main()
{
    init();
    input();
    solve();
    return 0;
}