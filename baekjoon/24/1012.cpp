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
#define MAX 52

using namespace std;

void init();
void input();
void solve();
void BFS();
void check();

int n, m, k, t, answer;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool visited[MAX][MAX];
bool map[MAX][MAX];
queue< pair<int, int> > q;

void init()
{
    answer = 0;
    memset(visited, false, sizeof(visited));
    memset(map, false, sizeof(map));
}

void input()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        x+=1;
        y+=1;
        map[x][y] = true;
        q.push(make_pair(x, y));
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

        if(!visited[p.first][p.second])
        {
            answer++;
            queue< pair<int, int> > subq;
            subq.push(p);
         
            while(!subq.empty())
            {
                pair<int, int> subp = subq.front();
                subq.pop();
                visited[subp.first][subp.second] = true;

                for(int i=0; i<4; i++)
                {
                    int nx = subp.first + dx[i];
                    int ny = subp.second + dy[i];
                    if(!visited[nx][ny] && map[nx][ny])
                    {
                        subq.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
    printf("%d\n", answer);
}

void check()
{
    putchar('\n');
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            map[i][j] ? putchar('1') : putchar('0');
        }
        putchar('\n');
    }
}
int main()
{
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        init();
        input();
        solve();
    }
    return 0;
}