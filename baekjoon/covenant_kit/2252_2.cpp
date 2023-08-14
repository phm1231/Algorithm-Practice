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

int n, m;
vector<int> inDegree;
vector<vector<int> > g;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    inDegree.resize(n+1, 0);
    g.resize(n+1, vector<int>());
    for(int i=0; i<m; i++){
        int a, b; // a가 b의 앞에 서야 함.
        cin >> a >> b;
        inDegree[b]++; // b를 줄세우려면 a를 먼저 줄세워야 한다.
        g[a].push_back(b); // a 이후에 없애줄 것들.
    }
}

void solve()
{
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int a = q.front();
        q.pop();

        cout << a << ' ';
        for(int i=0; i<g[a].size(); i++){
            int b = g[a][i];
            inDegree[b]--;
            if(inDegree[b] == 0){
                q.push(b);
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