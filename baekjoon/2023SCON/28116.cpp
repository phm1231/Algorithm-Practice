// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

int n;
vector<int> src;
vector<int> idxs; // idxs[1] = src에서 1의 인덱스
vector<int> answer;

void swap_src(int a, int b){
    int tmp = src[a];
    src[a] = src[b];
    src[b] = tmp;
}

void swap_idx(int a, int b){
    int tmp = idxs[b];
    idxs[b] = idxs[a];
    idxs[a] = tmp;
}

void init()
{
    FAST
}

void input()
{
    cin >> n;
    src.resize(n+1, 0);
    idxs.resize(n+1, 0);
    answer.resize(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> src[i]; 
        idxs[src[i]] = i;
    }
}


void solve()
{
    for(int i=1; i<=n; i++){ // 좌측부터 돌면서
        int idx = idxs[i]; // i가 있는 위치
        if(i != idx){
            answer[i] += abs(i - idx); // i가 이동한 거리
            answer[src[i]] += abs(i - idx); // src[i]가 이동한 거리.
            swap_src(i, idx);
            swap_idx(src[i], src[idx]);
        }
    }

    // 정답 출력
    for(int i=1; i<=n; i++) cout << answer[i] << ' ';
}

int main()
{
    init();
    input();
    solve();
    return 0;
}