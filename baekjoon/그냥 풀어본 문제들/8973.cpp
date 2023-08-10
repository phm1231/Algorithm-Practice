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
vector<ll> s1, s2;
vector<vector<ll> > dp(2001, vector<ll>(2001, 0)); 
// dp[i][j] = 앞에서 i개, 뒤에서 J개를 지웠을 때 흐린 수.

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    s1.resize(n, 0);
    s2.resize(n, 0);
    for(int i=0; i<n; i++) cin >> s1[i];
    for(int i=n-1; i>=0; i--) cin >> s2[i];
}

void solve()
{
    for(int i=0; i<n; i++){
        dp[0][0] += (s1[i] * s2[i]);
    }
    for(int i=1; i<n; i++){
        dp[i][0] = dp[i-1][0] - (s1[i-1] * s2[i-1]);
        dp[0][i] = dp[0][i-1] - (s1[n-i] * s2[n-i]);
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = dp[0][j] - dp[i][0];
        }
    }

    int maxValue = -987654321;
    int a, b;
    cout << "DP\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << ' ';
            if(maxValue < dp[i][j]){
                maxValue = dp[i][j];
                a = i;
                b = j;
            }
        }
        cout << "\n";
    }
    cout << a << " " << b << "\n" << maxValue;

}


int main()
{
    init();
    input();
    solve();
    return 0;
}