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

int n, m, from, to;
vector<vector<pair<int, int> > > g;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    g.resize(n+1, vector<pair<int, int> >());

    for(int i=0; i<m; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        g[src].push_back(make_pair(dst, cost));
    }
    cin >> from >> to;
}

void solve()
{
    vector<int> dist(n+1, 1e9);
    priority_queue<pair<int, int> > pq; // cost, here

    pq.push(make_pair(0, from));
    dist[from] = 0;
    
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        
        if(here == to){
            cout << cost;
            return;
        }

        for(int i=0; i<g[here].size(); i++){
            int next = g[here][i].first;
            int next_cost = g[here][i].second;
            if(dist[next] > cost + next_cost){
                dist[next] = cost + next_cost;
                pq.push(make_pair(-(cost + next_cost), next));
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