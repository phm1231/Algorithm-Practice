// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int dfs(int);
void makeDist();

int n, m; // 정점, 간선
vector<vector<pair<int, int> > > g;
vector<bool> visited;
vector<int> dist;
vector<int> dp;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    g.resize(n+1, vector<pair<int, int> >());
    dp.resize(n+1, -1);
    dist.resize(n+1, 987654321); // dist[i] = i에서 2로 가는 최단 거리
    dist[2] = 0;

    visited.resize(n+1, false);
    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
}

void solve()
{
    makeDist();
    cout << dfs(1);
}

int dfs(int here){
    // 이미 계산이 끝났다면
    if(dp[here] != -1) return dp[here];
    // 2에서 2로 가는 방법은 1가지임.
    if(here == 2) return dp[here] = 1;

    dp[here] = 0;

    for(pair<int, int> p: g[here]){
        int next = p.first;
        // next에서 2로 가는 것이 here에서 2로 가는 것보다 가깝다면
        if(dist[next] < dist[here]){
            dp[here] += dfs(next);
        }
    }
    return dp[here];
}


void makeDist(){
    priority_queue<pair<int, int> > pq; // 기본 내림차순 정렬
    pq.push({0, 2});
    while(!pq.empty()){
        int here = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        for(pair<int, int> p: g[here]){
            int next = p.first;
            int cost = p.second;
            if(visited[next]) continue;
            visited[next] = true;
            if(dist[next] > d + cost){
                dist[next] = d + cost;
                pq.push({-dist[next], next});
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