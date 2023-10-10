#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
double GetDistance(int a, int b);
int GetParent(int a);
void Merge(int a, int b);

const int MAX = 1e9;

int n;
vector<pair<double, double> > stars;
vector<int> parent;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n;
    for(int i=0; i<n; i++) parent.push_back(i);
    for(int i=0; i<n; i++){
        double a, b;
        cin >> a >> b;
        stars.push_back({a, b});
    }
}

void Solve()
{
    priority_queue<pair<double, pair<int, int> > > pq;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            pq.push({-GetDistance(i, j), {i, j}});
        }
    }
    double answer = 0;
    int cnt = 0;
    while(!pq.empty()){
        if(cnt == n-1) break;

        double dist = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        int pa = GetParent(a);
        int pb = GetParent(b);
        if(pa == pb) continue;

        Merge(a, b);
        answer += dist;
        cnt++;
    }
    cout << answer;
}

double GetDistance(int a, int b){
    double y_gap = (stars[b].first - stars[a].first) * (stars[b].first - stars[a].first);
    double x_gap = (stars[b].second - stars[a].second) * (stars[b].second - stars[a].second);
    return sqrt(y_gap + x_gap);
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