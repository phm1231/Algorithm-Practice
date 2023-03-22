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
#define MAX 102

using namespace std;

void init();
void input();
void solve();
void BFS();

int n, m;
bool map[MAX][MAX];
int dist[MAX][MAX];
queue< pair<int, int> > q;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void init()
{
    memset(map, false, sizeof(map));
    for(int i=1; i<MAX; i++)
    {
        for(int j=1; j<=MAX; j++)
        {
            dist[i][j] = 99999;
        }
    }
    dist[1][1] = 1;
}

void input()
{
    scanf("%d %d", &n, &m);
    getchar();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char Cinput;
            scanf("%c", &Cinput);
            if (Cinput == '1')
            {
                map[i][j] = true;
                q.push(make_pair(i, j));
            }
            if (Cinput == '0') map[i][j] = false;
        }
        getchar();
    }
}

void solve()
{
    BFS();
}

void BFS()
{
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if(dist[p.first][p.second] + 1 < dist[nx][ny] && map[nx][ny])
            {
                dist[nx][ny] = dist[p.first][p.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    printf("dist is %d\n", dist[n][m]);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}