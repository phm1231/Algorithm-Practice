// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

void LISDP();
void LISBinary();

int n;
vector<int> arr;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    arr.resize(n, 0);
    for(int i=0; i<n; i++) cin >> arr[i];
}

void solve()
{
//    LISDP();
    LISBinary();
}

void LISDP(){
    vector<int> dp(n, 0);
    dp[0] = 1;
    int answer = 0;

    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
        answer = max(answer, dp[i]);
    }
    cout << answer; // 가장 긴 LIS 길이.
}

void LISBinary(){
    vector<int> lis;
    lis.push_back(arr[0]);
    for(int i=1; i<n; i++){
        // lis 맨 뒤의 값보다 큰 값이면
        if(lis.back() < arr[i]) lis.push_back(arr[i]);
        else{
            // arr[i] 이상인 숫자가 최초로 등장하는지?
            int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[idx] = arr[i];
        }
    }
    int answer = lis.size();
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}