#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n, m;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    v.resize(n+1, 0);
    for(int i=1; i<=n; i++) cin >> v[i];
}

void solve()
{
    vector<ll> sum(n+1, 0);
    sum[0] = v[0];
    
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + v[i];
    }

    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        cout << sum[to] - sum[from - 1] << endl;
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}