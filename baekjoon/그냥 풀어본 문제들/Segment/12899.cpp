// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

void update(int start, int end, int node, int idx);
int query(int start, int end, int node, int k);

int n;
vector<int> Segtree;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    Segtree.resize(8000004, 0);
}

void solve()
{
    for(int i=0; i<n; i++){
        int type, value;
        cin >> type >> value;
        if(type == 1){
            update(0, 2000000, 1, value);
        }
        else if(type == 2){
            cout << query(0, 2000000, 1, value) << "\n";
        }
    }
}

// k번쨰로 작은 원소 가져오기.
int query(int start, int end, int node, int k){
    Segtree[node]--; // 제거.
    if(start == end) return start;
    int mid = (start + end) / 2;
    // 왼쪽에 k개 이상의 작은 수가 있음
    if(Segtree[node * 2] >= k) return query(start, mid, node * 2, k);
    else return query(mid + 1, end, node * 2 + 1, k - Segtree[node * 2]);
}


void update(int start, int end, int node, int idx){
    if(!(start <= idx && idx <= end)) return;

    Segtree[node]++; // 추가.

    if(start == end) return;

    int mid = (start + end) / 2;
    update(start, mid, node * 2, idx);
    update(mid + 1, end, node * 2 + 1, idx);
}


int main()
{
    init();
    input();
    solve();
    return 0;
}
