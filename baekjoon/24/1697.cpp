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
#define MAX 100001

using namespace std;

void init();
void input();
void solve();
void bfs();
void go(int, int);

int n, k;
int arr[MAX];
queue<int> q;

void init()
{
    for(int i=0; i<MAX; i++)
    {
        arr[i] = INT_MAX;
    }
}

void input()
{
    scanf("%d %d", &n, &k);
    arr[n] = 0;
    q.push(n);
}

void solve()
{
    bfs();
}

void bfs()
{
    while(!q.empty())
    {
        int start = q.front();
        q.pop();
        go(start, start - 1);
        go(start, start + 1);
        go(start, start * 2);
    }
    printf("%d", arr[k]);
}

void go(int src, int dst)
{
    if(dst < 0 || dst >= MAX) return;
    if(arr[src] + 1 < arr[dst])
    {
        arr[dst] = arr[src] + 1;
        q.push(dst);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}