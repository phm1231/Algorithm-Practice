// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define MAX 999999999999

void init();
void input();
void solve();

ll n, m;

vector<vector<pair<ll, ll> > > g; // 달빛 여우가 가는 길.

vector<vector<ll> > wolf_dist;
vector<ll> fox_dist;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;

    g.resize(n+1, vector<pair<ll, ll> > ());
    wolf_dist.resize(n+1, vector<ll>(2, MAX));
    fox_dist.resize(n+1, MAX);

    for(ll i=0; i<m; i++){
        ll src, dst, cost;
        cin >> src >> dst >> cost;
        // 달빛 여우는 일반 속도로 간다.
        g[src].push_back(make_pair(dst, cost * 2));
        g[dst].push_back(make_pair(src, cost * 2));
    }
}

void solve()
{
    // 달빛 여우의 최단거리 구하기.
    priority_queue<pair<ll, ll> > pq;
    pq.push(make_pair(0, 1));
    fox_dist[1] = 0;

    while(!pq.empty()){
        ll here = pq.top().second;
        ll dist = -pq.top().first;
        pq.pop();

        if(fox_dist[here] < dist) continue;

        for(ll i=0; i<g[here].size(); i++){
            ll next = g[here][i].first;
            ll next_dist = dist + g[here][i].second;
            if(fox_dist[next] > next_dist){
                fox_dist[next] = next_dist;
                pq.push(make_pair(-next_dist, next));
            }
        }
    }

    priority_queue<pair<ll, pair<ll, bool> > > wolfPQ;
    wolf_dist[1][0] = 0; // 느리게 들어온 것만 0으로 초기화
    wolfPQ.push(make_pair(0, make_pair(1, false)));

    while(!wolfPQ.empty()){
        ll here = wolfPQ.top().second.first;
        bool useFast = wolfPQ.top().second.second;
        ll dist = -wolfPQ.top().first;
        wolfPQ.pop();

        if(wolf_dist[here][useFast] < dist) continue;

        for(ll i=0; i<g[here].size(); i++){
            ll next = g[here][i].first;
            ll next_dist;

            if(!useFast) next_dist = dist + (g[here][i].second / 2);
            else next_dist = dist + (g[here][i].second * 2);

            if(wolf_dist[next][!useFast] > next_dist){
                wolf_dist[next][!useFast] = next_dist;
                wolfPQ.push(make_pair(-next_dist, make_pair(next, !useFast)));
            }
        }
    }

    ll answer = 0;
    for(ll i=2; i<=n; i++){
        ll minDist = min(wolf_dist[i][0], wolf_dist[i][1]);
        if(fox_dist[i] < minDist) answer++;
    }
    cout << answer;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}