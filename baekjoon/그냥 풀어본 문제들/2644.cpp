// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, src, dst;
int m;
vector<vector<int> > g;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> src >> dst;
    cin >> m;
    g.resize(n+1, vector<int>());
    for(int i=0; i<m; i++){
        int parent, child;
        cin >> parent >> child;
        g[parent].push_back(child);
        g[child].push_back(parent);
    }
}  

void solve()
{
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;

    int answer = 0;
    while(!q.empty()){
        int qs = q.size();
        while(qs--){
            int here = q.front();
            q.pop();
            
            if(here == dst){
                cout << answer;
                return;
            }

            for(int next: g[here]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        answer++;
    }
    cout << -1;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}