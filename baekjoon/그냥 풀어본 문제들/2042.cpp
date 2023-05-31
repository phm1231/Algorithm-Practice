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
void update(int, int, int, int, long long);
long long sum(int, int, int, int, int);
long long generate_segment_tree(int node, int start, int end);

int n, m, k;
long long arr[1000001];
long long *tree;

void update(int node, int start, int end, int index, long long diff){
    // 범위 밖이라면
    if(!(start <= index && index <= end)) return;
    
    // 세그먼트 트리 변경(구간합)
    tree[node] += diff;

    if(start != end){
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

long long sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;

    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

long long generate_segment_tree(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];

    int mid = (start + end ) / 2;

    return tree[node] = generate_segment_tree(node * 2, start, mid) + generate_segment_tree(node * 2 + 1, mid + 1, end);
}

void init()
{
    FAST
}

void input()
{
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
}

void solve()
{
    int h = (int)ceil(log2(n)); // 크기가 n인 배열을 세그먼트 트리로 만들 때 필요한 높이
    int tree_siz = (1 << (h + 1)); // 세그먼트 트리의 크기
    tree = new long long[tree_siz];
    generate_segment_tree(1, 1, n);

    long long a, b, c;
    for(int i=0; i<m+k; i++){
        cin >> a >> b >> c;
        // b번째 수를 c로 바꾼다
        if(a == 1){
            long long diff = c - arr[b]; // 기존의 수와 바꿔야 할 수의 차이.
            arr[b] = c; // b번째 수를 c로 변경하고
            update(1, 1, n, b, diff); // 세그먼트 트리에도 반영한다.
        }
        // b번째 수부터 c번째 수까지의 구간합을 출력하여라.
        else{
            cout << sum(1, 1, n, b, c) << "\n";
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