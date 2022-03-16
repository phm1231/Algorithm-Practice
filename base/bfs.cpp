// based problem: 1260
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
void bfs();

int n, m, v;
bool visited[MAX];
vector<int> vec[MAX];
queue<int> q;

void init()
{
    memset(visited, false, sizeof(visited));
}

void input()
{
    scanf("%d %d %d", &n, &m, &v);
    for(int i=0; i<m; i++)
    {
        int src, dst;
        scanf("%d %d", &src, &dst);
        vec[src].push_back(dst);
        vec[dst].push_back(src);
    }
}

void solve()
{
    for(int i=0; i<n; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    bfs();
}

void bfs()
{
    q.push(v);
    visited[v] = true;
    while(!q.empty())
    {
        int src = q.front();
        printf("%d, ", src);
        q.pop();
        int siz = vec[src].size();
        for(int i=0; i<siz; i++)
        {
            int dst = vec[src][i];
            if(!visited[dst])
            {
                q.push(dst);
                visited[dst] = true;
            }
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