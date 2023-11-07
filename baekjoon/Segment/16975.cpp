#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
void propagation(int start, int end, int node);
ll InitSegtree(int start, int end, int node);
ll GetX(int start, int end, int node, int index);
void update(int start, int end, int node, ll left, ll right, ll add);

const int MAX = 1e9;
int n, m;
vector<ll> v;
vector<ll> segtree;
vector<ll> lazy;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n;
    v.resize(n, 0);
    segtree.resize(n*4, 0);
    lazy.resize(n*4, 0);
    for(int i=0; i<n; i++) cin >> v[i];
    cin >> m;
}

void Solve()
{
    InitSegtree(0, n-1, 1);
    while(m--){
        int query_type;
        cin >> query_type;
        if(query_type == 1){
            ll i, j, k; // v[i-1] ~ v[j-1]까지 k를 더한다.
            cin >> i >> j >> k;
            update(0, n-1, 1, i-1, j-1, k);
        }
        else if(query_type == 2){
            int x;
            cin >> x; // v[x]를 출력한다.
            cout << GetX(0, n-1, 1, x-1) << endl;
        }
    }
}

ll InitSegtree(int start, int end, int node){
    if(start == end) return segtree[node] = v[start];
    int mid = (start + end) / 2;
    return segtree[node] = InitSegtree(start, mid, node * 2) + InitSegtree(mid + 1, end, node * 2 + 1);
}

ll GetX(int start, int end, int node, int index){
    propagation(start, end, node);
    if(!(start <= index && index <= end)) return 0;
    if(start == end) return segtree[node];

    int mid = (start + end) / 2;
    return GetX(start, mid, node * 2, index) + GetX(mid + 1, end, node * 2 + 1, index);
}

void update(int start, int end, int node, ll left, ll right, ll add){
    propagation(start, end, node);
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        segtree[node] += (end - start + 1) * add;
        if(start != end){
            lazy[node * 2] += add;
            lazy[node * 2 + 1] += add;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, left, right, add);
    update(mid + 1, end, node * 2 + 1, left, right, add);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

void propagation(int start, int end, int node){
    if(lazy[node] == 0) return;
    segtree[node] += lazy[node] * (end - start + 1);
    if(start != end){
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

int main()
{
    Init();
    Input();
    Solve();
    return 0;
}