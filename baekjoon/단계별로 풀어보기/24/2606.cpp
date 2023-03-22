// based problem: 2606
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
#define MAX 101

using namespace std;

void init();
void input();
void solve();

void StackDFS();
void RecursiveDFS(int);
void BFS();

int n, m;
int answer;
bool visited[MAX];
vector<int> vec[MAX];

void init()
{
    answer = 0;
    memset(visited, false, sizeof(visited));
}

void input()
{
    scanf("%d %d", &n, &m);
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
    StackDFS();
    init();
    RecursiveDFS(1);
    printf("Answer is %d\n", answer);
    init();
    BFS();
}

void StackDFS()
{
    stack<int> stk;
    stk.push(1);

    while(!stk.empty())
    {
        int start = stk.top();
        stk.pop();
        visited[start] = true;
        int siz = vec[start].size();
        for(int i=0; i<siz; i++)
        {
            int next = vec[start][i];
            if(!visited[next])
            {
                answer++;
                stk.push(next);
            }
        }
    }
    printf("Answer is %d\n", answer - 1);
}

void RecursiveDFS(int start)
{
    visited[start] = true;
    int siz = vec[start].size();
    for(int i=0; i<siz; i++)
    {
        int next = vec[start][i];
        if(!visited[next])
        {
            answer++;
            RecursiveDFS(next);
        }
    }
}

void BFS()
{
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty())
    {
        int start = q.front();
        q.pop();
        int siz = vec[start].size();
        for(int i=0; i<siz; i++)
        {
            int next = vec[start][i];
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
                answer++;
            }
        }
    }
    printf("Answer is %d\n", answer);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}