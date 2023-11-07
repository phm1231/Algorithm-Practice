// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(vector<int>& v);

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
    dfs(v);
}

void dfs(vector<int>& v){
    if(v.size() == m){
        for(int a: v) cout << a << ' ';
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++){
        if(v.size() == 0){
            v.push_back(i);
            dfs(v);
            v.pop_back();
        }
        else{
            if(i >= v.back()){
                v.push_back(i);
                dfs(v);
                v.pop_back();
            }
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