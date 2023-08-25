// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, k;
int dp[101][100001] = {0, };
vector<pair<int, int> > v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int weight, value;
        cin >> weight >> value;
        v.push_back(make_pair(weight, value));
    }
}

void solve()
{

    for(int i=1; i<=n; i++){
        int weight = v[i-1].first;
        int value = v[i-1].second;

        for(int j=0; j<=k; j++){
            if(j - weight >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];
}


int main()
{
    init();
    input();
    solve();
    return 0;
}