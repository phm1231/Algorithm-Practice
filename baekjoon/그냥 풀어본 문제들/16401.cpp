#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();

const int MAX = 1e9;
int n, m; // 조카의 수, 과자의 수
vector<int> snacks; // 과자의 길이

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m;
    snacks.resize(m, 0);
    for(int i=0; i<m; i++) cin >> snacks[i];
}

void Solve()
{
    // n명의 조카들에게 과자를 똑같이 나누어줄 때, 가능한 과자의 최대 길이
    int answer = 0;
    int left = 1;
    int right = 1;
    for(const int& snack: snacks) right = max(right, snack);
    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 0;
        for(const int& snack: snacks){
            cnt += (snack / mid);
        }
        
        if(cnt >= n){
            answer = max(mid, answer);
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << answer;
}


int main()
{
    Init();
    Input();
    Solve();
    return 0;
}