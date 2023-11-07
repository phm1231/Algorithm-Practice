// based problem:
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void BinaryLIS();
void DPLIS();

int n;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void solve()
{
    // DPLIS();
    BinaryLIS();
}

void DPLIS(){
    vector<int> dp(n, 0);
    vector<int> trace(n, 0);
    int maxLen = 1;
    int idx = 0;

    for(int i=0; i<n; i++){
        dp[i] = 1;
        trace[i] = -1;
        for(int j=0; j<i; j++){
            // 현재 검사하는 원소가 앞서 있던 원소보다 크다면, 해당 원소를 앞서 있던 원소 뒤에 붙여 LIS를 만들 수 있다.
            if(v[i] > v[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                trace[i] = j; // i번 원소는 j번 원소 뒤에 온다.
            }
        }
        // 기존 LIS보다 더 긴 LIS가 등장했다면
        if(maxLen < dp[i]){
            maxLen = dp[i];
            idx = i;
        }
    }

    stack<int> stk;
    while(idx != -1){
        stk.push(v[idx]);
        idx = trace[idx];
    }

    cout << maxLen << "\n";
    while(!stk.empty()){
        cout << stk.top() << ' ';
        stk.pop();
    }
}

void BinaryLIS(){
    vector<int> lis;
    vector<int> index(n, -1); // index[i] = v[i]는 lis에서 index[i]번째에 위치합니다.

    for(int i=0; i<n; i++){
        if(lis.size() == 0 || lis.back() < v[i]){
            lis.push_back(v[i]);
            index[i] = lis.size() - 1;
        }
        else{
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
            index[i] = idx;
        }
    }

    cout << lis.size() << "\n";
    stack<int> stk;
    int idx = lis.size() - 1;

    for(int i=n-1; i>=0; i--){
        if(idx == index[i]){
            stk.push(v[i]);
            idx--;
        }
    }
    while(!stk.empty()){
        cout << stk.top() << ' ';
        stk.pop();
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}