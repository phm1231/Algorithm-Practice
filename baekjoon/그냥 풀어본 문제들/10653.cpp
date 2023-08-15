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


int n, k;
vector<vector<int> > dist;
vector<vector<int> > dp;
vector<pair<int, int> > v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    v.resize(n+1, pair<int, int>());
    dist.resize(n+1, vector<int>(n+1, 0));
    dp.resize(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        int y, x;
        cin >> y >> x;
        v[i].first = y;
        v[i].second = x;
    }
}

void solve()
{
    // dp[i][j] = i에서 N으로 이동하면서 j개를 건너 뛸 때 드는 최소비용
    // dp[1][0] = i->N까지 모두 방문
    
    dp[n][0] = 0; // N에서 N으로 이동하는 비용은 0
    for(int i=n-1; i>=1; i--){
        dp[i][0] = dp[i+1][0] + getDistance(i, i+1); 
    }

    // i개를 건너 뛸 때
    for(int i=1; i<=k; i++){
        for(int j=n-1; j>=1; j--){
            // j번에서 N번으로 가면서 i개를 건너 뛸 떄 최소 비용을 결정해야 함.
            // 건너뛴다 -> dp[j+1][i-1]
            // 언제 건너 뛸 지를 결정해야 함.

            dp[j][i] = dp[j+1][i-1]
        }
    }

    cout << dp[1][k];

}


int getDistance(int a, int b){
    int ay = v[a].first;
    int ax = v[a].second;
    int by = v[b].first;
    int bx = v[b].second;

    return abs(by - ay) + abs(bx - ax);

}

int main()
{
    init();
    input();
    solve();
    return 0;
}