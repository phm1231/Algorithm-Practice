// based problem:
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();

void init()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int n;

void input()
{
    cin >> n;
}

void solve()
{
    // 6 = 1 1 0 
    vector<int> v;
    while(n != 0){
        v.push_back(n % 2);
        n = n / 2;
    }
    for(int i=0; i<v.size(); i++){
        if(v[i] == 1) cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    init();
    int t;
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}