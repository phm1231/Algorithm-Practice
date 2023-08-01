
// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, N;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    N = n * n;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void solve()
{
    sort(v.begin(), v.end(), greater<int>());
    cout << v[n-1];
}


int main()
{
    init();
    input();
    solve();
    return 0;
}