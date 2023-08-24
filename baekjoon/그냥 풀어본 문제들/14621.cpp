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
int getParent(int child);
void merge(int a, int b);

vector<vector<pair<int, int> > > g;
vector<char> over;
vector<int> parent;
int n, m;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    over.resize(n+1, ' ');
    g.resize(n+1, vector<pair<int, int> >());

    parent.resize(n+1, 0);
    for(int i=1; i<=n; i++) parent[i] = i;

    for(int i=1; i<=n; i++){
        cin >> over[i];
    }
    for(int i=0; i<m; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        if(over[src] == over[dst]) continue;
        g[src].push_back(make_pair(dst, cost));
        g[dst].push_back(make_pair(src, cost));
    }
}

void solve()
{
    priority_queue<pair<int, pair<int, int> > > pq;

    for(int i=1; i<=n; i++){
        for(int j=0; j<g[i].size(); j++){
            pq.push(make_pair(-g[i][j].second, make_pair(i, g[i][j].first)));
        }
    }

    int cnt = 0;
    int answer = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        int pa = getParent(a);
        int pb = getParent(b);
        if(pa == pb) continue;
        
        merge(a, b);
        if(cnt == 0) cnt = 2;
        else cnt++;
        answer += cost;
    }
    if(cnt == n) cout << answer;
    else cout << -1;
}

int getParent(int child){
    if(child == parent[child]) return child;
    else return parent[child] = getParent(parent[child]);
}

void merge(int a, int b){
    int pa = getParent(a);
    int pb = getParent(b);

    if(pa > pb) parent[pa] = pb;
    else parent[pb] = pa;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}