// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int getParent(int c);
void merge(int a, int b);

int n;
vector<pair<ll, int> > xs, ys, zs;
vector<int> parent;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    parent.resize(n, 0);
    for(int i=0; i<n; i++) parent[i] = i;
    for(int i=0; i<n; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        xs.push_back(make_pair(x, i));
        ys.push_back(make_pair(y, i));
        zs.push_back(make_pair(z, i));
    }
}

void solve()
{
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    sort(zs.begin(), zs.end());

    priority_queue<pair<ll, pair<int, int> > > pq;
    for(int i=1; i<n; i++){
        pq.push(make_pair(-abs(xs[i].first - xs[i-1].first), make_pair(xs[i].second, xs[i-1].second)));
        pq.push(make_pair(-abs(ys[i].first - ys[i-1].first), make_pair(ys[i].second, ys[i-1].second)));
        pq.push(make_pair(-abs(zs[i].first - zs[i-1].first), make_pair(zs[i].second, zs[i-1].second)));
    }

    int cnt = 0;
    ll answer = 0;
    while(!pq.empty()){
        ll cost = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        int pa = getParent(a);
        int pb = getParent(b);

        if(pa == pb) continue;
        
        merge(a, b);
        cnt++; // 다리 개수
        answer += cost;

        if(cnt == n-1){
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