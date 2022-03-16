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
void StackDFS();
void RecursiveDFS(int);

bool visited[MAX];
stack<int> stk;
vector<int> vec[MAX];
int n, m, v;

void init()
{
    memset(visited, false, sizeof(visited));
}

void input()
{
    scanf("%d %d %d", &n, &m, &v);
    stk.push(v);
    for (int i=0; i<m; i++)
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
    StackDFS();
    putchar('\n');
    init();
    RecursiveDFS(v);
}

void RecursiveDFS(int start)
{
    printf("%d, ", start);
    visited[start] = true;
    int siz = vec[start].size();
    for(int i=0; i<siz; i++)
    {
        int next = vec[start][i];
        if(!visited[next])
        {
            RecursiveDFS(next);
        }
    }
}

void StackDFS()
{
    while(!stk.empty())
    {
        int src = stk.top();
        stk.pop();
        visited[src] = true;
        printf("%d, ", src);
        int siz = vec[src].size();

        for(int i=0; i<siz; i++)
        {
            int dst = vec[src][i];
            if(!visited[dst])
            {
                stk.push(dst);
                StackDFS();
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