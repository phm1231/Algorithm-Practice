// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int go(int);

int n, c;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> c;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
}

void solve()
{
    int left, right; // 최소 간격, 최대 간격
    left = 1;
    right = v[n-1] - v[0];

    int answer = left;
    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = go(mid); // 공유기 사이의 간격이 최소 mid일 때, 설치할 수 있는 공유기의 개수
        // 최소 mid 만큼의 간격으로 c개 이상 설치할 수 있다면, left를 더 끌어올려도 된다.
        if(cnt >= c){
            answer = max(answer, mid);
            left = mid + 1;
        }
        // 그렇지 못하다면
        else{
            right = mid - 1;
        }
    }
    cout << answer;
    return;
}

int go(int mid){
    int cnt = 1;
    int left = 0;
    for(int right=1; right<n; right++){
        if(v[right] - v[left] >= mid){
            cnt++; // right에 공유기를 설치한다.
            left = right;
        }
    }
    return cnt;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}