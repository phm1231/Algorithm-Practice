// based problem:
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void init();
void input();
void solve();

int n;

void init()
{
    FAST
}

void input()
{
    cin >> n;
}

void solve()
{
    stack<int> stk;
    for(int i=1; i<2*n; i++){
        // 공백
        int space_cnt = abs(i-n);
        for(int j=0; j<space_cnt; j++) cout << ' ';
        // 별
        int star_cnt;
        if(n >= i){
            star_cnt = (i-1)*2 + 1;
            if(n != i) stk.push(star_cnt);
        }
        else{
            star_cnt = stk.top();
            stk.pop();
        }

        for(int j=0; j<star_cnt; j++) cout << '*'; 
        cout << endl;
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}