// based problem:
#include <vector>
#include <iostream>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int n;
vector<int> dp(100001, 0);

void init()
{
    FAST
}

void input()
{
    cin >> n;
}

void solve()
{
    dp[0] = 1;
    dp[1] = 3;
    for(int i=2; i<=n; i++){
        dp[i] = (dp[i-1] * 2 + dp[i-2]) % 9901;
    }
    cout << dp[n];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}

// n = 0일때, 사자를 배치하지 않음
// n = 1일때, 사자를 0마리 배치하기 1
//              사자를