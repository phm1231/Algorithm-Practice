// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int here);
void trace(int here, int prev);

int n;
vector<int> w;
vector<vector<int> > g;
vector<bool> visited;
vector<int> path;
int dp[10001][2] = {0, }; // dp[i][j] = i번 정점을 사용했을 때, 사용하지 않았을 때.

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    w.resize(n+1, 0);
    g.resize(n+1, vector<int>());
    visited.resize(n+1, false);
    
    for(int i=1; i<=n; i++) cin >> w[i];
    
    for(int i=0; i<n-1; i++){
        int src, dst;
        cin >> src >> dst;
        g[src].push_back(dst);
        g[dst].push_back(src);
    }
}

void solve()
{
    dfs(1);
    visited.clear();
    visited.resize(n+1, false);

    trace(1, 0);
    sort(path.begin(), path.end());
    cout << max(dp[1][0], dp[1][1]) << endl;
    for(int p: path) cout << p << ' ';
}

void dfs(int here){
    visited[here] = true;
    dp[here][0] = 0;
    dp[here][1] = w[here];

    for(int next: g[here]){
        if(visited[next]) continue;
        
        dfs(next);

        dp[here][0] += max(dp[next][1], dp[next][0]);
        dp[here][1] += dp[next][0];
    }
}

void trace(int here, int prev){
    // here을 사용하는 것이 더 높으면서 prev를 방문하지 않았을 경우
        // 만약 prev를 방문했었다면, here을 사용할 수 없음.
    if(dp[here][1] > dp[here][0] && !visited[prev]){
        visited[here] = true;
        path.push_back(here);
    }
    for(int next: g[here]){
        if(next == prev) continue;
        trace(next, here);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}