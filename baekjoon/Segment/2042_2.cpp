#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
ll InitSegtree(int start, int end, int node);
ll sum(int start, int end, int node, int left, int right);
void update(int start, int end, int node, int index, ll to);

const int MAX = 1e9;
int n, m, k;
vector<ll> v;
vector<ll> segtree;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m >> k;
    v.resize(n, 0);
    segtree.resize(n*4, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void Solve()
{
    InitSegtree(0, n-1, 1);
    int cnt = m + k;
    while(cnt--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            // b번째 수를 c로 바꿈
            update(0, n-1, 1, b-1, c);
            v[b-1] = c;
        }
        else if(a == 2){
            // b부터 c까지의 구간합 출력
            cout << sum(0, n-1, 1, b-1, c-1) << '\n';
        }
    }
}

ll InitSegtree(int start, int end, int node){
    if(start == end) return segtree[node] = v[start];
    int mid = (start + end) / 2;
    return segtree[node] = InitSegtree(start, mid, node * 2) + InitSegtree(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return segtree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, ll to){
    if(!(start <= index && index <= end)) return;

    if(start == end){
        segtree[node] = to;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, to);
    update(mid + 1, end, node * 2 + 1, index, to);
    segtree[node] = segtree[node*2] + segtree[node*2+1];
}

int main()
{
    Init();
    Input();
    Solve();
    return 0;
}