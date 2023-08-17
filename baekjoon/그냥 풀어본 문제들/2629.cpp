// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int idx, int w);

int n, m;
vector<int> weight, marble;
bool dp[31][15001] = {false, };

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n; // 30 이하
    weight.resize(n, 0);
    for(int i=0; i<n; i++) cin >> weight[i]; // 500g 이하, 가벼운 것부터 순서대로.

    cin >> m; // 7 이하
    marble.resize(m, 0);
    for(int i=0; i<m; i++) cin >> marble[i]; // 40000 이하
}

void solve()
{   
    dfs(0, 0);
    for(int i=0; i<m; i++){
        if(marble[i] > 15000) cout << "N ";
        else if(dp[n][marble[i]]) cout << "Y ";
        else cout << "N ";
    }
    return;
}

void dfs(int idx, int w){
    if(idx > n) return;
    if(dp[idx][w]) return;

    dp[idx][w] = true;

    // 같이 한쪽에 올려놓는 경우
    dfs(idx + 1, w + weight[idx]);
    // 반대쪽에 올려놓는 경우
    dfs(idx + 1, abs(w - weight[idx]));
    // idx번부터 새로 시작하는 경우
    dfs(idx + 1, w);
}


int main()
{
    init();
    input();
    solve();
    return 0;
}