// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int initMinSegtree(int start, int end, int node);
int initMaxSegtree(int start, int end, int node);
int getMin(int start, int end, int node, int left, int right);
int getMax(int start, int end, int node, int left, int right);

int n, m;
const int MAX_VALUE = 1000000001;
const int MIN_VALUE = -1;
vector<int> v;
vector<int> MinSegtree;
vector<int> MaxSegtree;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    MinSegtree.resize(n*4, MAX_VALUE);
    MaxSegtree.resize(n*4, MIN_VALUE);
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];

}

void solve()
{
    initMaxSegtree(0, n-1, 1);
    initMinSegtree(0, n-1, 1);
    while(m--){
        int from, to;
        cin >> from >> to;
        cout << getMin(0, n-1, 1, from - 1, to - 1) << ' ' << getMax(0, n-1, 1, from - 1, to - 1) << "\n";
    }
}

int initMinSegtree(int start, int end, int node){
    if(start == end) return MinSegtree[node] = v[start];
    int mid = (start + end) / 2;
    return MinSegtree[node] = min(initMinSegtree(start, mid, node * 2), initMinSegtree(mid + 1, end, node * 2 + 1));
}

int initMaxSegtree(int start, int end, int node){
    if(start == end) return MaxSegtree[node] = v[start];
    int mid = (start + end) / 2;
    return MaxSegtree[node] = max(initMaxSegtree(start, mid, node * 2), initMaxSegtree(mid + 1, end, node * 2 + 1));
}

int getMin(int start, int end, int node, int left, int right){
    // 범위에 속하지 않는다면
    if(left > end || right < start) return MAX_VALUE;
    // 범위에 속한다면
    if(left <= start && end <= right) return MinSegtree[node];

    int mid = (start + end) / 2;
    return min(getMin(start, mid, node * 2, left, right), getMin(mid + 1, end, node * 2 + 1, left, right));
}

int getMax(int start, int end, int node, int left, int right){
    // 범위에 속하지 않는다면
    if(left > end || right < start) return MIN_VALUE;
    // 범위에 속한다면
    if(left <= start && end <= right) return MaxSegtree[node];

    int mid = (start + end) / 2;
    return max(getMax(start, mid, node * 2, left, right), getMax(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
    init();
    input();
    solve();
    return 0;
}