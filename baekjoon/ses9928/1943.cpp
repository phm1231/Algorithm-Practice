// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int sum, n, siz;
vector<pair<int, int> > v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    v.clear();
}

void input()
{
    sum = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        int money, cnt;
        cin >> money >> cnt;

        v.push_back({money, cnt});
        sum += (money * cnt);
    }
}

void solve()
{
    if(sum % 2 == 1){
        cout << 0 << "\n";
        return;
    }

    sum /= 2;
    vector<bool> dp(sum+1, false);
    dp[0] = true;

    for(int i=0; i<v.size(); i++){
        int money = v[i].first;
        int cnt = v[i].second;

        vector<bool> tmp = dp;
        for(int amount=0; amount<=sum; amount++){
            if(dp[amount]){
                for(int k=1; k<=cnt; k++){
                    if(amount + money * k <= sum)
                        tmp[amount + money * k] = true;
                }
            }
        }
        dp = tmp;
    }
    cout << dp[sum] << "\n";
}

int main()
{
    int t = 3;
    while(t--){
        init();
        input();
        solve();
    }
    return 0;
}