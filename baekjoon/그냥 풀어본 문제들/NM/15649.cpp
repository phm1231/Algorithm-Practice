// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(vector<int>& v, int num);

int n, m; // 1부터 n까지 자연수 중에서 중복 없이 m개를 고른 수열을 모두 출력
vector<bool> visited(10, false);

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
    dfs(v, 0);
}

void dfs(vector<int>& v, int num){
    if(v.size() == m){
        for(int a: v) cout << a << ' ';
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            v.push_back(i);
            visited[i] = true;
            dfs(v, i);
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