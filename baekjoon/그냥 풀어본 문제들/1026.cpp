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
vector<int> a;
vector<int> b;

void init()
{
    FAST
}

void input()
{
    cin >> n;
    a.resize(n, 0);
    b.resize(n, 0);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

}

void solve()
{
    sort(a.begin(), a.end(), less<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    long long sum = 0;
    for(int i=0; i<n; i++) sum += a[i]*b[i];
    cout << sum << endl;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}