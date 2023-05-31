// based problem:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

long long generate_segment_tree(int, int, int);
long long update(int, int, int, int, int);
long long multiply(int, int, int, int, int);

int n, m, k;
int arr[1000001];
long long *tree;
const long long MOD = 1000000007;

long long generate_segment_tree(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = generate_segment_tree(node * 2, start, mid) * generate_segment_tree(node * 2 + 1, mid + 1, end) % MOD;
}

long long update(int node, int start, int end, int index, int value){
    if(!(start <= index && index <= end)) return tree[node];
    if(start == end) return tree[node] = value;

    int mid = (start + end) / 2;
    return tree[node] = update(node * 2, start, mid, index, value) * update(node * 2 + 1, mid + 1, end, index, value) % MOD;
}


long long multiply(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 1;
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return multiply(node * 2, start, mid, left, right) * multiply(node * 2 + 1, mid + 1, end, left, right) % MOD;
}

void init()
{
    FAST
}

void input()
{
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> arr[i];

}

void solve()
{
    int h = (int)ceil(log2(n));
    int tree_siz = 1 << (h + 1);
    tree = new long long[tree_siz];
    generate_segment_tree(1, 1, n);

    for(int i=0; i<m+k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        // b번째 수를 c로 바꾼다
        if(a == 1){
            update(1, 1, n, b, c);
            arr[b] = c;
        }
        // b부터 c까지의 구간곱을 구한다.
        else{
            cout << multiply(1, 1, n, b, c) << "\n";
        }
    }

}

int main()
{
    init();
    input();
    solve();
    return 0;
}