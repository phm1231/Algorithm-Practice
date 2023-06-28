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
int src, dst;
vector<vector<pair<int, int> > > tree; // tree[from].first = to, second = cost
vector<int> visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    tree.resize(n+1, vector<pair<int, int> >());
    visited.resize(n+1, 987654321);
    for(int i=0; i<m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        tree[from].push_back(make_pair(to, cost));
    }
    cin >> src >> dst;
}

void solve()
{
    priority_queue<pair<int, int> > pq; // 가중치, 목적지, first 기준으로 내림차순 정렬. cost가 큰 것을 나중에 선택해야 한다.
    pq.push(make_pair(0, src));
    visited[src] = 0;

    while(!pq.empty()){
        int distance = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(visited[here] < distance) continue; // 이미 최단경로를 체크한 노드라면

        for(int i=0; i<tree[here].size(); i++){
            int next = tree[here][i].first;
            int cost = distance + tree[here][i].second;
            if(visited[next] > cost){
                visited[next] = cost;
                pq.push(make_pair(-cost, next));
            }
        }
    }
    cout << visited[dst];
}

int main()
{
    init();
    input();
    solve();
    return 0;
}