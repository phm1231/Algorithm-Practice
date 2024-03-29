// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, m;
vector<int> memories;
vector<int> costs;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    memories.resize(n+1, 0);
    costs.resize(n+1, 0);
    for(int i=1; i<=n; i++) cin >> memories[i];
    for(int i=1; i<=n; i++) cin >> costs[i];
}

void solve()
{
    // dp[i][j] = i번째 프로그램을 종료(고려)했을 때 j만큼의 비용이 들고 최대 확보할 수 있는 메모리
    vector<vector<int> > dp(101, vector<int>(10001, 0));
    for(int i=1; i<=n; i++){
        dp[i][costs[i]] = memories[i]; // i번쨰 프로그램을 종료하면 costs[i]만큼의 비용이 들고 memories[i]만큼 메모리를 확보할 수 있음.
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<10001; j++){
            if(j >= costs[i]){ // costs[i]만큼의 비용을 지불할 수 있다면.
                // 이전 것과, 이전 것에서 현재 코스트를 지불하기 전의 값에 memories[i]를 더한 것 중 최댓값.
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-costs[i]] + memories[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // 최소비용이므로 찾자마자 출력 후 리턴.
    // n번째 프로그램까지 고려했을 떄 m을 초과하여 i를 넘길 수 있다면 출력 후 종료
    for(int i=0; i<10001; i++){
        if(dp[n][i] >= m){
            cout << i;
            return;
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