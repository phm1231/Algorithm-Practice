// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int mergeLeft(char target);
int mergeRight(char target);


int n;
vector<char> v;

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
    int answer = 987654321;
    // 빨간색을 좌측으로 모은다.
    answer = min(answer, mergeLeft('R'));
    answer = min(answer, mergeLeft('B'));
    answer = min(answer, mergeRight('R'));
    answer = min(answer, mergeRight('B'));
    cout << answer;
}

int mergeLeft(char target){
    int cnt = 0;
    bool meetR, meetB;
    meetR = meetB = false;
    for(int i=0; i<n; i++){
        if(v[i] == 'R') meetR = true;
        if(v[i] == 'B') meetB = true;

        if(v[i] == target){
            if(meetR && meetB) cnt++;
        }
    }
    return cnt;
}

int mergeRight(char target){
    int cnt = 0;
    bool meetR, meetB;
    meetR = meetB = false;
    for(int i=n-1; i>=0; i--){
        if(v[i] == 'R') meetR = true;
        if(v[i] == 'B') meetB = true;

        if(v[i] == target){
            if(meetR && meetB) cnt++;
        }
    }
    return cnt;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}