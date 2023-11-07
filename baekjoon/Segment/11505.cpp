// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
ll initSegtree(int start, int end, int node);
void update(int start, int end, int node, int index);
ll sum(int start, int end, int node, int left, int right);

const ll MOD = 1000000007;
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
    for(int i=0; i<n; i++){
        cin >> v[i];
        v[i] %= MOD;
    }
}

void solve()
{
    segtree.resize(n*4, 0);
    initSegtree(0, n-1, 1);
    for(int i=0; i<m+k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            // b번째 수를 c로 바꾼다.
            v[b-1] = (c % MOD);
            update(0, n-1, 1, b-1);
        }
        if(a == 2){
            cout << sum(0, n-1, 1, b-1, c-1) << "\n";
        }
    }
}

ll initSegtree(int start, int end, int node){
    if(start == end) return segtree[node] = v[start];
    int mid = (start + end) / 2;
    return segtree[node] = (initSegtree(start, mid, node * 2) * initSegtree(mid + 1, end, node * 2 + 1)) % MOD;
}

void update(int start, int end, int node, int index){
    // 범위 밖
    if(!(start <= index && index <= end)) return;
    // 리프 노드
    if(start == end && start == index){
        segtree[node] = v[index] % MOD;
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node * 2, index);
    update(mid + 1, end, node * 2 + 1, index);

    segtree[node] = (segtree[node*2] * segtree[node * 2 + 1]) % MOD;

}

ll sum(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 1;
    if(left <= start && end <= right) return segtree[node] % MOD;

    int mid = (start + end) / 2;
    return (sum(start, mid, node * 2, left, right) * sum(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}