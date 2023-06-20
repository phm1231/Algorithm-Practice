// based problem:
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int lcm(int, int); // 최소공배수
int gcd(int, int); // 최대공약수

int n, m;

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
}

void solve()
{
    cout << gcd(n, m) << endl;
    cout << lcm(n, m) << endl;

}

int main()
{
    init();
    input();
    solve();
    return 0;
}