// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<int> v;
vector<int> tmp;

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
    if(n == 1){
        cout << 1;
        return;
    }

    vector<ll> dp(n+1, 0); // dp[i] = i번째 숫자를 시작으로 포함했을 때 가능한 경우의 수
    vector<int> where(100001, -1);
    vector<bool> visited(100001, false);
    int right = n-1; // 엔드포인트

    for(int i=n-1; i>=0; i--){
        if(!visited[v[i]]){
            visited[v[i]] = true;
            dp[i] = dp[i+1] + 1;
        }
        // 이미 방문한 적이 있음
        else{
            int idx = where[v[i]];
            // 이미 방문한 적이 있지만 이미 계산 범위에서 제외된 경우
            if(right < idx){
                dp[i] = dp[i+1] + 1;
            }
            // 이미 방문한 적이 있어서 right를 업데이트 해야하는 경우
            else{ 
                dp[i] = idx - i;
                right = idx;
            }
        }
        where[v[i]] = i;
    }

    ll sum = 0;
    for(int i=0; i<n; i++){
        // cout << dp[i] << ' ';
        sum += dp[i];
    }
    cout <<  sum;
}

int main()
{
    init();
    input();
    solve();
    return 0;
} 
