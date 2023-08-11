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
void dfs(vector<int>& v);


int n, m;
vector<int> seq;
vector<bool> visited(10001, false);

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    seq.resize(n);
    for(int i=0; i<n; i++) cin >> seq[i];
    sort(seq.begin(), seq.end());
    
}

void solve()
{
    vector<int> v;
    dfs(v);
}

void dfs(vector<int>& v){
    if(v.size() == m){
        for(int a: v) cout << a << ' ';
        cout << "\n";
        return;
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(seq[i]);
            dfs(v);
            v.pop_back();
            visited[i] = false;
        }

    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}