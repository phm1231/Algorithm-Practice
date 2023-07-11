// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
bool check(int);

int n, m;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void solve()
{
    // 배열을 m개 "이하"의 구간으로 나누어서 얻어진 구간의 점수 중 최솟값.
    int left = 0;
    int right = 0;
    for(int i=0; i<n; i++) right = max(v[i], right);
    int answer = right;

    while(left <= right){
        int mid = (left + right) / 2;
        // m개 이하라면, Mid를 더 줄여도 된다.
        if(check(mid)){
            answer = min(answer, mid);
            right = mid -1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << answer;
}
// 구간의 점수가 m개 이하인지
bool check(int num){
    int cnt = 1;
    int maxV = v[0];
    int minV = v[0];
    for(int i=1; i<n; i++){
        maxV = max(maxV, v[i]);
        minV = min(minV, v[i]);

        if(maxV - minV > num){
            cnt++;
            maxV = minV = v[i];
        }
    }
    return cnt <= m;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}