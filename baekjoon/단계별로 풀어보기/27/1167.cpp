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
void dfs(int, int);

vector< pair <int, int> > v[MAX];
bool visited[MAX];
long long answer_distance;
int n;

void init()
{
    answer_distance = 0;
    memset(visited, false, sizeof(visited));
}

void input()
{
    int start, end, dist;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &start);
        while(1)
        {
            scanf("%d", &end);
            if(end == -1) break;
            else
            {
                scanf("%d", &dist);
                v[start].push_back(make_pair(end, dist));
            }
        }
    }
}

void solve()
{
    dfs(1);
}

void dfs(int start, int current_dist)
{
    bool flag = false;

    for(int i=0; i<v[start].size(); i++)
    {
        int destination = v[start][i].first;
        int dist = v[start][i].second;
        if(!visited[destination])
        {
            visited[destination] = true;
            flag = true;
            dfs(destination);
        }
    }
    if()
}

int main()
{
    init();
    input();
    solve();
    return 0;
}