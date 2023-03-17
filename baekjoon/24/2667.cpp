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
#define MAX 26

using namespace std;

void init();
void input();
void solve();
void BFS();

int n;
bool visited[MAX][MAX];
bool map[MAX][MAX];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
vector<int> answer;
queue< pair<int, int> > q;

void init()
{
    memset(visited, false, sizeof(visited));
    memset(map, false, sizeof(map));
}

void input()
{
    scanf("%d", &n);
    getchar();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char Cinput;
            scanf("%c", &Cinput);

            if(Cinput == '0') map[i][j] = false;
            if(Cinput == '1')
            {
                map[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
        getchar();
    }
}

void solve()
{
    BFS();
    sort(answer.begin(), answer.end());
    int siz = answer.size();
    printf("%d\n", siz);
    for(int i=0; i<siz; i++)
        printf("%d\n", answer[i]);
}

void BFS()
{
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if(!visited[p.first][p.second])
        {
            int count = 1;
            visited[p.first][p.second] = true;
            queue< pair<int, int> > subq;
            subq.push(p);

            while(!subq.empty())
            {
                pair<int, int> subp = subq.front();
                subq.pop();

                for(int i=0; i<4; i++)
                {
                    int nx = subp.first + dx[i];
                    int ny = subp.second + dy[i];
                    if(map[nx][ny] && !visited[nx][ny])
                    {
                        subq.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                        count++;
                    }
                }
            }
            answer.push_back(count);
        }
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}