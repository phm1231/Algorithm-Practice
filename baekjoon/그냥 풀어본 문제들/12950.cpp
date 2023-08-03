// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, m;
int edge[20][20];
int dp[20][20];
queue<pair<int, int> > q;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;

            edge[i][j] = -1;
            dp[i][j] = 987654321;
        }
    }
    while(m--){
        int a, b;
        char c;
        cin >> a >> b >> c;
        edge[a][b] = edge[b][a] = c - 'a';
        dp[a][b] = dp[b][a] = 1;
        q.push({a, b}); // 바로 연결된 정점 둘
    }
}

void solve()
{
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(k == i || k == j) continue;
                if(edge[i][k] == -1 || edge[k][j] == -1) continue;

                if(edge[i][k] == edge[k][j] && dp[i][j] > 2){
                    dp[i][j] = dp[j][i] = 2;
                    q.push({i, j}); // k를 통해 연결된 정점 둘. 즉 i - k - j를 통해 이동 가능하면서 i - k, k - j 간 간선의 종류가 동일함.
                }
            }
        }
    }

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        // a와 b는 팰린드롬을 유지하며 연결되어있는 정점.

        // i는 a와 연결된 b가 아닌 다른 정점
        for(int i=0; i<n; i++){
            if(i == a || i == b) continue;
            // j는 b와 연결된 i나 a가 아닌 다른 정점 
            for(int j=0; j<n; j++){
                if(j == i || j == a || j == b) continue;
                if(edge[a][i] == -1 || edge[b][j] == -1) continue;

                if(edge[a][i] == edge[b][j] && dp[i][j] > dp[a][b] + 2){
                    dp[i][j] = dp[j][i] = dp[a][b] + 2;
                    q.push({i, j});
                }
            }
        }
    }

    if(dp[0][1] == 987654321) cout << -1;
    else cout << dp[0][1];
}


int main()
{
    init();
    input();
    solve();
    return 0;
}