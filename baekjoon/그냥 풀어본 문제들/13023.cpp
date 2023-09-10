#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();
void dfs(vector<int>& v, int depth);

int n, m;
vector<vector<int> > g;
vector<bool> visited(2001, false);
bool isFind = false;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    g.resize(n, vector<int>());
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void solve()
{
    vector<int> v;
    for(int i=0; i<n; i++){
        v.push_back(i);
        visited[i] = true;
        dfs(v, 1);
        visited[i] = false;
        v.pop_back();
    }

    cout << isFind;

}

void dfs(vector<int>& v, int depth){

    if(depth == 5){
        isFind = true;
        return;
    }

    if(isFind) return;
    
    int here = v.back();

    for(int next: g[here]){
        if(!visited[next]){
            visited[next] = true;
            v.push_back(next);
            dfs(v, depth + 1);
            visited[next] = false;
            v.pop_back();
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