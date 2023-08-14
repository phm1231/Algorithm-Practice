// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
ll initTree(int start, int end, int node);
ll sum(int start, int end, int node, int left, int right);
void update(int start, int end, int node, int index, ll diff);


int n, m, k;
vector<ll> v;
vector<ll> segtree;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m >> k;
    v.resize(n, 0);
    segtree.resize(n*4, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
}

void solve()
{
    initTree(0, n-1, 1);
    for(int i=0; i<m+k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){ // b번째 수를 c로 바꾼다.
            ll diff = c - v[b-1];
            v[b-1] = c;
            update(0, n-1, 1, b-1, diff);
        }
        else if(a == 2){
            cout << sum(0, n-1, 1, b-1, c-1) << "\n";
        }
    }
}

ll initTree(int start, int end, int node){
    if(start == end) return segtree[node] = v[start];

    int mid = (start + end) / 2;
    return initTree(start, mid, node * 2) + initTree(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return segtree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, ll diff){
    if(!(start <= index && index <= end)) return;

    segtree[node] += diff;

    if(start != end){
        int mid = (start + end) / 2;
        update(start, mid, node * 2, index, diff);
        update(mid + 1, end, node * 2 + 1, index, diff);
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}