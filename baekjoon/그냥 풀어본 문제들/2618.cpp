// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int go(int idx, pair<int, int> loc1, pair<int, int> loc2);
int n, m;
vector<pair<int, int> > v;
int dp[1000][2];

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
}

void solve()
{
    for(int i=0; i<1000; i++){
        dp[i][0] = dp[i][1] = -1;
    }
    cout << go(0, make_pair(1, 1), make_pair(n, n));
}

int go(int idx, pair<int, int> loc1, pair<int, int> loc2){

    if(loc1 == loc2) return 987654321;

    if(idx == v.size()) return 0;

    if(dp[idx][0] != -1 && dp[idx][1] != -1) return min(dp[idx][0], dp[idx][1]);

    pair<int, int> here = v[idx];
    if(dp[idx][0] == -1) dp[idx][0] = (abs(here.first - loc1.first) + abs(here.second - loc1.second)) + go(idx+1, here, loc2);
    if(dp[idx][1] == -1) dp[idx][1] = (abs(here.first - loc2.first) + abs(here.second - loc2.second)) + go(idx+1, loc1, here);

    return min(dp[idx][0], dp[idx][1]);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}