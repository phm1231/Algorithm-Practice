// based problem:
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define MAX 100001

int n;

void init();
void input();
void solve();

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
}

void solve()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);

    for(int i=2; i<=n; i++){
        v.push_back(v[i-2] + v[i-1]);
    }
    cout << v[n];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}