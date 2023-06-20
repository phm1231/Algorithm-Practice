// based problem:
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int m, n;
vector<bool> isPrime;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> m >> n; // m이상 n이하
}

void solve()
{
    isPrime.resize(n+1, true);
    isPrime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(!isPrime[i]) continue;
        for(int j=i*i; j<=n; j+=i){
            isPrime[j] = false;
        }
    }
    int sum = 0;
    int minimum = 987654321;
    for(int i=m; i<=n; i++){
        if(isPrime[i]){
            minimum = min(i, minimum);
            sum += i;
        }
    }
    if(sum == 0 && minimum == 987654321) cout << -1;
    else{
        cout << sum << endl;
        cout << minimum << endl;
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}