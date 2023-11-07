#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
pair<ll, ll> InitSegtree(int start, int end, int node);
pair<ll, ll> GetMinMax(int start, int end, int node, int left, int right);
void update(int start, int end, int node, int index, ll to);

const int MAX = 1e9;
int n, k;
vector<ll> v;
vector<pair<ll, ll> > segtree; // first = min, second = max

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> k;
    segtree.reserve(n*4);
    v.reserve(n);
    for(int i=0; i<n; i++) v[i] = i;
    InitSegtree(0, n-1, 1);
}

void Solve()
{
    while(k--){
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 0){
            // a랑 b를 바꾼다
            update(0, n-1, 1, a, v[b]);
            update(0, n-1, 1, b, v[a]);
            int tmp = v[a];
            v[a] = v[b];
            v[b] = tmp;
        }
        else if(q == 1){
            // a부터 b까지 확인한다.
            pair<ll, ll> res = GetMinMax(0, n-1, 1, a, b);
            if(res.first == a && res.second == b) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

pair<ll, ll> GetMinMax(int start, int end, int node, int left, int right){
    if(left > end || right < start) return {1e9, -1e9};
    if(left <= start && end <= right) return segtree[node];
    int mid = (start + end) / 2;
    pair<ll, ll> left_tree = GetMinMax(start, mid, node * 2, left, right);
    pair<ll, ll> right_tree = GetMinMax(mid + 1, end, node * 2 + 1, left, right);
    return {min(left_tree.first, right_tree.first), max(left_tree.second, right_tree.second)};
}

void update(int start, int end, int node, int index, ll to){
    if(!(start <= index && index <= end)) return;
    if(start == end){
        segtree[node].first = to;
        segtree[node].second = to;
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, to);
    update(mid + 1, end, node * 2 + 1, index, to);
    segtree[node].first = min(segtree[node * 2].first, segtree[node * 2 + 1].first);
    segtree[node].second = max(segtree[node * 2].second, segtree[node * 2 + 1].second);
}

pair<ll, ll> InitSegtree(int start, int end, int node){
    if(start == end){
        segtree[node].first = v[start];
        segtree[node].second = v[start];
        return segtree[node];
    }
    int mid = (start + end) / 2;
    pair<ll, ll> left_tree = InitSegtree(start, mid, node * 2);
    pair<ll, ll> right_tree = InitSegtree(mid + 1, end, node * 2 + 1);
    segtree[node].first = min(left_tree.first, right_tree.first);
    segtree[node].second = max(left_tree.second, right_tree.second);
    return segtree[node];
}


int main()
{
    int t;
    cin >> t;
    Init();
    while(t--){
        Input();
        Solve();
    }
    return 0;
}