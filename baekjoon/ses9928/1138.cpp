// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<int> v; // v[i] = 키가 i인 사람이 자기보다 왼쪽에 큰 사람이 몇명인지.

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n+1, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void solve()
{
    vector<int> answer(n, 987654321);

    for(int i=0; i<n; i++){
        int height = i+1; // i번째 사람의 키
        if(i == n-1){
            for(int j=0; j<n; j++){
                if(answer[j] == 987654321){
                    answer[j] = i+1;
                    break;
                }
            }
            continue;
        }

        int cnt = 0; // 앞서 등장한 h보다 큰 사람.
        for(int j=0; j<n; j++){
            // 앞서 cnt명이 이미 등장했을 때
            if(cnt == v[i]){
                if(answer[j] == 987654321){
                    answer[j] = height;
                    break;
                }
            }
            else if(answer[j] > height){
                cnt++;
            }
        }
    }

    for(int i=0; i<n; i++) cout << answer[i] << ' ';
}

int main()
{
    init();
    input();
    solve();
    return 0;
}