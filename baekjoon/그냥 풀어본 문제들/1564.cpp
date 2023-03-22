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
#include <map>
#include <unordered_map>
#include <set>

#define ll long long
#define MAX 100001
using namespace std;

void init();
void input();
void solve();

int n;
const long long int MOD = 1e12;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> n;
}

void solve()
{
    long long number = 1;
    for(int i=2; i<=n; i++){
        number *= i;
        // 뒤에 0 제거
        while(number % 10 == 0){
            number = number / 10;
        }
        number = number % 1000000000000;
    }
    printf("%05lld", number % 100000);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}