// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int);
void bfs();

int n, m, s;
vector<vector<int> > graph;
vector<bool> visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> s;
    graph.resize(n+1, vector<int>());
    visited.resize(n+1, false);
    for(int i=0; i<m; i++){
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }

    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
}

void solve()
{
    dfs(s);
    cout << endl;
    bfs();
}

void dfs(int here){
    visited[here] = true;
    cout << here << ' ';
    for(int i=0; i<graph[here].size(); i++){
        int next = graph[here][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}

void bfs(){
    for(int i=0; i<visited.size(); i++) visited[i] = false;

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int here = q.front();
        q.pop();
        cout << here << ' ';
        for(int i=0; i<graph[here].size(); i++){
            int next = graph[here][i];
            if(!visited[next]){
                visited[next] = true;
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