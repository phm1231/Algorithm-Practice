// based problem:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>

#define ll long long
#define MAX 1001
// #define CPP_INOUT true

using namespace std;

void init();
void input();
void solve();
int get_gcd(int, int);
int get_lcm(int, int);

int n, m;

void init()
{
    #ifdef CPP_INOUT
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif
}

void input()
{
    scanf("%d %d", &n, &m);
}

void solve()
{
    printf("%d\n%d\n", get_gcd(n, m), get_lcm(n, m));
}

/* gcd is 최대공약수 */
int get_gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/* lcm is 최소공배수 */
int get_lcm(int a, int b)
{
    return (a*b) / get_gcd(a,b);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}