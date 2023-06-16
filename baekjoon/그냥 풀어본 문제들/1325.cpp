// based problem:
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();
int dfs(int number, vector<bool>& visited);

int n, m;
vector<vector<int> > tree;

void init()
{
    FAST
}

void input()
{
    cin >> n >> m;
    tree.resize(n+1, vector<int>());

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b; // a가 b를 신뢰한다.
        tree[b].push_back(a);
    }
}

void solve()
{
    vector<pair<int, int> > v; // v.first = 번호, v.second = 해킹할 수 있는 컴퓨터 수
    for(int i=0; i<tree.size(); i++){
        // i = 해킹할 컴퓨터 번호
        vector<bool> visited(n+1, false);
        visited[i] = true;
        v.push_back(make_pair(i, dfs(i, visited)));
    }

    int max_value = 0;
    for(pair<int, int>& p: v){
        max_value = max(p.second, max_value);
    }
    set<int> s;
    for(pair<int, int>& p: v){
        if(p.second == max_value) s.insert(p.first);
    }
    for(auto iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << ' ';
    }
    
    
}

int dfs(int number, vector<bool>& visited){
    int ret = 1;
    for(int i=0; i<tree[number].size(); i++){
        int target = tree[number][i];
        if(!visited[target]){
            visited[target] = true;
            ret += dfs(target, visited);
        }
    }
    return ret;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}