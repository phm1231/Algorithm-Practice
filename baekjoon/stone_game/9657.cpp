#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();

const int MAX = 1e9;

int n;
vector<bool> dp(1001, false);

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n;
}

void Solve()
{
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;

    for(int i=5; i<=n; i++){
        if(dp[i-1] && dp[i-3] && dp[i-4]) dp[i] = false;
        else dp[i] = true;
    }

    if(dp[n]) cout << "SK";
    else cout << "CY";
}


int main()
{
    Init();
    Input();
    Solve();
    return 0;
}