// based problem:
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void init();
void input();
void solve();

vector<vector<int> > board(4, vector<int>(2, 0));

void init()
{
    FAST
}

void input()
{
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            cin >> board[i][j];
        }
    }
}

void solve()
{
    int answer = 0;
    int current = 0;
    for(int i=0; i<4; i++){
        int off = board[i][0]; // 내린 사람
        int on = board[i][1]; // 타는 사람
        current -= off;
        current += on;
        answer = max(answer, current);
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