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
void kruskal();
void prim();
void merge(int, int, vector<int>&);

int v, e;
vector<vector<pair<int, int> > > tree;

int getParent(int target, const vector<int>& parents){
    if(target == parents[target]) return target;
    else return getParent(parents[target], parents);
}

void merge(int a, int b, vector<int>& parents){
    int pa = getParent(a, parents);
    int pb = getParent(b, parents);
    parents[pa] = pb;
}

void kruskal(){
    // 0. Union-Find 를 통한 관계 확인
    vector<int> parents(v+1, 0);
    for(int i=0; i<parents.size(); i++) parents[i] = i;

    priority_queue<pair<int, pair<int, int> > > pq;

    for(int i=0; i<tree.size(); i++){
        for(int j=0; j<tree[i].size(); j++){
            int src = i;
            int dst = tree[i][j].first;
            int cost = tree[i][j].second;
            pq.push({-cost, {src, dst}});
        }
    }

    int answer = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int src = pq.top().second.first;
        int dst = pq.top().second.second;

        pq.pop();

        if(getParent(src, parents) == getParent(dst, parents)) continue;
        merge(src, dst, parents);
        answer += cost;

    }
    cout << "kruskal is " << answer << endl;
}

void prim(){
    // 1번 정점으로부터 시작한다고 가정
    
    priority_queue<pair<int, int> > pq;
    for(int i=0; i<tree[1].size(); i++){
        int dst = tree[1][i].first;
        int cost = tree[1][i].second;
        pq.push({-cost, dst});
    }

    vector<bool> visited(v+1, false);
    visited[1] = true;
    int answer = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(visited[here]) continue;
        visited[here] = true;
        answer += cost;
        for(int i=0; i<tree[here].size(); i++){
            int next = tree[here][i].first;
            int dist = tree[here][i].second;
            pq.push({-dist, next});
        }
    }

    cout << "prim is " << answer << endl;
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> v >> e;
    tree.resize(v+1, vector<pair<int, int> >());
    for(int i=0; i<e; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        tree[src].push_back(make_pair(dst, cost));
        tree[dst].push_back(make_pair(src, cost));
    }
}

void solve()
{
    prim();
    kruskal();
}

int main()
{
    init();
    input();
    solve();
    return 0;
}