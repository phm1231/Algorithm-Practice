// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int, vector<int>& v);

int n, m;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
}

void solve()
{
    vector<int> v;
    dfs(0, v);
}

void dfs(int num, vector<int>& v)
{
    if(v.size() == m){
        for(int a: v) cout << a << ' ';
        cout << "\n";
        return;
    }

    for(int i=num+1; i<=n; i++){
        v.push_back(i);
        dfs(i, v);
        v.pop_back();
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}