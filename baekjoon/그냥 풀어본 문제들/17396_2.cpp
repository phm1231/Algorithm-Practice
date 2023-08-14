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
vector<int> isVisible;
vector<vector<pair<int, int> > > g;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    isVisible.resize(n, 0);
    g.resize(n, vector<pair<int, int> > ());

    for(int i=0; i<n; i++) cin >> isVisible[i];

    for(int i=0; i<m; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        // n-1번은 넥서스이므로 Visible에 상관없이 가야함.
        if(src == n-1 || dst == n-1){
            g[src].push_back(make_pair(dst, cost));
            g[dst].push_back(make_pair(src, cost));
        }
        // 넥서스가 아니면 무조건 Visible이 꺼져야 함
        else if(isVisible[src] != 1 && isVisible[dst] != 1){
            g[src].push_back(make_pair(dst, cost));
            g[dst].push_back(make_pair(src, cost));            
        }
    }
}

void solve()
{
    priority_queue<pair<ll, int> > pq;
    vector<ll> dist(n+1, (ll)300001 * 100001);
    pq.push(make_pair(0, 0));
    dist[0] = 0;

    while(!pq.empty()){
        int here = pq.top().second;
        ll cost = -pq.top().first;
        pq.pop();

        if(dist[here] < cost) continue;

        if(here == n-1){
            cout << cost;
            return;
        }

        for(int i=0; i<g[here].size(); i++){
            int next = g[here][i].first;
            ll next_cost = g[here][i].second;
            
            if(dist[next] > cost + next_cost){
                dist[next] = cost + next_cost;
                pq.push(make_pair(-(cost + next_cost), next));
            }
        }

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