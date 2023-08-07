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

int n, m; // 분기점 개수, 길 개수
vector<vector<pair<int, int> > > g;
vector<bool> canSee;
vector<ll> visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    canSee.resize(n, false);
    visited.resize(n, (ll)300000 * 100001);
    g.resize(n, vector<pair<int, int> >());

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 1) canSee[i] = true;
    }

    for(int i=0; i<m; i++){
        int a, b, t;
        cin >> a >> b >> t;
        if(a == n-1 || b == n-1){
            g[a].push_back(make_pair(b, t));
            g[b].push_back(make_pair(a, t));
        }
        else if(!canSee[a] && !canSee[b]){
            g[a].push_back(make_pair(b, t));
            g[b].push_back(make_pair(a, t));   
        }
    }
}

void solve()
{
    priority_queue<pair<ll, int> > pq; // 거리, 현재 위치
    pq.push(make_pair(0, 0));
    visited[0] = 0;

    while(!pq.empty()){
        ll dist = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(visited[here] < dist) continue;

        if(here == n-1){
            cout << dist;
            return;
        }

        for(int i=0; i<g[here].size(); i++){
            int next = g[here][i].first;
            ll cost = dist + g[here][i].second;
            if(visited[next] > cost){
                visited[next] = cost;
                pq.push(make_pair(-cost, next));
            }
        }
    }
    cout << -1;
    return;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}