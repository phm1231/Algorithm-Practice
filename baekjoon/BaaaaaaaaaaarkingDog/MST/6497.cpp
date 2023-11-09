#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
int GetParent(int a);
void merge(int a, int b);

int n, m; // 집의 수, 길의 수
ll max_cost; // 평소에 드는 비용의 합계.

vector<int> parent;
vector<vector<pair<int, int> > > g;
priority_queue<pair<int, pair<int, int> > > pq;
const int MAX = 1e9;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    parent.clear();
    parent.resize(n, 0);
    max_cost = 0;
    for(int i=0; i<n; i++) parent[i] = i;
    for(int i=0; i<m; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        max_cost += cost;
        pq.push({-cost, {src, dst}});
    }
}

void Solve()
{
    ll min_cost = 0; // 최소로 드는 비용
    while(!pq.empty()){
        int dist = -pq.top().first;
        int src = pq.top().second.first;
        int dst = pq.top().second.second;
        pq.pop();
        
        if(GetParent(src) == GetParent(dst)) continue;
        merge(src, dst);
        min_cost += dist;
    }
    cout << max_cost - min_cost << endl;
}

int GetParent(int a){
    if(a == parent[a]) return a;
    else return parent[a] = GetParent(parent[a]);
}

void merge(int a, int b){
    int pa = GetParent(a);
    int pb = GetParent(b);
    if(pa > pb) parent[pa] = pb;
    else parent[pb] = pa;
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