// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


#define ll long long
#define MAX 100001

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
    if(n <= 10){
        cout << n << endl;
        return;
    }

    queue<ll> q;
    for(int i=1; i<=9; i++){
        q.push(i);
    }

    int idx = 1;
    while(!q.empty()){
        ll number = q.front();
        q.pop();
        if(idx == n){
            cout << number << endl;
            return;
        }
        for(int i=0; i<number % 10; i++){
            ll tmp = number * 10 + i;
            q.push(tmp);
        }
        idx++;
    }
    cout << -1;
    return;

}



int main()
{
    init();
    input();
    solve();
    return 0;
}