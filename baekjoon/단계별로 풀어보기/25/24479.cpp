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
#include <cmath>
#include <map>
#include <set>

#define ll long long
#define MAX 100001
using namespace std;

void init();
void input();
void solve();
void dfs(int here);

int n, m, r;
int visited_cnt;
int visited[MAX];
vector< set<int> > v;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<MAX; i++) visited[i] = -1;
    visited_cnt = 0;
}

void input()
{
    cin >> n >> m >> r;
    visited[r] = 1;
    visited_cnt = 2;
    for(int i=0; i<=n; i++){
        set<int> tmp_v;
        v.push_back(tmp_v);
    }
    for(int i=0; i<m; i++){
        int src, dst;
        cin >> src >> dst;
        v[src].insert(dst);
        v[dst].insert(src);
    }
}

void solve()
{
    dfs(r);
    for(int i=1; i<=n; i++){
        if(visited[i] == -1) cout << "0\n";
        else cout << visited[i] << "\n";
    }
}

void dfs(int here){
    if(here != r){
        visited[here] = visited_cnt;
        visited_cnt++;
    }
    for(set<int>::iterator iter = v[here].begin(); iter != v[here].end(); iter++){
        int next = *iter;
        if(visited[next] == -1){
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