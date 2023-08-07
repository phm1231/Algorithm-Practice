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

int n, m, src, dst;
vector<vector<pair<int, int> > > g;
vector<ll> visited;


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    g.resize(n+1, vector<pair<int,int> >());
    visited.resize(n+1, 987654321);
    for(int i=0; i<m; i++){
        int s, d, c;
        cin >> s >> d >> c;
        g[s].push_back(make_pair(d, c));
    }
    cin >> src >> dst;
}

void solve()
{
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    visited[src] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(visited[here] < dist) continue;

        if(here == dst){
            cout << dist;
            return;
        }

        for(int i=0; i<g[here].size(); i++){
            int next = g[here][i].first;
            int cost = dist + g[here][i].second;
            if(visited[next] > cost){
                visited[next] = cost;
                pq.push(make_pair(-cost, next));
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