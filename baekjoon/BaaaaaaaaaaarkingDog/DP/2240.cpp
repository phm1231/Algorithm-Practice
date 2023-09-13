#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int t, w;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> t >> w;
    v.resize(t+1, 0);
    for(int i=1; i<=t; i++){
        cin >> v[i];
    }
}

void solve()
{
    int dp[3][1001][31] = {0, }; // 자두나무의 위치, 시간, 교환 횟수
    
    // 1번 자두나무에서 시작하므로, 위치 = 1, 시간 = 1, 교환 횟수 = 0
    dp[1][1][0] = (v[1] == 1 ? 1 : 0);
    // 2번 자두나무는 시작하자마자 이동한다고 가정, 위치 = 2, 시간 = 1, 교환 횟수 = 1
    dp[2][1][1] = (v[1] == 2 ? 1 : 0);

    for(int i=2; i<=t; i++){
        for(int j=0; j<=w; j++){
            // i초에서 1번 자두나무의 자두가 떨어질 경우
            if(v[i] == 1){
                // 건너뛰기 불가
                if(j == 0){
                    dp[1][i][j] = dp[1][i-1][j] + 1;
                    continue;
                }

                // 1번 자두나무에서 가만히 기다리거나, 2번 자두나무에서 건너옴
                dp[1][i][j] = max(dp[1][i-1][j] + 1, dp[2][i-1][j-1] + 1);
                // 2번 자두나무는 둘 중 큰 값으로 유지됨,
                dp[2][i][j] = max(dp[2][i-1][j], dp[1][i-1][j-1]);
            }
            // i초에서 2번 자두나무의 자두가 떨어질 경우
            else{
                if(j == 0){
                    dp[1][i][j] = dp[1][i-1][j];
                    continue;
                }
                dp[2][i][j] = max(dp[2][i-1][j] + 1, dp[1][i-1][j-1] + 1);
                dp[1][i][j] = max(dp[1][i-1][j], dp[2][i-1][j-1]);
            }
        }
    }
    int answer = 0;
    for(int i=0; i<=w; i++){
        answer = max(answer, dp[1][t][i]);
        answer = max(answer, dp[2][t][i]);
    }
    cout << answer;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}