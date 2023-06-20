// based problem:
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();

vector<int> v;
vector<bool> isPrime;
int n;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++)
       cin >> v[i];
}

void solve()
{
    isPrime.resize(1001, true);
    isPrime[1] = false;
    for(int i=2; i*i<1001; i++){
        if(!isPrime[i]) continue;

        for(int j=i*i; j<1001; j+=i) isPrime[j] = false;
    }

    int answer = 0;
    for(int a: v){
        if(isPrime[a]) answer++;
    }
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}