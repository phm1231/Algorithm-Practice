// based problem:
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{

}

void solve()
{
    int cur = 0;
    int answer = 0;
    for(int i=1; i<=10; i++){
        int up, down;
        cin >> down >> up;
        cur -= down;
        cur += up;
        answer = max(cur, answer);
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