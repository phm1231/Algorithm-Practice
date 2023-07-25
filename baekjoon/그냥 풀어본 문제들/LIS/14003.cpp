// based problem:
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
    DPLIS();
//    BinaryLIS();
}

void DPLIS(){
    vector<int> dp(n, 0);
    vector<int> trace(n, -1);
    int maxLen = 1;
    int lastIdx = 0;

    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(v[i] > v[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
        if(maxLen < dp[i]){
            maxLen = dp[i];
            lastIdx = i;
        }
    }

    stack<int> stk;
    while(lastIdx != -1){
        stk.push(v[lastIdx]);
        lastIdx = trace[lastIdx];
    }
    cout << maxLen << '\n';
    while(!stk.empty()){
        cout << stk.top() << ' ';
        stk.pop();
    }
}


void BinaryLIS(){
    vector<int> lis;
    vector<int> index(n, -1); // index[i] = v[i]는 lis에서 idx에 위치한다.

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

    stack<int> stk;
    int number = lis.size() - 1;
    for(int i=n-1; i>=0; i--){
        if(index[i] == number){
            stk.push(v[i]);        
            number--;
        }
    }
    cout << lis.size() << "\n";
    while(!stk.empty()) {
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