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
string str;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> str;
}

void solve()
{
    // dp[i] = long이 i개일 때, 나타날 수 있는 경우의 수.
    vector<int> dp(21, 0);
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4; i<=20; i++) dp[i] = dp[i-1]+dp[i-2];

    // 문자열 속 long을 추출한다.
    vector<int> v; // v[i] = long 위치.
    const string s = "long";
    for(int i=0; i<n-3; i++){
        bool isLong = true;
        for(int j=0; j<4; j++){
            if(str[i+j] != s[j]) isLong = false;
        }
        if(isLong) v.push_back(i);
    }

    // 연속한 long 개수 세기
    vector<int> cnts;
    for(int i=0; i<v.size();){
        int cnt = 1;
        for(int j=i+1; j<v.size(); j++){
            if(v[j] - v[j-1] == 4) cnt++;
            else break;
        }
        i += cnt;
        cnts.push_back(cnt);
    }

    int answer = 1;
    for(int cnt: cnts){
        if(dp[cnt] == 0) continue;
        else answer *= dp[cnt];
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