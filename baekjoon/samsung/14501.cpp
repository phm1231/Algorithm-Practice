// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<pair<int, int> > v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int time, cost;
        cin >> time >> cost;
        v.push_back(make_pair(time, cost));
    }
}

void solve()
{
    vector<int> dp(n+1, 0); // dp[i] = i일에 받을 수 있는 최대 이익

    for(int i=n-1; i>=0; i--){
        int time = v[i].first;
        int cost = v[i].second;
        // i번째 일을 시작해서 끝낼 수 있는 경우
        if(i + time <= n) dp[i] = max(dp[i + time] + cost, dp[i+1]);
        // 그럴 수 없는 경우
        else dp[i] = max(dp[i], dp[i+1]);
    }
    cout << dp[0];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}