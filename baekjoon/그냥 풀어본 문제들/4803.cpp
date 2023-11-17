#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
bool Dfs(const int prev, const int here);


const int MAX = 1e9;
vector<vector<int> > g;
vector<bool> visited;
int n, m;
int test_case = 1;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    g.clear();
    g.resize(n+1, vector<int>());

    visited.clear();
    visited.resize(n+1, false);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void Solve()
{
    int answer = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            if(Dfs(0, i)) answer++;
        }
    }
    cout << "Case " << test_case << ": ";
    if(answer == 0){cout << "No trees." << endl;}
    else if(answer == 1){cout << "There is one tree." << endl;}
    else{cout << "A forest of " << answer << " trees." << endl;}
    test_case++;
}

bool Dfs(const int prev, const int here){
    for(const int next: g[here]){
        if(next == prev) continue;
        if(visited[next]) return false;
        visited[next] = true;

        if(!Dfs(here, next)) return false;
    }
    return true;
}

int main()
{
    Init();
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        Input();
        Solve();
    }
    return 0;
}