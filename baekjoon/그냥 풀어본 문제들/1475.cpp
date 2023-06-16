// based problem:
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void init();
void input();
void solve();

string str;

void init()
{
    FAST
}

void input()
{
    cin >> str;
}

void solve()
{
    vector<int> v(10, 0);
    for(int i=0; i<str.size(); i++){
        int number = str[i] - '0';
        v[number]++;
    }

    int max_idx = 0;
    int max_cnt = 0;
    for(int i=0; i<v.size(); i++){
        if(i == 6 || i == 9) max_cnt = max((v[6] + v[9]) / 2 + (v[6] + v[9]) % 2, max_cnt);
        else max_cnt = max(v[i], max_cnt);
    }
    cout << max_cnt;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}