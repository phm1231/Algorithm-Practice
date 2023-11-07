// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int idx, ll w, ll cnt);

int n, c;
vector<ll> weight;


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> c;
    weight.resize(n, 0);
    for(int i=0; i<n; i++) cin >> weight[i];
}

void solve()
{
    // n개의 물건을 최대 C만큼의 무게를 넣을 수 있는 가방에 넣는 방법의 수
    // dp[i][w] = i번째 물건까지 사용하여 w의 무게를 만들 수 있는 경우의 수
    dfs(0, 0, 0);
}

void dfs(int idx, ll w, ll cnt){
    
    // 이전의 물건에 현재 물건을 합침
    dfs(idx + 1, w + weight[idx], cnt);
    // 현재 물건을 건너뜀
    dfs(idx + 1, w, cnt);
    // 이전 물건을 버림
    dfs(idx + 1, weight[idx], 1);
}




int main()
{
    init();
    input();
    solve();
    return 0;
}