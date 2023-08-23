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

vector<vector<pair<ll, ll> > > slow_g; // 달빛 늑대가 체력을 회복하며 가는 길
vector<vector<pair<ll, ll> > > g; // 달빛 여우가 가는 길.
vector<vector<pair<ll, ll> > > fast_g; // 달빛 늑대가 빠르게 가는 길

vector<vector<ll> > wolf_dist;
vector<ll> fox_dist;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;

    slow_g.resize(n+1, vector<pair<ll, ll> > ());
    g.resize(n+1, vector<pair<ll, ll> > ());
    fast_g.resize(n+1, vector<pair<ll, ll> > ());
    wolf_dist.resize(n+1, vector<ll>(2, MAX));
    fox_dist.resize(n+1, MAX);

    for(ll i=0; i<m; i++){
        ll src, dst, cost;
        cin >> src >> dst >> cost;

        // 달빛 늑대는 두 배로 빨리 간다.
        fast_g[src].push_back(make_pair(dst, cost));
        fast_g[dst].push_back(make_pair(src, cost));

        // 달빛 여우는 일반 속도로 간다.
        g[src].push_back(make_pair(dst, cost * 2));
        g[dst].push_back(make_pair(src, cost * 2));

        // 달빛 늑대는 두 배로 천천히 간다.
        slow_g[src].push_back(make_pair(dst, cost * 4));
        slow_g[dst].push_back(make_pair(src, cost * 4));
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

        // here에 빠른 길로 도착했으므로, 다으에는 느린 길로 가야 함.
        if(useFast){
            for(ll i=0; i<slow_g[here].size(); i++){
                ll next = slow_g[here][i].first;
                ll next_dist = dist + slow_g[here][i].second; // * 4한거임
                if(wolf_dist[next][0] > next_dist){
                    wolf_dist[next][0] = next_dist;
                    wolfPQ.push(make_pair(-next_dist, make_pair(next, false)));
                }
            }
        }
        else{
            for(ll i=0; i<fast_g[here].size(); i++){
                ll next = fast_g[here][i].first;
                ll next_dist = dist + fast_g[here][i].second;
                // next를 사용해서 빠른 길로 온 것이
                if(wolf_dist[next][1] > next_dist){
                    wolf_dist[next][1] = next_dist;
                    wolfPQ.push(make_pair(-next_dist, make_pair(next, true)));
                }
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