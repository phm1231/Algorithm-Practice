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
void dfs(int);

int n;
vector<vector<int> > g;
vector<vector<int> > dp;
vector<bool> visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    g.resize(n+1, vector<int>());
    dp.resize(n+1, vector<int>(2, 0));
    visited.resize(n+1, false);

    int a, b;
    for(int i=0; i<n-1; i++){
        cin >> a >> b; // a와 b는 친구임
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void solve()
{
    dfs(1);
    for(int i=1; i<=n; i++){
        cout << dp[i][0] << ", " << dp[i][1] << endl;
    }
    cout << min(dp[1][0], dp[1][1]);
}

void dfs(int here){
    visited[here] = true;
    dp[here][0] = 1;
    for(int next: g[here]){
        if(visited[next]) continue;
        dfs(next);

        // dp[here][0] = here이 early일 때, here과 here의 자식 노드 중 필요한 early의 개수
        // dp[here][1] = here이 early가 아닐 때, here의 모든 자식 노드 중 필요한 early의 개수
        
        // here이 early라면 작은 것
        dp[here][0] += min(dp[next][0], dp[next][1]);
        // here이 early가 아니라면 모든 next는 무조건 early여야 한다.
        dp[here][1] += dp[next][0];
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}