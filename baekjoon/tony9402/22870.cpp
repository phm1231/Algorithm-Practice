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
void dijkstra(vector<int>&, int);
void eraseEdge(int, int);

vector<vector<pair<int, int> > > g;
int n, m, s, e;
vector<int> distS;
vector<int> distE;
vector<int> used;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    distS.resize(n+1, 987654321);
    distE.resize(n+1, 987654321);
    g.resize(n+1, vector<pair<int, int> >());
    used.resize(n+1, 0);

    for(int i=0; i<m; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        g[src].push_back(make_pair(dst, cost));
        g[dst].push_back(make_pair(src, cost));
    }
    cin >> s >> e;
}

void solve()
{
    int answer = 0;
    dijkstra(distS, s);
    dijkstra(distE, e);
    answer += distS[e];

    eraseEdge(s, e);

    distE = vector<int>(n+1, 987654321);
    dijkstra(distE, e);

    answer += distE[s];
    cout << answer;    
}

void eraseEdge(int S, int E){
    int pre = S;
    int here = S;
    // S에서 출발하여 E로 간다.
    while(here != E){
        int mn = 987654321; // 다음 노드 번호.
        for(int i=0; i<g[here].size(); i++){
            int next = g[here][i].first;
            int cost = g[here][i].second;

            if(next == pre) continue;
            // S에서 here까지 오는 비용 + here에서 next로 가는 비용 + E에서 next까지 오는 비용 == S에서 E까지 가는 비용 이라면
            // next는 S -> E로 가는데 사용되었을 수 있다.
            if(distS[here] + cost + distE[next] == distS[E]){
                mn = min(mn, next); // 사용되었을 수 있을 next중 가장 빠른 값.
            }
        }
        pre = S;
        S = mn;
        if(S != E) used[S] = 1;
    }
}

void dijkstra(vector<int>& dist, int src){
    priority_queue<pair<int, int> > pq;
    vector<bool> visited(n+1, false);
    pq.push(make_pair(0, src));

    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        dist[here] = min(dist[here], cost);

        if(!visited[here]){
            visited[here] = true;
            for(int i=0; i<g[here].size(); i++){
                int next = g[here][i].first;
                int next_cost = g[here][i].second;
                if(used[next]) continue;
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