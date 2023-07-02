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
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void solve()
{
    vector<vector<ll> > dp(n, vector<ll>(21, 0));
    // dp[i][j] = v[i]까지 계산했을 때 식의 값이 j인 식의 수.
    dp[0][v[0]] = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<=20; j++){
            if(dp[i-1][j] == 0) continue;

            if(0 <= j + v[i] && j + v[i] <= 20){
                dp[i][j+v[i]] += dp[i-1][j];
            }
            if(0 <= j - v[i] && j - v[i] <= 20){
                dp[i][j-v[i]] += dp[i-1][j];
            }            
        }
    }

    // n-2번째에 v[n-1]이 되는 식의 개수
    cout << dp[n-2][v[n-1]];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}