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
    if(n % 2 == 1) cout << "SK";
    else cout << "CY";
}


int main()
{
    init();
    input();
    solve();
    return 0;
}