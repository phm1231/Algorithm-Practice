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

void merge(int, int);
int getParent(int);

int n, m;
vector<int> parent;
priority_queue<pair<int, pair<int, int> > > pq;

void merge(int a, int b){
    int ap = getParent(a);
    int bp = getParent(b);
    // 번호가 낮은 사람이 부모가 되도록 설정
    ap > bp ? parent[bp] = ap : parent[ap] = bp; 
}

int getParent(int child){
    if(child == parent[child]) return child;
    else return getParent(parent[child]);
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    parent.resize(n+1, 0);
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=0; i<m; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        pq.push(make_pair(-cost, make_pair(src, dst)));
    }
}

void solve()
{
    int cnt = 1;
    ll answer = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int src = pq.top().second.first;
        int dst = pq.top().second.second;
        pq.pop();

        int ap = getParent(src);
        int bp = getParent(dst);
        if(ap != bp){
            answer += cost;
            merge(ap, bp);
            cnt++;
        }

        if(cnt == n) break;
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