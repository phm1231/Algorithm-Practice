// based problem:
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void init();
void input();
void solve();

void init()
{
    FAST
}

void input()
{

}

void solve()
{
    for(int i=0; i<3; i++){
        int zero = 0; // 배
        int one = 0; // 등
        for(int j=0; j<4; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 0) zero++;
            else one++;
        }
        if(zero == 1 && one == 3) cout << "A";
        else if(zero == 2 && one == 2) cout << "B";
        else if(zero == 3 && one == 1) cout << "C";
        else if(zero == 4) cout << "D";
        else cout << "E";
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