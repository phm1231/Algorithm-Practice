#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
ll GetSum(ll start, ll end, ll node, ll left, ll right);
ll InitSegtree(ll start, ll end, ll node);
void Update(ll start, ll end, ll node, ll left, ll right, ll add);
void Propagate(ll start, ll end, ll node);

const int MAX = 1e9;
ll n, m, k;
vector<ll> v;
vector<ll> lazy;
vector<ll> segtree;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m >> k;
    v.resize(n, 0);
    lazy.resize(n*4, 0);
    segtree.resize(n*4, 0);
    for(ll i=0; i<n; i++) cin >> v[i];
}

void Solve()
{
    InitSegtree(0, n-1, 1);
    int cnt = m + k;
    while(cnt--){
        int query_type;
        cin >> query_type;
        if(query_type == 1){
            // from 부터 to까지 add를 더한다.
            ll from, to, add;
            cin >> from >> to >> add;
            Update(0, n-1, 1, from - 1, to - 1, add);
        }
        else if(query_type == 2){
            // from부터 to까지 구간합을 출력한다.
            ll from, to;
            cin >> from >> to;
            cout << GetSum(0, n-1, 1, from - 1, to - 1) << endl;
        }
    }
}

ll GetSum(ll start, ll end, ll node, ll left, ll right){
    Propagate(start, end, node);
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return segtree[node];

    int mid = (start + end) / 2;
    return GetSum(start, mid, node * 2, left, right) + GetSum(mid + 1, end, node * 2 + 1, left, right);
}

ll InitSegtree(ll start, ll end, ll node){
    if(start == end) return segtree[node] = v[start];
    ll mid = (start + end) / 2;
    return segtree[node] = InitSegtree(start, mid, node * 2) + InitSegtree(mid + 1, end, node * 2 + 1);
}

void Update(ll start, ll end, ll node, ll left, ll right, ll add){
    Propagate(start, end, node);
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
    Update(start, mid, node * 2, left, right, add);
    Update(mid + 1, end, node * 2 + 1, left, right, add);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

void Propagate(ll start, ll end, ll node){
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