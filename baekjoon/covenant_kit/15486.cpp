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
vector<int> times;
vector<int> pays;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    times.resize(n+1, 0);
    pays.resize(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> times[i] >> pays[i];
    }
}

void solve()
{

    vector<int> dp(n+2, 0);
    dp[n+1] = 0;
    for(int i=n; i>=1; i--){
        // 기한 안에 끝내지 못하는 일임.
        if(i + times[i] > n + 1){
            dp[i] = dp[i+1];
            continue;
        }
        else{
            dp[i] = max(pays[i] + dp[i + times[i]], dp[i+1]);
        }
    }
    cout << dp[1];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}