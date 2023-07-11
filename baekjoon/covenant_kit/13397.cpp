#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
bool calcul(int);

int n, m, answer;
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
    int left = 0;
    int right = -1;
    for(int i=0; i<n; i++) right = max(right, v[i]);
    // 배열을 M개 이하의 구간으로 나누었을 때, 구간의 점수의 최댓값 중 최솟값을 구하는 문제이다.
    // mid를 최솟값으로 설정한다.
    answer = right;
    while(left <= right){
        int mid = (left + right) / 2;
        // 구간의 점수가 mid보다 작은 개수가 m개 이하라면, mid를 키워준다.
        if(calcul(mid)){
            answer = min(answer, mid);
            right = mid - 1;
        }
        // m개보다 많다면 mid를 
        else{
            left = mid + 1;
        }
    }
    cout << answer;
}

bool calcul(int num){
    int cnt = 1; // 마지막 구간은 무조건 나뉘므로.
    int minV = v[0];
    int maxV = v[0];
    for(int i=1; i<n; i++){
        minV = min(minV, v[i]);
        maxV = max(maxV, v[i]);

        // 구간의 점수가 num보다 커진다면, 구간을 나누어준다.
        if(maxV - minV > num){
            cnt++; // 구간의 점수가 num보다 작은 구간의 개수
            minV = maxV = v[i];
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