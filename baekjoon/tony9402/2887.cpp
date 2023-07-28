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
void merge(int, int);
int getParent(int);

int n;
vector<int> parent;
vector<pair<int, int> > xv;
vector<pair<int, int> > yv;
vector<pair<int, int> > zv;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    parent.resize(n, 0);
    for(int i=0; i<n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        xv.push_back(make_pair(x, i));
        yv.push_back(make_pair(y, i));
        zv.push_back(make_pair(z, i));
    }

    for(int i=0; i<n; i++) parent[i] = i;
}

void solve()
{
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    sort(zv.begin(), zv.end());

    priority_queue<pair<int, pair<int, int> > > pq;
    for(int i=0; i<n-1; i++){
        pq.push(make_pair(-abs(xv[i+1].first - xv[i].first), make_pair(xv[i+1].second, xv[i].second)));
        pq.push(make_pair(-abs(yv[i+1].first - yv[i].first), make_pair(yv[i+1].second, yv[i].second)));
        pq.push(make_pair(-abs(zv[i+1].first - zv[i].first), make_pair(zv[i+1].second, zv[i].second)));
    }

    ll answer = 0;
    while(!pq.empty()){
        if(n == 0) break;
        int cost = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        int pa = getParent(a);
        int pb = getParent(b);

        if(pa == pb) continue;

        merge(pa, pb);
        n--;
        answer += cost;
    }

    cout << answer;
}


void merge(int a, int b){
    int pa = getParent(a);
    int pb = getParent(b);
    if(pa < pb) parent[pa] = pb;
    else parent[pb] = pa;
}

int getParent(int child){
    if(child == parent[child]) return child;
    else return parent[child] = getParent(parent[child]);
}


int main()
{
    init();
    input();
    solve();
    return 0;
}