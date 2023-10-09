#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();

const ll MAX = 1000000003;

// n개의 색상환에서 인접한 두 색도 동시에 선택하지 않고 k개를 고를 수 있는 경우의 수.
int n, k;
ll dp[1001][1001] = {0, };

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> k;
}
// dp[i][j] = i개의 색상환에서 조건에 맞게 j개를 고르는 경우의 수.
void Solve()
{
    for(int i=0; i<=n; i++){
        dp[i][0] = 1; // i개 중 아무것도 선택하지 않는 경우
        dp[i][1] = i; // i개 중 1개만 고르는 경우
    }
    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            // i번째를 선택하는 경우 + i번째를 선택하지 않는 경우
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MAX;
        }
    }
    cout << (dp[n-3][k-1] + dp[n-1][k]) % MAX << endl;    
}

int main()
{
    Init();
    Input();
    Solve();
    return 0;
}