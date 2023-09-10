#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();
int dfs(int here, vector<int>& v);

// n = 친구 수 = 30000 이하
// m = 관계 수 = 100000 이하
// k = 공명 수 = 3000 이하

int n, m, k;
vector<int> candy;
vector<vector<int> > g;
// 이미 털었는지
vector<bool> visited;
vector<pair<int, int> > group;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> k;

    candy.resize(n+1, 0);
    g.resize(n+1, vector<int>());
    visited.resize(n+1, false);

    for(int i=1; i<=n; i++) cin >> candy[i];

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void solve()
{
    for(int here=1; here<=n; here++){
        if(visited[here]) continue;
        visited[here] = true;

        vector<int> v;
        v.push_back(here);
        int cnt = dfs(here, v);

        group.push_back(make_pair(cnt, v.size())); // group[i]를 털면 사탕을 cnt개 털 수 있고, size명의 아이들이 운다.
    }

    for(pair<int, int> p: group) cout << p.first << ", " << p.second << endl;

    vector<vector<int> > dp(group.size() + 1, vector<int>(k+1, 0)); // dp[i][j] = i번째 그룹을 텀, j번째 명까지 울림.
    int siz = group.size();
    for(int i=1; i<=siz; i++){
        pair<int, int> grp = group[i-1];
        int candy_cnt = grp.first;
        int sad = grp.second;

        for(int j=0; j<k; j++){
            if(j - sad >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-sad] + candy_cnt);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[siz][k-1];
}

int dfs(int here, vector<int>& v){
    int cnt = candy[here];

    // 모든 친구들을 순회하며 압수.
    for(int next: g[here]){
        if(visited[next]) continue;
        visited[next] = true;

        v.push_back(next);
        cnt += dfs(next, v);
    }
    return cnt;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}