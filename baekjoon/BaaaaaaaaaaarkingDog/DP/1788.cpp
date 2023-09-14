#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();

int n;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
}

void solve()
{
    int fib[2000001] = {0, };
    const int NUM = 1000000;
    const int MOD = 1000000000;
    n += NUM;

    fib[NUM-1] = 1;
    fib[NUM] = 0;
    fib[NUM + 1] = 1;

    if(n >= NUM){
        for(int i=NUM + 2; i<=n; i++){
            fib[i] = (fib[i-1] + fib[i-2]) % MOD;
        } 
    }
    else{
        for(int i=NUM; i>=n+1; i--){
            fib[i-1] = (fib[i+1] - fib[i]) % MOD;
        }
    }

    if(fib[n] > 0){
        cout << 1 << endl;
    }
    else if(fib[n] == 0){
        cout << 0 << endl;
    }
    else{
        cout << -1 << endl;
    }
    cout << abs(fib[n]);
}


int main()
{
    init();
    input();
    solve();
    return 0;
}