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
int getParent(int c);
void merge(int a, int b);

int n, m;
vector<int> parent;
priority_queue<pair<int, pair<int, int> > > pq;

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
    int cnt = 0;
    int answer = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int src = pq.top().second.first;
        int dst = pq.top().second.second;
        pq.pop();

        if(getParent(src) != getParent(dst)){
            merge(src, dst);
            if(cnt == 0) cnt = 2;
            else cnt++;
            answer += cost;
        }

        if(cnt == n){
            cout << answer;
            return;
        }
    }
}

int getParent(int c){
    if(c == parent[c]) return c;
    else return parent[c] = getParent(parent[c]);
}

void merge(int a, int b){
    int pa = getParent(a);
    int pb = getParent(b);

    if(pa > pb) parent[pa] = pb;
    else parent[pb] = pa;
}
int main()
{
    init();
    input();
    solve();
    return 0;
}