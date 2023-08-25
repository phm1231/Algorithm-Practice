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
        int a, b;
        cin >> a >> b; // a가 b의 앞이다.
        g[a].push_back(b); // 나중에 a를 하고 난 후 inDegree를 줄여주어야 함.
        inDegree[b]++;
    }
}

void solve()
{
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int smaller = q.front();
        q.pop();
        cout << smaller << ' ';

        for(int i=0; i<g[smaller].size(); i++){
            int bigger = g[smaller][i];
            inDegree[bigger]--;

            if(inDegree[bigger] == 0) q.push(bigger);
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