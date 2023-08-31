#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n, k;
const int MOD = 1000000007;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
}

void solve()
{
    ll a = 1;
    for(int i=k+1; i<=n; i++){
        a *= i;
        a %= MOD;
    }

    ll b = 1;
    for(int i=1; i<=n-k; i++){
        b *= i;
        b %= MOD;
    }
    ll answer = a / b;
    if(a % b != 0) answer += a % b;
    cout << answer; 
}


int main()
{
    init();
    input();
    solve();
    return 0;
}