#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n;
vector<ll> fib;

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
    fib.push_back(0);
    fib.push_back(1);
    for(int i=2; i<=n; i++){
        fib.push_back(fib[i-2] + fib[i-1]);
    }
    cout << fib[n];
}


int main()
{
    init();
    input();
    solve();
    return 0;
}