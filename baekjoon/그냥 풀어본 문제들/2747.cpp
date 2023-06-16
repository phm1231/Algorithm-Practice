// based problem:
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void init();
void input();
void solve();

int n;
vector<long long> pibos;

void init()
{
    FAST
}

void input()
{
    cin >> n;
}

void solve()
{
    pibos.push_back(0);
    pibos.push_back(1);
    for(int i=2; i<=n; i++){
        pibos.push_back(pibos[i-1] + pibos[i-2]);
    }
    cout << pibos[n];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}