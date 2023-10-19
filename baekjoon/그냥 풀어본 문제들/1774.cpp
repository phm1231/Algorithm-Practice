#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
int GetParent(int a);
void Merge(int a, int b);
double GetDistance(pair<ll, ll> a, pair<ll, ll> b);

const int MAX = 1e9;
vector<int> parent;
vector<pair<ll, ll> > locs;
int n, m, bridge_count;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cout << fixed;
    cout.precision(2);
}

void Input()
{
    cin >> n >> m;
    parent.resize(n+1, 0);
    locs.reserve(n+1);
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=1; i<=n; i++){
        int y, x;
        cin >> y >> x;
        locs[i] = {y, x};
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(GetParent(a) == GetParent(b)) continue;
        Merge(a, b);
        bridge_count++;
    }
}

void Solve()
{
    double answer = 0.0;
    priority_queue<pair<double, pair<ll, ll> > > pq;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            pq.push({-GetDistance(locs[i], locs[j]), {i, j}});
        }
    }
    while(!pq.empty()){
        //if(bridge_count == n-1) break;

        double dist = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        if(GetParent(a) == GetParent(b)) continue;
        Merge(a, b);
        answer += dist;
        bridge_count++;
    }

    cout << answer << endl;
}

double GetDistance(pair<ll, ll> a, pair<ll, ll> b){
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}

int GetParent(int a){
    if(a == parent[a]) return a;
    else return parent[a] = GetParent(parent[a]);
}

void Merge(int a, int b){
    int pa = GetParent(a);
    int pb = GetParent(b);
    if(pa > pb) parent[pa] = pb;
    else parent[pb] = pa;
}


int main()
{
    Init();
    Input();
    Solve();
    return 0;
}