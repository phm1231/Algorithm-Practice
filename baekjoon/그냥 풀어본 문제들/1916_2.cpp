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
    g.resize(n+1, vector<pair<int, int> > ());
    for(int i=0; i<m; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        g[src].push_back(make_pair(dst, cost));
    }
    cin >> from >> to;
}

void solve()
{
    priority_queue<pair<ll, ll> > pq;
    vector<ll> dist(n+1, 1e10);
    dist[from] = 0;
    pq.push(make_pair(0, from));

    while(!pq.empty()){
        ll here = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();

        if(dist[here] < d) continue;    

        if(here == to){
            cout << d;
            return;
        }

        for(int i=0; i<g[here].size(); i++){
            ll next = g[here][i].first;
            ll next_dist = d + g[here][i].second;
            if(dist[next] > next_dist){
                dist[next] = next_dist;
                pq.push(make_pair(-next_dist, next));
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