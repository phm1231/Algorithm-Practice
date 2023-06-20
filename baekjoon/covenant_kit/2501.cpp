// based problem:
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

// n의 약수 중 k번째로 작은 수를 출력하기.
int n, k;

void init()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
}

void solve()
{
    int cnt = 0;
    int answer = 0;
    for(int i=1; i<=n; i++){
        if(n % i == 0) cnt++;

        if(cnt == k){
            answer = i;
            break;
        }
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