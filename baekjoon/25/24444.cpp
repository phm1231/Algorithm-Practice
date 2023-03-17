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
void bfs();

int n, m, r;
int visited[MAX];
int visited_cnt;
vector< set<int, less<int> > > v;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<MAX; i++) visited[i] = -1;
    visited_cnt = 1;

}

void input()
{
    cin >> n >> m >> r;
    for(int i=0; i<=n; i++){
        set<int, less<int> > tmp_s;
        v.push_back(tmp_s);
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
    bfs();
    for(int i=1; i<=n; i++){
        if(visited[i] == -1) cout << "0\n";
        else cout << visited[i] << "\n";
    }
}

void bfs(){
    queue<int> q;
    q.push(r);
    visited[r] = visited_cnt;
    visited_cnt++;

    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(set<int>::iterator iter = v[here].begin(); iter != v[here].end(); iter++){
            int next = *iter;
            if(visited[next] == -1){
                visited[next] = visited_cnt;
                visited_cnt++;
                q.push(next);
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