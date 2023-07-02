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
vector<bool> visited;
vector<vector<int> > tree;
vector<vector<int> > dp;
vector<int> path;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    w.resize(n+1, 0);
    tree.resize(n+1, vector<int>());
    dp.resize(n+1, vector<int>(2, 0));
    visited.resize(n+1, false);

    for(int i=1; i<=n; i++) cin >> w[i];
    int src, dst;
    for(int i=0; i<n-1; i++){
        cin >> src >> dst;
        tree[src].push_back(dst);
        tree[dst].push_back(src);
    }
}

void solve()
{
    dfs(1);
    visited.clear();
    visited.resize(n+1, false);
    trace(1, 0);

    cout << max(dp[1][0], dp[1][1]) << endl;
    sort(path.begin(), path.end());
    for(int p: path) cout << p << ' ';
}

void dfs(int here){
    // here을 포함하지 않음
    dp[here][0] = 0;
    // here을 포함함
    dp[here][1] = w[here];
    visited[here] = true;

    for(int next: tree[here]){
        if(visited[next]) continue;
        dfs(next);

        // here을 포함하지 않으면 next를 포함하지 않거나 포함하는 것 중 큰 것을 합침.
        dp[here][0] += max(dp[next][0], dp[next][1]);
        // here을 포함하면 next를 포함하지 않는 것
        dp[here][1] += dp[next][0];
    }
}

void trace(int here, int prev){
    // here을 포함한 경우가 더 큰데, dp[prev][1]을 사용하지 않았을 경우
    if(dp[here][1] > dp[here][0]){//  && !visited[prev]){
        visited[here] = true;
        path.push_back(here);
    }
    for(int next: tree[here]){
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