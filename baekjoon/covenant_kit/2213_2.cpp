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
void dfs(int);
void trace(int, int);

int n;
vector<int> w;
vector<vector<int> > g;
vector<vector<int> > dp;
vector<bool> visited;
vector<int> path;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    w.resize(n+1, 0);
    g.resize(n+1, vector<int>());
    dp.resize(n+1, vector<int>(2, 0));
    visited.resize(n+1, false);

    for(int i=1; i<=n; i++) cin >> w[i];

    int src, dst;
    for(int i=0; i<n-1; i++){
        cin >> src >> dst;
        g[src].emplace_back(dst);
        g[dst].emplace_back(src);
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

        dp[here][0] += max(dp[next][0], dp[next][1]);
        dp[here][1] += dp[next][0];
    }
}

void trace(int here, int prev){
    // here을 사용해야 하고, prev를 사용하지 않았을 경우
    // prev를 사용하면 here을 사용하지 못하므로.
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