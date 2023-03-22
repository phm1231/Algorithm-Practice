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

#define ll long long
#define MAX 100001

using namespace std;

void init();
void input();
void solve();
void dfs(int);

vector<int> tree[MAX];
int parents[MAX];
bool visited[MAX];
int n;

void init()
{
    memset(parents, 0, sizeof(parents));
    memset(visited, false, sizeof(visited));
}

void input()
{
    scanf("%d", &n);
    for(int i=0; i<n-1; i++)
    {
        int src, dst;
        scanf("%d %d", &src, &dst);
        tree[src].push_back(dst);
        tree[dst].push_back(src);
    }
}

void solve()
{
    dfs(1);

    for(int i=2; i<=n; i++)
    {
        printf("%d\n", parents[i]);
    }
}

void dfs(int start)
{
    for(int i=0; i<tree[start].size(); i++)
    {
        int next = tree[start][i];
        if(!visited[next])
        {
            parents[next] = start;
            visited[next] = true;
            dfs(next);
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