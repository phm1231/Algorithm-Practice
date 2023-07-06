// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, m;
vector<int> memories;
vector<int> costs;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    memories.resize(n, 0);
    costs.resize(m, 0);
    for(int i=0; i<n; i++) cin >> memories[i];
    for(int i=0; i<m; i++) cin >> costs[i];
}

void solve()
{
    //dp[i][j] = i번째 프로그램을 종료했을 때 j만큼의 비용이 들고 최대 확보할 수 있는 메모리
}

int main()
{
    init();
    input();
    solve();
    return 0;
}