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
string src, dst;

bool cmp(char a, char b){
    if(a == 'i'){
        if(b == 'i' || b == 'j' || b == 'l') return true;
        else return false;
    }
    else if(a == 'v'){
        if(b == 'v' || b == 'w') return true;
        else return false;
    }
    return a == b;
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    cin >> src >> dst;
}

void solve()
{
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<n+1; i++) dp[i][0] = i; // dp[i][j] = src[i]까지의 문자열이 dst[j]가 되기 위해 필요한 최소 추가, 수정, 삭제의 횟수
    for(int i=0; i<m+1; i++) dp[0][i] = i;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(cmp(src[i-1], dst[j-1])){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                int tmp = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(dp[i-1][j-1], tmp) + 1;
            }
        }
    }
    cout << dp[n][m];
}


int main()
{
    init();
    input();
    solve();
    return 0;
}