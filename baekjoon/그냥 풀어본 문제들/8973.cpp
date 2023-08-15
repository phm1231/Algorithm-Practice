// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int getNumber(int s, int e);

int n;
vector<ll> s1, s2;
vector<vector<ll> > dp(2001, vector<ll>(2001, -999999999999)); 

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
    for(int i=0; i<n; i++) cin >> s2[i];
}

void solve()
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i + j >= n) continue;
            // if(i == j && i != 0) dp[i][j] = dp[i-1][j-1] - (s1[i-1] * s2[n-1-i] + s1[n-1-j] * s2[j-1]);
            dp[i][j] = getNumber(i, j);
        }
    }


    ll maxValue = -999999999999;
    int a, b;
    // cout << "DP\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i + j >= n) continue;
        //    cout << dp[i][j] << ' ';
            if(maxValue < dp[i][j]){
                maxValue = dp[i][j];
                a = i;
                b = j;
            }
        }
        // cout << "\n";
    }
    cout << a << " " << b << "\n" << maxValue;

}

int getNumber(int s, int e){ // 앞에서부터 s개, 뒤에서부터 e개 지움
    int ret = 0;
    int cnt = n - (s + e);
    for(int i=0; i<cnt; i++){
        ret += s1[i+s] * s2[n-e-1-i];
    }
    return ret;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}